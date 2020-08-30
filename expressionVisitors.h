#ifndef EXPR_VISITOR_H
#define EXPR_VISITOR_H

class FormulaBinaryExp;
class FormulaVar;

class FormulaVisitor
{
    public:
        virtual void visit(FormulaVar* fVar){};
        virtual void visit(FormulaBinaryExp* fBinExp){};
};

#include "expressionAST.h"

class formulaCommutatorVisitor : public FormulaVisitor
{
    void visit(FormulaVar* fVar)
    {
        //
    }
    void visit(FormulaBinaryExp* fBinExp)
    {
        //
        fBinExp->prettyPrinter();
        std::cout<<"\n";
        fBinExp->changeOperator();
        fBinExp->prettyPrinter();
        std::cout<<"\n";
        fBinExp->swapOperands();
        fBinExp->prettyPrinter();
        std::cout<<"\n";
    }
};

#endif //EXPR_VISITOR_H