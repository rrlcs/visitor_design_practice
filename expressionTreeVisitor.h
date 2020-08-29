#include <iostream>

class FormulaBinaryExp;
class FormulaVar;

class FormulaVisitor
{
    public:
        virtual void visit(FormulaVar* fVar){};
        virtual void visit(FormulaBinaryExp* fBinExp){};
};

class Formula
{
    public:
        virtual void accept(FormulaVisitor* visitor){};
        virtual void prettyPrinter(){};
        virtual void changeOperator(){};
        virtual void swapOperands(){};
};

//FormulaBinaryExp* temp = new FormulaBinaryExp(NULL, NULL, "");
Formula* temp = new Formula();

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
            //std::cout << "in accept" << std::endl;
            visitor->visit(this);
            //std::cout << "in accept" << std::endl;
        }
        void prettyPrinter() //Printer
        {
            std::cout<<"(";
            left->prettyPrinter();
            std::cout<<op;
            right->prettyPrinter();
            std::cout<<")";
        }
        void changeOperator()
        {
            left->changeOperator();
            if(op == "+")
            {
                op = "-";
            }
            right->changeOperator();
        }
        void swapOperands()
        {
            left->swapOperands();
            if(op == "&&")
            {
                temp = left;
                left = right;
                right = temp;
            }
            right->swapOperands();
        }

};

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