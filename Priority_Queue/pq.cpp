#include <iostream>
#include "pq.h"

PQ::PQ(){
    int size = 0;   
    Node *head = nullptr;
    vector<Node *> v;
}

PQ::~PQ(){
    destroyTree(head);
    head = nullptr;
    size = 0;
}
