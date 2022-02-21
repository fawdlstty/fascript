
// Generated from FAScript.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "FAScriptVisitor.h"


/**
 * This class provides an empty implementation of FAScriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FAScriptBaseVisitor : public FAScriptVisitor {
public:

  virtual antlrcpp::Any visitShiftLAssign(FAScriptParser::ShiftLAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftRAssign(FAScriptParser::ShiftRAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllAssign(FAScriptParser::AllAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftLOp(FAScriptParser::ShiftLOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftROp(FAScriptParser::ShiftROpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLtOp(FAScriptParser::LtOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLtEqualOp(FAScriptParser::LtEqualOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGtOp(FAScriptParser::GtOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGtEqualOp(FAScriptParser::GtEqualOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualOp(FAScriptParser::EqualOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotEqualOp(FAScriptParser::NotEqualOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprFuncDef(FAScriptParser::ExprFuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelfOp2(FAScriptParser::SelfOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompareOp2(FAScriptParser::CompareOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllOp2(FAScriptParser::AllOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(FAScriptParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotStmtPart(FAScriptParser::QuotStmtPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(FAScriptParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStmt(FAScriptParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStmt2(FAScriptParser::WhileStmt2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStmt(FAScriptParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStmt2(FAScriptParser::ForStmt2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStmtPart(FAScriptParser::SwitchStmtPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStmt(FAScriptParser::SwitchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprOpt(FAScriptParser::ExprOptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotExpr(FAScriptParser::QuotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFnExpr(FAScriptParser::FnExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrongExprBase(FAScriptParser::StrongExprBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrongExprPrefix(FAScriptParser::StrongExprPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrongExprSuffix(FAScriptParser::StrongExprSuffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrongExpr(FAScriptParser::StrongExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMiddleExpr(FAScriptParser::MiddleExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(FAScriptParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFnStmt(FAScriptParser::FnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(FAScriptParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram(FAScriptParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }


};

