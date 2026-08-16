#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>

using namespace std;

// for now class implementation only holds integer values

class PQ{
private:
    vector<int> v;
    int size = 0;
    bool (*comp)(int, int);
    static bool defaultCompareFunc(int a, int b){
        return a > b;
    }

public:
    // Operations to be performed
    // push, size, isempty, top, pop, print-tree
    // private functions: swim, sink
    PQ(bool (*cf)(int, int) = defaultCompareFunc) : comp(cf){};
    ~PQ();
    void push(int val);
    // int getLength();
    // bool isEmpty();
    // int top();
    void printPQ();
};

#include "pq.cpp"
#endif