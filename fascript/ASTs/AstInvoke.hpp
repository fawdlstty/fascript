#ifndef __AST_INVOKE_HPP__
#define __AST_INVOKE_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstInvoke: IAstExpr {
	AstInvoke (std::shared_ptr<IAstExpr> _func, std::vector<std::shared_ptr<IAstExpr>> _args): m_func (_func), m_args (_args) {}

public:
	std::shared_ptr<IAstExpr> m_func = nullptr;
	std::vector<std::shared_ptr<IAstExpr>> m_args;

	static std::shared_ptr<IAstExpr> Make (std::shared_ptr<IAstExpr> _func, std::vector<std::shared_ptr<IAstExpr>> _args) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstInvoke { _func, _args });
	}

	size_t GetBinaryCodeSize (FAScript &_s, OpType _type, size_t _start) override {
		if (_type == OpType::Load || _type == OpType::None) {
			size_t _size = 0;
			for (size_t i = 0; i < m_args.size (); ++i) {
				_size += m_args [i]->GetBinaryCodeSize (_s, OpType::Load, _start + _size);
			}
			return _size + (_type == OpType::None ? 7 : 6);
		} else {
			throw Exception::NotImplement ();
		}
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		if (_type == OpType::Load || _type == OpType::None) {
			for (size_t i = 0; i < m_args.size (); ++i) {
				m_args [i]->GenerateBinaryCode (_bc, _s, OpType::Load);
			}
			m_func->GenerateBinaryCode (_bc, _s, OpType::Load);
			_bc.GoTo ();
			if (_type == OpType::None)
				_bc.Ignore ();
		} else {
			throw Exception::NotImplement ();
		}
	}
};
}



#endif //__AST_INVOKE_HPP__
