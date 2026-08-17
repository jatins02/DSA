#include <iostream>
#include "pq.h"

int main(){

    PQ pq;
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