#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>
#include <functional>

using namespace std;

// for now class implementation only holds integer values

class PQ{
private:
    vector<int> v;
    int size = 0;
    std::function<bool(int, int)> comp;

    void swim(int i);
    void sink(int i);
    void swap(int i, int j);

public:
    // Operations to be performed
    // push, size, isempty, top, pop, print-tree
    // private functions: swim, sink
    PQ(std::function<bool(int, int)> cf = std::less<int>()) : comp(cf){
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