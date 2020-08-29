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

int main()
{
    FormulaVar *p = new FormulaVar("p");
    FormulaVar *q = new FormulaVar("q");
    FormulaVar *r = new FormulaVar("r");
    p->prettyPrinter();
    q->prettyPrinter();

    std::cout<<"\n";
    FormulaBinaryExp *pPlusQ = new FormulaBinaryExp(p,q,"+");
    pPlusQ->prettyPrinter();

    std::cout<<"\n";
    FormulaBinaryExp *be2 = new FormulaBinaryExp(r,pPlusQ,"&&");
    be2->prettyPrinter();
    std::cout<<"\n";

    FormulaBinaryExp *be3 = new FormulaBinaryExp(be2,pPlusQ,"XOR");
    be3->prettyPrinter();
    std::cout<<"\n";

    formulaCommutatorVisitor* visitor = new formulaCommutatorVisitor();
    be3->accept(visitor);
}

// class LeafPrinterVisitor : public FormulaVisitor
// {
//     public:
//         void visit(FormulaVar &leaf)
//         {
//             //visit leaf node;
//             std::cout << leaf.val;
//         }
//         void visit(FormulaBinaryExp * root)
//         {
//             //visit expression;
//             //std::cout << "visite expr" << std::endl;
//             if(root)
//             {
//                 visit(root->left);
//                 if(root->op.size())
//                 {
//                     std::cout << root->op;
//                 }
//                 else
//                 {
//                     //std::cout << root->fv.val;
//                     visit(root->fv);
//                 }
//                 visit(root->right);
//             }
//         }
// };

// void inorder_traversal(FormulaBinaryExp * root)
// {
//     /*std::cout << root->left->left->fv.val;
//     std::cout << root->left->op;
//     std::cout << root->left->right->fv.val;
//     std::cout << root->op;
//     std::cout << root->right->left->fv.val;
//     std::cout << root->right->op;
//     std::cout << root->right->right->fv.val;*/
//     if(root)
//     {
//         inorder_traversal(root->left);
//         if(root->op.size())
//         {
//             std::cout << root->op;
//         }
//         else
//         {
//             std::cout << root->fv.val;
//         }
//         inorder_traversal(root->right);
//     }
// }
