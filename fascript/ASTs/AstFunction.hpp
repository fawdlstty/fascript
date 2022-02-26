#ifndef __AST_FUNCTION_HPP__
#define __AST_FUNCTION_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstFunction: IAstExpr {
	AstFunction (FAScriptParser::FnExprContext *_ctx) {
		auto _ids = _ctx->Id ();
		for (size_t i = 0; i < _ids.size (); ++i)
			Arguments.push_back (_ids [i]->getText ());
	}

	AstFunction (FAScriptParser::FnStmtContext *_ctx) {
		auto _ids = _ctx->Id ();
		for (size_t i = 1; i < _ids.size (); ++i)
			Arguments.push_back (_ids [i]->getText ());
	}

public:
	std::vector<std::string> Arguments;

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::FnExprContext *_ctx) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstFunction { _ctx });
	}

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::FnStmtContext *_ctx) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstFunction { _ctx });
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, bool _load) override {
		throw Exception::NotImplement ();
	}
};
}



#endif //__AST_FUNCTION_HPP__
