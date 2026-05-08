#include <iostream>
#include "singly_linkedlist.h"

int main(){

    SLL sll;
    sll.appendNode(22);
    sll.appendNode(12);
    sll.appendNode(5);
    sll.prependNode(7);
    sll.prependNode(1);
    sll.prependNode(2);

    sll.deleteByVal(7);
    sll.printSLL();
    std::cout << "Length of SLL: " << sll.getLength() << std::endl;
    // getting index of 22
    int ind_22 = sll.getIndex(22);
    if (ind_22 == -1){
        std::cout << "22 was not found" << std::endl;
    }
    else{
        std::cout << "22 was found at: " << ind_22 << std::endl;
    }

    sll.prependNode(66);
    sll.printSLL();
    sll.reverseSLL();
    sll.printSLL();

    sll.insertAt(44, 1);
    sll.printSLL();
    sll.insertAt(69, sll.getLength()-1);
    sll.printSLL();
    sll.insertAt(23, 0);
    sll.printSLL();

    return 0;
}