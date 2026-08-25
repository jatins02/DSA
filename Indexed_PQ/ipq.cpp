#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
#include "ipq.h"

using namespace std;

// look at these functions again, very high likely of mistakes here
bool IPQ::less(int i, int j){
    return vals[im[i]] < vals[im[j]];
}

bool IPQ::more(int i, int j){
    return vals[im[i]] > vals[im[j]];
}

void IPQ::swim(int i){
    for (int p = (i-1)/2; i > 0 && (this->*comp)(i, p); ){
        swap(i, p);
        i = p;
        p = (i-1)/2;
    }
}

void IPQ::sink(int i){
    while (true){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = left;
        if (right < sz && (this->*comp)(right, left)){
            smallest = right;
        }
        if (left >= sz || (this->*comp)(i, smallest)) break;

        swap(smallest, i);
        i = smallest;
    }
}

void IPQ::swap(int i, int j){
    pm[im[j]] = i;
    pm[im[i]] = j;
    int tmp = im[i];
    im[i] = im[j];
    im[j] = tmp;
}

// public functions definitions
void IPQ::print(){
    cout << "print called" << endl;
    for (int i = 0; i < sz; i++){
        if (vals[im[i]] == __INT_MAX__) continue;
        cout << vals[im[i]] << " ";
    }
    cout << endl;
}

void IPQ::insert(pair<int, int> p){
    giveKIgetName[ki] = p.first;
    giveNamegetKI[p.first] = ki;
    pm[ki] = sz;
    im[sz] = ki;
    vals[ki] = p.second;
    swim(sz);
    sz++;
    ki++;
}
