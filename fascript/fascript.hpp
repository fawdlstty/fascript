#ifndef __FASCRIPT_H__
#define __FASCRIPT_H__



#include "value.hpp"
#include "function.hpp"



namespace fas {
class FAScript: std::enable_shared_from_this<FAScript> {
public:
	Value RunCode (std::string _code);
	uint16_t GetGlobalNameId (std::string _name);
	uint16_t GetGlobalFuncId (std::shared_ptr<Function> _func);

private:
	std::mutex m_mtx;
	std::map<std::string, uint16_t> m_name_to_id;
	std::map<uint16_t, Value> m_id_to_var;
	uint16_t m_next_id = 0;

	std::map<uint16_t, std::shared_ptr<Function>> m_id_to_func;
	uint16_t m_next_func_id = 0;
};
}



#endif //__FASCRIPT_H__
