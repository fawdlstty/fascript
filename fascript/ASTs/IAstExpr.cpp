#include "pch.h"
#include "IAstExpr.hpp"



namespace fas {
std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FAScriptParser::ExprOptContext *_ctx) {
	return _ctx->expr () ? FromCtx (_ctx->expr ()) : AstValue::FromNull ();
}



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FAScriptParser::ExprContext *_ctx) {
	std::vector<std::shared_ptr<IAstExpr>> _exprs;
	std::vector<std::string> _ops;
	for (auto _expr_ctx : _ctx->middleExpr ())
		_exprs.push_back (FromCtx (_expr_ctx));
	for (auto _op_ctx : _ctx->allAssign ())
		_ops.push_back (_op_ctx->getText ());
	while (!_ops.empty ()) {
		_exprs [_exprs.size () - 2] = AstOp2::MakeOp2 (_exprs [_exprs.size () - 2], _ops [_ops.size () - 1], _exprs [_exprs.size () - 1]);
		_exprs.erase (_exprs.begin () + _exprs.size () - 1);
		_ops.erase (_ops.begin () + _ops.size () - 1);
	}
	return _exprs [0];
}



std::vector<std::shared_ptr<IAstExpr>> IAstExpr::FromCtxs (std::vector<FAScriptParser::ExprContext *> _ctxs) {
	std::vector<std::shared_ptr<IAstExpr>> _exprs;
	for (auto _ctx : _ctxs)
		_exprs.push_back (FromCtx (_ctx));
	return _exprs;
}



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FAScriptParser::MiddleExprContext *_ctx) {
	std::vector<std::shared_ptr<IAstExpr>> _exprs;
	std::vector<std::string> _ops;
	for (auto _expr_ctx : _ctx->strongExpr ())
		_exprs.push_back (FromCtx (_expr_ctx));
	for (auto _op_ctx : _ctx->allOp2 ())
		_ops.push_back (_op_ctx->getText ());
	while (!_ops.empty ()) {
		_exprs [_exprs.size () - 2] = AstOp2::MakeOp2 (_exprs [_exprs.size () - 2], _ops [_ops.size () - 1], _exprs [_exprs.size () - 1]);
		_exprs.erase (_exprs.begin () + _exprs.size () - 1);
		_ops.erase (_ops.begin () + _ops.size () - 1);
	}
	return _exprs [0];
}



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FAScriptParser::StrongExprContext *_ctx) {
	auto _prefix_ctxs = _ctx->strongExprPrefix ();
	auto _base = FromCtx (_ctx->strongExprBase ());
	auto _suffix_ctxs = _ctx->strongExprSuffix ();
	size_t _add_sub = 0;
	while (!_suffix_ctxs.empty ()) {
		auto _suffix = _suffix_ctxs [0];
		_suffix_ctxs.erase (_suffix_ctxs.begin ());
		if (_suffix->AddAddOp () || _suffix->SubSubOp ()) {
			if (!_base->AllowAddAddSubSub ())
				throw Exception ("非值名称无法使用自增自减运算符");
			_base = AstOp1::FromExprOp1 (_base, _suffix->AddAddOp () ? AstOp1Type::suffix_addadd : AstOp1Type::suffix_subsub);
		} else if (_suffix->QuotYuanL ()) {
			_base = AstInvoke::Make (_base, FromCtxs (_suffix->expr ()));
		} else if (_suffix->QuotFangL ()) {
			if (_suffix->PointPoint ()) {
				_base = AstRangeAccess::Make (_base, FromCtx (_suffix->exprOpt (0)), FromCtx (_suffix->exprOpt (1)));
			} else {
				_base = AstAccess::Make (_base, FromCtx (_suffix->exprOpt (0)));
			}
		} else if (_suffix->Id ()) {
			_base = AstOp2::MakePoint (_base, _suffix->Id ()->getText ());
		} else {
			throw Exception::NotImplement ();
		}
	}
	while (!_prefix_ctxs.empty ()) {
		auto _prefix = _prefix_ctxs [_prefix_ctxs.size () - 1];
		_prefix_ctxs.erase (_prefix_ctxs.begin () + _prefix_ctxs.size () - 1);
		if (_prefix->AddAddOp () || _prefix->SubSubOp ()) {
			if (!_base->AllowAddAddSubSub ())
				throw Exception ("非值名称无法使用自增自减运算符");
			_base = AstOp1::FromExprOp1 (_base, _prefix->AddAddOp () ? AstOp1Type::prefix_addadd : AstOp1Type::prefix_subsub);
		} else if (_prefix->SubOp ()) {
			_base = AstOp1::FromExprOp1 (_base, AstOp1Type::prefix_sub);
		} else if (_prefix->ReverseOp ()) {
			_base = AstOp1::FromExprOp1 (_base, AstOp1Type::prefix_reverse);
		} else if (_prefix->Exclam ()) {
			_base = AstOp1::FromExprOp1 (_base, AstOp1Type::prefix_not);
		} else {
			throw Exception::NotImplement ();
		}
	}
	return _base;
}



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FAScriptParser::StrongExprBaseContext *_ctx) {
	if (_ctx->Id ()) {
		return AstId::FromName (_ctx->getText ());
	} else if (_ctx->literal ()) {
		return AstValue::FromCtx (_ctx->literal ());
	} else if (_ctx->quotExpr ()) {
		return FromCtx (_ctx->quotExpr ()->expr ());
	} else if (_ctx->fnExpr ()) {
		return AstFunction::FromCtx (_ctx->fnExpr ());
	} else {
		throw Exception::NotImplement ();
	}
}
}
