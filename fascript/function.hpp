#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__



#include "value.hpp"



namespace fas {
class Function {
public:
	int32_t m_id = 0;
	size_t m_argument_count = 0;
	size_t m_start_pos = 0;

	Function (size_t _argument_count): m_argument_count (_argument_count) {}
};
}



#endif //__FUNCTION_HPP__
