#ifndef __AST_ID_HPP__
#define __AST_ID_HPP__



#include "IAstExpr.hpp"



namespace fas {
enum AstIdType { Normal = 0, Global = 1, This = 2 };



class AstId: IAstExpr {
	AstId (std::string _name, AstIdType _type): m_name (_name), m_type (_type) {}

public:
	std::string m_name;
	AstIdType m_type;

	static std::shared_ptr<IAstExpr> FromName (std::string _id) {
		AstIdType Type = AstIdType::Normal;
		if (_id.size () > 2 && _id.substr (0, 2) == "::") {
			return std::shared_ptr<IAstExpr> ((IAstExpr*) new AstId { _id.substr (2), AstIdType::Global });
		} else if (_id.size () > 5 && _id.substr (0, 5) == "this.") {
			return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstId { _id.substr (5), AstIdType::This });
		} else {
			return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstId { _id, AstIdType::Normal });
		}
	}

	bool GenerateBinaryCode (std::vector<uint8_t> &_buf, fas::FAScript &_fas) override {

	}

	bool AllowAddAddSubSub () override { return true; }
};
}



#endif //__AST_ID_HPP__
