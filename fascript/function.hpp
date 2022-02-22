#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__



#include "value.hpp"



namespace fas {
class Function {
public:
	std::string Name;
	size_t Id;
	size_t ArgumentCount;
	std::vector<uint8_t> Codes;

	Value Call (std::vector<Value> &_stack);
};
}



#endif //__FUNCTION_HPP__
