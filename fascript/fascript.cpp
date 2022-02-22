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
	std::vector<uint8_t> _codes;
	for (auto _expr : _exprs) {
		auto _expr_p = _expr.get ();
		if (auto _op2 = dynamic_cast<AstOp2*> (_expr_p)) {
			if (auto _op2_left = dynamic_cast<AstId *> (_op2->m_left.get ())) {

			} else {
				throw fas::Exception ("赋值运算符的左侧必须是ID");
			}
		}
	}

	// TODO 执行代码

	// 执行栈
	auto _stack = std::make_shared<std::vector<Value>> ();
}
}
