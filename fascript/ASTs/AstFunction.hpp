#ifndef __AST_FUNCTION_HPP__
#define __AST_FUNCTION_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstFunction: IAstExpr {
	AstFunction (FAScriptParser::FnExprContext *_ctx) {
		auto _ids = _ctx->Id ();
		for (size_t i = 0; i < _ids.size (); ++i)
			Arguments.push_back (_ids [i]->getText ());
		Codes = IAstExpr::FromCtxs (_ctx->stmt ());
	}

	AstFunction (FAScriptParser::FnStmtContext *_ctx) {
		auto _ids = _ctx->Id ();
		for (size_t i = 1; i < _ids.size (); ++i)
			Arguments.push_back (_ids [i]->getText ());
		Codes = IAstExpr::FromCtxs (_ctx->stmt ());
	}

public:
	std::vector<std::string> Arguments;
	std::vector<std::shared_ptr<IAstExpr>> Codes;

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::FnExprContext *_ctx) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstFunction { _ctx });
	}

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::FnStmtContext *_ctx) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstFunction { _ctx });
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		if (_type == OpType::Load) {
			auto _func = std::make_shared<Function> ();
			_func->ArgumentCount = Arguments.size ();
			BinCode _bc1 {};
			for (auto _code : Codes) {
				if (_code)
					_code->GenerateBinaryCode (_bc, _s, OpType::None);
			}
			_func->Codes = _bc1.Dump ();
			auto _func_id = _s.GetGlobalFuncId (_func);
			_func->Id = _func_id;
			_bc.LoadFunction (_func_id);
		} else {
			throw Exception::NotImplement ();
		}
	}
};
}



#endif //__AST_FUNCTION_HPP__
