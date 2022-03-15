#ifndef __VALUE_H__
#define __VALUE_H__



#include "common.hpp"
#include "exception.hpp"



namespace fas {
class Value {
public:
	explicit Value (std::shared_ptr<FAScript> _s = nullptr);
	explicit Value (std::shared_ptr<FAScript> _s, bool _val);
	explicit Value (std::shared_ptr<FAScript> _s, int32_t _val);
	explicit Value (std::shared_ptr<FAScript> _s, int64_t _val);
	explicit Value (std::shared_ptr<FAScript> _s, double _val);
	explicit Value (std::shared_ptr<FAScript> _s, std::string _val);
	explicit Value (std::shared_ptr<FAScript> _s, std::shared_ptr<Function> _val);
	explicit Value (std::shared_ptr<FAScript> _s, std::vector<Value> _val);
	explicit Value (std::shared_ptr<FAScript> _s, std::map<MapKey, Value> _val);
	Value (const Value &_o);
	Value &operator= (const Value &_o);

	template<AllowedCppType ...Args>
	Value Invoke (std::vector<Value> &_stack, Args ...args);
	Value Invoke (std::vector<Value> &_stack);

	Value operator[] (int64_t _val);
	Value operator[] (std::string _val);

	template<AllowedCppType T>
	T Get () {
		if constexpr (std::is_same<std::decay<T>, bool>::value) {
			if (m_data.index () != (size_t) CppType::type_bool)
				throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_bool);
			return (T) std::get<bool> (m_data);
		} else if constexpr (std::is_same<std::decay<T>, int32_t>::value) {
			if (m_data.index () != (size_t) CppType::type_int32)
				throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_int32);
			return (T) std::get<int32_t> (m_data);
		} else if constexpr (std::is_same<std::decay<T>, int64_t>::value) {
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
		} else if constexpr (std::is_same<std::decay<T>, std::shared_ptr<Function>>::value) {
			if (m_data.index () != (size_t) CppType::type_function)
				throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_function);
			return (T) std::get<std::shared_ptr<Function>> (m_data);
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

private:
	std::shared_ptr<FAScript> m_s;
	ValueData m_data;
};
}



#endif //__VALUE_H__
