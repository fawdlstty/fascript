#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__



#include "value.hpp"



namespace fas {
class Function {
public:
	int32_t m_id = 0;
	size_t m_argument_count = 0;
	size_t m_start_pos = 0;

	Function (int32_t _id, size_t _argument_count, size_t _start_pos):
		m_id (_id), m_argument_count (_argument_count), m_start_pos (_start_pos) {}
};
}



#endif //__FUNCTION_HPP__
