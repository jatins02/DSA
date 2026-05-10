#include <iostream>
#include "stack.h"

int main(){

    Stack stk;
    stk.pushEle(22);
    stk.pushEle(12);
    stk.pushEle(5);
    
    stk.popEle();
    std::cout << "Peaking element: " << stk.peakEle() << std::endl;

    std::string emptyStatus = (stk.isEmpty() == 0) ? "True" : "False"; 
    std::cout << "Stack empty: " << emptyStatus << std::endl;

    stk.printStk();

    std::cout << "Stack length: " << stk.sizeStk() << std::endl;

    return 0;
}


