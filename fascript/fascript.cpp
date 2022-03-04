#include "pch.h"
#include "fascript.hpp"

#include "_AntlrGens/FAScriptParser.h"
#include "_AntlrGens/FAScriptLexer.h"
#include "_AntlrGens/FAScriptBaseVisitor.h"
#include "FASVisitor.hpp"
#include "ASTs/IAstExpr.hpp"
#include "exception.hpp"
#include "executor.hpp"

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

	// 获取代码执行位置
	Executor _exec { shared_from_this (), m_bc.Dump (), _code.size () };

	// 编译代码
	std::vector<std::shared_ptr<IAstExpr>> _exprs = _visitor.visit (_parser.program ()).as<std::vector<std::shared_ptr<IAstExpr>>> ();
	std::unique_lock _ul { m_mtx, std::defer_lock };
	_ul.lock ();

	// 忽略空语句
	for (size_t i = 0; i < _exprs.size (); ++i) {
		if (!_exprs [i]) {
			_exprs.erase (_exprs.begin () + i);
			--i;
		}
	}

	// 最后一个语句改为return
	size_t _last_index = _exprs.size ();
	if (_last_index == 0)
		return Value { shared_from_this () };
	_last_index--;
	auto _last_ret = dynamic_cast<AstReturn*> (_exprs [_last_index].get ());
	if (!_last_ret)
		_exprs [_last_index] = AstReturn::Make (_exprs [_last_index]);

	// 初步计算长度
	size_t _start = 0;
	for (size_t i = 0; i < _exprs.size (); ++i) {
		_start += _exprs [i]->GetBinaryCodeSize (*this, OpType::None, _start);
	}

	// 计算函数代码长度
	for (size_t i = 0; i < m_uncompiled_funcs.size (); ++i) {
		_start += m_uncompiled_funcs [i]->GetBinaryCodeSize (*this, OpType::None, _start);
	}

	// 编译代码
	for (auto _expr : _exprs) {
		_expr->GenerateBinaryCode (m_bc, *this, OpType::None);
	}

	// 编译函数代码
	for (size_t i = 0; i < m_uncompiled_funcs.size (); ++i) {
		m_uncompiled_funcs [i]->GenerateBinaryCode (m_bc, *this, OpType::None);
	}

	// 执行代码
	_exec.Exec ();
	return Value { shared_from_this () };
}



int32_t FAScript::GetNameId (AstIdType _type, std::string _name) {
	std::unique_lock _ul { m_mtx };
	if (_type == AstIdType::Global || _type == AstIdType::Member || _type == AstIdType::Local) {
		auto _p = m_name_to_id.find (_name);
		if (_p != m_name_to_id.end ())
			return _p->second;
		m_next_id++;
		m_name_to_id [_name] = m_next_id;
		return m_next_id;
	} else if (_type == AstIdType::Argument) {
		// 找到最后一个 func
		for (auto _i = m_current_blocks.rbegin (); _i != m_current_blocks.rend (); ++_i) {
			if (auto _pclass = dynamic_cast<AstFunction *> (_i->get ())) {
				for (size_t i = 0; i < _pclass->Arguments.size (); ++i) {
					if (_pclass->Arguments[i] == _name)
						return (int32_t) i;
				}
			}
		}

		// 找不到则抛异常
		throw Exception::NotImplement ();
	} else {
		throw Exception::NotImplement ();
	}
}



int32_t FAScript::NewGlobalFuncId (std::shared_ptr<Function> _func) {
	std::unique_lock _ul { m_mtx };
	m_next_id++;
	m_id_to_func [m_next_id] = _func;
	_func->Id = m_next_id;
	return m_next_id;
}



std::shared_ptr<Function> FAScript::GetFuncFromId (int32_t _func_id) {
	std::unique_lock _ul { m_mtx };
	auto _p = m_id_to_func.find (_func_id);
	return _p != m_id_to_func.end () ? _p->second : nullptr;
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
			return AstIdType::Member;
		} else {
			throw Exception::NotImplement ();
		}
	}
}
}
