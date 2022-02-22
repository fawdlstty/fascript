#include "../pch.h"
#include "IAstExpr.hpp"



namespace fas {
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

}
}
