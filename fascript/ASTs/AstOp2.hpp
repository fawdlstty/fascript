#ifndef __AST_OP2_HPP__
#define __AST_OP2_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstOp2: IAstExpr {
	AstOp2 (std::shared_ptr<IAstExpr> _left, std::string _op, std::shared_ptr<IAstExpr> _right): m_left (_left), m_op (_op), m_right (_right) {}

public:
	std::shared_ptr<IAstExpr> m_left = nullptr, m_right = nullptr;
	std::string m_op = "";

	static std::shared_ptr<IAstExpr> MakeAssign (std::string _left, std::shared_ptr<IAstExpr> _right) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstOp2 { AstId::FromName (_left), "=", _right });
	}

	static std::shared_ptr<IAstExpr> MakePoint (std::shared_ptr<IAstExpr> _left, std::string _right) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstOp2 { _left, ".", AstId::FromName (_right) });
	}

	static std::shared_ptr<IAstExpr> MakeOp2 (std::shared_ptr<IAstExpr> _left, std::string _op, std::shared_ptr<IAstExpr> _right) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstOp2 { _left, _op, _right });
	}

	size_t GetBinaryCodeSize (FAScript &_s, OpType _type, size_t _start) override {
		if (_type == OpType::None) {
			if (m_op == "=") {
				_start = m_right->GetBinaryCodeSize (_s, OpType::Load, _start);
				_start = m_left->GetBinaryCodeSize (_s, OpType::Store, _start);
				return _start;
			} else {
				throw Exception::NotImplement ();
			}
		} else if (_type == OpType::Load) {
			_start = m_left->GetBinaryCodeSize (_s, OpType::Store, _start);
			_start = m_right->GetBinaryCodeSize (_s, OpType::Load, _start);
			return _start + 1;
		} else {
			throw Exception::NotImplement ();
		}
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		if (_type == OpType::None) {
			if (m_op == "=") {
				m_right->GenerateBinaryCode (_bc, _s, OpType::Load);
				m_left->GenerateBinaryCode (_bc, _s, OpType::Store);
			} else {
				throw Exception::NotImplement ();
			}
		} else if (_type == OpType::Load) {
			m_right->GenerateBinaryCode (_bc, _s, OpType::Load);
			m_left->GenerateBinaryCode (_bc, _s, OpType::Load);
			_bc.DoOp2 (m_op);
		} else {
			throw Exception::NotImplement ();
		}
	}
};
}



#endif //__AST_OP2_HPP__
