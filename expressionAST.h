#ifndef EXPR_AST_H
#define EXPR_AST_H

#include <iostream>

#include "expressionVisitors.h"

class FormulaBinaryExp;
class FormulaVar;
class FormulaVisitor;

class Formula
{
    public:
        virtual Formula* accept(FormulaVisitor* visitor){};
        virtual void accept2(FormulaVisitor* visitor){};
        virtual void prettyPrinter(){};
};

class FormulaVar : public Formula
{
    private:
        std::string var;
    public:
        FormulaVar(std::string var)//Constructor
        {
            this->var = var;
        }
        Formula* accept(FormulaVisitor visitor)
        {
            visitor.visit(this);
        }
        void accept2(FormulaVisitor* visitor)
        {
            visitor->visitPrint(this);
        }
        void prettyPrinter() //Printer
        {
            std::cout<<var;
        }
        std::string getVar()
        {
            return var;
        }
};

class FormulaBinaryExp : public Formula
{
    private:
        Formula *left;
        Formula *right;
        std::string op;
    public:
        FormulaBinaryExp(Formula* left, Formula* right, std::string op)
        {
            this->left = left;
            this->right = right;
            this->op = op;
        }
        Formula* accept(FormulaVisitor* visitor)
        {
            return visitor->visit(this);
        }
        void accept2(FormulaVisitor* visitor)
        {
            visitor->visitPrint(this);
        }
        void prettyPrinter() //Printer
        {
            std::cout<<"(";
            left->prettyPrinter();
            std::cout<<op;
            right->prettyPrinter();
            std::cout<<")";
        }
        
        Formula* getLeft()
        {
            return left;
        }
        void setLeft(Formula* right)
        {
            this->left = right;
        }
        Formula* getRight()
        {
            return right;
        }
        void setRight(Formula* left)
        {
            this->right = left;
        }
        std::string getOp()
        {
            return op;
        }
        void setOp(std::string op)
        {
            this->op = op;
        }
};

#endif //EXPR_AST_H