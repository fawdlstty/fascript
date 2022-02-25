#include "pch.h"
#include "value.hpp"
#include "function.hpp"



namespace fas {
static std::shared_ptr<Function> _get_func_check_arg (ValueData &m_data, size_t _arg_size) {
	if (m_data.index () != (size_t) CppType::type_function)
		throw Exception { "failed access." };
	auto _func = std::get<std::shared_ptr<Function>> (m_data);
	if (_func->ArgumentCount != _arg_size)
		throw Exception { std::format ("function {} need {} argument but input {} argument.", _func->Name, _func->ArgumentCount, _arg_size) };
	return _func;
}

template<AllowedCppType T1, AllowedCppType ...Args>
static void _push_args (std::vector<Value> &_stack, T1 _t, Args ...args) {
	_stack.push_back (_t);
	_push_args (args...);
}

template<AllowedCppType T1>
static void _push_args (std::vector<Value> &_stack, T1 _t) {
	_stack.push_back (_t);
}



Value::Value (std::shared_ptr<FAScript> _s): m_s (_s), m_data (std::nullopt) {}
Value::Value (std::shared_ptr<FAScript> _s, int64_t _val): m_s (_s), m_data (_val) {}
Value::Value (std::shared_ptr<FAScript> _s, double _val): m_s (_s), m_data (_val) {}
Value::Value (std::shared_ptr<FAScript> _s, std::string _val): m_s (_s), m_data (_val) {}
Value::Value (std::shared_ptr<FAScript> _s, std::vector<Value> _val): m_s (_s), m_data (_val) {}
Value::Value (std::shared_ptr<FAScript> _s, std::map<MapKey, Value> _val): m_s (_s), m_data (_val) {}
Value::Value (const Value &_o): m_s (_o.m_s), m_data (_o.m_data) {}
Value &Value::operator= (const Value &_o) { m_s = _o.m_s; m_data = _o.m_data; return *this; }

template<AllowedCppType ...Args>
Value Value::Invoke (std::vector<Value> &_stack, Args ...args) {
	auto _func = _get_func_check_arg (m_data, sizeof... (args));
	_push_args (args...);
	// TODO
	//return _func->Call (_stack);
	throw Exception::NotImplement ();
}

Value Value::Invoke (std::vector<Value> &_stack) {
	auto _func = _get_func_check_arg (m_data, 0);
	// TODO
	//return _func->Call (_stack);
	throw Exception::NotImplement ();
}

Value Value::operator[] (int64_t _val) {
	if (m_data.index () == (size_t) CppType::type_vector) {
		auto &_vec = std::get<std::vector<Value>> (m_data);
		if (_val < 0)
			_val += (int64_t) _vec.size ();
		if (_val >= 0 && _vec.size () > (size_t) _val)
			return _vec [(size_t) _val];
		throw Exception::NotImplement ();
	} else if (m_data.index () == (size_t) CppType::type_map) {
		auto &_map = std::get<std::map<MapKey, Value>> (m_data);
		auto _pval = _map.find (_val);
		if (_pval != _map.end ())
			return Value { _pval->second };
	}
	throw Exception { "failed access." };
}

Value Value::operator[] (std::string _val) {
	if (m_data.index () == (size_t) CppType::type_map) {
		auto &_map = std::get<std::map<MapKey, Value>> (m_data);
		auto _pval = _map.find (_val);
		if (_pval != _map.end ())
			return Value { _pval->second };
	}
	throw Exception { "failed access." };
}

template<typename T>
Value::operator T() {
	if constexpr (std::is_same<std::decay<T>, bool>::value) {
		if (m_data.index () != (size_t) CppType::type_bool)
			throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_bool);
		return (T) std::get<bool> (m_data);
	} else if constexpr (std::is_same<std::decay<T>, double>::value) {
		if (m_data.index () != (size_t) CppType::type_int64)
			throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_int64);
		return (T) std::get<int64_t> (m_data);
	} else if constexpr (std::is_same<std::decay<T>, double>::value) {
		if (m_data.index () != (size_t) CppType::type_double)
			throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_double);
		return (T) std::get<double> (m_data);
	} else if constexpr (std::is_same<std::decay<T>, std::string>::value) {
		if (m_data.index () != (size_t) CppType::type_string)
			throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_string);
		return (T) std::get<std::string> (m_data);
	} else if constexpr (std::is_same<std::decay<T>, Function>::value) {
		if (m_data.index () != (size_t) CppType::type_function)
			throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_function);
		return (T) std::get<Function> (m_data);
	} else if constexpr (std::is_same<std::decay<T>, std::vector<Value>>::value) {
		if (m_data.index () != (size_t) CppType::type_vector)
			throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_vector);
		return (T) std::get<std::vector<Value>> (m_data);
	} else if constexpr (std::is_same<std::decay<T>, std::map<MapKey, Value>>::value) {
		if (m_data.index () != (size_t) CppType::type_map)
			throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_map);
		return (T) std::get<std::map<MapKey, Value>> (m_data);
	} else {
		throw Exception::NotSupportType ();
	}
}
}
