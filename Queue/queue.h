#ifndef QUEUE_H
#define QUEUE_H

#include "/media/jatins02/New Volume/DSA_/DSA/Linked_Lists/DLL/doubly_linkedlist.h"
#include <string>

class Queue{
private:
    int length;
    DLL dll;

public:
    // write the function prototypes of the functions
    Queue();
    ~Queue();
    void enqueue(int val);
    void dequeue();
    Node *peek();
    int isEmpty();
    int size();
};

#endif