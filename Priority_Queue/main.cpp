#include <iostream>
#include <functional>
#include "pq.h"

bool maxfunc(int a, int b);

int main(){

    PQ pq(greater<int>{});
    pq.push(1);
    pq.printPQ();
    cout << pq.getLength() << endl;

    pq.push(8);
    pq.printPQ();
    cout << pq.getLength() << endl;

    pq.push(2);
    pq.printPQ();
    cout << pq.getLength() << endl;

    pq.push(3);
    pq.printPQ();
    cout << pq.getLength() << endl;

    pq.push(4);
    pq.printPQ();
    cout << pq.getLength() << endl;

    return 0;
}

bool maxfunc(int a, int b){
    return a < b;
}