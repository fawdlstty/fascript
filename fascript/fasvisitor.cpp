#include "pch.h"
#include "fasvisitor.hpp"
#include "exception.hpp"
#include "function.hpp"



namespace fas {
antlrcpp::Any FASVisitor::visitProgram (FAScriptParser::ProgramContext *ctx) {
	//std::vector<Function> _funcs;
	for (auto _stmt : ctx->stmt ()) {
		if (_stmt->fnStmt ()) {
			//
		} else if (_stmt->expr ()) {

		} else {
			throw fas::Exception ("visit not implement.");
		}
	}
	return visitChildren (ctx);
}
}
