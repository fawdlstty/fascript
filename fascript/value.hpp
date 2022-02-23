#ifndef __VALUE_H__
#define __VALUE_H__



#include "common.hpp"
#include "exception.hpp"



namespace fas {
class Value {
public:
	Value (std::shared_ptr<FAScript> _s);
	explicit Value (std::shared_ptr<FAScript> _s, int64_t _val);
	explicit Value (std::shared_ptr<FAScript> _s, double _val);
	explicit Value (std::shared_ptr<FAScript> _s, std::string _val);
	explicit Value (std::shared_ptr<FAScript> _s, std::vector<Value> _val);
	explicit Value (std::shared_ptr<FAScript> _s, std::map<MapKey, Value> _val);
	Value (const Value &_o);
	Value &operator= (const Value &_o);

	template<AllowedCppType ...Args>
	Value Invoke (std::vector<Value> &_stack, Args ...args);
	Value Invoke (std::vector<Value> &_stack);

	Value &operator[] (int64_t _val);
	Value &operator[] (std::string _val);

	template<typename T>
	operator T();

private:
	std::shared_ptr<FAScript> m_s;
	ValueData m_data;
};
}



#endif //__VALUE_H__
