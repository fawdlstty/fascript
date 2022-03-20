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

	int32_t CalcBinaryCodeSize (FAScript &_s, OpType _type) override {
		if (_type == OpType::None) {
			if (m_expr) {
				m_expr->SetPos (GetPos ());
				int32_t _length = 1 + (m_expr ? m_expr->CalcBinaryCodeSize (_s, OpType::Load) : 1);
				SetLength (_length);
				return _length;
			} else {
				SetLength (3);
				return 3;
			}
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
