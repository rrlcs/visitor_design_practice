#include <iostream>
//Header only libraries
#include "expressionVisitors.h"

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

    formulaCommutatorVisitor* visitor1 = new formulaCommutatorVisitor("+");
    be3->accept(visitor1);
    std::cout<<"Formula Commutated with && Operator:"<<std::endl;
    be3->prettyPrinter();
    std::cout<<"\n";

    formulaPrinterVisitor* visitor2 = new formulaPrinterVisitor();
    std::cout<<"Formula Printed using Printer Visitor:"<<std::endl;
    be3->accept(visitor2);
    std::cout<<"\n";

    //new and delete. malloc and free. preferably don't mix.
    // free memory
    delete p;
    delete q;
    delete r;
    delete pPlusQ;
    delete be2;
    delete be3;
    delete visitor1;
    delete visitor2;
    //free(temp);
}