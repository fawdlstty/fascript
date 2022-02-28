#ifndef __AST_RETURN_HPP__
#define __AST_RETURN_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstReturn: public IAstExpr {
	AstReturn (std::shared_ptr<IAstExpr> _expr): m_expr (_expr) {}

public:
	std::shared_ptr<IAstExpr> m_expr;

	static std::shared_ptr<IAstExpr> Make (std::shared_ptr<IAstExpr> _expr = nullptr) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstReturn { _expr });
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		if (_type == OpType::None) {
			if (m_expr)
				m_expr->GenerateBinaryCode (_bc, _s, OpType::Load);
			_bc.Return (!!m_expr);
		} else {
			throw Exception::NotImplement ();
		}
	}
};
}



#endif //__AST_RETURN_HPP__
