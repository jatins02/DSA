#include <iostream>
#include "doubly_linkedlist.h"

template <typename T>
DLL<T>::DLL(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
DLL<T>::~DLL(){
    Node<T> *trav1 = head;
    Node<T> *trav2;
    for (int i = 0; i < length; i++){
        trav2 = trav1->next;
        delete trav1;
        trav1 = trav2;
    }

    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
void DLL<T>::prependNode(T val){
    Node<T> *newNode = new Node<T>();
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

template <typename T>
void DLL<T>::printDLL(){
    Node<T> *trav = head;
    do{
        std::cout << trav->value << " -> ";
        trav = trav->next;
    } while(trav != head);

    std::cout << std::endl;
}

template <typename T>
void DLL<T>::appendNode(T val){

    if (head == nullptr){
        prependNode(val);
        return;
    }
    
    Node<T> *newNode = new Node<T>();
    newNode->value = val;
    newNode->next = head;

    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    
    tail = newNode;
    length++;
}

template <typename T>
void DLL<T>::insertAt(int ind, T val){

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
    Node<T> *trav = head;

    Node<T> *newNode = new Node<T>();
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
    Node<T> *nextNode = trav->next;
    newNode->prev = trav;
    trav->next = newNode;
    newNode->next = nextNode;
    nextNode->prev = newNode;
    length++;
}

template <typename T>
void DLL<T>::deleteAt(int ind){
    if ((ind < 0) || (ind > length) || head == nullptr) return;

    if (length == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
        return;
    }

    Node<T> *todelete = nullptr;
    if (ind == 0){
        todelete = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
    }
    else{
        Node<T> *trav = head;
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
        Node<T> *next = todelete->next;
        trav->next = next;
        next->prev = trav;

        if (ind == length-1){
            tail = trav;
        }
    }
    delete todelete;
    length--;
}

template <typename T>
void DLL<T>::deleteVal(T val){

    if (head == nullptr) return;

    if (head->value == val){
        Node<T> *todelete = head;
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
        Node<T> *todelete = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete todelete;
        length--;
        return;
    }

    Node<T> *travF = head->next;
    Node<T> *travB = tail->prev; 

    for (int i = 0; i < (length - 2)/2 + 1; i++){
        Node<T> *todelete = nullptr;

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

template <typename T>
int DLL<T>::getLength(){
    return length;
}

template <typename T>
T DLL<T>::getNodeValue(int ind){
    Node<T> *trav = head;
    for (int i = 1; i<=ind; i++){
        trav = trav->next;

    } 
    return trav->value;
}

template <typename T>
int DLL<T>::getIndex(T val){
    Node<T> *trav = head;
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

template <typename T>
Node<T> *DLL<T>::getNode(int ind){
    Node<T> *trav = head;
    for (int i = 1; i <= ind; i++){
        trav = trav->next;
    }

    return trav;
}