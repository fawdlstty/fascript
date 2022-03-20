#ifndef __I_AST_EXPR_HPP__
#define __I_AST_EXPR_HPP__



#include "../fascript.h"
#include "../_AntlrGens/FAScriptParser.h"
#include "../BinCode.hpp"



namespace fas {
class IAstExpr: public std::enable_shared_from_this<IAstExpr> {
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

	virtual int32_t CalcBinaryCodeSize (FAScript &_s, OpType _type) = 0;
	void SetPos (int32_t _start) { m_pos = _start; }
	int32_t GetPos () { return m_pos; }
	void SetLength (int32_t _length) {
		if (m_length != -1)
			throw Exception::NotImplement ();
		m_length = _length;
	}
	int32_t GetLength () { return m_length; }

	virtual void GenerateBinaryCode (BinCode &_bc, FAScript &_s, OpType _type) = 0;

	virtual bool AllowAddAddSubSub () { return false; }

private:
	int32_t m_pos = -1;
	int32_t m_length = -1;
};
}



#include "AstAccess.hpp"
#include "AstClass.hpp"
#include "AstFunction.hpp"
#include "AstId.hpp"
#include "AstInvoke.hpp"
#include "AstOp1.hpp"
#include "AstOp2.hpp"
#include "AstRangeAccess.hpp"
#include "AstReturn.hpp"
#include "AstValue.hpp"



#endif //__I_AST_EXPR_HPP__
