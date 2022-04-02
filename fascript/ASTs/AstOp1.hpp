#ifndef __AST_OP1_HPP__
#define __AST_OP1_HPP__



#include "IAstExpr.hpp"



namespace fas {
enum class AstOp1Type { prefix_sub, prefix_addadd, prefix_subsub, prefix_reverse, prefix_not, suffix_addadd, suffix_subsub };



class AstOp1: IAstExpr {
	AstOp1 (std::shared_ptr<IAstExpr> _value, AstOp1Type _type): m_value (_value), m_type (_type) {}

public:
	std::shared_ptr<IAstExpr> m_value;
	AstOp1Type m_type;

	static std::shared_ptr<IAstExpr> FromExprOp1 (std::shared_ptr<IAstExpr> _value, AstOp1Type _type) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstOp1 { _value, _type });
	}

	void GenerateBinaryCode (Generator &_bc, FAScript &_s, OpType _type) override {
		throw Exception::NotImplement ();
	}

	bool AllowAddAddSubSub () override { return s_allow_aass.contains (m_type) && m_value->AllowAddAddSubSub (); }

private:
	inline static std::set<AstOp1Type> s_allow_aass { AstOp1Type::prefix_addadd, AstOp1Type::prefix_subsub, AstOp1Type::suffix_addadd, AstOp1Type::suffix_subsub };
};
}



#endif //__AST_OP1_HPP__
