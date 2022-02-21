#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__



#include <exception>
#include <string>

#include <magic_enum.hpp>

#include "common.hpp"



namespace fas {
// fas “Ï≥£
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
}



#endif //__EXCEPTION_HPP__
