#include <iostream>
#include "pq.h"

// PQ::PQ(bool (*cf)(int, int) = defaultCompareFunc) : comp(cf){
//     v.push_back(__INT_MAX__);
// }

PQ::~PQ(){
    // reset / remove the size and vector
    size = 0;
    v = {};
}

void PQ::swim(int i){
    // get its parent and swap location if comparison
    for (int p = (i)/2; p>0 && comp(v[p], v[i]); ){
        swap(i, p);
        i = p;
        p = (i-1)/2;
    }
}

void PQ::sink(int i){
    // get its children and swap location if comparison
    while (true){
        int left = 2*i;
        int right = 2*i + 1;
        int thechild = left;

        if ((right <= size) && comp(v[left], v[right])){
            thechild = right;
        }
        if ((left > size) && !comp(v[i], v[thechild])) break;

        swap(thechild, i);
        i = thechild;
    }
}

// takes in indices
void PQ::swap(int i, int j){
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void PQ::push(int val){
    // push the element at the end of the array, then float it upwards
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