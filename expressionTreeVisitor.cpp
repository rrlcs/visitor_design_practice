#include <iostream>
#include <cstring>

class FormulaBinaryExp;
class FormulaVar;

class FormulaVisitor
{
    public:
        virtual void visit(FormulaVar &leaf) {};
        virtual void visit(FormulaBinaryExp * expr) {};
};



class Formula
{
    public:
        virtual void accept(FormulaVisitor &visitor) {};
};

class FormulaVar : public Formula
{
    public:
        int val;
        void accept(FormulaVisitor &visitor)
        {
                visitor.visit(*this);
        }
};

class FormulaBinaryExp : public Formula
{
    public:
        FormulaBinaryExp *left;
        FormulaBinaryExp *right;
        FormulaVar fv;
        std::string op;
        void accept(FormulaVisitor &visitor)
        {
            //std::cout << "in accept" << std::endl;
            visitor.visit(this);
        }
};

class LeafPrinterVisitor : public FormulaVisitor
{
    public:
        void visit(FormulaVar &leaf)
        {
            //visit leaf node;
            std::cout << leaf.val;
        }
        void visit(FormulaBinaryExp * root)
        {
            //visit expression;
            //std::cout << "visite expr" << std::endl;
            if(root)
            {
                visit(root->left);
                if(root->op.size())
                {
                    std::cout << root->op;
                }
                else
                {
                    //std::cout << root->fv.val;
                    visit(root->fv);
                }
                visit(root->right);
            }
        }
};

void inorder_traversal(FormulaBinaryExp * root)
{
    /*std::cout << root->left->left->fv.val;
    std::cout << root->left->op;
    std::cout << root->left->right->fv.val;
    std::cout << root->op;
    std::cout << root->right->left->fv.val;
    std::cout << root->right->op;
    std::cout << root->right->right->fv.val;*/
    if(root)
    {
        inorder_traversal(root->left);
        if(root->op.size())
        {
            std::cout << root->op;
        }
        else
        {
            std::cout << root->fv.val;
        }
        inorder_traversal(root->right);
    }
}

int main()
{
    FormulaBinaryExp *root = NULL;
    FormulaBinaryExp *left = NULL;
    FormulaBinaryExp *right = NULL;
    FormulaVar *fv1 = NULL;
    FormulaVar *fv2 = NULL;
    fv1 = new FormulaVar();
    fv2 = new FormulaVar();
    fv1->val = 2;
    fv2->val = 3;
    //std::cout << fv1->val;
    //std::cout << fv2->val;
    root = new FormulaBinaryExp();
    left = new FormulaBinaryExp();
    right = new FormulaBinaryExp();
    //left->fv.val = 2;
    //right->fv.val = 3;
    root->left = left;
    root->right = right;

    root->op = '+';
    root->left->op = '+';
    root->right->op = '-';
    
    root->left->left = new FormulaBinaryExp();
    root->left->right = new FormulaBinaryExp();
    root->right->left = new FormulaBinaryExp();
    root->right->right = new FormulaBinaryExp();
    
    root->left->left->fv.val = 2;
    root->left->right->fv.val = 3;
    root->right->left->fv.val = 5;
    root->right->right->fv.val = 1;

    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    std::cout << "Inorder Traversal" << std::endl;

    LeafPrinterVisitor lpv;
    root->accept(lpv);
    //inorder_traversal(root);
}