#ifndef __AST_ID_HPP__
#define __AST_ID_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstId: IAstExpr {
	AstId (std::string _name, AstIdType _type): m_name (_name), m_type (_type) {}

public:
	std::string m_name;
	AstIdType m_type;
	int32_t m_var_id = -1;

	static std::shared_ptr<IAstExpr> FromName (std::string _id) {
		//AstIdType Type = AstIdType::Normal;
		if (_id.size () > 2 && _id.substr (0, 2) == "::") {
			return std::shared_ptr<IAstExpr> ((IAstExpr*) new AstId { _id.substr (2), AstIdType::Global });
		} else {
			return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstId { _id, AstIdType::Unknown });
		}
	}

	void GenerateBinaryCode (Generator &_bc, FAScript &_s, OpType _type) override {
		if (m_type == AstIdType::Unknown)
			m_type = _s.CheckIdType (m_name);
		if (m_var_id == -1)
			m_var_id = _s.GetNameId (m_type, m_name);

		if (_type == OpType::Load) {
			_bc.LoadVariable (m_type, m_var_id);
		} else if (_type == OpType::Store) {
			_bc.StoreVariable (m_type, m_var_id);
		} else {
			throw Exception::NotImplement ();
		}
	}

	bool AllowAddAddSubSub () override { return true; }
};
}



#endif //__AST_ID_HPP__
