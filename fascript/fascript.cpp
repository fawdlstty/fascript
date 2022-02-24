#include "pch.h"
#include "fascript.hpp"

#include "_AntlrGens/FAScriptParser.h"
#include "_AntlrGens/FAScriptLexer.h"
#include "_AntlrGens/FAScriptBaseVisitor.h"
#include "FASVisitor.hpp"
#include "ASTs/IAstExpr.hpp"
#include "exception.hpp"



namespace fas {
bool FAScript::RunCode (std::string _code) {
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
	std::vector<uint8_t> _bincodes;
	for (auto _expr : _exprs) {
		_expr->GenerateBinaryCode (_bincodes, *this);
	}

	// TODO 执行代码

	// 执行栈
	auto _stack = std::make_shared<std::vector<Value>> ();
}
}
