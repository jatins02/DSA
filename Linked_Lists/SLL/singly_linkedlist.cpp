#include <iostream>
#include "singly_linkedlist.h"

SLL::SLL(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

SLL::~SLL(){
    Node *curr = head;
    while (curr != nullptr){
        Node *nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void SLL::printSLL(){
    Node *trav1 = head;
    while (trav1 != nullptr){
        std::cout << trav1->value << " -> ";
        trav1 = trav1->next;
    }
    std::cout << "null" << std::endl;
}

void SLL::prependNode(int value){
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = head;

    if (head == nullptr){       // or if(isEmpty())
        tail = newNode;
    }

    head = newNode;
    length ++;
}

void SLL::appendNode(int value){

    Node *newNode = nullptr;
    if (head == nullptr){
        newNode = new Node();
        head = newNode;
    }
    else{
        newNode = tail;
        newNode->next = new Node();
        newNode = newNode->next;
    }

    newNode->value = value;
    newNode->next = nullptr;
    tail = newNode;
    length ++;
}


// void SLL::deleteNodeAt(int ind){
//     if ((head == nullptr) || (ind < 0) || (ind>=length)) return;
//     Node *toDelete = nullptr;

//     if (ind == 0){
//         toDelete = head;
//         head = head->next;

//         if (length == 1){
//             tail == nullptr;
//         }

//     }
//     else {
//         Node *prev = head;
//         for (int i = 0; i<ind-1; i++){
//             prev = prev->next;
//         }
//         toDelete = prev->next;
//         prev->next = toDelete->next;        //bypass the node to be deleted

//         if (ind == length - 1){
//             tail = prev;
//         }
//     }
//     delete toDelete;
//     length--;
// }



void SLL::deleteNodeAt(int ind){
    if ((ind < 0) || (ind >= length) || (head == nullptr)) return;

    Node *trav1;

    // deleting the first element of the linked list
    if (ind == 0){
        trav1 = head;
        head = trav1->next;
    
        if (length == 1){
            tail = nullptr;
        }
        delete trav1;
        length--;
    }

    else{
        Node *trav2;
        trav1 = head;
        for (int i = 0; i < ind-1; i++){
            trav1 = trav1->next;
        }
        trav2 = trav1->next;
        trav1->next = trav2->next;

        if (ind == length-1){
            tail = trav1;
        }
        delete trav2;
        length--;
    }
}


void SLL::deleteByVal(int value){
    if (head == nullptr){
        std::cout << "Invalid Operation" << std::endl;
        return;
    }

    Node *trav1 = head;

    int indx = -1;
    for (int i = 0; i < length; i++){
        int val = trav1->value;
        if (val == value){
            indx = i;
            break;
        }
        trav1 = trav1->next;
    }

    if (indx == -1){
        std::cout << "Element not found...";
        return;
    }
    else{
        deleteNodeAt(indx);
    }
}
