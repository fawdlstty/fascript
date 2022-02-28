#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__



#include "value.hpp"



namespace fas {
class Function {
public:
	uint16_t Id = 0;
	size_t ArgumentCount = 0;
	std::vector<uint8_t> Codes;
};
}



#endif //__FUNCTION_HPP__
