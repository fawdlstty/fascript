#ifndef __AST_ACCESS_HPP__
#define __AST_ACCESS_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstAccess: IAstExpr {
	AstAccess (std::shared_ptr<IAstExpr> _value, std::shared_ptr<IAstExpr> _arg): m_value (_value), m_arg (_arg) {}

public:
	std::shared_ptr<IAstExpr> m_value = nullptr, m_arg = nullptr;

	static std::shared_ptr<IAstExpr> Make (std::shared_ptr<IAstExpr> _value, std::shared_ptr<IAstExpr> _arg) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstAccess { _value, _arg });
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, bool _load) override {
		throw Exception::NotImplement ();
	}
};
}



#endif //__AST_ACCESS_HPP__
