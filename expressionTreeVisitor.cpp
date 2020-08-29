#include "expressionTreeVisitor.h"
#include <iostream>

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

    // free memory
    free(p);
    free(q);
    free(r);
    free(pPlusQ);
    free(be2);
    free(be3);
    free(visitor);
    //free(temp);
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
