#ifndef __AST_INVOKE_HPP__
#define __AST_INVOKE_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstInvoke: IAstExpr {
	AstInvoke (std::shared_ptr<IAstExpr> _func, std::vector<std::shared_ptr<IAstExpr>> _args): m_func (_func), m_args (_args) {}

public:
	std::shared_ptr<IAstExpr> m_func = nullptr;
	std::vector<std::shared_ptr<IAstExpr>> m_args;

	static std::shared_ptr<IAstExpr> Make (std::shared_ptr<IAstExpr> _func, std::vector<std::shared_ptr<IAstExpr>> _args) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstInvoke { _func, _args });
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		throw Exception::NotImplement ();
	}
};
}



#endif //__AST_INVOKE_HPP__
