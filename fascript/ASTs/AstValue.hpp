#ifndef __IASTVALUE_HPP__
#define __IASTVALUE_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstValue: IAstExpr {
public:
	bool GenerateBinaryCode (std::vector<uint8_t> &_buf, fas::FAScript &_fas) override {

	}
};
}



#endif //__IASTVALUE_HPP__
