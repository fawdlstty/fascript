#ifndef __FASCRIPT_H__
#define __FASCRIPT_H__



#include "value.hpp"



namespace fas {
class FAScript {
public:
	bool RunCode (std::string _code);

private:
	std::map<std::string, Value> m_global_vars;
};
}



#endif //__FASCRIPT_H__
