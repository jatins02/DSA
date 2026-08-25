#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#include "ipq.h"

using namespace std;
int main(){

    IPQ ipq(25);
    ipq.insert({22, 12});
    ipq.insert({2, 1});
    ipq.insert({5, 7});

    ipq.print();

    return 0;
}