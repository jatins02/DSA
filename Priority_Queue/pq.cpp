#include <iostream>
#include "pq.h"

PQ::~PQ(){
    size = 0;
    v = {};
}

void PQ::swim(int i){
    for (int p = i/2; p>0 && comp(v[p], v[i]); ){
        swap(i, p);
        i = p;
        p = i/2;
    }
}

void PQ::sink(int i){
    while (2*i <= size){
        int left = 2*i;
        int right = 2*i + 1;
        int thechild = left;

        if ((right <= size) && comp(v[left], v[right])){
            thechild = right;
        }
        if (!comp(v[i], v[thechild])) break;

        swap(thechild, i);
        i = thechild;
    }
}

// takes in indices
void PQ::swap(int i, int j){
    if (i == j) return;
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void PQ::push(int val){
    v.push_back(val);
    size++;
    swim(size);
}

void PQ::printPQ(){
    cout << "printPQ was called..." << endl;

    for (int i = 1; i <= size; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int PQ::getLength(){ return size; }

bool PQ::isEmpty(){ return (size == 0); }

int PQ::topEle(){ return v[1]; }

void PQ::popEle(){
    if (size == 0) return;

    swap(1, size);
    size--;
    v.pop_back();
    if (size > 0) sink(1);
}