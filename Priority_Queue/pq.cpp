#include <iostream>
#include "pq.h"

PQ::PQ(){
    int size = 0;   
    Node *head = nullptr;
    vector<Node *> v;
}

PQ::~PQ(){
    cout << "this was called and the error occured here within the destructor";
    destroyTree(head);
    head = nullptr;
    size = 0;
}

void PQ::push(int val){
    Node *curr = new Node(val, nullptr, nullptr);
    curr->ind = size;
    v.push_back(curr);
    size++;

    if (size == 1) return;

    // now compare curr with its parent, and swap them if necessary
    for (int p = (curr->ind-1)/2; p > 0 && (curr->val < v[p]->val);){
        Node *tmp1 = v[p];
        Node *tmp2 = v[curr->ind];

        curr = v[p];
        curr->ind = tmp1->ind;
        curr->left = tmp1->left;
        curr->right = tmp1->right;

        tmp1->ind = tmp2->ind;
        tmp1->left = tmp2->left;
        tmp1->right = tmp2->right;
        v[p] = tmp1;

        // but this is kindof pointless, because nodes are stored in array, so left and right child 
        // can be accessed from it
        delete tmp1;
        delete tmp2;
    }
}

void PQ::printPQ(){
    for (Node *n : v){
        cout << n->val << " ";
    }
    cout << endl;
}