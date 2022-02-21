#include "pch.h"
#include "fascript.hpp"



#include "_AntlrGens/FAScriptParser.h"
#include "_AntlrGens/FAScriptLexer.h"
#include "_AntlrGens/FAScriptBaseVisitor.h"
#include "FASVisitor.hpp"



namespace fas {
bool FAScript::RunCode (std::string _code) {
	// TODO 解析代码
	antlr4::ANTLRInputStream _stream { _code };
	FAScriptLexer _lexer { &_stream };
	antlr4::CommonTokenStream _cts { &_lexer };
	_cts.fill ();
	FAScriptParser _parser { &_cts };
	fas::FASVisitor _visitor {};

	// TODO 编译代码
	_visitor.visit (_parser.program ());

	// TODO 执行代码

	// 执行栈
	auto _stack = std::make_shared<std::vector<Value>> ();
}
}
