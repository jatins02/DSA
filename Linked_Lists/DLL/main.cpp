#include <iostream>
#include "doubly_linkedlist.h"

int main(){

    DLL dll;
    dll.appendNode(22);
    dll.appendNode(12);
    dll.appendNode(2005);
    dll.prependNode(2007);
    dll.prependNode(1);
    dll.appendNode(2);

    dll.insertAt(0, 22);
    dll.deleteAt(2);
    dll.deleteVal(12);
    dll.printDLL();
    return 0;
}