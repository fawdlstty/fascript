#ifndef __COMMON_HPP__
#define __COMMON_HPP__



#include <cstdint>
#include <exception>
#include <format>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <semaphore>
#include <set>
#include <string>
#include <tuple>
#include <type_traits>
#include <variant>
#include <vector>



namespace fas {
class Value;
class Function;
class FAScript;



// ast id ����
enum class AstIdType { Unknown, Global, This, Local, Argument };

// opcode ������ʽ
enum class OpType { None, Load, Store };

// opcode ��������
template<typename T>
concept OpIntType = std::is_same<T, int8_t>::value
|| std::is_same<T, uint8_t>::value
|| std::is_same<T, int16_t>::value
|| std::is_same<T, uint16_t>::value
|| std::is_same<T, int32_t>::value
|| std::is_same<T, uint32_t>::value
|| std::is_same<T, int64_t>::value
|| std::is_same<T, uint64_t>::value;

// fas �ű������������Ϊ map key ������
using MapKey = std::variant<int64_t, std::string>;

// �ɽ�������
enum class CppType { type_nullopt, type_bool, type_int64, type_double, type_string, type_function, type_vector, type_map, };
using ValueData = std::variant<std::nullopt_t, bool, int64_t, double, std::string, std::shared_ptr<Function>, std::vector<Value>, std::map<MapKey, Value>>;



// �浵����
template<typename T>
concept AllowedCppType = std::is_same<T, bool>::value
|| std::is_same<T, int64_t>::value
|| std::is_same<T, double>::value
|| std::is_same<T, std::string>::value
|| std::is_same<T, std::shared_ptr<Function>>::value
|| std::is_same<T, std::vector<Value>>::value
|| std::is_same<T, std::map<MapKey, Value>>::value;
}



#endif //__COMMON_HPP__
