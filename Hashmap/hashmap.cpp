#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "hashmap.h"

Hashmap::Hashmap(){
    length = 104;
    size = 0;
    arr = new Node*[length];
    for (int i = 0; i<length; i++){
        *(arr+i) = nullptr;
    }
}

Hashmap::~Hashmap(){
    for (int i = 0; i<length; i++){
        if (*(arr+i) != nullptr) clearBlock(*(arr+i));
    }
    delete[] arr;
}

int Hashmap::hashFunction(std::string branch){
    std::transform(branch.begin(), branch.end(), branch.begin(),
        [](unsigned char c){ return std::tolower(c); });
    int baseind = ((int)branch[0] - 'a') * 4;
    int i = 0;
    while (i<4){
        int currentPos = baseind + i;
        if (*(arr + currentPos) == nullptr) {
            return currentPos; // Found an empty slot
        }
        
        if ((*(arr + currentPos))->branch == branch) {
            return currentPos; // Found the existing branch
        }
        i++;
    }
    
    return baseind;
}

void Hashmap::clearBlock(Node *node){
    Node *trav1 = node;
    Node *trav2 = nullptr;
    while (trav1 != nullptr){
        trav2 = trav1;
        trav1 = trav1->next;
        delete trav2;
        trav2 = nullptr;
    }
}

void Hashmap::put(std::string branch, std::string name, std::string rollno){
    int ind = hashFunction(branch);
    Node *newnode = new Node();
    newnode->branch = branch;
    newnode->name = name;
    newnode->rollno = rollno;

    newnode->next = *(arr+ind);       // add the newnode at the front of the linkedlist, so that the addition takes less time
    *(arr+ind) = newnode;
    size++;
}

Node *Hashmap::get(std::string branch, std::string rollno){
    int ind = hashFunction(branch);
    Node *trav = *(arr+ind);
    while(trav != nullptr){
        if (trav->rollno == rollno) return trav;
        trav = trav->next;
    }
    return trav;
}

void Hashmap::remove(std::string branch, std::string rollno){
    int ind = hashFunction(branch);

    if (*(arr+ind) == nullptr) return;

    // case 1, when the node is the first node in the linked list
    if ((*(arr+ind))->rollno == rollno){
        Node *todelete = *(arr+ind);
        *(arr+ind) = todelete->next;
        delete todelete;
        todelete = nullptr;
        size--;
    }
    else{
        Node *trav2 = *(arr+ind);
        Node *trav1 = trav2->next;      // trav1 is the one to be deleted
        
        while (trav1 != nullptr){
            if (trav1->rollno == rollno){
                trav2->next = trav1->next;
                delete trav1;
                trav1 = nullptr;
                size--;
                return;
            }
            trav2 = trav1;
            trav1 = trav1->next;
        }
    }
}

bool Hashmap::contains(std::string branch, std::string rollno){
    int ind = hashFunction(branch);

    Node *trav = *(arr+ind);
    while (trav != nullptr){
        if (trav->rollno == rollno){
            return true;
        }
        trav = trav->next;
    }
    return false;
}

int Hashmap::getSize(){
    return size;
}

bool Hashmap::isEmpty(){
    return (size == 0) ? true : false;
}