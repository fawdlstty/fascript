#ifndef __AST_FUNCTION_HPP__
#define __AST_FUNCTION_HPP__



#include "IAstExpr.hpp"
#include "AstReturn.hpp"
#include "AstValue.hpp"



namespace fas {
template<typename T>
concept FnContext = std::is_same<T, FAScriptParser::FnExprContext>::value || std::is_same<T, FAScriptParser::FnStmtContext>::value;



class AstFunction: IAstExpr {
	template<FnContext T>
	AstFunction (T *_ctx) {
		std::vector<antlr4::tree::TerminalNode *> _ids = _ctx->Id ();
		constexpr size_t _start = std::is_same<T, FAScriptParser::FnExprContext>::value ? 0 : 1;
		for (size_t i = _start; i < _ids.size (); ++i)
			Arguments.push_back (_ids [i]->getText ());
		Codes = IAstExpr::FromCtxs (_ctx->stmt ());
		Codes.push_back (AstReturn::Make (AstValue::FromNull ()));
	}

public:
	bool m_registered = false;
	int32_t m_func_id = 0;
	std::vector<std::string> Arguments { "this" };
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
			for (size_t i = 0; i < Codes.size (); ++i) {
				if (!Codes [i]) {
					Codes.erase (Codes.begin () + i);
					--i;
				}
			}

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
			if (m_func_id == 0)
				m_func_id = _s.NewGlobalFuncId (std::make_shared<Function> (0, Arguments.size (), CodeStart));
			_bc.LoadFunction (m_func_id);
		} else {
			throw Exception::NotImplement ();
		}
	}
};
}



#endif //__AST_FUNCTION_HPP__
