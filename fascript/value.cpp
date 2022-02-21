#include "pch.h"
#include "value.hpp"
#include "function.hpp"



namespace fas {
static std::shared_ptr<Function> _get_func_check_arg (ValueData &m_value, size_t _arg_size) {
	if (m_value.index () != 4)
		throw Exception { "failed access." };
	auto _func = std::get<std::shared_ptr<Function>> (m_value);
	if (_func->Arguments.size () != _arg_size)
		throw Exception { std::format ("function {} need {} argument but input {} argument.", _func->Name, _func->Arguments.size (), _arg_size) };
	return _func;
}

template<AllowedCppType T1, AllowedCppType ...Args>
void _push_args (T1 _t, Args ...args) {
	m_s->m_exec_stack.push_back (_t);
	_push_args (args...);
}

template<AllowedCppType T1>
void _push_args (T1 _t) {
	m_s->m_exec_stack.push_back (_t);
}



Value::Value (std::shared_ptr<FAScript> _s): m_s (_s), m_value (std::nullopt) {}
Value::Value (std::shared_ptr<FAScript> _s, int64_t _val): m_s (_s), m_value (_val) {}
Value::Value (std::shared_ptr<FAScript> _s, double _val): m_s (_s), m_value (_val) {}
Value::Value (std::shared_ptr<FAScript> _s, std::string _val): m_s (_s), m_value (_val) {}
Value::Value (std::shared_ptr<FAScript> _s, std::vector<Value> _val): m_s (_s), m_value (_val) {}
Value::Value (std::shared_ptr<FAScript> _s, std::map<MapKey, Value> _val): m_s (_s), m_value (_val) {}
Value::Value (const Value &_o): m_s (_o.m_s), m_value (_o.m_value) {}
Value &Value::operator= (const Value &_o) { m_s = _o.m_s; m_value = _o.m_value; }

template<AllowedCppType ...Args>
Value Value::Invoke (Args ...args) {
	auto _func = _get_func_check_arg (m_value, sizeof... (args));
	_push_args (args...);
	//return _func.Call ();
}

Value Value::Invoke () {
	auto _func = _get_func_check_arg (m_value, 0);
	//return _func.Call ();
}

Value &Value::operator[] (int64_t _val) {
	if (m_value.index () == 5) {
		auto &_vec = std::get<std::vector<Value>> (m_value);
		if (_vec.size () > _val)
			return _vec [_val];
	} else if (m_value.index () == 6) {
		return std::get<std::map<MapKey, Value>> (m_value) [_val];
	} else {
		throw Exception { "failed access." };
	}
}

Value &Value::operator[] (std::string _val) {
	if (m_value.index () == 6) {
		return std::get<std::map<MapKey, Value>> (m_value) [_val];
	} else {
		throw Exception { "failed access." };
	}
}

template<typename T>
Value::operator T() {
	if constexpr (std::is_same<std::decay<T>, int64_t>::value) {
		if (m_value.index () != 1)
			throw Exception::FromConvert (CppType (m_value.index ()), CppType::type_int64);
		return (T) std::get<int64_t> (m_value);
	} else if constexpr (std::is_same<std::decay<T>, double>::value) {
		if (m_value.index () != 2)
			throw Exception::FromConvert (CppType (m_value.index ()), CppType::type_double);
		return (T) std::get<double> (m_value);
	} else if constexpr (std::is_same<std::decay<T>, std::string>::value) {
		if (m_value.index () != 3)
			throw Exception::FromConvert (CppType (m_value.index ()), CppType::type_string);
		return (T) std::get<std::string> (m_value);
	} else if constexpr (std::is_same<std::decay<T>, Function>::value) {
		if (m_value.index () != 4)
			throw Exception::FromConvert (CppType (m_value.index ()), CppType::type_function);
		return (T) std::get<Function> (m_value);
	} else if constexpr (std::is_same<std::decay<T>, std::vector<Value>>::value) {
		if (m_value.index () != 5)
			throw Exception::FromConvert (CppType (m_value.index ()), CppType::type_vector);
		return (T) std::get<std::vector<Value>> (m_value);
	} else if constexpr (std::is_same<std::decay<T>, std::map<MapKey, Value>>::value) {
		if (m_value.index () != 6)
			throw Exception::FromConvert (CppType (m_value.index ()), CppType::type_map);
		return (T) std::get<Map> (m_value);
	} else constexpr {
		throw Exception::NotSupportType ();
	}
}
}
