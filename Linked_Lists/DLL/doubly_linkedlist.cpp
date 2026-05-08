#include <iostream>
#include "doubly_linkedlist.h"

DLL::DLL(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

DLL::~DLL(){
    Node *trav1 = head;
    Node *trav2;
    for (int i = 0; i < length; i++){
        trav2 = trav1->next;
        delete trav1;
        trav1 = trav2;
    }

    head = nullptr;
    tail = nullptr;
    length = 0;
}

void DLL::prependNode(int val){
    Node *newNode = new Node();
    newNode->value = val;

    if (head == nullptr){
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        newNode->prev = tail;

        head->prev = newNode;
        tail->next = newNode;
    }
    head = newNode;
    length++;
}

void DLL::printDLL(){
    Node *trav = head;
    do{
        std::cout << trav->value << " -> ";
        trav = trav->next;
    } while(trav != head);

    std::cout << std::endl;
}

void DLL::appendNode(int val){

    if (head == nullptr){
        prependNode(val);
        return;
    }
    
    Node *newNode = new Node();
    newNode->value = val;
    newNode->next = head;

    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    
    tail = newNode;
    length++;
}

void DLL::insertAt(int ind, int val){

    if ((ind < 0) || (ind > length)) return;

    if (head == nullptr || ind == 0){
        prependNode(val);
        return;
    }
    else if (ind == length){
        appendNode(val);
        return;
    }


    // you could do this the normal way, but using doubly linked list, you can traverse the list backwards, thus increase the efficiency
    Node *trav = head;

    Node *newNode = new Node();
    newNode->value = val;
    if (ind < length/2){
        for (int i = 0; i<ind-1; i++){
            trav = trav->next;
        }
    }
    else{
        trav = tail;
        for (int i = 0; i<length-ind; i++){
            trav = trav->prev;
        }
    }
    Node *nextNode = trav->next;
    newNode->prev = trav;
    trav->next = newNode;
    newNode->next = nextNode;
    nextNode->prev = newNode;
    length++;
}

void DLL::deleteAt(int ind){
    if ((ind < 0) || (ind > length) || head == nullptr) return;

    if (length == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
        return;
    }

    Node *todelete = nullptr;
    if (ind == 0){
        todelete = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
    }
    else{
        Node *trav = head;
        if (ind < length/2){
            for(int i = 0; i<ind-1; i++){
                trav = trav->next;
            }
        }
        else{
            trav = tail;
                for (int i = 0; i<length-ind; i++){
                    trav = trav->prev;
                }
        }
        todelete = trav->next;
        Node *next = todelete->next;
        trav->next = next;
        next->prev = trav;

        if (ind == length-1){
            tail = trav;
        }
    }
    delete todelete;
    length--;
}

void DLL::deleteVal(int val){

    if (head == nullptr) return;

    if (head->value == val){
        Node *todelete = head;
        if (length == 1){
            head = tail = nullptr;
        }
        else{
            head = head->next;
            tail->next = head;
            head->prev = tail;
        }
        delete todelete;
        length--;
        return;
    }
    else if (tail->value == val){
        Node *todelete = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete todelete;
        length--;
        return;
    }

    Node *travF = head->next;
    Node *travB = tail->prev; 
    
    // for (int i = 0; i < (length/2)+1; i++){
    //     if (travF->value == val || travB->value == val){
    //         Node *todelete = (travF->value == val) ? travF : travB;
    //         Node *prevnode = todelete->prev;
    //         Node *nextnode = todelete->next;
    //         prevnode->next = nextnode;
    //         nextnode->prev = prevnode;
    //         delete todelete;
    //         length--;
    //         return;
    //     }
    //     else{
    //         // traverse the pointers
    //         travF = travF->next;
    //         travB = travB->prev;
    //     }
    // }

    for (int i = 0; i < (length - 2)/2 + 1; i++){
        Node *todelete = nullptr;

        if (travF->value == val) todelete = travF;
        else if (travB->value == val) todelete = travB;

        if (todelete){
            todelete->prev->next = todelete->next;
            todelete->next->prev = todelete->prev;
            delete todelete;
            length--;
            return;
        }

        if (travF == travB || travF->next == travB) break;

        travF = travF->next;
        travB = travB->prev;
    }
}

int DLL::getLength(){
    return length;
}

int DLL::getNode(int ind){
    Node *trav = head;
    for (int i = 1; i<=ind; i++){
        trav = trav->next;

    } 
    return trav->value;
}

int DLL::getIndex(int val){
    Node *trav = head;
    int counter = 0;
    int found = 1;
    while (trav->value != val){
        trav = trav->next;
        counter++;
        if (counter == length-1){
            found = 0;
            break;
        }
    }
    if (found) return counter;
    else return -1;
}