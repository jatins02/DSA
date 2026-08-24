#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include "ipq.h"

using namespace std;

// IPQ::IPQ(){
//     len = 0;
// }

// IPQ::~IPQ(){
//     pm = {};
//     im = {};
//     vals = {};
//     len = 0;
// }

void IPQ::addele(const pair<int, int> &p){
    pq.push(p);
}

void IPQ::printpq(){
    if (pq.empty()) return;

    cout << pq.top().first << " : " << pq.top().second << endl;
}

