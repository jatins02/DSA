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

    void swim(int i);
    void sink(int i);
    void swap(int i, int j);

public:
    // Operations to be performed
    // push, size, isempty, top, pop, print-tree
    // private functions: swim, sink
    static bool defaultCompareFunc(int a, int b){
        return a > b;
    }
    
    PQ(bool (*cf)(int, int) = defaultCompareFunc) : comp(cf){
        v.push_back(__INT_MAX__);
    };
    ~PQ();

    void push(int val);
    int getLength();
    // bool isEmpty();
    // int top();
    void printPQ();
};

#include "pq.cpp"
#endif