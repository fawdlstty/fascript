#ifndef __FASCRIPT_H__
#define __FASCRIPT_H__



#include <cstdint>
#include <exception>
#include <format>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <variant>
#include <vector>

#include <magic_enum.hpp>



namespace fas {
class Value;
class Function;
class FAScript;

using MapKey = std::variant<int64_t, std::string>;
enum class CppType { type_nullopt, type_int64, type_double, type_string, type_function, type_vector, type_map, };

template<typename T>
concept AllowedCppType = std::is_same<T, int64_t>::value
	|| std::is_same<T, double>::value
	|| std::is_same<T, std::string>::value
	|| std::is_same<T,Function>::value
	|| std::is_same<T, std::vector<Value>>::value
	|| std::is_same<T, std::map<MapKey, Value>>::value;



// fas Òì³£
class Exception: public std::exception {
public:
	static Exception FromConvert (CppType _src, CppType _dest) {
		return Exception { std::format ("cannot convert {} to {}.", magic_enum::enum_name (_src), magic_enum::enum_name (_dest)) };
	}
	static Exception NotSupportType () { return Exception { "not support type." }; }
	static Exception FailedAccess () { return Exception { "failed access." }; }

	Exception (std::string _msg): m_msg (_msg) {}
	char const *what () const override { return m_msg.data (); }

private:
	std::string m_msg;
};



// fas º¯Êý
class Function {
public:
	std::string Name;
	size_t ArgumentCount;

	Value Call () {}
};



// fas Öµ
class Value {
public:
	Value (std::shared_ptr<FAScript> _s): m_s (_s), m_value (std::nullopt) {}
	explicit Value (std::shared_ptr<FAScript> _s, int64_t _val): m_s (_s), m_value (_val) {}
	explicit Value (std::shared_ptr<FAScript> _s, double _val): m_s (_s), m_value (_val) {}
	explicit Value (std::shared_ptr<FAScript> _s, std::string _val): m_s (_s), m_value (_val) {}
	explicit Value (std::shared_ptr<FAScript> _s, std::vector<Value> _val): m_s (_s), m_value (_val) {}
	explicit Value (std::shared_ptr<FAScript> _s, std::map<MapKey, Value> _val): m_s (_s), m_value (_val) {}
	Value (const Value &_o): m_value (_o.m_value) {}
	Value &operator= (const Value &_o) { m_value = _o.m_value; }

	template<AllowedCppType T1, AllowedCppType ...Args>
	Value Invoke (T1 _t, Args ...args) {
		Function &_func = _get_func_check_arg (sizeof... (args) + 1);
		_push_args (_t, args...);
		return _func.Call ();
	}

	template<AllowedCppType T1>
	Value Invoke (T1 _t) {
		Function &_func = _get_func_check_arg (1);
		_push_args (_t);
		return _func.Call ();
	}

	Value Invoke () {
		Function &_func = _get_func_check_arg (0);
		return _func.Call ();
	}

	Value &operator[] (int64_t _val) {
		if (m_value.index () == 5) {
			auto &_vec = std::get<std::vector<Value>> (m_value);
			if (_vec.size () > _val)
				return _vec [_val];
		} else if (m_value.index () == 6) {
			return std::get<std::map<MapKey, Value>> (m_value)[_val];
		} else {
			throw Exception { "failed access." };
		}
	}

	Value &operator[] (std::string _val) {
		if (m_value.index () == 6) {
			return std::get<std::map<MapKey, Value>> (m_value)[_val];
		} else {
			throw Exception { "failed access." };
		}
	}

	template<typename T>
	T operator() () {
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

private:
	std::shared_ptr<FAScript> m_s;
	std::variant<
		std::nullopt_t, int64_t, double,
		std::string, Function,
		std::vector<Value>, std::map<MapKey, Value>
	> m_value;

	Function &_get_func_check_arg (size_t _arg_size) {
		if (m_value.index () != 4)
			throw Exception { "failed access." };
		Function &_func = std::get<Function> (m_value);
		if (_func.ArgumentCount != _arg_size)
			throw Exception { std::format ("function {} need {} argument but input {} argument.", _func.Name, _func.ArgumentCount, _arg_size) };
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
};



class FAScript {
public:
	void RunCode () {}

private:
	std::vector<std::shared_ptr<Value>> m_exec_stack;
};
}



#endif //__FASCRIPT_H__
