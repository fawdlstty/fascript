
// Generated from FAScript.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FAScriptLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, Break = 2, Continue = 3, Do = 4, Else = 5, For = 6, If = 7, 
    Return = 8, Switch = 9, When = 10, While = 11, Fn = 12, Assign = 13, 
    AddAssign = 14, SubAssign = 15, StarAssign = 16, DivAssign = 17, ModAssign = 18, 
    OrAssign = 19, AndAssign = 20, XorAssign = 21, StarStarAssign = 22, 
    AndAndAssign = 23, OrOrAssign = 24, ReverseOp = 25, AddAddOp = 26, SubSubOp = 27, 
    Exclam = 28, PointPoint = 29, PointOp = 30, AddOp = 31, SubOp = 32, 
    StarOp = 33, DivOp = 34, ModOp = 35, OrOp = 36, AndOp = 37, XorOp = 38, 
    StarStarOp = 39, AndAndOp = 40, OrOrOp = 41, Comma = 42, ColonColon = 43, 
    Colon = 44, Semi = 45, Underline = 46, QuotFangL = 47, QuotFangR = 48, 
    QuotJianL = 49, QuotJianR = 50, QuotHuaL = 51, QuotHuaR = 52, QuotYuanL = 53, 
    QuotYuanR = 54, BoolLiteral = 55, NumLiteral = 56, String1Literal = 57, 
    String2Literal = 58, StringLiteral = 59, Id = 60, Comment1 = 61, Comment2 = 62, 
    WS = 63
  };

  explicit FAScriptLexer(antlr4::CharStream *input);
  ~FAScriptLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

