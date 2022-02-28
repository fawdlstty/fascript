
// Generated from FAScript.g4 by ANTLR 4.9.3


#include "FAScriptVisitor.h"

#include "FAScriptParser.h"


using namespace antlrcpp;
using namespace antlr4;

FAScriptParser::FAScriptParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

FAScriptParser::~FAScriptParser() {
  delete _interpreter;
}

std::string FAScriptParser::getGrammarFileName() const {
  return "FAScript.g4";
}

const std::vector<std::string>& FAScriptParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& FAScriptParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ShiftLAssignContext ------------------------------------------------------------------

FAScriptParser::ShiftLAssignContext::ShiftLAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FAScriptParser::ShiftLOpContext* FAScriptParser::ShiftLAssignContext::shiftLOp() {
  return getRuleContext<FAScriptParser::ShiftLOpContext>(0);
}

tree::TerminalNode* FAScriptParser::ShiftLAssignContext::Assign() {
  return getToken(FAScriptParser::Assign, 0);
}


size_t FAScriptParser::ShiftLAssignContext::getRuleIndex() const {
  return FAScriptParser::RuleShiftLAssign;
}


antlrcpp::Any FAScriptParser::ShiftLAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitShiftLAssign(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ShiftLAssignContext* FAScriptParser::shiftLAssign() {
  ShiftLAssignContext *_localctx = _tracker.createInstance<ShiftLAssignContext>(_ctx, getState());
  enterRule(_localctx, 0, FAScriptParser::RuleShiftLAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    shiftLOp();
    setState(77);
    match(FAScriptParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShiftRAssignContext ------------------------------------------------------------------

FAScriptParser::ShiftRAssignContext::ShiftRAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FAScriptParser::ShiftROpContext* FAScriptParser::ShiftRAssignContext::shiftROp() {
  return getRuleContext<FAScriptParser::ShiftROpContext>(0);
}

tree::TerminalNode* FAScriptParser::ShiftRAssignContext::Assign() {
  return getToken(FAScriptParser::Assign, 0);
}


size_t FAScriptParser::ShiftRAssignContext::getRuleIndex() const {
  return FAScriptParser::RuleShiftRAssign;
}


antlrcpp::Any FAScriptParser::ShiftRAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitShiftRAssign(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ShiftRAssignContext* FAScriptParser::shiftRAssign() {
  ShiftRAssignContext *_localctx = _tracker.createInstance<ShiftRAssignContext>(_ctx, getState());
  enterRule(_localctx, 2, FAScriptParser::RuleShiftRAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    shiftROp();
    setState(80);
    match(FAScriptParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AllAssignContext ------------------------------------------------------------------

FAScriptParser::AllAssignContext::AllAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::AllAssignContext::Assign() {
  return getToken(FAScriptParser::Assign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::AddAssign() {
  return getToken(FAScriptParser::AddAssign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::SubAssign() {
  return getToken(FAScriptParser::SubAssign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::StarAssign() {
  return getToken(FAScriptParser::StarAssign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::StarStarAssign() {
  return getToken(FAScriptParser::StarStarAssign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::DivAssign() {
  return getToken(FAScriptParser::DivAssign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::ModAssign() {
  return getToken(FAScriptParser::ModAssign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::AndAssign() {
  return getToken(FAScriptParser::AndAssign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::OrAssign() {
  return getToken(FAScriptParser::OrAssign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::XorAssign() {
  return getToken(FAScriptParser::XorAssign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::AndAndAssign() {
  return getToken(FAScriptParser::AndAndAssign, 0);
}

tree::TerminalNode* FAScriptParser::AllAssignContext::OrOrAssign() {
  return getToken(FAScriptParser::OrOrAssign, 0);
}

FAScriptParser::ShiftLAssignContext* FAScriptParser::AllAssignContext::shiftLAssign() {
  return getRuleContext<FAScriptParser::ShiftLAssignContext>(0);
}

FAScriptParser::ShiftRAssignContext* FAScriptParser::AllAssignContext::shiftRAssign() {
  return getRuleContext<FAScriptParser::ShiftRAssignContext>(0);
}


size_t FAScriptParser::AllAssignContext::getRuleIndex() const {
  return FAScriptParser::RuleAllAssign;
}


antlrcpp::Any FAScriptParser::AllAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitAllAssign(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::AllAssignContext* FAScriptParser::allAssign() {
  AllAssignContext *_localctx = _tracker.createInstance<AllAssignContext>(_ctx, getState());
  enterRule(_localctx, 4, FAScriptParser::RuleAllAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(96);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FAScriptParser::Assign: {
        enterOuterAlt(_localctx, 1);
        setState(82);
        match(FAScriptParser::Assign);
        break;
      }

      case FAScriptParser::AddAssign: {
        enterOuterAlt(_localctx, 2);
        setState(83);
        match(FAScriptParser::AddAssign);
        break;
      }

      case FAScriptParser::SubAssign: {
        enterOuterAlt(_localctx, 3);
        setState(84);
        match(FAScriptParser::SubAssign);
        break;
      }

      case FAScriptParser::StarAssign: {
        enterOuterAlt(_localctx, 4);
        setState(85);
        match(FAScriptParser::StarAssign);
        break;
      }

      case FAScriptParser::StarStarAssign: {
        enterOuterAlt(_localctx, 5);
        setState(86);
        match(FAScriptParser::StarStarAssign);
        break;
      }

      case FAScriptParser::DivAssign: {
        enterOuterAlt(_localctx, 6);
        setState(87);
        match(FAScriptParser::DivAssign);
        break;
      }

      case FAScriptParser::ModAssign: {
        enterOuterAlt(_localctx, 7);
        setState(88);
        match(FAScriptParser::ModAssign);
        break;
      }

      case FAScriptParser::AndAssign: {
        enterOuterAlt(_localctx, 8);
        setState(89);
        match(FAScriptParser::AndAssign);
        break;
      }

      case FAScriptParser::OrAssign: {
        enterOuterAlt(_localctx, 9);
        setState(90);
        match(FAScriptParser::OrAssign);
        break;
      }

      case FAScriptParser::XorAssign: {
        enterOuterAlt(_localctx, 10);
        setState(91);
        match(FAScriptParser::XorAssign);
        break;
      }

      case FAScriptParser::AndAndAssign: {
        enterOuterAlt(_localctx, 11);
        setState(92);
        match(FAScriptParser::AndAndAssign);
        break;
      }

      case FAScriptParser::OrOrAssign: {
        enterOuterAlt(_localctx, 12);
        setState(93);
        match(FAScriptParser::OrOrAssign);
        break;
      }

      case FAScriptParser::QuotJianL: {
        enterOuterAlt(_localctx, 13);
        setState(94);
        shiftLAssign();
        break;
      }

      case FAScriptParser::QuotJianR: {
        enterOuterAlt(_localctx, 14);
        setState(95);
        shiftRAssign();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShiftLOpContext ------------------------------------------------------------------

FAScriptParser::ShiftLOpContext::ShiftLOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FAScriptParser::ShiftLOpContext::QuotJianL() {
  return getTokens(FAScriptParser::QuotJianL);
}

tree::TerminalNode* FAScriptParser::ShiftLOpContext::QuotJianL(size_t i) {
  return getToken(FAScriptParser::QuotJianL, i);
}


size_t FAScriptParser::ShiftLOpContext::getRuleIndex() const {
  return FAScriptParser::RuleShiftLOp;
}


antlrcpp::Any FAScriptParser::ShiftLOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitShiftLOp(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ShiftLOpContext* FAScriptParser::shiftLOp() {
  ShiftLOpContext *_localctx = _tracker.createInstance<ShiftLOpContext>(_ctx, getState());
  enterRule(_localctx, 6, FAScriptParser::RuleShiftLOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    match(FAScriptParser::QuotJianL);
    setState(99);
    match(FAScriptParser::QuotJianL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShiftROpContext ------------------------------------------------------------------

FAScriptParser::ShiftROpContext::ShiftROpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FAScriptParser::ShiftROpContext::QuotJianR() {
  return getTokens(FAScriptParser::QuotJianR);
}

tree::TerminalNode* FAScriptParser::ShiftROpContext::QuotJianR(size_t i) {
  return getToken(FAScriptParser::QuotJianR, i);
}


size_t FAScriptParser::ShiftROpContext::getRuleIndex() const {
  return FAScriptParser::RuleShiftROp;
}


antlrcpp::Any FAScriptParser::ShiftROpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitShiftROp(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ShiftROpContext* FAScriptParser::shiftROp() {
  ShiftROpContext *_localctx = _tracker.createInstance<ShiftROpContext>(_ctx, getState());
  enterRule(_localctx, 8, FAScriptParser::RuleShiftROp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(FAScriptParser::QuotJianR);
    setState(102);
    match(FAScriptParser::QuotJianR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LtOpContext ------------------------------------------------------------------

FAScriptParser::LtOpContext::LtOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::LtOpContext::QuotJianL() {
  return getToken(FAScriptParser::QuotJianL, 0);
}


size_t FAScriptParser::LtOpContext::getRuleIndex() const {
  return FAScriptParser::RuleLtOp;
}


antlrcpp::Any FAScriptParser::LtOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitLtOp(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::LtOpContext* FAScriptParser::ltOp() {
  LtOpContext *_localctx = _tracker.createInstance<LtOpContext>(_ctx, getState());
  enterRule(_localctx, 10, FAScriptParser::RuleLtOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(FAScriptParser::QuotJianL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LtEqualOpContext ------------------------------------------------------------------

FAScriptParser::LtEqualOpContext::LtEqualOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::LtEqualOpContext::QuotJianL() {
  return getToken(FAScriptParser::QuotJianL, 0);
}

tree::TerminalNode* FAScriptParser::LtEqualOpContext::Assign() {
  return getToken(FAScriptParser::Assign, 0);
}


size_t FAScriptParser::LtEqualOpContext::getRuleIndex() const {
  return FAScriptParser::RuleLtEqualOp;
}


antlrcpp::Any FAScriptParser::LtEqualOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitLtEqualOp(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::LtEqualOpContext* FAScriptParser::ltEqualOp() {
  LtEqualOpContext *_localctx = _tracker.createInstance<LtEqualOpContext>(_ctx, getState());
  enterRule(_localctx, 12, FAScriptParser::RuleLtEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(FAScriptParser::QuotJianL);
    setState(107);
    match(FAScriptParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GtOpContext ------------------------------------------------------------------

FAScriptParser::GtOpContext::GtOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::GtOpContext::QuotJianR() {
  return getToken(FAScriptParser::QuotJianR, 0);
}


size_t FAScriptParser::GtOpContext::getRuleIndex() const {
  return FAScriptParser::RuleGtOp;
}


antlrcpp::Any FAScriptParser::GtOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitGtOp(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::GtOpContext* FAScriptParser::gtOp() {
  GtOpContext *_localctx = _tracker.createInstance<GtOpContext>(_ctx, getState());
  enterRule(_localctx, 14, FAScriptParser::RuleGtOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(FAScriptParser::QuotJianR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GtEqualOpContext ------------------------------------------------------------------

FAScriptParser::GtEqualOpContext::GtEqualOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::GtEqualOpContext::QuotJianR() {
  return getToken(FAScriptParser::QuotJianR, 0);
}

tree::TerminalNode* FAScriptParser::GtEqualOpContext::Assign() {
  return getToken(FAScriptParser::Assign, 0);
}


size_t FAScriptParser::GtEqualOpContext::getRuleIndex() const {
  return FAScriptParser::RuleGtEqualOp;
}


antlrcpp::Any FAScriptParser::GtEqualOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitGtEqualOp(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::GtEqualOpContext* FAScriptParser::gtEqualOp() {
  GtEqualOpContext *_localctx = _tracker.createInstance<GtEqualOpContext>(_ctx, getState());
  enterRule(_localctx, 16, FAScriptParser::RuleGtEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(FAScriptParser::QuotJianR);
    setState(112);
    match(FAScriptParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualOpContext ------------------------------------------------------------------

FAScriptParser::EqualOpContext::EqualOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FAScriptParser::EqualOpContext::Assign() {
  return getTokens(FAScriptParser::Assign);
}

tree::TerminalNode* FAScriptParser::EqualOpContext::Assign(size_t i) {
  return getToken(FAScriptParser::Assign, i);
}


size_t FAScriptParser::EqualOpContext::getRuleIndex() const {
  return FAScriptParser::RuleEqualOp;
}


antlrcpp::Any FAScriptParser::EqualOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitEqualOp(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::EqualOpContext* FAScriptParser::equalOp() {
  EqualOpContext *_localctx = _tracker.createInstance<EqualOpContext>(_ctx, getState());
  enterRule(_localctx, 18, FAScriptParser::RuleEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(FAScriptParser::Assign);
    setState(115);
    match(FAScriptParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotEqualOpContext ------------------------------------------------------------------

FAScriptParser::NotEqualOpContext::NotEqualOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::NotEqualOpContext::Exclam() {
  return getToken(FAScriptParser::Exclam, 0);
}

tree::TerminalNode* FAScriptParser::NotEqualOpContext::Assign() {
  return getToken(FAScriptParser::Assign, 0);
}


size_t FAScriptParser::NotEqualOpContext::getRuleIndex() const {
  return FAScriptParser::RuleNotEqualOp;
}


antlrcpp::Any FAScriptParser::NotEqualOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitNotEqualOp(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::NotEqualOpContext* FAScriptParser::notEqualOp() {
  NotEqualOpContext *_localctx = _tracker.createInstance<NotEqualOpContext>(_ctx, getState());
  enterRule(_localctx, 20, FAScriptParser::RuleNotEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(FAScriptParser::Exclam);
    setState(118);
    match(FAScriptParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprFuncDefContext ------------------------------------------------------------------

FAScriptParser::ExprFuncDefContext::ExprFuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::ExprFuncDefContext::Assign() {
  return getToken(FAScriptParser::Assign, 0);
}

tree::TerminalNode* FAScriptParser::ExprFuncDefContext::QuotJianR() {
  return getToken(FAScriptParser::QuotJianR, 0);
}


size_t FAScriptParser::ExprFuncDefContext::getRuleIndex() const {
  return FAScriptParser::RuleExprFuncDef;
}


antlrcpp::Any FAScriptParser::ExprFuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitExprFuncDef(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ExprFuncDefContext* FAScriptParser::exprFuncDef() {
  ExprFuncDefContext *_localctx = _tracker.createInstance<ExprFuncDefContext>(_ctx, getState());
  enterRule(_localctx, 22, FAScriptParser::RuleExprFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(FAScriptParser::Assign);
    setState(121);
    match(FAScriptParser::QuotJianR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelfOp2Context ------------------------------------------------------------------

FAScriptParser::SelfOp2Context::SelfOp2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::AddOp() {
  return getToken(FAScriptParser::AddOp, 0);
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::SubOp() {
  return getToken(FAScriptParser::SubOp, 0);
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::StarOp() {
  return getToken(FAScriptParser::StarOp, 0);
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::DivOp() {
  return getToken(FAScriptParser::DivOp, 0);
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::StarStarOp() {
  return getToken(FAScriptParser::StarStarOp, 0);
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::ModOp() {
  return getToken(FAScriptParser::ModOp, 0);
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::AndOp() {
  return getToken(FAScriptParser::AndOp, 0);
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::OrOp() {
  return getToken(FAScriptParser::OrOp, 0);
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::XorOp() {
  return getToken(FAScriptParser::XorOp, 0);
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::AndAndOp() {
  return getToken(FAScriptParser::AndAndOp, 0);
}

tree::TerminalNode* FAScriptParser::SelfOp2Context::OrOrOp() {
  return getToken(FAScriptParser::OrOrOp, 0);
}

FAScriptParser::ShiftLOpContext* FAScriptParser::SelfOp2Context::shiftLOp() {
  return getRuleContext<FAScriptParser::ShiftLOpContext>(0);
}

FAScriptParser::ShiftROpContext* FAScriptParser::SelfOp2Context::shiftROp() {
  return getRuleContext<FAScriptParser::ShiftROpContext>(0);
}


size_t FAScriptParser::SelfOp2Context::getRuleIndex() const {
  return FAScriptParser::RuleSelfOp2;
}


antlrcpp::Any FAScriptParser::SelfOp2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitSelfOp2(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::SelfOp2Context* FAScriptParser::selfOp2() {
  SelfOp2Context *_localctx = _tracker.createInstance<SelfOp2Context>(_ctx, getState());
  enterRule(_localctx, 24, FAScriptParser::RuleSelfOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FAScriptParser::AddOp: {
        enterOuterAlt(_localctx, 1);
        setState(123);
        match(FAScriptParser::AddOp);
        break;
      }

      case FAScriptParser::SubOp: {
        enterOuterAlt(_localctx, 2);
        setState(124);
        match(FAScriptParser::SubOp);
        break;
      }

      case FAScriptParser::StarOp: {
        enterOuterAlt(_localctx, 3);
        setState(125);
        match(FAScriptParser::StarOp);
        break;
      }

      case FAScriptParser::DivOp: {
        enterOuterAlt(_localctx, 4);
        setState(126);
        match(FAScriptParser::DivOp);
        break;
      }

      case FAScriptParser::StarStarOp: {
        enterOuterAlt(_localctx, 5);
        setState(127);
        match(FAScriptParser::StarStarOp);
        break;
      }

      case FAScriptParser::ModOp: {
        enterOuterAlt(_localctx, 6);
        setState(128);
        match(FAScriptParser::ModOp);
        break;
      }

      case FAScriptParser::AndOp: {
        enterOuterAlt(_localctx, 7);
        setState(129);
        match(FAScriptParser::AndOp);
        break;
      }

      case FAScriptParser::OrOp: {
        enterOuterAlt(_localctx, 8);
        setState(130);
        match(FAScriptParser::OrOp);
        break;
      }

      case FAScriptParser::XorOp: {
        enterOuterAlt(_localctx, 9);
        setState(131);
        match(FAScriptParser::XorOp);
        break;
      }

      case FAScriptParser::AndAndOp: {
        enterOuterAlt(_localctx, 10);
        setState(132);
        match(FAScriptParser::AndAndOp);
        break;
      }

      case FAScriptParser::OrOrOp: {
        enterOuterAlt(_localctx, 11);
        setState(133);
        match(FAScriptParser::OrOrOp);
        break;
      }

      case FAScriptParser::QuotJianL: {
        enterOuterAlt(_localctx, 12);
        setState(134);
        shiftLOp();
        break;
      }

      case FAScriptParser::QuotJianR: {
        enterOuterAlt(_localctx, 13);
        setState(135);
        shiftROp();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompareOp2Context ------------------------------------------------------------------

FAScriptParser::CompareOp2Context::CompareOp2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FAScriptParser::LtOpContext* FAScriptParser::CompareOp2Context::ltOp() {
  return getRuleContext<FAScriptParser::LtOpContext>(0);
}

FAScriptParser::LtEqualOpContext* FAScriptParser::CompareOp2Context::ltEqualOp() {
  return getRuleContext<FAScriptParser::LtEqualOpContext>(0);
}

FAScriptParser::GtOpContext* FAScriptParser::CompareOp2Context::gtOp() {
  return getRuleContext<FAScriptParser::GtOpContext>(0);
}

FAScriptParser::GtEqualOpContext* FAScriptParser::CompareOp2Context::gtEqualOp() {
  return getRuleContext<FAScriptParser::GtEqualOpContext>(0);
}

FAScriptParser::EqualOpContext* FAScriptParser::CompareOp2Context::equalOp() {
  return getRuleContext<FAScriptParser::EqualOpContext>(0);
}

FAScriptParser::NotEqualOpContext* FAScriptParser::CompareOp2Context::notEqualOp() {
  return getRuleContext<FAScriptParser::NotEqualOpContext>(0);
}


size_t FAScriptParser::CompareOp2Context::getRuleIndex() const {
  return FAScriptParser::RuleCompareOp2;
}


antlrcpp::Any FAScriptParser::CompareOp2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitCompareOp2(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::CompareOp2Context* FAScriptParser::compareOp2() {
  CompareOp2Context *_localctx = _tracker.createInstance<CompareOp2Context>(_ctx, getState());
  enterRule(_localctx, 26, FAScriptParser::RuleCompareOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(138);
      ltOp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(139);
      ltEqualOp();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(140);
      gtOp();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(141);
      gtEqualOp();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(142);
      equalOp();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(143);
      notEqualOp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AllOp2Context ------------------------------------------------------------------

FAScriptParser::AllOp2Context::AllOp2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FAScriptParser::SelfOp2Context* FAScriptParser::AllOp2Context::selfOp2() {
  return getRuleContext<FAScriptParser::SelfOp2Context>(0);
}

FAScriptParser::CompareOp2Context* FAScriptParser::AllOp2Context::compareOp2() {
  return getRuleContext<FAScriptParser::CompareOp2Context>(0);
}


size_t FAScriptParser::AllOp2Context::getRuleIndex() const {
  return FAScriptParser::RuleAllOp2;
}


antlrcpp::Any FAScriptParser::AllOp2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitAllOp2(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::AllOp2Context* FAScriptParser::allOp2() {
  AllOp2Context *_localctx = _tracker.createInstance<AllOp2Context>(_ctx, getState());
  enterRule(_localctx, 28, FAScriptParser::RuleAllOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(148);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(146);
      selfOp2();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(147);
      compareOp2();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

FAScriptParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::LiteralContext::BoolLiteral() {
  return getToken(FAScriptParser::BoolLiteral, 0);
}

tree::TerminalNode* FAScriptParser::LiteralContext::NumLiteral() {
  return getToken(FAScriptParser::NumLiteral, 0);
}

tree::TerminalNode* FAScriptParser::LiteralContext::StringLiteral() {
  return getToken(FAScriptParser::StringLiteral, 0);
}


size_t FAScriptParser::LiteralContext::getRuleIndex() const {
  return FAScriptParser::RuleLiteral;
}


antlrcpp::Any FAScriptParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::LiteralContext* FAScriptParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 30, FAScriptParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotStmtPartContext ------------------------------------------------------------------

FAScriptParser::QuotStmtPartContext::QuotStmtPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::QuotStmtPartContext::QuotHuaL() {
  return getToken(FAScriptParser::QuotHuaL, 0);
}

tree::TerminalNode* FAScriptParser::QuotStmtPartContext::QuotHuaR() {
  return getToken(FAScriptParser::QuotHuaR, 0);
}

std::vector<FAScriptParser::StmtContext *> FAScriptParser::QuotStmtPartContext::stmt() {
  return getRuleContexts<FAScriptParser::StmtContext>();
}

FAScriptParser::StmtContext* FAScriptParser::QuotStmtPartContext::stmt(size_t i) {
  return getRuleContext<FAScriptParser::StmtContext>(i);
}


size_t FAScriptParser::QuotStmtPartContext::getRuleIndex() const {
  return FAScriptParser::RuleQuotStmtPart;
}


antlrcpp::Any FAScriptParser::QuotStmtPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitQuotStmtPart(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::QuotStmtPartContext* FAScriptParser::quotStmtPart() {
  QuotStmtPartContext *_localctx = _tracker.createInstance<QuotStmtPartContext>(_ctx, getState());
  enterRule(_localctx, 32, FAScriptParser::RuleQuotStmtPart);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    match(FAScriptParser::QuotHuaL);
    setState(156);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::T__0)
      | (1ULL << FAScriptParser::Break)
      | (1ULL << FAScriptParser::Continue)
      | (1ULL << FAScriptParser::Return)
      | (1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::Semi)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(153);
      stmt();
      setState(158);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(159);
    match(FAScriptParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

FAScriptParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FAScriptParser::IfStmtContext::If() {
  return getTokens(FAScriptParser::If);
}

tree::TerminalNode* FAScriptParser::IfStmtContext::If(size_t i) {
  return getToken(FAScriptParser::If, i);
}

std::vector<FAScriptParser::ExprContext *> FAScriptParser::IfStmtContext::expr() {
  return getRuleContexts<FAScriptParser::ExprContext>();
}

FAScriptParser::ExprContext* FAScriptParser::IfStmtContext::expr(size_t i) {
  return getRuleContext<FAScriptParser::ExprContext>(i);
}

std::vector<FAScriptParser::QuotStmtPartContext *> FAScriptParser::IfStmtContext::quotStmtPart() {
  return getRuleContexts<FAScriptParser::QuotStmtPartContext>();
}

FAScriptParser::QuotStmtPartContext* FAScriptParser::IfStmtContext::quotStmtPart(size_t i) {
  return getRuleContext<FAScriptParser::QuotStmtPartContext>(i);
}

std::vector<tree::TerminalNode *> FAScriptParser::IfStmtContext::Else() {
  return getTokens(FAScriptParser::Else);
}

tree::TerminalNode* FAScriptParser::IfStmtContext::Else(size_t i) {
  return getToken(FAScriptParser::Else, i);
}


size_t FAScriptParser::IfStmtContext::getRuleIndex() const {
  return FAScriptParser::RuleIfStmt;
}


antlrcpp::Any FAScriptParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::IfStmtContext* FAScriptParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, FAScriptParser::RuleIfStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(FAScriptParser::If);
    setState(162);
    expr();
    setState(163);
    quotStmtPart();
    setState(171);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(164);
        match(FAScriptParser::Else);
        setState(165);
        match(FAScriptParser::If);
        setState(166);
        expr();
        setState(167);
        quotStmtPart(); 
      }
      setState(173);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FAScriptParser::Else) {
      setState(174);
      match(FAScriptParser::Else);
      setState(175);
      quotStmtPart();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

FAScriptParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::WhileStmtContext::While() {
  return getToken(FAScriptParser::While, 0);
}

FAScriptParser::ExprContext* FAScriptParser::WhileStmtContext::expr() {
  return getRuleContext<FAScriptParser::ExprContext>(0);
}

tree::TerminalNode* FAScriptParser::WhileStmtContext::QuotHuaL() {
  return getToken(FAScriptParser::QuotHuaL, 0);
}

tree::TerminalNode* FAScriptParser::WhileStmtContext::QuotHuaR() {
  return getToken(FAScriptParser::QuotHuaR, 0);
}

std::vector<FAScriptParser::StmtContext *> FAScriptParser::WhileStmtContext::stmt() {
  return getRuleContexts<FAScriptParser::StmtContext>();
}

FAScriptParser::StmtContext* FAScriptParser::WhileStmtContext::stmt(size_t i) {
  return getRuleContext<FAScriptParser::StmtContext>(i);
}


size_t FAScriptParser::WhileStmtContext::getRuleIndex() const {
  return FAScriptParser::RuleWhileStmt;
}


antlrcpp::Any FAScriptParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::WhileStmtContext* FAScriptParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, FAScriptParser::RuleWhileStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(FAScriptParser::While);
    setState(179);
    expr();
    setState(180);
    match(FAScriptParser::QuotHuaL);
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::T__0)
      | (1ULL << FAScriptParser::Break)
      | (1ULL << FAScriptParser::Continue)
      | (1ULL << FAScriptParser::Return)
      | (1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::Semi)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(181);
      stmt();
      setState(186);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(187);
    match(FAScriptParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmt2Context ------------------------------------------------------------------

FAScriptParser::WhileStmt2Context::WhileStmt2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::WhileStmt2Context::Do() {
  return getToken(FAScriptParser::Do, 0);
}

tree::TerminalNode* FAScriptParser::WhileStmt2Context::QuotHuaL() {
  return getToken(FAScriptParser::QuotHuaL, 0);
}

tree::TerminalNode* FAScriptParser::WhileStmt2Context::QuotHuaR() {
  return getToken(FAScriptParser::QuotHuaR, 0);
}

tree::TerminalNode* FAScriptParser::WhileStmt2Context::While() {
  return getToken(FAScriptParser::While, 0);
}

FAScriptParser::ExprContext* FAScriptParser::WhileStmt2Context::expr() {
  return getRuleContext<FAScriptParser::ExprContext>(0);
}

std::vector<FAScriptParser::StmtContext *> FAScriptParser::WhileStmt2Context::stmt() {
  return getRuleContexts<FAScriptParser::StmtContext>();
}

FAScriptParser::StmtContext* FAScriptParser::WhileStmt2Context::stmt(size_t i) {
  return getRuleContext<FAScriptParser::StmtContext>(i);
}


size_t FAScriptParser::WhileStmt2Context::getRuleIndex() const {
  return FAScriptParser::RuleWhileStmt2;
}


antlrcpp::Any FAScriptParser::WhileStmt2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitWhileStmt2(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::WhileStmt2Context* FAScriptParser::whileStmt2() {
  WhileStmt2Context *_localctx = _tracker.createInstance<WhileStmt2Context>(_ctx, getState());
  enterRule(_localctx, 38, FAScriptParser::RuleWhileStmt2);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    match(FAScriptParser::Do);
    setState(190);
    match(FAScriptParser::QuotHuaL);
    setState(194);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::T__0)
      | (1ULL << FAScriptParser::Break)
      | (1ULL << FAScriptParser::Continue)
      | (1ULL << FAScriptParser::Return)
      | (1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::Semi)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(191);
      stmt();
      setState(196);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(197);
    match(FAScriptParser::QuotHuaR);
    setState(198);
    match(FAScriptParser::While);
    setState(199);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

FAScriptParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::ForStmtContext::For() {
  return getToken(FAScriptParser::For, 0);
}

std::vector<FAScriptParser::StmtContext *> FAScriptParser::ForStmtContext::stmt() {
  return getRuleContexts<FAScriptParser::StmtContext>();
}

FAScriptParser::StmtContext* FAScriptParser::ForStmtContext::stmt(size_t i) {
  return getRuleContext<FAScriptParser::StmtContext>(i);
}

std::vector<FAScriptParser::ExprContext *> FAScriptParser::ForStmtContext::expr() {
  return getRuleContexts<FAScriptParser::ExprContext>();
}

FAScriptParser::ExprContext* FAScriptParser::ForStmtContext::expr(size_t i) {
  return getRuleContext<FAScriptParser::ExprContext>(i);
}

tree::TerminalNode* FAScriptParser::ForStmtContext::Semi() {
  return getToken(FAScriptParser::Semi, 0);
}

tree::TerminalNode* FAScriptParser::ForStmtContext::QuotHuaL() {
  return getToken(FAScriptParser::QuotHuaL, 0);
}

tree::TerminalNode* FAScriptParser::ForStmtContext::QuotHuaR() {
  return getToken(FAScriptParser::QuotHuaR, 0);
}

std::vector<tree::TerminalNode *> FAScriptParser::ForStmtContext::Comma() {
  return getTokens(FAScriptParser::Comma);
}

tree::TerminalNode* FAScriptParser::ForStmtContext::Comma(size_t i) {
  return getToken(FAScriptParser::Comma, i);
}


size_t FAScriptParser::ForStmtContext::getRuleIndex() const {
  return FAScriptParser::RuleForStmt;
}


antlrcpp::Any FAScriptParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ForStmtContext* FAScriptParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 40, FAScriptParser::RuleForStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(FAScriptParser::For);
    setState(202);
    stmt();
    setState(203);
    expr();
    setState(204);
    match(FAScriptParser::Semi);
    setState(213);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(205);
      expr();
      setState(210);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FAScriptParser::Comma) {
        setState(206);
        match(FAScriptParser::Comma);
        setState(207);
        expr();
        setState(212);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(215);
    match(FAScriptParser::QuotHuaL);
    setState(219);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::T__0)
      | (1ULL << FAScriptParser::Break)
      | (1ULL << FAScriptParser::Continue)
      | (1ULL << FAScriptParser::Return)
      | (1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::Semi)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(216);
      stmt();
      setState(221);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(222);
    match(FAScriptParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmt2Context ------------------------------------------------------------------

FAScriptParser::ForStmt2Context::ForStmt2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::ForStmt2Context::For() {
  return getToken(FAScriptParser::For, 0);
}

tree::TerminalNode* FAScriptParser::ForStmt2Context::Id() {
  return getToken(FAScriptParser::Id, 0);
}

tree::TerminalNode* FAScriptParser::ForStmt2Context::Colon() {
  return getToken(FAScriptParser::Colon, 0);
}

FAScriptParser::ExprContext* FAScriptParser::ForStmt2Context::expr() {
  return getRuleContext<FAScriptParser::ExprContext>(0);
}

tree::TerminalNode* FAScriptParser::ForStmt2Context::QuotHuaL() {
  return getToken(FAScriptParser::QuotHuaL, 0);
}

tree::TerminalNode* FAScriptParser::ForStmt2Context::QuotHuaR() {
  return getToken(FAScriptParser::QuotHuaR, 0);
}

std::vector<FAScriptParser::StmtContext *> FAScriptParser::ForStmt2Context::stmt() {
  return getRuleContexts<FAScriptParser::StmtContext>();
}

FAScriptParser::StmtContext* FAScriptParser::ForStmt2Context::stmt(size_t i) {
  return getRuleContext<FAScriptParser::StmtContext>(i);
}


size_t FAScriptParser::ForStmt2Context::getRuleIndex() const {
  return FAScriptParser::RuleForStmt2;
}


antlrcpp::Any FAScriptParser::ForStmt2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitForStmt2(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ForStmt2Context* FAScriptParser::forStmt2() {
  ForStmt2Context *_localctx = _tracker.createInstance<ForStmt2Context>(_ctx, getState());
  enterRule(_localctx, 42, FAScriptParser::RuleForStmt2);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    match(FAScriptParser::For);
    setState(225);
    match(FAScriptParser::Id);
    setState(226);
    match(FAScriptParser::Colon);
    setState(227);
    expr();
    setState(228);
    match(FAScriptParser::QuotHuaL);
    setState(232);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::T__0)
      | (1ULL << FAScriptParser::Break)
      | (1ULL << FAScriptParser::Continue)
      | (1ULL << FAScriptParser::Return)
      | (1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::Semi)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(229);
      stmt();
      setState(234);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(235);
    match(FAScriptParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStmtPartContext ------------------------------------------------------------------

FAScriptParser::SwitchStmtPartContext::SwitchStmtPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FAScriptParser::ExprContext *> FAScriptParser::SwitchStmtPartContext::expr() {
  return getRuleContexts<FAScriptParser::ExprContext>();
}

FAScriptParser::ExprContext* FAScriptParser::SwitchStmtPartContext::expr(size_t i) {
  return getRuleContext<FAScriptParser::ExprContext>(i);
}

FAScriptParser::ExprFuncDefContext* FAScriptParser::SwitchStmtPartContext::exprFuncDef() {
  return getRuleContext<FAScriptParser::ExprFuncDefContext>(0);
}

FAScriptParser::StmtContext* FAScriptParser::SwitchStmtPartContext::stmt() {
  return getRuleContext<FAScriptParser::StmtContext>(0);
}

tree::TerminalNode* FAScriptParser::SwitchStmtPartContext::When() {
  return getToken(FAScriptParser::When, 0);
}


size_t FAScriptParser::SwitchStmtPartContext::getRuleIndex() const {
  return FAScriptParser::RuleSwitchStmtPart;
}


antlrcpp::Any FAScriptParser::SwitchStmtPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitSwitchStmtPart(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::SwitchStmtPartContext* FAScriptParser::switchStmtPart() {
  SwitchStmtPartContext *_localctx = _tracker.createInstance<SwitchStmtPartContext>(_ctx, getState());
  enterRule(_localctx, 44, FAScriptParser::RuleSwitchStmtPart);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    expr();
    setState(240);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FAScriptParser::When) {
      setState(238);
      match(FAScriptParser::When);
      setState(239);
      expr();
    }
    setState(242);
    exprFuncDef();
    setState(243);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStmtContext ------------------------------------------------------------------

FAScriptParser::SwitchStmtContext::SwitchStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::SwitchStmtContext::Switch() {
  return getToken(FAScriptParser::Switch, 0);
}

FAScriptParser::ExprContext* FAScriptParser::SwitchStmtContext::expr() {
  return getRuleContext<FAScriptParser::ExprContext>(0);
}

tree::TerminalNode* FAScriptParser::SwitchStmtContext::QuotHuaL() {
  return getToken(FAScriptParser::QuotHuaL, 0);
}

tree::TerminalNode* FAScriptParser::SwitchStmtContext::QuotHuaR() {
  return getToken(FAScriptParser::QuotHuaR, 0);
}

std::vector<FAScriptParser::SwitchStmtPartContext *> FAScriptParser::SwitchStmtContext::switchStmtPart() {
  return getRuleContexts<FAScriptParser::SwitchStmtPartContext>();
}

FAScriptParser::SwitchStmtPartContext* FAScriptParser::SwitchStmtContext::switchStmtPart(size_t i) {
  return getRuleContext<FAScriptParser::SwitchStmtPartContext>(i);
}


size_t FAScriptParser::SwitchStmtContext::getRuleIndex() const {
  return FAScriptParser::RuleSwitchStmt;
}


antlrcpp::Any FAScriptParser::SwitchStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitSwitchStmt(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::SwitchStmtContext* FAScriptParser::switchStmt() {
  SwitchStmtContext *_localctx = _tracker.createInstance<SwitchStmtContext>(_ctx, getState());
  enterRule(_localctx, 46, FAScriptParser::RuleSwitchStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(FAScriptParser::Switch);
    setState(246);
    expr();
    setState(247);
    match(FAScriptParser::QuotHuaL);
    setState(251);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(248);
      switchStmtPart();
      setState(253);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(254);
    match(FAScriptParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprOptContext ------------------------------------------------------------------

FAScriptParser::ExprOptContext::ExprOptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FAScriptParser::ExprContext* FAScriptParser::ExprOptContext::expr() {
  return getRuleContext<FAScriptParser::ExprContext>(0);
}


size_t FAScriptParser::ExprOptContext::getRuleIndex() const {
  return FAScriptParser::RuleExprOpt;
}


antlrcpp::Any FAScriptParser::ExprOptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitExprOpt(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ExprOptContext* FAScriptParser::exprOpt() {
  ExprOptContext *_localctx = _tracker.createInstance<ExprOptContext>(_ctx, getState());
  enterRule(_localctx, 48, FAScriptParser::RuleExprOpt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(256);
      expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotExprContext ------------------------------------------------------------------

FAScriptParser::QuotExprContext::QuotExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::QuotExprContext::QuotYuanL() {
  return getToken(FAScriptParser::QuotYuanL, 0);
}

FAScriptParser::ExprContext* FAScriptParser::QuotExprContext::expr() {
  return getRuleContext<FAScriptParser::ExprContext>(0);
}

tree::TerminalNode* FAScriptParser::QuotExprContext::QuotYuanR() {
  return getToken(FAScriptParser::QuotYuanR, 0);
}


size_t FAScriptParser::QuotExprContext::getRuleIndex() const {
  return FAScriptParser::RuleQuotExpr;
}


antlrcpp::Any FAScriptParser::QuotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitQuotExpr(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::QuotExprContext* FAScriptParser::quotExpr() {
  QuotExprContext *_localctx = _tracker.createInstance<QuotExprContext>(_ctx, getState());
  enterRule(_localctx, 50, FAScriptParser::RuleQuotExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(FAScriptParser::QuotYuanL);
    setState(260);
    expr();
    setState(261);
    match(FAScriptParser::QuotYuanR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FnExprContext ------------------------------------------------------------------

FAScriptParser::FnExprContext::FnExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::FnExprContext::Fn() {
  return getToken(FAScriptParser::Fn, 0);
}

tree::TerminalNode* FAScriptParser::FnExprContext::QuotYuanL() {
  return getToken(FAScriptParser::QuotYuanL, 0);
}

tree::TerminalNode* FAScriptParser::FnExprContext::QuotYuanR() {
  return getToken(FAScriptParser::QuotYuanR, 0);
}

tree::TerminalNode* FAScriptParser::FnExprContext::QuotHuaL() {
  return getToken(FAScriptParser::QuotHuaL, 0);
}

tree::TerminalNode* FAScriptParser::FnExprContext::QuotHuaR() {
  return getToken(FAScriptParser::QuotHuaR, 0);
}

std::vector<tree::TerminalNode *> FAScriptParser::FnExprContext::Id() {
  return getTokens(FAScriptParser::Id);
}

tree::TerminalNode* FAScriptParser::FnExprContext::Id(size_t i) {
  return getToken(FAScriptParser::Id, i);
}

std::vector<FAScriptParser::StmtContext *> FAScriptParser::FnExprContext::stmt() {
  return getRuleContexts<FAScriptParser::StmtContext>();
}

FAScriptParser::StmtContext* FAScriptParser::FnExprContext::stmt(size_t i) {
  return getRuleContext<FAScriptParser::StmtContext>(i);
}


size_t FAScriptParser::FnExprContext::getRuleIndex() const {
  return FAScriptParser::RuleFnExpr;
}


antlrcpp::Any FAScriptParser::FnExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitFnExpr(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::FnExprContext* FAScriptParser::fnExpr() {
  FnExprContext *_localctx = _tracker.createInstance<FnExprContext>(_ctx, getState());
  enterRule(_localctx, 52, FAScriptParser::RuleFnExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(FAScriptParser::Fn);
    setState(264);
    match(FAScriptParser::QuotYuanL);
    setState(268);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FAScriptParser::Id) {
      setState(265);
      match(FAScriptParser::Id);
      setState(270);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(271);
    match(FAScriptParser::QuotYuanR);
    setState(272);
    match(FAScriptParser::QuotHuaL);
    setState(276);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::T__0)
      | (1ULL << FAScriptParser::Break)
      | (1ULL << FAScriptParser::Continue)
      | (1ULL << FAScriptParser::Return)
      | (1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::Semi)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(273);
      stmt();
      setState(278);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(279);
    match(FAScriptParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassExprItemContext ------------------------------------------------------------------

FAScriptParser::ClassExprItemContext::ClassExprItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::ClassExprItemContext::Id() {
  return getToken(FAScriptParser::Id, 0);
}

tree::TerminalNode* FAScriptParser::ClassExprItemContext::Assign() {
  return getToken(FAScriptParser::Assign, 0);
}

FAScriptParser::MiddleExprContext* FAScriptParser::ClassExprItemContext::middleExpr() {
  return getRuleContext<FAScriptParser::MiddleExprContext>(0);
}

FAScriptParser::FnStmtContext* FAScriptParser::ClassExprItemContext::fnStmt() {
  return getRuleContext<FAScriptParser::FnStmtContext>(0);
}


size_t FAScriptParser::ClassExprItemContext::getRuleIndex() const {
  return FAScriptParser::RuleClassExprItem;
}


antlrcpp::Any FAScriptParser::ClassExprItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitClassExprItem(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ClassExprItemContext* FAScriptParser::classExprItem() {
  ClassExprItemContext *_localctx = _tracker.createInstance<ClassExprItemContext>(_ctx, getState());
  enterRule(_localctx, 54, FAScriptParser::RuleClassExprItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FAScriptParser::Id: {
        enterOuterAlt(_localctx, 1);
        setState(281);
        match(FAScriptParser::Id);
        setState(282);
        match(FAScriptParser::Assign);
        setState(283);
        middleExpr();
        break;
      }

      case FAScriptParser::Fn: {
        enterOuterAlt(_localctx, 2);
        setState(284);
        fnStmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassExprContext ------------------------------------------------------------------

FAScriptParser::ClassExprContext::ClassExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::ClassExprContext::QuotHuaL() {
  return getToken(FAScriptParser::QuotHuaL, 0);
}

tree::TerminalNode* FAScriptParser::ClassExprContext::QuotHuaR() {
  return getToken(FAScriptParser::QuotHuaR, 0);
}

std::vector<FAScriptParser::ClassExprItemContext *> FAScriptParser::ClassExprContext::classExprItem() {
  return getRuleContexts<FAScriptParser::ClassExprItemContext>();
}

FAScriptParser::ClassExprItemContext* FAScriptParser::ClassExprContext::classExprItem(size_t i) {
  return getRuleContext<FAScriptParser::ClassExprItemContext>(i);
}


size_t FAScriptParser::ClassExprContext::getRuleIndex() const {
  return FAScriptParser::RuleClassExpr;
}


antlrcpp::Any FAScriptParser::ClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitClassExpr(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ClassExprContext* FAScriptParser::classExpr() {
  ClassExprContext *_localctx = _tracker.createInstance<ClassExprContext>(_ctx, getState());
  enterRule(_localctx, 56, FAScriptParser::RuleClassExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(FAScriptParser::QuotHuaL);
    setState(296);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FAScriptParser::Fn

    || _la == FAScriptParser::Id) {
      setState(288);
      classExprItem();
      setState(293);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FAScriptParser::T__0) {
        setState(289);
        match(FAScriptParser::T__0);
        setState(290);
        classExprItem();
        setState(295);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(298);
    match(FAScriptParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StrongExprBaseContext ------------------------------------------------------------------

FAScriptParser::StrongExprBaseContext::StrongExprBaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::StrongExprBaseContext::Id() {
  return getToken(FAScriptParser::Id, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprBaseContext::ColonColon() {
  return getToken(FAScriptParser::ColonColon, 0);
}

FAScriptParser::LiteralContext* FAScriptParser::StrongExprBaseContext::literal() {
  return getRuleContext<FAScriptParser::LiteralContext>(0);
}

FAScriptParser::QuotExprContext* FAScriptParser::StrongExprBaseContext::quotExpr() {
  return getRuleContext<FAScriptParser::QuotExprContext>(0);
}

FAScriptParser::FnExprContext* FAScriptParser::StrongExprBaseContext::fnExpr() {
  return getRuleContext<FAScriptParser::FnExprContext>(0);
}


size_t FAScriptParser::StrongExprBaseContext::getRuleIndex() const {
  return FAScriptParser::RuleStrongExprBase;
}


antlrcpp::Any FAScriptParser::StrongExprBaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitStrongExprBase(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::StrongExprBaseContext* FAScriptParser::strongExprBase() {
  StrongExprBaseContext *_localctx = _tracker.createInstance<StrongExprBaseContext>(_ctx, getState());
  enterRule(_localctx, 58, FAScriptParser::RuleStrongExprBase);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(307);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FAScriptParser::ColonColon:
      case FAScriptParser::Id: {
        enterOuterAlt(_localctx, 1);
        setState(301);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FAScriptParser::ColonColon) {
          setState(300);
          match(FAScriptParser::ColonColon);
        }
        setState(303);
        match(FAScriptParser::Id);
        break;
      }

      case FAScriptParser::BoolLiteral:
      case FAScriptParser::NumLiteral:
      case FAScriptParser::StringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(304);
        literal();
        break;
      }

      case FAScriptParser::QuotYuanL: {
        enterOuterAlt(_localctx, 3);
        setState(305);
        quotExpr();
        break;
      }

      case FAScriptParser::Fn: {
        enterOuterAlt(_localctx, 4);
        setState(306);
        fnExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StrongExprPrefixContext ------------------------------------------------------------------

FAScriptParser::StrongExprPrefixContext::StrongExprPrefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::StrongExprPrefixContext::SubOp() {
  return getToken(FAScriptParser::SubOp, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprPrefixContext::AddAddOp() {
  return getToken(FAScriptParser::AddAddOp, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprPrefixContext::SubSubOp() {
  return getToken(FAScriptParser::SubSubOp, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprPrefixContext::ReverseOp() {
  return getToken(FAScriptParser::ReverseOp, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprPrefixContext::Exclam() {
  return getToken(FAScriptParser::Exclam, 0);
}


size_t FAScriptParser::StrongExprPrefixContext::getRuleIndex() const {
  return FAScriptParser::RuleStrongExprPrefix;
}


antlrcpp::Any FAScriptParser::StrongExprPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitStrongExprPrefix(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::StrongExprPrefixContext* FAScriptParser::strongExprPrefix() {
  StrongExprPrefixContext *_localctx = _tracker.createInstance<StrongExprPrefixContext>(_ctx, getState());
  enterRule(_localctx, 60, FAScriptParser::RuleStrongExprPrefix);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StrongExprSuffixContext ------------------------------------------------------------------

FAScriptParser::StrongExprSuffixContext::StrongExprSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::StrongExprSuffixContext::AddAddOp() {
  return getToken(FAScriptParser::AddAddOp, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprSuffixContext::SubSubOp() {
  return getToken(FAScriptParser::SubSubOp, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprSuffixContext::QuotYuanL() {
  return getToken(FAScriptParser::QuotYuanL, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprSuffixContext::QuotYuanR() {
  return getToken(FAScriptParser::QuotYuanR, 0);
}

std::vector<FAScriptParser::ExprContext *> FAScriptParser::StrongExprSuffixContext::expr() {
  return getRuleContexts<FAScriptParser::ExprContext>();
}

FAScriptParser::ExprContext* FAScriptParser::StrongExprSuffixContext::expr(size_t i) {
  return getRuleContext<FAScriptParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FAScriptParser::StrongExprSuffixContext::Comma() {
  return getTokens(FAScriptParser::Comma);
}

tree::TerminalNode* FAScriptParser::StrongExprSuffixContext::Comma(size_t i) {
  return getToken(FAScriptParser::Comma, i);
}

tree::TerminalNode* FAScriptParser::StrongExprSuffixContext::QuotFangL() {
  return getToken(FAScriptParser::QuotFangL, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprSuffixContext::QuotFangR() {
  return getToken(FAScriptParser::QuotFangR, 0);
}

std::vector<FAScriptParser::ExprOptContext *> FAScriptParser::StrongExprSuffixContext::exprOpt() {
  return getRuleContexts<FAScriptParser::ExprOptContext>();
}

FAScriptParser::ExprOptContext* FAScriptParser::StrongExprSuffixContext::exprOpt(size_t i) {
  return getRuleContext<FAScriptParser::ExprOptContext>(i);
}

tree::TerminalNode* FAScriptParser::StrongExprSuffixContext::PointPoint() {
  return getToken(FAScriptParser::PointPoint, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprSuffixContext::PointOp() {
  return getToken(FAScriptParser::PointOp, 0);
}

tree::TerminalNode* FAScriptParser::StrongExprSuffixContext::Id() {
  return getToken(FAScriptParser::Id, 0);
}


size_t FAScriptParser::StrongExprSuffixContext::getRuleIndex() const {
  return FAScriptParser::RuleStrongExprSuffix;
}


antlrcpp::Any FAScriptParser::StrongExprSuffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitStrongExprSuffix(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::StrongExprSuffixContext* FAScriptParser::strongExprSuffix() {
  StrongExprSuffixContext *_localctx = _tracker.createInstance<StrongExprSuffixContext>(_ctx, getState());
  enterRule(_localctx, 62, FAScriptParser::RuleStrongExprSuffix);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(335);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FAScriptParser::AddAddOp: {
        enterOuterAlt(_localctx, 1);
        setState(311);
        match(FAScriptParser::AddAddOp);
        break;
      }

      case FAScriptParser::SubSubOp: {
        enterOuterAlt(_localctx, 2);
        setState(312);
        match(FAScriptParser::SubSubOp);
        break;
      }

      case FAScriptParser::QuotYuanL: {
        enterOuterAlt(_localctx, 3);
        setState(313);
        match(FAScriptParser::QuotYuanL);
        setState(322);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FAScriptParser::Fn)
          | (1ULL << FAScriptParser::ReverseOp)
          | (1ULL << FAScriptParser::AddAddOp)
          | (1ULL << FAScriptParser::SubSubOp)
          | (1ULL << FAScriptParser::Exclam)
          | (1ULL << FAScriptParser::SubOp)
          | (1ULL << FAScriptParser::ColonColon)
          | (1ULL << FAScriptParser::QuotYuanL)
          | (1ULL << FAScriptParser::BoolLiteral)
          | (1ULL << FAScriptParser::NumLiteral)
          | (1ULL << FAScriptParser::StringLiteral)
          | (1ULL << FAScriptParser::Id))) != 0)) {
          setState(314);
          expr();
          setState(319);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == FAScriptParser::Comma) {
            setState(315);
            match(FAScriptParser::Comma);
            setState(316);
            expr();
            setState(321);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(324);
        match(FAScriptParser::QuotYuanR);
        break;
      }

      case FAScriptParser::QuotFangL: {
        enterOuterAlt(_localctx, 4);
        setState(325);
        match(FAScriptParser::QuotFangL);

        setState(326);
        exprOpt();
        setState(329);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FAScriptParser::PointPoint) {
          setState(327);
          match(FAScriptParser::PointPoint);
          setState(328);
          exprOpt();
        }
        setState(331);
        match(FAScriptParser::QuotFangR);
        break;
      }

      case FAScriptParser::PointOp: {
        enterOuterAlt(_localctx, 5);
        setState(333);
        match(FAScriptParser::PointOp);
        setState(334);
        match(FAScriptParser::Id);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StrongExprContext ------------------------------------------------------------------

FAScriptParser::StrongExprContext::StrongExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FAScriptParser::StrongExprBaseContext* FAScriptParser::StrongExprContext::strongExprBase() {
  return getRuleContext<FAScriptParser::StrongExprBaseContext>(0);
}

std::vector<FAScriptParser::StrongExprPrefixContext *> FAScriptParser::StrongExprContext::strongExprPrefix() {
  return getRuleContexts<FAScriptParser::StrongExprPrefixContext>();
}

FAScriptParser::StrongExprPrefixContext* FAScriptParser::StrongExprContext::strongExprPrefix(size_t i) {
  return getRuleContext<FAScriptParser::StrongExprPrefixContext>(i);
}

std::vector<FAScriptParser::StrongExprSuffixContext *> FAScriptParser::StrongExprContext::strongExprSuffix() {
  return getRuleContexts<FAScriptParser::StrongExprSuffixContext>();
}

FAScriptParser::StrongExprSuffixContext* FAScriptParser::StrongExprContext::strongExprSuffix(size_t i) {
  return getRuleContext<FAScriptParser::StrongExprSuffixContext>(i);
}


size_t FAScriptParser::StrongExprContext::getRuleIndex() const {
  return FAScriptParser::RuleStrongExpr;
}


antlrcpp::Any FAScriptParser::StrongExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitStrongExpr(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::StrongExprContext* FAScriptParser::strongExpr() {
  StrongExprContext *_localctx = _tracker.createInstance<StrongExprContext>(_ctx, getState());
  enterRule(_localctx, 64, FAScriptParser::RuleStrongExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp))) != 0)) {
      setState(337);
      strongExprPrefix();
      setState(342);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(343);
    strongExprBase();
    setState(347);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::PointOp)
      | (1ULL << FAScriptParser::QuotFangL)
      | (1ULL << FAScriptParser::QuotYuanL))) != 0)) {
      setState(344);
      strongExprSuffix();
      setState(349);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MiddleExprContext ------------------------------------------------------------------

FAScriptParser::MiddleExprContext::MiddleExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FAScriptParser::StrongExprContext *> FAScriptParser::MiddleExprContext::strongExpr() {
  return getRuleContexts<FAScriptParser::StrongExprContext>();
}

FAScriptParser::StrongExprContext* FAScriptParser::MiddleExprContext::strongExpr(size_t i) {
  return getRuleContext<FAScriptParser::StrongExprContext>(i);
}

std::vector<FAScriptParser::AllOp2Context *> FAScriptParser::MiddleExprContext::allOp2() {
  return getRuleContexts<FAScriptParser::AllOp2Context>();
}

FAScriptParser::AllOp2Context* FAScriptParser::MiddleExprContext::allOp2(size_t i) {
  return getRuleContext<FAScriptParser::AllOp2Context>(i);
}


size_t FAScriptParser::MiddleExprContext::getRuleIndex() const {
  return FAScriptParser::RuleMiddleExpr;
}


antlrcpp::Any FAScriptParser::MiddleExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitMiddleExpr(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::MiddleExprContext* FAScriptParser::middleExpr() {
  MiddleExprContext *_localctx = _tracker.createInstance<MiddleExprContext>(_ctx, getState());
  enterRule(_localctx, 66, FAScriptParser::RuleMiddleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(350);
    strongExpr();
    setState(356);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(351);
        allOp2();
        setState(352);
        strongExpr(); 
      }
      setState(358);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

FAScriptParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FAScriptParser::MiddleExprContext *> FAScriptParser::ExprContext::middleExpr() {
  return getRuleContexts<FAScriptParser::MiddleExprContext>();
}

FAScriptParser::MiddleExprContext* FAScriptParser::ExprContext::middleExpr(size_t i) {
  return getRuleContext<FAScriptParser::MiddleExprContext>(i);
}

std::vector<FAScriptParser::AllAssignContext *> FAScriptParser::ExprContext::allAssign() {
  return getRuleContexts<FAScriptParser::AllAssignContext>();
}

FAScriptParser::AllAssignContext* FAScriptParser::ExprContext::allAssign(size_t i) {
  return getRuleContext<FAScriptParser::AllAssignContext>(i);
}


size_t FAScriptParser::ExprContext::getRuleIndex() const {
  return FAScriptParser::RuleExpr;
}


antlrcpp::Any FAScriptParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ExprContext* FAScriptParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 68, FAScriptParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(359);
    middleExpr();
    setState(365);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(360);
        allAssign();
        setState(361);
        middleExpr(); 
      }
      setState(367);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FnStmtContext ------------------------------------------------------------------

FAScriptParser::FnStmtContext::FnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::FnStmtContext::Fn() {
  return getToken(FAScriptParser::Fn, 0);
}

std::vector<tree::TerminalNode *> FAScriptParser::FnStmtContext::Id() {
  return getTokens(FAScriptParser::Id);
}

tree::TerminalNode* FAScriptParser::FnStmtContext::Id(size_t i) {
  return getToken(FAScriptParser::Id, i);
}

tree::TerminalNode* FAScriptParser::FnStmtContext::QuotYuanL() {
  return getToken(FAScriptParser::QuotYuanL, 0);
}

tree::TerminalNode* FAScriptParser::FnStmtContext::QuotYuanR() {
  return getToken(FAScriptParser::QuotYuanR, 0);
}

tree::TerminalNode* FAScriptParser::FnStmtContext::QuotHuaL() {
  return getToken(FAScriptParser::QuotHuaL, 0);
}

tree::TerminalNode* FAScriptParser::FnStmtContext::QuotHuaR() {
  return getToken(FAScriptParser::QuotHuaR, 0);
}

std::vector<FAScriptParser::StmtContext *> FAScriptParser::FnStmtContext::stmt() {
  return getRuleContexts<FAScriptParser::StmtContext>();
}

FAScriptParser::StmtContext* FAScriptParser::FnStmtContext::stmt(size_t i) {
  return getRuleContext<FAScriptParser::StmtContext>(i);
}


size_t FAScriptParser::FnStmtContext::getRuleIndex() const {
  return FAScriptParser::RuleFnStmt;
}


antlrcpp::Any FAScriptParser::FnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitFnStmt(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::FnStmtContext* FAScriptParser::fnStmt() {
  FnStmtContext *_localctx = _tracker.createInstance<FnStmtContext>(_ctx, getState());
  enterRule(_localctx, 70, FAScriptParser::RuleFnStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    match(FAScriptParser::Fn);
    setState(369);
    match(FAScriptParser::Id);
    setState(370);
    match(FAScriptParser::QuotYuanL);
    setState(374);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FAScriptParser::Id) {
      setState(371);
      match(FAScriptParser::Id);
      setState(376);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(377);
    match(FAScriptParser::QuotYuanR);
    setState(378);
    match(FAScriptParser::QuotHuaL);
    setState(382);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::T__0)
      | (1ULL << FAScriptParser::Break)
      | (1ULL << FAScriptParser::Continue)
      | (1ULL << FAScriptParser::Return)
      | (1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::Semi)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(379);
      stmt();
      setState(384);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(385);
    match(FAScriptParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

FAScriptParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::StmtContext::Semi() {
  return getToken(FAScriptParser::Semi, 0);
}

FAScriptParser::FnStmtContext* FAScriptParser::StmtContext::fnStmt() {
  return getRuleContext<FAScriptParser::FnStmtContext>(0);
}

tree::TerminalNode* FAScriptParser::StmtContext::Break() {
  return getToken(FAScriptParser::Break, 0);
}

tree::TerminalNode* FAScriptParser::StmtContext::Continue() {
  return getToken(FAScriptParser::Continue, 0);
}

tree::TerminalNode* FAScriptParser::StmtContext::Return() {
  return getToken(FAScriptParser::Return, 0);
}

FAScriptParser::ExprContext* FAScriptParser::StmtContext::expr() {
  return getRuleContext<FAScriptParser::ExprContext>(0);
}


size_t FAScriptParser::StmtContext::getRuleIndex() const {
  return FAScriptParser::RuleStmt;
}


antlrcpp::Any FAScriptParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::StmtContext* FAScriptParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 72, FAScriptParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      setState(387);
      fnStmt();
      break;
    }

    case 2: {
      setState(389);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FAScriptParser::Return) {
        setState(388);
        match(FAScriptParser::Return);
      }
      setState(392);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FAScriptParser::Fn)
        | (1ULL << FAScriptParser::ReverseOp)
        | (1ULL << FAScriptParser::AddAddOp)
        | (1ULL << FAScriptParser::SubSubOp)
        | (1ULL << FAScriptParser::Exclam)
        | (1ULL << FAScriptParser::SubOp)
        | (1ULL << FAScriptParser::ColonColon)
        | (1ULL << FAScriptParser::QuotYuanL)
        | (1ULL << FAScriptParser::BoolLiteral)
        | (1ULL << FAScriptParser::NumLiteral)
        | (1ULL << FAScriptParser::StringLiteral)
        | (1ULL << FAScriptParser::Id))) != 0)) {
        setState(391);
        expr();
      }
      break;
    }

    case 3: {
      setState(394);
      match(FAScriptParser::Break);
      break;
    }

    case 4: {
      setState(395);
      match(FAScriptParser::Continue);
      break;
    }

    default:
      break;
    }
    setState(398);
    _la = _input->LA(1);
    if (!(_la == FAScriptParser::T__0

    || _la == FAScriptParser::Semi)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

FAScriptParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FAScriptParser::ProgramContext::EOF() {
  return getToken(FAScriptParser::EOF, 0);
}

std::vector<FAScriptParser::StmtContext *> FAScriptParser::ProgramContext::stmt() {
  return getRuleContexts<FAScriptParser::StmtContext>();
}

FAScriptParser::StmtContext* FAScriptParser::ProgramContext::stmt(size_t i) {
  return getRuleContext<FAScriptParser::StmtContext>(i);
}


size_t FAScriptParser::ProgramContext::getRuleIndex() const {
  return FAScriptParser::RuleProgram;
}


antlrcpp::Any FAScriptParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FAScriptVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

FAScriptParser::ProgramContext* FAScriptParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 74, FAScriptParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FAScriptParser::T__0)
      | (1ULL << FAScriptParser::Break)
      | (1ULL << FAScriptParser::Continue)
      | (1ULL << FAScriptParser::Return)
      | (1ULL << FAScriptParser::Fn)
      | (1ULL << FAScriptParser::ReverseOp)
      | (1ULL << FAScriptParser::AddAddOp)
      | (1ULL << FAScriptParser::SubSubOp)
      | (1ULL << FAScriptParser::Exclam)
      | (1ULL << FAScriptParser::SubOp)
      | (1ULL << FAScriptParser::ColonColon)
      | (1ULL << FAScriptParser::Semi)
      | (1ULL << FAScriptParser::QuotYuanL)
      | (1ULL << FAScriptParser::BoolLiteral)
      | (1ULL << FAScriptParser::NumLiteral)
      | (1ULL << FAScriptParser::StringLiteral)
      | (1ULL << FAScriptParser::Id))) != 0)) {
      setState(400);
      stmt();
      setState(405);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(406);
    match(FAScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> FAScriptParser::_decisionToDFA;
atn::PredictionContextCache FAScriptParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN FAScriptParser::_atn;
std::vector<uint16_t> FAScriptParser::_serializedATN;

std::vector<std::string> FAScriptParser::_ruleNames = {
  "shiftLAssign", "shiftRAssign", "allAssign", "shiftLOp", "shiftROp", "ltOp", 
  "ltEqualOp", "gtOp", "gtEqualOp", "equalOp", "notEqualOp", "exprFuncDef", 
  "selfOp2", "compareOp2", "allOp2", "literal", "quotStmtPart", "ifStmt", 
  "whileStmt", "whileStmt2", "forStmt", "forStmt2", "switchStmtPart", "switchStmt", 
  "exprOpt", "quotExpr", "fnExpr", "classExprItem", "classExpr", "strongExprBase", 
  "strongExprPrefix", "strongExprSuffix", "strongExpr", "middleExpr", "expr", 
  "fnStmt", "stmt", "program"
};

std::vector<std::string> FAScriptParser::_literalNames = {
  "", "'\n'", "'break'", "'continue'", "'do'", "'else'", "'for'", "'if'", 
  "'return'", "'switch'", "'when'", "'while'", "'fn'", "'='", "", "", "", 
  "", "", "", "", "", "", "", "", "'~'", "'++'", "'--'", "'!'", "'..'", 
  "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'", "'&'", "'^'", "", "", 
  "", "','", "'::'", "':'", "';'", "'_'", "'['", "']'", "'<'", "'>'", "'{'", 
  "'}'", "'('", "')'"
};

std::vector<std::string> FAScriptParser::_symbolicNames = {
  "", "", "Break", "Continue", "Do", "Else", "For", "If", "Return", "Switch", 
  "When", "While", "Fn", "Assign", "AddAssign", "SubAssign", "StarAssign", 
  "DivAssign", "ModAssign", "OrAssign", "AndAssign", "XorAssign", "StarStarAssign", 
  "AndAndAssign", "OrOrAssign", "ReverseOp", "AddAddOp", "SubSubOp", "Exclam", 
  "PointPoint", "PointOp", "AddOp", "SubOp", "StarOp", "DivOp", "ModOp", 
  "OrOp", "AndOp", "XorOp", "StarStarOp", "AndAndOp", "OrOrOp", "Comma", 
  "ColonColon", "Colon", "Semi", "Underline", "QuotFangL", "QuotFangR", 
  "QuotJianL", "QuotJianR", "QuotHuaL", "QuotHuaR", "QuotYuanL", "QuotYuanR", 
  "BoolLiteral", "NumLiteral", "String1Literal", "String2Literal", "StringLiteral", 
  "Id", "Comment1", "Comment2", "WS"
};

dfa::Vocabulary FAScriptParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> FAScriptParser::_tokenNames;

FAScriptParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x41, 0x19b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x63, 0xa, 0x4, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x8b, 
       0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0xf, 0x5, 0xf, 0x93, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x97, 
       0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 
       0x9d, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xa0, 0xb, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xac, 0xa, 0x13, 0xc, 
       0x13, 0xe, 0x13, 0xaf, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 
       0xb3, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 
       0x14, 0xb9, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0xbc, 0xb, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xc3, 
       0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xc6, 0xb, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xd3, 0xa, 0x16, 
       0xc, 0x16, 0xe, 0x16, 0xd6, 0xb, 0x16, 0x5, 0x16, 0xd8, 0xa, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xdc, 0xa, 0x16, 0xc, 0x16, 0xe, 
       0x16, 0xdf, 0xb, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0xe9, 0xa, 
       0x17, 0xc, 0x17, 0xe, 0x17, 0xec, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0xf3, 0xa, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x7, 0x19, 0xfc, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0xff, 0xb, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x5, 0x1a, 0x104, 0xa, 0x1a, 
       0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x7, 0x1c, 0x10d, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x110, 
       0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x115, 0xa, 
       0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x118, 0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x120, 0xa, 
       0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x126, 
       0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x129, 0xb, 0x1e, 0x5, 0x1e, 0x12b, 
       0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x5, 0x1f, 0x130, 0xa, 
       0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x136, 
       0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x140, 0xa, 0x21, 0xc, 
       0x21, 0xe, 0x21, 0x143, 0xb, 0x21, 0x5, 0x21, 0x145, 0xa, 0x21, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x14c, 
       0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
       0x152, 0xa, 0x21, 0x3, 0x22, 0x7, 0x22, 0x155, 0xa, 0x22, 0xc, 0x22, 
       0xe, 0x22, 0x158, 0xb, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x15c, 
       0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x15f, 0xb, 0x22, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x165, 0xa, 0x23, 0xc, 0x23, 
       0xe, 0x23, 0x168, 0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
       0x24, 0x7, 0x24, 0x16e, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x171, 0xb, 
       0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x177, 
       0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x17a, 0xb, 0x25, 0x3, 0x25, 0x3, 
       0x25, 0x3, 0x25, 0x7, 0x25, 0x17f, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
       0x182, 0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x5, 
       0x26, 0x188, 0xa, 0x26, 0x3, 0x26, 0x5, 0x26, 0x18b, 0xa, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x5, 0x26, 0x18f, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 
       0x3, 0x27, 0x7, 0x27, 0x194, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x197, 
       0xb, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x2, 0x2, 0x28, 0x2, 
       0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
       0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
       0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
       0x48, 0x4a, 0x4c, 0x2, 0x5, 0x4, 0x2, 0x39, 0x3a, 0x3d, 0x3d, 0x4, 
       0x2, 0x1b, 0x1e, 0x22, 0x22, 0x4, 0x2, 0x3, 0x3, 0x2f, 0x2f, 0x2, 
       0x1bb, 0x2, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x51, 0x3, 0x2, 0x2, 0x2, 
       0x6, 0x62, 0x3, 0x2, 0x2, 0x2, 0x8, 0x64, 0x3, 0x2, 0x2, 0x2, 0xa, 
       0x67, 0x3, 0x2, 0x2, 0x2, 0xc, 0x6a, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6c, 
       0x3, 0x2, 0x2, 0x2, 0x10, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x71, 0x3, 
       0x2, 0x2, 0x2, 0x14, 0x74, 0x3, 0x2, 0x2, 0x2, 0x16, 0x77, 0x3, 0x2, 
       0x2, 0x2, 0x18, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x8a, 0x3, 0x2, 0x2, 
       0x2, 0x1c, 0x92, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x96, 0x3, 0x2, 0x2, 0x2, 
       0x20, 0x98, 0x3, 0x2, 0x2, 0x2, 0x22, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x24, 
       0xa3, 0x3, 0x2, 0x2, 0x2, 0x26, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x28, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0x2a, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xe2, 0x3, 
       0x2, 0x2, 0x2, 0x2e, 0xef, 0x3, 0x2, 0x2, 0x2, 0x30, 0xf7, 0x3, 0x2, 
       0x2, 0x2, 0x32, 0x103, 0x3, 0x2, 0x2, 0x2, 0x34, 0x105, 0x3, 0x2, 
       0x2, 0x2, 0x36, 0x109, 0x3, 0x2, 0x2, 0x2, 0x38, 0x11f, 0x3, 0x2, 
       0x2, 0x2, 0x3a, 0x121, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x135, 0x3, 0x2, 
       0x2, 0x2, 0x3e, 0x137, 0x3, 0x2, 0x2, 0x2, 0x40, 0x151, 0x3, 0x2, 
       0x2, 0x2, 0x42, 0x156, 0x3, 0x2, 0x2, 0x2, 0x44, 0x160, 0x3, 0x2, 
       0x2, 0x2, 0x46, 0x169, 0x3, 0x2, 0x2, 0x2, 0x48, 0x172, 0x3, 0x2, 
       0x2, 0x2, 0x4a, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x195, 0x3, 0x2, 
       0x2, 0x2, 0x4e, 0x4f, 0x5, 0x8, 0x5, 0x2, 0x4f, 0x50, 0x7, 0xf, 0x2, 
       0x2, 0x50, 0x3, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x5, 0xa, 0x6, 0x2, 
       0x52, 0x53, 0x7, 0xf, 0x2, 0x2, 0x53, 0x5, 0x3, 0x2, 0x2, 0x2, 0x54, 
       0x63, 0x7, 0xf, 0x2, 0x2, 0x55, 0x63, 0x7, 0x10, 0x2, 0x2, 0x56, 
       0x63, 0x7, 0x11, 0x2, 0x2, 0x57, 0x63, 0x7, 0x12, 0x2, 0x2, 0x58, 
       0x63, 0x7, 0x18, 0x2, 0x2, 0x59, 0x63, 0x7, 0x13, 0x2, 0x2, 0x5a, 
       0x63, 0x7, 0x14, 0x2, 0x2, 0x5b, 0x63, 0x7, 0x16, 0x2, 0x2, 0x5c, 
       0x63, 0x7, 0x15, 0x2, 0x2, 0x5d, 0x63, 0x7, 0x17, 0x2, 0x2, 0x5e, 
       0x63, 0x7, 0x19, 0x2, 0x2, 0x5f, 0x63, 0x7, 0x1a, 0x2, 0x2, 0x60, 
       0x63, 0x5, 0x2, 0x2, 0x2, 0x61, 0x63, 0x5, 0x4, 0x3, 0x2, 0x62, 0x54, 
       0x3, 0x2, 0x2, 0x2, 0x62, 0x55, 0x3, 0x2, 0x2, 0x2, 0x62, 0x56, 0x3, 
       0x2, 0x2, 0x2, 0x62, 0x57, 0x3, 0x2, 0x2, 0x2, 0x62, 0x58, 0x3, 0x2, 
       0x2, 0x2, 0x62, 0x59, 0x3, 0x2, 0x2, 0x2, 0x62, 0x5a, 0x3, 0x2, 0x2, 
       0x2, 0x62, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x62, 0x5c, 0x3, 0x2, 0x2, 0x2, 
       0x62, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x62, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x62, 
       0x5f, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x61, 
       0x3, 0x2, 0x2, 0x2, 0x63, 0x7, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 
       0x33, 0x2, 0x2, 0x65, 0x66, 0x7, 0x33, 0x2, 0x2, 0x66, 0x9, 0x3, 
       0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x34, 0x2, 0x2, 0x68, 0x69, 0x7, 
       0x34, 0x2, 0x2, 0x69, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x33, 
       0x2, 0x2, 0x6b, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x33, 0x2, 
       0x2, 0x6d, 0x6e, 0x7, 0xf, 0x2, 0x2, 0x6e, 0xf, 0x3, 0x2, 0x2, 0x2, 
       0x6f, 0x70, 0x7, 0x34, 0x2, 0x2, 0x70, 0x11, 0x3, 0x2, 0x2, 0x2, 
       0x71, 0x72, 0x7, 0x34, 0x2, 0x2, 0x72, 0x73, 0x7, 0xf, 0x2, 0x2, 
       0x73, 0x13, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0xf, 0x2, 0x2, 0x75, 
       0x76, 0x7, 0xf, 0x2, 0x2, 0x76, 0x15, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 
       0x7, 0x1e, 0x2, 0x2, 0x78, 0x79, 0x7, 0xf, 0x2, 0x2, 0x79, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0xf, 0x2, 0x2, 0x7b, 0x7c, 0x7, 
       0x34, 0x2, 0x2, 0x7c, 0x19, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x8b, 0x7, 
       0x21, 0x2, 0x2, 0x7e, 0x8b, 0x7, 0x22, 0x2, 0x2, 0x7f, 0x8b, 0x7, 
       0x23, 0x2, 0x2, 0x80, 0x8b, 0x7, 0x24, 0x2, 0x2, 0x81, 0x8b, 0x7, 
       0x29, 0x2, 0x2, 0x82, 0x8b, 0x7, 0x25, 0x2, 0x2, 0x83, 0x8b, 0x7, 
       0x27, 0x2, 0x2, 0x84, 0x8b, 0x7, 0x26, 0x2, 0x2, 0x85, 0x8b, 0x7, 
       0x28, 0x2, 0x2, 0x86, 0x8b, 0x7, 0x2a, 0x2, 0x2, 0x87, 0x8b, 0x7, 
       0x2b, 0x2, 0x2, 0x88, 0x8b, 0x5, 0x8, 0x5, 0x2, 0x89, 0x8b, 0x5, 
       0xa, 0x6, 0x2, 0x8a, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x7e, 0x3, 0x2, 
       0x2, 0x2, 0x8a, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x80, 0x3, 0x2, 0x2, 
       0x2, 0x8a, 0x81, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x82, 0x3, 0x2, 0x2, 0x2, 
       0x8a, 0x83, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x84, 0x3, 0x2, 0x2, 0x2, 0x8a, 
       0x85, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x87, 
       0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x89, 0x3, 
       0x2, 0x2, 0x2, 0x8b, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x93, 0x5, 0xc, 
       0x7, 0x2, 0x8d, 0x93, 0x5, 0xe, 0x8, 0x2, 0x8e, 0x93, 0x5, 0x10, 
       0x9, 0x2, 0x8f, 0x93, 0x5, 0x12, 0xa, 0x2, 0x90, 0x93, 0x5, 0x14, 
       0xb, 0x2, 0x91, 0x93, 0x5, 0x16, 0xc, 0x2, 0x92, 0x8c, 0x3, 0x2, 
       0x2, 0x2, 0x92, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x92, 0x8e, 0x3, 0x2, 0x2, 
       0x2, 0x92, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 
       0x92, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x94, 
       0x97, 0x5, 0x1a, 0xe, 0x2, 0x95, 0x97, 0x5, 0x1c, 0xf, 0x2, 0x96, 
       0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x1f, 
       0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x9, 0x2, 0x2, 0x2, 0x99, 0x21, 0x3, 
       0x2, 0x2, 0x2, 0x9a, 0x9e, 0x7, 0x35, 0x2, 0x2, 0x9b, 0x9d, 0x5, 
       0x4a, 0x26, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 
       0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 
       0x2, 0x2, 0x9f, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 
       0x2, 0xa1, 0xa2, 0x7, 0x36, 0x2, 0x2, 0xa2, 0x23, 0x3, 0x2, 0x2, 
       0x2, 0xa3, 0xa4, 0x7, 0x9, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x46, 0x24, 
       0x2, 0xa5, 0xad, 0x5, 0x22, 0x12, 0x2, 0xa6, 0xa7, 0x7, 0x7, 0x2, 
       0x2, 0xa7, 0xa8, 0x7, 0x9, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x46, 0x24, 
       0x2, 0xa9, 0xaa, 0x5, 0x22, 0x12, 0x2, 0xaa, 0xac, 0x3, 0x2, 0x2, 
       0x2, 0xab, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 0x2, 
       0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 
       0xb2, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 
       0x7, 0x7, 0x2, 0x2, 0xb1, 0xb3, 0x5, 0x22, 0x12, 0x2, 0xb2, 0xb0, 
       0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x25, 0x3, 
       0x2, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0xd, 0x2, 0x2, 0xb5, 0xb6, 0x5, 0x46, 
       0x24, 0x2, 0xb6, 0xba, 0x7, 0x35, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x4a, 
       0x26, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbc, 0x3, 0x2, 
       0x2, 0x2, 0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 
       0x2, 0xbb, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 
       0xbd, 0xbe, 0x7, 0x36, 0x2, 0x2, 0xbe, 0x27, 0x3, 0x2, 0x2, 0x2, 
       0xbf, 0xc0, 0x7, 0x6, 0x2, 0x2, 0xc0, 0xc4, 0x7, 0x35, 0x2, 0x2, 
       0xc1, 0xc3, 0x5, 0x4a, 0x26, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 0x2, 
       0xc3, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc4, 
       0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 
       0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x36, 0x2, 0x2, 0xc8, 0xc9, 
       0x7, 0xd, 0x2, 0x2, 0xc9, 0xca, 0x5, 0x46, 0x24, 0x2, 0xca, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x8, 0x2, 0x2, 0xcc, 0xcd, 0x5, 
       0x4a, 0x26, 0x2, 0xcd, 0xce, 0x5, 0x46, 0x24, 0x2, 0xce, 0xd7, 0x7, 
       0x2f, 0x2, 0x2, 0xcf, 0xd4, 0x5, 0x46, 0x24, 0x2, 0xd0, 0xd1, 0x7, 
       0x2c, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x46, 0x24, 0x2, 0xd2, 0xd0, 0x3, 
       0x2, 0x2, 0x2, 0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 
       0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 
       0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xcf, 0x3, 0x2, 0x2, 0x2, 
       0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 
       0xdd, 0x7, 0x35, 0x2, 0x2, 0xda, 0xdc, 0x5, 0x4a, 0x26, 0x2, 0xdb, 
       0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 
       0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe0, 0x3, 
       0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x36, 
       0x2, 0x2, 0xe1, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x8, 0x2, 
       0x2, 0xe3, 0xe4, 0x7, 0x3e, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x2e, 0x2, 
       0x2, 0xe5, 0xe6, 0x5, 0x46, 0x24, 0x2, 0xe6, 0xea, 0x7, 0x35, 0x2, 
       0x2, 0xe7, 0xe9, 0x5, 0x4a, 0x26, 0x2, 0xe8, 0xe7, 0x3, 0x2, 0x2, 
       0x2, 0xe9, 0xec, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 
       0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xed, 0x3, 0x2, 0x2, 0x2, 0xec, 
       0xea, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x7, 0x36, 0x2, 0x2, 0xee, 
       0x2d, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf2, 0x5, 0x46, 0x24, 0x2, 0xf0, 
       0xf1, 0x7, 0xc, 0x2, 0x2, 0xf1, 0xf3, 0x5, 0x46, 0x24, 0x2, 0xf2, 
       0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 
       0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x18, 0xd, 0x2, 0xf5, 0xf6, 
       0x5, 0x4a, 0x26, 0x2, 0xf6, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 
       0x7, 0xb, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x46, 0x24, 0x2, 0xf9, 0xfd, 
       0x7, 0x35, 0x2, 0x2, 0xfa, 0xfc, 0x5, 0x2e, 0x18, 0x2, 0xfb, 0xfa, 
       0x3, 0x2, 0x2, 0x2, 0xfc, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 
       0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x100, 0x3, 
       0x2, 0x2, 0x2, 0xff, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x7, 
       0x36, 0x2, 0x2, 0x101, 0x31, 0x3, 0x2, 0x2, 0x2, 0x102, 0x104, 0x5, 
       0x46, 0x24, 0x2, 0x103, 0x102, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 
       0x3, 0x2, 0x2, 0x2, 0x104, 0x33, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 
       0x7, 0x37, 0x2, 0x2, 0x106, 0x107, 0x5, 0x46, 0x24, 0x2, 0x107, 0x108, 
       0x7, 0x38, 0x2, 0x2, 0x108, 0x35, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 
       0x7, 0xe, 0x2, 0x2, 0x10a, 0x10e, 0x7, 0x37, 0x2, 0x2, 0x10b, 0x10d, 
       0x7, 0x3e, 0x2, 0x2, 0x10c, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 
       0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 
       0x3, 0x2, 0x2, 0x2, 0x10f, 0x111, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 
       0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x7, 0x38, 0x2, 0x2, 0x112, 0x116, 
       0x7, 0x35, 0x2, 0x2, 0x113, 0x115, 0x5, 0x4a, 0x26, 0x2, 0x114, 0x113, 
       0x3, 0x2, 0x2, 0x2, 0x115, 0x118, 0x3, 0x2, 0x2, 0x2, 0x116, 0x114, 
       0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x119, 
       0x3, 0x2, 0x2, 0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 
       0x7, 0x36, 0x2, 0x2, 0x11a, 0x37, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 
       0x7, 0x3e, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0xf, 0x2, 0x2, 0x11d, 0x120, 
       0x5, 0x44, 0x23, 0x2, 0x11e, 0x120, 0x5, 0x48, 0x25, 0x2, 0x11f, 
       0x11b, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 
       0x39, 0x3, 0x2, 0x2, 0x2, 0x121, 0x12a, 0x7, 0x35, 0x2, 0x2, 0x122, 
       0x127, 0x5, 0x38, 0x1d, 0x2, 0x123, 0x124, 0x7, 0x3, 0x2, 0x2, 0x124, 
       0x126, 0x5, 0x38, 0x1d, 0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x126, 
       0x129, 0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 0x127, 
       0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x129, 
       0x127, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x122, 0x3, 0x2, 0x2, 0x2, 0x12a, 
       0x12b, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 
       0x12d, 0x7, 0x36, 0x2, 0x2, 0x12d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x12e, 
       0x130, 0x7, 0x2d, 0x2, 0x2, 0x12f, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12f, 
       0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x3, 0x2, 0x2, 0x2, 0x131, 
       0x136, 0x7, 0x3e, 0x2, 0x2, 0x132, 0x136, 0x5, 0x20, 0x11, 0x2, 0x133, 
       0x136, 0x5, 0x34, 0x1b, 0x2, 0x134, 0x136, 0x5, 0x36, 0x1c, 0x2, 
       0x135, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x135, 0x132, 0x3, 0x2, 0x2, 0x2, 
       0x135, 0x133, 0x3, 0x2, 0x2, 0x2, 0x135, 0x134, 0x3, 0x2, 0x2, 0x2, 
       0x136, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x9, 0x3, 0x2, 0x2, 
       0x138, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x139, 0x152, 0x7, 0x1c, 0x2, 0x2, 
       0x13a, 0x152, 0x7, 0x1d, 0x2, 0x2, 0x13b, 0x144, 0x7, 0x37, 0x2, 
       0x2, 0x13c, 0x141, 0x5, 0x46, 0x24, 0x2, 0x13d, 0x13e, 0x7, 0x2c, 
       0x2, 0x2, 0x13e, 0x140, 0x5, 0x46, 0x24, 0x2, 0x13f, 0x13d, 0x3, 
       0x2, 0x2, 0x2, 0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 
       0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x145, 0x3, 
       0x2, 0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x13c, 0x3, 
       0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 
       0x2, 0x2, 0x2, 0x146, 0x152, 0x7, 0x38, 0x2, 0x2, 0x147, 0x148, 0x7, 
       0x31, 0x2, 0x2, 0x148, 0x14b, 0x5, 0x32, 0x1a, 0x2, 0x149, 0x14a, 
       0x7, 0x1f, 0x2, 0x2, 0x14a, 0x14c, 0x5, 0x32, 0x1a, 0x2, 0x14b, 0x149, 
       0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 
       0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x7, 0x32, 0x2, 0x2, 0x14e, 0x152, 
       0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x7, 0x20, 0x2, 0x2, 0x150, 0x152, 
       0x7, 0x3e, 0x2, 0x2, 0x151, 0x139, 0x3, 0x2, 0x2, 0x2, 0x151, 0x13a, 
       0x3, 0x2, 0x2, 0x2, 0x151, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x151, 0x147, 
       0x3, 0x2, 0x2, 0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x152, 0x41, 
       0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 0x5, 0x3e, 0x20, 0x2, 0x154, 0x153, 
       0x3, 0x2, 0x2, 0x2, 0x155, 0x158, 0x3, 0x2, 0x2, 0x2, 0x156, 0x154, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x3, 0x2, 0x2, 0x2, 0x157, 0x159, 
       0x3, 0x2, 0x2, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15d, 
       0x5, 0x3c, 0x1f, 0x2, 0x15a, 0x15c, 0x5, 0x40, 0x21, 0x2, 0x15b, 
       0x15a, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15d, 
       0x15b, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15e, 
       0x43, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x160, 
       0x166, 0x5, 0x42, 0x22, 0x2, 0x161, 0x162, 0x5, 0x1e, 0x10, 0x2, 
       0x162, 0x163, 0x5, 0x42, 0x22, 0x2, 0x163, 0x165, 0x3, 0x2, 0x2, 
       0x2, 0x164, 0x161, 0x3, 0x2, 0x2, 0x2, 0x165, 0x168, 0x3, 0x2, 0x2, 
       0x2, 0x166, 0x164, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 0x2, 
       0x2, 0x167, 0x45, 0x3, 0x2, 0x2, 0x2, 0x168, 0x166, 0x3, 0x2, 0x2, 
       0x2, 0x169, 0x16f, 0x5, 0x44, 0x23, 0x2, 0x16a, 0x16b, 0x5, 0x6, 
       0x4, 0x2, 0x16b, 0x16c, 0x5, 0x44, 0x23, 0x2, 0x16c, 0x16e, 0x3, 
       0x2, 0x2, 0x2, 0x16d, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x171, 0x3, 
       0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x3, 
       0x2, 0x2, 0x2, 0x170, 0x47, 0x3, 0x2, 0x2, 0x2, 0x171, 0x16f, 0x3, 
       0x2, 0x2, 0x2, 0x172, 0x173, 0x7, 0xe, 0x2, 0x2, 0x173, 0x174, 0x7, 
       0x3e, 0x2, 0x2, 0x174, 0x178, 0x7, 0x37, 0x2, 0x2, 0x175, 0x177, 
       0x7, 0x3e, 0x2, 0x2, 0x176, 0x175, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17a, 
       0x3, 0x2, 0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 
       0x3, 0x2, 0x2, 0x2, 0x179, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 
       0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x7, 0x38, 0x2, 0x2, 0x17c, 0x180, 
       0x7, 0x35, 0x2, 0x2, 0x17d, 0x17f, 0x5, 0x4a, 0x26, 0x2, 0x17e, 0x17d, 
       0x3, 0x2, 0x2, 0x2, 0x17f, 0x182, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 
       0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x3, 0x2, 0x2, 0x2, 0x181, 0x183, 
       0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 
       0x7, 0x36, 0x2, 0x2, 0x184, 0x49, 0x3, 0x2, 0x2, 0x2, 0x185, 0x18f, 
       0x5, 0x48, 0x25, 0x2, 0x186, 0x188, 0x7, 0xa, 0x2, 0x2, 0x187, 0x186, 
       0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18a, 
       0x3, 0x2, 0x2, 0x2, 0x189, 0x18b, 0x5, 0x46, 0x24, 0x2, 0x18a, 0x189, 
       0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18f, 
       0x3, 0x2, 0x2, 0x2, 0x18c, 0x18f, 0x7, 0x4, 0x2, 0x2, 0x18d, 0x18f, 
       0x7, 0x5, 0x2, 0x2, 0x18e, 0x185, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x187, 
       0x3, 0x2, 0x2, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18d, 
       0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 
       0x9, 0x4, 0x2, 0x2, 0x191, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x192, 0x194, 
       0x5, 0x4a, 0x26, 0x2, 0x193, 0x192, 0x3, 0x2, 0x2, 0x2, 0x194, 0x197, 
       0x3, 0x2, 0x2, 0x2, 0x195, 0x193, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 
       0x3, 0x2, 0x2, 0x2, 0x196, 0x198, 0x3, 0x2, 0x2, 0x2, 0x197, 0x195, 
       0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x7, 0x2, 0x2, 0x3, 0x199, 0x4d, 
       0x3, 0x2, 0x2, 0x2, 0x27, 0x62, 0x8a, 0x92, 0x96, 0x9e, 0xad, 0xb2, 
       0xba, 0xc4, 0xd4, 0xd7, 0xdd, 0xea, 0xf2, 0xfd, 0x103, 0x10e, 0x116, 
       0x11f, 0x127, 0x12a, 0x12f, 0x135, 0x141, 0x144, 0x14b, 0x151, 0x156, 
       0x15d, 0x166, 0x16f, 0x178, 0x180, 0x187, 0x18a, 0x18e, 0x195, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

FAScriptParser::Initializer FAScriptParser::_init;
