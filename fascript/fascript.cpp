#include "pch.h"
#include "fascript.hpp"

#include "_AntlrGens/FAScriptParser.h"
#include "_AntlrGens/FAScriptLexer.h"
#include "_AntlrGens/FAScriptBaseVisitor.h"
#include "FASVisitor.hpp"
#include "ASTs/IAstExpr.hpp"
#include "exception.hpp"
#include "BinCode.hpp"

#pragma comment (lib, "antlr4-runtime.lib")



namespace fas {
Value FAScript::RunCode (std::string _code) {
	// 解析代码
	antlr4::ANTLRInputStream _stream { _code };
	FAScriptLexer _lexer { &_stream };
	antlr4::CommonTokenStream _cts { &_lexer };
	_cts.fill ();
	FAScriptParser _parser { &_cts };
	fas::FASVisitor _visitor {};

	// 编译代码
	std::vector<std::shared_ptr<IAstExpr>> _exprs = _visitor.visit (_parser.program ()).as<std::vector<std::shared_ptr<IAstExpr>>> ();
	std::unique_lock _ul { m_mtx, std::defer_lock };
	_ul.lock ();
	BinCode _bc;
	size_t _start = 0;
	for (auto _expr : _exprs) {
		if (_expr)
			_start += _expr->GetBinaryCodeSize (*this, OpType::None, _start);
	}
	for (auto _expr : _exprs) {
		if (_expr)
			_expr->GenerateBinaryCode (_bc, *this, OpType::None);
	}

	// TODO 执行代码

	// 执行栈
	//auto _stack = std::make_shared<std::vector<Value>> ();
	return Value { shared_from_this () };
}



uint16_t FAScript::GetNameId (AstIdType _type, std::string _name) {
	std::unique_lock _ul { m_mtx };
	if (_type == AstIdType::Global) {
		auto _p = m_name_to_id.find (_name);
		if (_p != m_name_to_id.end ())
			return _p->second;
		m_next_id++;
		m_name_to_id [_name] = m_next_id;
		return m_next_id;
	} else if (_type == AstIdType::This) {
		// TODO 找到最后一个class
		for () {
		}
	} else if (_type == AstIdType::Local) {
		//
	} else if (_type == AstIdType::Argument) {
		//
	} else {
		throw Exception::NotImplement ();
	}
}



uint16_t FAScript::NewGlobalFuncId (std::shared_ptr<Function> _func) {
	std::unique_lock _ul { m_mtx };
	m_next_id++;
	m_id_to_func [m_next_id] = _func;
	_func->Id = m_next_id;
	return m_next_id;
}



AstIdType FAScript::CheckIdType (std::string _id) {
	if (m_current_blocks.empty ()) {
		return AstIdType::Global;
	} else {
		auto _p = m_current_blocks.rbegin ()->get ();
		if (auto _pfunc = dynamic_cast<AstFunction *> (_p)) {
			for (std::string _arg : _pfunc->Arguments) {
				if (_arg == _id)
					return AstIdType::Argument;
			}
			return AstIdType::Local;
		} else if (auto _pclass = dynamic_cast<AstClass *> (_p)) {
			return AstIdType::This;
		} else {
			throw Exception::NotImplement ();
		}
	}
}
}
