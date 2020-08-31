#ifndef EXPR_AST_H
#define EXPR_AST_H

#include <iostream>

#include "expressionVisitors.h"

class FormulaBinaryExp;
class FormulaVar;

class Formula
{
    public:
        virtual void accept(FormulaVisitor* visitor){};
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
        void accept(FormulaVisitor visitor)
        {
            visitor.visit(this);
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
        void accept(FormulaVisitor* visitor)
        {
            visitor->visit(this);
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
        void setLeft(Formula* formula)
        {
            this->left = formula;
        }
        Formula* getRight()
        {
            return right;
        }
        void setRight(Formula* formula)
        {
            this->right = formula;
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