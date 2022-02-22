#ifndef __ASTOP2_HPP__
#define __ASTOP2_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstOp2: IAstExpr {
public:
	std::shared_ptr<IAstExpr> m_left = nullptr, m_right = nullptr;
	std::string m_op = "";

	AstOp2 (std::shared_ptr<IAstExpr> _left, std::string _op, std::shared_ptr<IAstExpr> _right): m_left (_left), m_op (_op), m_right (_right) {}

	static std::shared_ptr<IAstExpr> MakeAssign (std::string _left, std::shared_ptr<IAstExpr> _right) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstOp2 { AstId::FromName (_left), "=", _right });
	}

	static std::shared_ptr<IAstExpr> MakeOp2 (std::shared_ptr<IAstExpr> _left, std::string _op, std::shared_ptr<IAstExpr> _right) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstOp2 { _left, _op, _right });
	}

	bool GenerateBinaryCode (std::vector<uint8_t> &_buf, fas::FAScript &_fas) override {

	}
};
}



#endif //__ASTOP2_HPP__
