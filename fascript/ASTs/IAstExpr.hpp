#ifndef __I_AST_EXPR_HPP__
#define __I_AST_EXPR_HPP__



#include "../fascript.hpp"
#include "../_AntlrGens/FAScriptParser.h"



namespace fas {
class IAstExpr {
public:
	antlr4::Token *m_token = nullptr;

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::ExprOptContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::ExprContext *_ctx);
	static std::vector<std::shared_ptr<IAstExpr>> FromCtxs (std::vector<FAScriptParser::ExprContext *> _ctxs);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::MiddleExprContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::StrongExprContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::StrongExprBaseContext *_ctx);

	virtual void GenerateBinaryCode (std::vector<uint8_t> &_bincodes, fas::FAScript &_fas) = 0;

	virtual bool AllowAddAddSubSub () { return false; }
};
}



#include "AstFunction.hpp"
#include "AstId.hpp"
#include "AstInvoke.hpp"
#include "AstOp1.hpp"
#include "AstOp2.hpp"
#include "AstAccess.hpp"
#include "AstRangeAccess.hpp"
#include "AstValue.hpp"



#endif //__I_AST_EXPR_HPP__
