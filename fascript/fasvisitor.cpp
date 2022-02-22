#include "pch.h"
#include "fasvisitor.hpp"
#include "exception.hpp"
#include "function.hpp"
#include "ASTs/IAstExpr.hpp"



namespace fas {
antlrcpp::Any FASVisitor::visitProgram (FAScriptParser::ProgramContext *ctx) {
	std::vector<std::shared_ptr<IAstExpr>> _exprs;
	for (auto _stmt : ctx->stmt ()) {
		if (_stmt->fnStmt ()) {
			auto _fn = AstFunction::FromCtx (_stmt->fnStmt ());
			_exprs.push_back (AstOp2::MakeAssign (_stmt->fnStmt ()->Id () [0]->getText (), _fn));
		} else if (_stmt->expr ()) {
			_exprs.push_back (IAstExpr::FromCtx (_stmt->expr ()));
		} else {
			throw fas::Exception ("visit not implement.");
		}
	}
	return _exprs;
}
}
