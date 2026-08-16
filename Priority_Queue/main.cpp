#include <iostream>
#include "pq.h"

int main(){

    PQ pq;
    pq.push(1);
    pq.push(2);
    pq.push(12);
    pq.push(4);

    pq.printPQ();

    return 0;
}