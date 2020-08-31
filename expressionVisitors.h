#ifndef EXPR_VISITOR_H
#define EXPR_VISITOR_H

class FormulaBinaryExp;
class FormulaVar;
class Formula;

class FormulaVisitor
{
    public:
        virtual void visit(FormulaVar* fVar){};
        virtual void visit(FormulaBinaryExp* fBinExp){};
};

#include "expressionAST.h"

class formulaCommutatorVisitor : public FormulaVisitor
{
    private:
        std::string op;
    public:
    formulaCommutatorVisitor(std::string op)
    {
        this->op = op;
    }
    void visit(FormulaVar* fVar)
    {
        std::cout<<"\n Visiting node: ";
        fVar->prettyPrinter();
        std::cout<<"\n";
    }
    void visit(FormulaBinaryExp* fBinExp)
    {
        std::cout<<"\n Visiting node: ";
        fBinExp->prettyPrinter();
        std::cout<<"\n";

        Formula* temp = NULL;
        fBinExp->getLeft()->accept(this);
        if(fBinExp->getOp() == op)
        {
            temp = fBinExp->getLeft();
            fBinExp->setLeft(fBinExp->getRight());
            fBinExp->setRight(temp);
            std::cout<<"In \n";
            fBinExp->prettyPrinter();
        }
        fBinExp->getRight()->accept(this);
    }
};

class formulaPrinterVisitor : public FormulaVisitor
{
    public:
        void visit(FormulaVar* fVar)
        {
            std::cout<<"\n Printer Visiting node: ";
            fVar->prettyPrinter();
            std::cout<<"\n";
            fVar->prettyPrinter();
        }
        void visit(FormulaBinaryExp* fBinExp)
        {
            std::cout<<"\n Printer Visiting node: ";
            fBinExp->prettyPrinter();
            std::cout<<"\n";

            std::cout<<"(";
            fBinExp->getLeft()->accept(this);
            std::cout<<fBinExp->getOp();
            fBinExp->getRight()->accept(this);
            std::cout<<")";
        }
};

#endif //EXPR_VISITOR_H