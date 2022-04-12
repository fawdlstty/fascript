#ifndef __AST_INVOKE_HPP__
#define __AST_INVOKE_HPP__



#include "IAstExpr.hpp"



namespace fas {
class AstInvoke: IAstExpr {
	AstInvoke (std::shared_ptr<IAstExpr> _func_id, std::vector<std::shared_ptr<IAstExpr>> _args): m_func_id (_func_id) {
		m_args.push_back (AstId::FromName ("this"));
		m_args.insert (m_args.end (), _args.begin (), _args.end ());
	}

public:
	std::shared_ptr<IAstExpr> m_func_id = nullptr;
	std::vector<std::shared_ptr<IAstExpr>> m_args;

	static std::shared_ptr<IAstExpr> Make (std::shared_ptr<IAstExpr> _func_id, std::vector<std::shared_ptr<IAstExpr>> _args) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstInvoke { _func_id, _args });
	}

	void GenerateBinaryCode (Generator &_bc, FAScript &_s, OpType _type) override {
		if (_type == OpType::Load || _type == OpType::None) {
			int32_t _pos = _bc.GetCodePos ();
			_bc.LoadPos (0);
			for (auto &_item : m_args)
				_item->GenerateBinaryCode (_bc, _s, OpType::Load);
			m_func_id->GenerateBinaryCode (_bc, _s, OpType::Load);
			_bc.Invoke ((uint8_t) m_args.size ());
			int32_t _end_pos = _bc.GetCodePos ();
			//*(int32_t *) &_bc.GetCodes () [_pos + 1] = _end_pos;
			IntDataType4 _d { .int32 = _end_pos, };
			for (size_t i = 0; i < 4; ++i)
				_bc.GetCodes () [_pos + 1 + i] = _d.uint8 [i];
			if (_type == OpType::None)
				_bc.Ignore ();
		} else {
			throw Exception::NotImplement ();
		}
	}
};
}



#endif //__AST_INVOKE_HPP__
