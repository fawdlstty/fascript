#ifndef __FASCRIPT_H__
#define __FASCRIPT_H__



#include "value.hpp"



namespace fas {
class FAScript {
public:
	bool RunCode (std::string _code);

private:
	std::mutex m_mtx;
	std::map<std::string, uint16_t> m_name_to_id;
	std::map<uint16_t, Value> m_id_to_var;
	uint16_t m_next_id;
};
}



#endif //__FASCRIPT_H__
