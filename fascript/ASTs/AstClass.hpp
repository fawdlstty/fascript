#ifndef __AST_CLASS_HPP__
#define __AST_CLASS_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstClass: IAstExpr {
public:
	std::vector<std::shared_ptr<IAstExpr>> m_init;

	int32_t CalcBinaryCodeSize (FAScript &_s, OpType _type) override {
		throw Exception::NotImplement ();
		IAstExpr::SetLength (0);
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		throw Exception::NotImplement ();
	}
};
}



#endif //__AST_CLASS_HPP__
