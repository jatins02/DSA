#include <iostream>
#include "singly_linkedlist.h"

template <typename T>
SLL<T>::SLL(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
SLL<T>::~SLL(){
    Node<T> *curr = head;
    while (curr != nullptr){
        Node<T> *nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
void SLL<T>::printSLL(){
    Node<T> *trav1 = head;
    while (trav1 != nullptr){
        std::cout << trav1->value << " -> ";
        trav1 = trav1->next;
    }
    std::cout << "null" << std::endl;
}

template <typename T>
void SLL<T>::prependNode(T value){
    Node<T> *newNode = new Node<T>();
    newNode->value = value;
    newNode->next = head;

    if (head == nullptr){       // or if(isEmpty())
        tail = newNode;
    }

    head = newNode;
    length ++;
}

template <typename T>
void SLL<T>::appendNode(T value){

    Node<T> *newNode = nullptr;
    if (head == nullptr){
        newNode = new Node<T>();
        head = newNode;
    }
    else{
        newNode = tail;
        newNode->next = new Node<T>();
        newNode = newNode->next;
    }

    newNode->value = value;
    newNode->next = nullptr;
    tail = newNode;
    length ++;
}

template <typename T>
void SLL<T>::insertAt(T value, int ind){

    if ((ind < 0) || (ind > length)) return;

    Node<T> *newNode = new Node<T>();
    newNode->value = value;

    if (ind == 0){
        newNode->next = head;
        head = newNode;
        length++;
        return;
    }

    // pointer traversal
    Node<T> *trav = head;
    for (int i = 1; i <= ind-1; i++){
        trav = trav->next;      // trav is at the index, one less than where newNode has to be added
    }
    newNode->next = trav->next;
    trav->next = newNode;

    if(ind == length-1){
        tail = newNode;
    }
    length++;
}

template <typename T>
void SLL<T>::deleteNodeAt(int ind){
    if ((ind < 0) || (ind >= length) || (head == nullptr)) return;

    Node<T> *trav1;

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
        Node<T> *trav2;
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

template <typename T>
void SLL<T>::deleteByVal(T value){
    if (head == nullptr){
        std::cout << "Invalid Operation" << std::endl;
        return;
    }

    Node<T> *trav1 = head;

    int indx = -1;
    for (int i = 0; i < length; i++){
        T val = trav1->value;
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

template <typename T>
void SLL<T>::reverseSLL(){
    if (length == 1 || length == 0) return;

    Node<T> *trav1 = head;
    Node<T> *trav2 = head->next;
    for (int i = 0; i<length-1; i++){
        Node<T> *temp = trav2->next;
        trav2->next = trav1;
        trav1 = trav2;
        trav2 = temp;
    }
    tail = head;
    head = trav1;
    tail->next = nullptr;
}

template <typename T>
int SLL<T>::getLength(){
    return length;
}

template <typename T>
T SLL<T>::getNode(int ind){
    Node<T> *trav = head;

    for (int i = 1; i <= ind; i++){
        trav = trav->next;
    }
    return trav->value;
}

template <typename T>
int SLL<T>::getIndex(T value){
    Node<T> *trav = head;
    int counter = 0;
    int found = 1;
    while (trav->value != value){
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