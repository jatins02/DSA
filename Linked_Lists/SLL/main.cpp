#include <iostream>
#include "singly_linkedlist.h"

int main(){

    SLL sll;
    sll.appendNode(22);
    sll.printSLL();
    sll.prependNode(2);
    sll.prependNode(1);
    sll.prependNode(7);
    sll.printSLL();
    sll.deleteByVal(7);
    sll.printSLL();

    return 0;
}



