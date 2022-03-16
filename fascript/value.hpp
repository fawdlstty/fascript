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
	static CppType GetCppType () {
		if constexpr (std::is_same<std::decay<T>, bool>::value) {
			return CppType::type_bool;
		} else if constexpr (std::is_same<std::decay<T>, int32_t>::value) {
			return CppType::type_int32;
		} else if constexpr (std::is_same<std::decay<T>, int64_t>::value) {
			return CppType::type_int64;
		} else if constexpr (std::is_same<std::decay<T>, double>::value) {
			return CppType::type_double;
		} else if constexpr (std::is_same<std::decay<T>, std::string>::value) {
			return CppType::type_string;
		} else if constexpr (std::is_same<std::decay<T>, std::shared_ptr<Function>>::value) {
			return CppType::type_function;
		} else if constexpr (std::is_same<std::decay<T>, std::vector<Value>>::value) {
			return CppType::type_vector;
		} else if constexpr (std::is_same<std::decay<T>, std::map<MapKey, Value>>::value) {
			return CppType::type_map;
		} else {
			throw Exception::NotSupportType ();
		}
	}

	template<AllowedCppType T>
	bool IsType () { return GetCppType<T> () == (CppType) m_data.index (); }

	template<AllowedCppType T>
	T Get () { throw Exception::NotSupportType (); }
	template<> bool Get<> () { return std::get<bool> (m_data); }
	template<> int32_t Get<> () { return std::get<int32_t> (m_data); }
	template<> int64_t Get<> () { return std::get<int64_t> (m_data); }
	template<> double Get<> () { return std::get<double> (m_data); }
	template<> std::string Get<> () { return std::get<std::string> (m_data); }
	template<> std::shared_ptr<Function> Get<> () { return std::get<std::shared_ptr<Function>> (m_data); }
	template<> std::vector<Value> Get<> () { return std::get<std::vector<Value>> (m_data); }
	template<> std::map<MapKey, Value> Get<> () { return std::get<std::map<MapKey, Value>> (m_data); }

	//template<AllowedCppType T>
	//T Get () {
	//	if (!IsType<T> ())
	//		throw Exception::FromConvert (CppType (m_data.index ()), CppType::type_bool);
	//	//switch ((CppType) m_data.index ()) {
	//	//	case CppType::type_bool:		return std::get<bool> (m_data);
	//	//	case CppType::type_int32:		return std::get<int32_t> (m_data);
	//	//	case CppType::type_int64:		return std::get<int64_t> (m_data);
	//	//	case CppType::type_double:		return std::get<double> (m_data);
	//	//	case CppType::type_string:		return std::get<std::string> (m_data);
	//	//	case CppType::type_function:	return std::get<std::shared_ptr<Function>> (m_data);
	//	//	case CppType::type_vector:		return std::get<std::vector<Value>> (m_data);
	//	//	case CppType::type_map:			return std::get<std::map<MapKey, Value>> (m_data);
	//	//	default:						throw Exception::NotSupportType ();
	//	//}
	//	constexpr CppType _type = GetCppType<T> ();
	//	if constexpr (_type == CppType::type_bool)			{ return std::get<bool> (m_data); }
	//	else if constexpr (_type == CppType::type_int32)	{ return std::get<int32_t> (m_data); }
	//	else if constexpr (_type == CppType::type_int64)	{ return std::get<int64_t> (m_data); }
	//	else if constexpr (_type == CppType::type_double)	{ return std::get<double> (m_data); }
	//	else if constexpr (_type == CppType::type_string)	{ return std::get<std::string> (m_data); }
	//	else if constexpr (_type == CppType::type_function)	{ return std::get<std::shared_ptr<Function>> (m_data); }
	//	else if constexpr (_type == CppType::type_vector)	{ return std::get<std::vector<Value>> (m_data); }
	//	else if constexpr (_type == CppType::type_map)		{ return std::get<std::map<MapKey, Value>> (m_data); }
	//	else												{ throw Exception::NotSupportType (); }
	//}

private:
	std::shared_ptr<FAScript> m_s;
	ValueData m_data;
};
}



#endif //__VALUE_H__
