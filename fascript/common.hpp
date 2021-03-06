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



// ast id 类型
enum class AstIdType { Unknown, Global, Local, Argument, Member };

// opcode 操作方式
enum class OpType { None, Load, Store };

// opcode 整数类型
template<typename T>
concept OpIntType = std::is_same<T, int8_t>::value
|| std::is_same<T, uint8_t>::value
|| std::is_same<T, int16_t>::value
|| std::is_same<T, uint16_t>::value
|| std::is_same<T, int32_t>::value
|| std::is_same<T, uint32_t>::value
|| std::is_same<T, int64_t>::value
|| std::is_same<T, uint64_t>::value;

// fas 脚本语言允许的作为 map key 的类型
using MapKey = std::variant<int64_t, std::string>;

// int64类型或double类型
template<typename T>
concept Int64OrFloat64 = std::is_same<T, int64_t>::value || std::is_same<T, double>::value;

// 可交互类型
enum class CppType { type_nullopt, type_bool, type_int32, type_int64, type_double, type_string, type_function, type_vector, type_map, };
using ValueData = std::variant<std::nullopt_t, bool, int32_t, int64_t, double, std::string, std::shared_ptr<Function>, std::vector<Value>, std::map<MapKey, Value>>;



// 整数类型
union IntDataType2 { uint8_t uint8 [2]; int16_t int16; uint16_t uint16; };
union IntDataType4 { uint8_t uint8 [4]; int32_t int32; uint32_t uint32; };
union IntDataType8 { uint8_t uint8 [8]; int64_t int64; uint64_t uint64; double float64; };



// 存档类型
template<typename T>
concept AllowedCppType = std::is_same<T, bool>::value
|| std::is_same<T, int32_t>::value
|| std::is_same<T, int64_t>::value
|| std::is_same<T, double>::value
|| std::is_same<T, std::string>::value
|| std::is_same<T, std::shared_ptr<Function>>::value
|| std::is_same<T, std::vector<Value>>::value
|| std::is_same<T, std::map<MapKey, Value>>::value;
}



#endif //__COMMON_HPP__
