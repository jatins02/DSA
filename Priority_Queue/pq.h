#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>

using namespace std;

class PQ{
private:

public:
    // Operations to be performed
    // push, size, isempty, top, pop, print-tree
    // private functions: swim, sink
    PQ();
    ~PQ();
    void push(int val);
    // int getLength();
    // bool isEmpty();
    // int top();
    void printPQ();
};

#include "pq.cpp"
#endif