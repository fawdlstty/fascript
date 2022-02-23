
// Generated from FAScript.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "FAScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by FAScriptParser.
 */
class  FAScriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FAScriptParser.
   */
    virtual antlrcpp::Any visitShiftLAssign(FAScriptParser::ShiftLAssignContext *context) = 0;

    virtual antlrcpp::Any visitShiftRAssign(FAScriptParser::ShiftRAssignContext *context) = 0;

    virtual antlrcpp::Any visitAllAssign(FAScriptParser::AllAssignContext *context) = 0;

    virtual antlrcpp::Any visitShiftLOp(FAScriptParser::ShiftLOpContext *context) = 0;

    virtual antlrcpp::Any visitShiftROp(FAScriptParser::ShiftROpContext *context) = 0;

    virtual antlrcpp::Any visitLtOp(FAScriptParser::LtOpContext *context) = 0;

    virtual antlrcpp::Any visitLtEqualOp(FAScriptParser::LtEqualOpContext *context) = 0;

    virtual antlrcpp::Any visitGtOp(FAScriptParser::GtOpContext *context) = 0;

    virtual antlrcpp::Any visitGtEqualOp(FAScriptParser::GtEqualOpContext *context) = 0;

    virtual antlrcpp::Any visitEqualOp(FAScriptParser::EqualOpContext *context) = 0;

    virtual antlrcpp::Any visitNotEqualOp(FAScriptParser::NotEqualOpContext *context) = 0;

    virtual antlrcpp::Any visitExprFuncDef(FAScriptParser::ExprFuncDefContext *context) = 0;

    virtual antlrcpp::Any visitSelfOp2(FAScriptParser::SelfOp2Context *context) = 0;

    virtual antlrcpp::Any visitCompareOp2(FAScriptParser::CompareOp2Context *context) = 0;

    virtual antlrcpp::Any visitAllOp2(FAScriptParser::AllOp2Context *context) = 0;

    virtual antlrcpp::Any visitLiteral(FAScriptParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitQuotStmtPart(FAScriptParser::QuotStmtPartContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(FAScriptParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(FAScriptParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt2(FAScriptParser::WhileStmt2Context *context) = 0;

    virtual antlrcpp::Any visitForStmt(FAScriptParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitForStmt2(FAScriptParser::ForStmt2Context *context) = 0;

    virtual antlrcpp::Any visitSwitchStmtPart(FAScriptParser::SwitchStmtPartContext *context) = 0;

    virtual antlrcpp::Any visitSwitchStmt(FAScriptParser::SwitchStmtContext *context) = 0;

    virtual antlrcpp::Any visitExprOpt(FAScriptParser::ExprOptContext *context) = 0;

    virtual antlrcpp::Any visitQuotExpr(FAScriptParser::QuotExprContext *context) = 0;

    virtual antlrcpp::Any visitFnExpr(FAScriptParser::FnExprContext *context) = 0;

    virtual antlrcpp::Any visitClassExprItem(FAScriptParser::ClassExprItemContext *context) = 0;

    virtual antlrcpp::Any visitClassExpr(FAScriptParser::ClassExprContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprBase(FAScriptParser::StrongExprBaseContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprPrefix(FAScriptParser::StrongExprPrefixContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprSuffix(FAScriptParser::StrongExprSuffixContext *context) = 0;

    virtual antlrcpp::Any visitStrongExpr(FAScriptParser::StrongExprContext *context) = 0;

    virtual antlrcpp::Any visitMiddleExpr(FAScriptParser::MiddleExprContext *context) = 0;

    virtual antlrcpp::Any visitExpr(FAScriptParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitFnStmt(FAScriptParser::FnStmtContext *context) = 0;

    virtual antlrcpp::Any visitStmt(FAScriptParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitProgram(FAScriptParser::ProgramContext *context) = 0;


};

