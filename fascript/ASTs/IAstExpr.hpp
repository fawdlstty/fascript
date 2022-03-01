#ifndef __I_AST_EXPR_HPP__
#define __I_AST_EXPR_HPP__



#include "../fascript.hpp"
#include "../_AntlrGens/FAScriptParser.h"
#include "../BinCode.hpp"



namespace fas {
class IAstExpr {
public:
	antlr4::Token *m_token = nullptr;

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::StmtContext *_ctx);
	static std::vector<std::shared_ptr<IAstExpr>> FromCtxs (std::vector<FAScriptParser::StmtContext *> _ctxs);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::ExprOptContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::ExprContext *_ctx);
	static std::vector<std::shared_ptr<IAstExpr>> FromCtxs (std::vector<FAScriptParser::ExprContext *> _ctxs);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::MiddleExprContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::StrongExprContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::StrongExprBaseContext *_ctx);

	virtual size_t GetBinaryCodeSize (FAScript &_s, OpType _type, size_t _start) = 0;
	virtual void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) = 0;

	virtual bool AllowAddAddSubSub () { return false; }
};
}



#include "AstAccess.hpp"
#include "AstFunction.hpp"
#include "AstId.hpp"
#include "AstInvoke.hpp"
#include "AstOp1.hpp"
#include "AstOp2.hpp"
#include "AstRangeAccess.hpp"
#include "AstReturn.hpp"
#include "AstValue.hpp"



#endif //__I_AST_EXPR_HPP__
