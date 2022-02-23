#ifndef __AST_VALUE_HPP__
#define __AST_VALUE_HPP__



#include "IAstExpr.hpp"
#include "../common.hpp"



namespace fas {
class AstValue: IAstExpr {
	AstValue (CppType _type, std::string _data) {
		switch (_type) {
			case CppType::type_nullopt:		m_data = std::nullopt;			break;
			case CppType::type_int64:		m_data = std::stoll (_data);	break;
			case CppType::type_double:		m_data = std::stod (_data);		break;
			case CppType::type_string:		m_data = _data;					break;
			//case CppType::type_function:
			//case CppType::type_vector:
			//case CppType::type_map:
			default:
				throw Exception (std::format ("暂不支持的值初始化类型 {}", magic_enum::enum_name (_type)));
		}
	}

public:
	ValueData m_data { std::nullopt };

	static std::shared_ptr<IAstExpr> FromNull () { return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstValue { CppType::type_nullopt, "" }); }
	static std::shared_ptr<IAstExpr> FromInt64 (std::string _val) { return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstValue { CppType::type_int64, _val }); }

	bool GenerateBinaryCode (std::vector<uint8_t> &_buf, fas::FAScript &_fas) override {

	}
};
}



#endif //__AST_VALUE_HPP__
