#include <iostream>
//Header only libraries
#include "expressionVisitors.h"
#include "expressionAST.h"

int main()
{
    FormulaVar *p = new FormulaVar("p");
    FormulaVar *q = new FormulaVar("q");
    FormulaVar *r = new FormulaVar("r");
    //p->prettyPrinter();
    //q->prettyPrinter();

    //*p = FormulaBinaryExp();

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

    formulaCommutatorVisitor* visitor = new formulaCommutatorVisitor("&&");
    Formula *be4;
    be4 = be3->accept(visitor);
    be4->prettyPrinter();

    //new and delete. malloc and free. don't mix.
    // free memory
    delete p;
    delete q;
    delete r;
    delete pPlusQ;
    delete be2;
    delete be3;
    delete visitor;
    //free(temp);
}