#ifndef __ASTFUNCTION_HPP__
#define __ASTFUNCTION_HPP__



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
		auto _fn = std::shared_ptr<IAstExpr> ((IAstExpr *) new AstFunction { _ctx });
	}

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::FnStmtContext *_ctx) {
		auto _fn = std::shared_ptr<IAstExpr> ((IAstExpr *) new AstFunction { _ctx });
	}

	bool GenerateBinaryCode (std::vector<uint8_t> &_buf, fas::FAScript &_fas) override {

	}
};
}



#endif //__ASTFUNCTION_HPP__
