#include <iostream>
#include "stack.h"

Stack::Stack() : arr(4){
    length = 0;
}

Stack::~Stack(){
    // deconstructing the stack will call the deconstuctor of arr on its own, so no need to write it again
    length = 0;
}

void Stack::pushEle(int ele){
    arr.appendEle(ele);
    length++;
}

void Stack::popEle(){
    arr.popEle();
    length--;
}

int Stack::peakEle(){
    return arr.eleAt(length-1);
}

int Stack::isEmpty(){
    return (length == 0) ? 0 : 1;
}

int Stack::sizeStk(){
    return length;
}

void Stack::printStk(){
    std::cout << std::endl;
    for (int i = length-1; i>=0; i--){
        std::cout << arr.eleAt(i) << std::endl;
    }
    std::cout << std::endl;
}



