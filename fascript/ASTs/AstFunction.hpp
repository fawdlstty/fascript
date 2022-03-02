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
	bool m_registered = false;
	uint16_t FuncId = 0;
	std::vector<std::string> Arguments;
	std::vector<std::shared_ptr<IAstExpr>> Codes;
	size_t CodeStart = 0;

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::FnExprContext *_ctx) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstFunction { _ctx });
	}

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::FnStmtContext *_ctx) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstFunction { _ctx });
	}

	size_t GetBinaryCodeSize (FAScript &_s, OpType _type, size_t _start) override {
		if (_type == OpType::None) {
			CodeStart = _start;
			for (size_t i = 0; i < Codes.size (); ++i) {
				_start = Codes [i]->GetBinaryCodeSize (_s, OpType::None, _start);
			}
			return _start - CodeStart;
		} else if (_type == OpType::Load) {
			if (!m_registered) {
				m_registered = true;
				_s.RegisterUncompiledFunc (shared_from_this ());
			}
			return 3;
		} else {
			throw Exception::NotImplement ();
		}
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		if (_type == OpType::None) {
			for (size_t i = 0; i < Codes.size (); ++i) {
				Codes [i]->GenerateBinaryCode (_bc, _s, OpType::None);
			}
		} else if (_type == OpType::Load) {
			if (FuncId == 0)
				FuncId = _s.NewGlobalFuncId (std::shared_ptr<Function> (new Function { .Id = 0, .ArgumentCount = Arguments.size () }));
			_bc.LoadFunction (FuncId);
		} else {
			throw Exception::NotImplement ();
		}
	}
};
}



#endif //__AST_FUNCTION_HPP__
