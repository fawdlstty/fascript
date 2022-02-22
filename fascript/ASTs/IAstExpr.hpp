#ifndef __IASTEXPR_HPP__
#define __IASTEXPR_HPP__



#include "../fascript.hpp"
#include "../_AntlrGens/FAScriptParser.h"



namespace fas {
class IAstExpr {
public:
	antlr4::Token *m_token = nullptr;

	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::ExprContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::MiddleExprContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FAScriptParser::StrongExprContext *_ctx);

	virtual bool GenerateBinaryCode (std::vector<uint8_t> &_buf, fas::FAScript &_fas) = 0;
};
}



#include "AstId.hpp"
#include "AstOp2.hpp"
#include "AstValue.hpp"
#include "AstFunction.hpp"



#endif //__IASTEXPR_HPP__
