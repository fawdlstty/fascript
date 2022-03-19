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

	int32_t GetBinaryCodeSize (FAScript &_s, OpType _type, int32_t _start) override {
		SetPos (_start);
		if (_type == OpType::None) {
			return 1 + (m_expr ? m_expr->GetBinaryCodeSize (_s, OpType::Load, _start) : 1);
		} else {
			throw Exception::NotImplement ();
		}
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		if (_type == OpType::None) {
			if (m_expr) {
				m_expr->GenerateBinaryCode (_bc, _s, OpType::Load);
			} else {
				_bc.LoadNull ();
			}
			_bc.Return (1);// TODO 待补充参数数量
		} else {
			throw Exception::NotImplement ();
		}
	}
};
}



#endif //__AST_RETURN_HPP__
