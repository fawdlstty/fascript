#ifndef __AST_INVOKE_HPP__
#define __AST_INVOKE_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstInvoke: IAstExpr {
	AstInvoke (std::shared_ptr<IAstExpr> _func, std::vector<std::shared_ptr<IAstExpr>> _args): m_func (_func) {
		m_args.push_back (AstId::FromName ("this"));
		m_args.insert (m_args.end (), _args.begin (), _args.end ());
	}

public:
	std::shared_ptr<IAstExpr> m_func = nullptr;
	std::vector<std::shared_ptr<IAstExpr>> m_args;
	int32_t m_pos_end = 0;

	static std::shared_ptr<IAstExpr> Make (std::shared_ptr<IAstExpr> _func, std::vector<std::shared_ptr<IAstExpr>> _args) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstInvoke { _func, _args });
	}

	int32_t GetBinaryCodeSize (FAScript &_s, OpType _type, int32_t _start) override {
		SetPos (_start);
		if (_type == OpType::Load || _type == OpType::None) {
			size_t _size = 0;
			// TODO 检查参数数量，不足则抛异常
			for (size_t i = 0; i < m_args.size (); ++i) {
				_size += m_args [i]->GetBinaryCodeSize (_s, OpType::Load, _start + _size);
			}
			m_pos_end = (int32_t) (_size + (_type == OpType::None ? 12 : 11));
			return (size_t) m_pos_end;
		} else {
			throw Exception::NotImplement ();
		}
	}

	void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) override {
		// TODO push current+N
		_bc.LoadPos (m_pos_end); // current+这整段代码长度
		if (_type == OpType::Load || _type == OpType::None) {
			for (size_t i = 0; i < m_args.size (); ++i) {
				m_args [i]->GenerateBinaryCode (_bc, _s, OpType::Load);
			}
			_bc.LoadPos (m_func->GetPos ());
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
