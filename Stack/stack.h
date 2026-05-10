#ifndef STACK_H
#define STACK_H

#include "/media/jatins02/New Volume/DSA_/DSA/Dynamic_Array/dynamicArr.h"

class Stack{
private:
    int length;
    DynamicArr arr;

public:
    Stack();
    ~Stack();
    void pushEle(int ele);
    void popEle();
    int peakEle();
    int isEmpty();
    int sizeStk();
    void printStk();
};

#endif