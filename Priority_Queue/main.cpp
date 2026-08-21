#include <iostream>
#include <functional>
#include "pq.h"

int main(){

    PQ pq(greater<int>{});
    pq.push(1);
    pq.push(8);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.printPQ();
    cout << pq.getLength() << endl;
    cout << pq.topEle() << endl;
    pq.popEle();
    pq.printPQ();

    return 0;
}