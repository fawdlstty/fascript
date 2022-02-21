#ifndef __FASVISITOR_HPP__
#define __FASVISITOR_HPP__



#include "_AntlrGens/FAScriptBaseVisitor.h"



namespace fas {
class FASVisitor: public FAScriptBaseVisitor {
public:
	antlrcpp::Any visitProgram (FAScriptParser::ProgramContext *ctx) override;
};
}



#endif //__FASVISITOR_HPP__
