#include <iostream>
#include "ipq.h"

using namespace std;
int main(){

    IPQ ipq;
    ipq.addele({2, 22});
    ipq.addele({1, 12});
    ipq.addele({7, 5});

    ipq.printpq();
    return 0;
}