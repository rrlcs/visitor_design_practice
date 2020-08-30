#ifndef EXPR_VISITOR_H
#define EXPR_VISITOR_H

class FormulaBinaryExp;
class FormulaVar;
class Formula;

class FormulaVisitor
{
    public:
        virtual Formula* visit(FormulaVar* fVar){};
        virtual Formula* visit(FormulaBinaryExp* fBinExp){};
};

#include "expressionAST.h"

class formulaCommutatorVisitor : public FormulaVisitor
{
    private:
        Formula* temp;
        std::string op;
    public:
    formulaCommutatorVisitor(std::string op)
    {
        this->op = op;
    }
    Formula* visit(FormulaVar* fVar)
    {
        //
        
    }
    Formula* visit(FormulaBinaryExp* fBinExp)
    {
        fBinExp->getLeft()->accept(this);
        if(fBinExp->getOp() == op)
        {
            temp = fBinExp->getLeft();
            fBinExp->setLeft(fBinExp->getRight());
            fBinExp->setRight(temp);
        }
        fBinExp->getRight()->accept(this);

        return fBinExp;
    }
};

#endif //EXPR_VISITOR_H