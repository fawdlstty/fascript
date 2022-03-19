#ifndef __AST_RANGE_ACCESS_HPP__
#define __AST_RANGE_ACCESS_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstRangeAccess: IAstExpr {
	AstRangeAccess (std::shared_ptr<IAstExpr> _value, std::shared_ptr<IAstExpr> _arg1, std::shared_ptr<IAstExpr> _arg2): m_value (_value), m_arg1 (_arg1), m_arg2 (_arg2) {}

public:
	std::shared_ptr<IAstExpr> m_value = nullptr, m_arg1 = nullptr, m_arg2 = nullptr;

	static std::shared_ptr<IAstExpr> Make (std::shared_ptr<IAstExpr> _value, std::shared_ptr<IAstExpr> _arg1, std::shared_ptr<IAstExpr> _arg2) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstRangeAccess { _value, _arg1, _arg2 });
	}

	int32_t GetBinaryCodeSize (FAScript &_s, OpType _type, int32_t _start) override {
		SetPos (_start);
		throw Exception::NotImplement ();
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		throw Exception::NotImplement ();
	}
};
}



#endif //__AST_INVOKE_HPP__
