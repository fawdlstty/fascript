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
	for (auto _expr : _exprs) {
		_expr->GenerateBinaryCode (_bc, *this, true);
	}

	// TODO 执行代码

	// 执行栈
	//auto _stack = std::make_shared<std::vector<Value>> ();
	return Value { shared_from_this () };
}



uint16_t FAScript::GetGlobalNameId (std::string _name) {
	std::unique_lock _ul { m_mtx };
	auto _p = m_name_to_id.find (_name);
	if (_p != m_name_to_id.end ())
		return _p->second;
	m_next_id++;
	m_name_to_id [_name] = m_next_id;
	//m_id_to_var [m_next_id] = Value { shared_from_this () };
	return m_next_id;
}
}
