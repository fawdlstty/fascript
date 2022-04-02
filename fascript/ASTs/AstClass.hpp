#ifndef __AST_CLASS_HPP__
#define __AST_CLASS_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstClass: IAstExpr {
public:
	std::vector<std::shared_ptr<IAstExpr>> m_init;

	void GenerateBinaryCode (Generator &_bc, FAScript &_s, OpType _type) override {
		throw Exception::NotImplement ();
	}
};
}



#endif //__AST_CLASS_HPP__
