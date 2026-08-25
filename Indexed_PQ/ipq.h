#ifndef INDEXED_PRIORITY_QUEUE
#define INDEXED_PRIORITY_QUEUE

#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <unordered_map>

// for now the ipq only takes in int values, generalise it later on.

using namespace std;

class IPQ { 
private:
    int num;

    // for the overall ipq implementation
    unordered_map<int, int> giveKIgetName;
    unordered_map<int, int> giveNamegetKI;

    vector<int> vals;
    vector<int> pm;
    vector<int> im;
    int ki = 0;

    // for the underlying pq implementation
    vector<int> v;
    int sz = 0;
    // std::function<bool(const pair<int, int>&, const pair<int, int>&)> comp;
    bool (IPQ::*comp)(int, int);

    void swim(int i);
    void sink(int i);
    void swap(int i, int j);
    // considering only the min heap implementation underneath, so only less function is implemented
    bool less(int i, int j);
    bool more(int i, int j);

    // struct compFunc{
    //     bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    //         return a.second > b.second;
    //     }
    // };

public:

    IPQ(int n, int type = 0) : num(n) {
        if (type == 0) comp = &IPQ::less;
        else comp = &IPQ::more;
        vals.assign(num, __INT_MAX__);
        pm.assign(num, -1);
        im.assign(num, -1);
    };
    ~IPQ() = default;

    void print();
    void insert(pair<int, int> p);
    void remove(int name);
    void hatao(int ki);
    int topVal();
    void popEle();
    int valueof(int name);
    void decreaseKey(int name, int val);
    void increaseKey(int name, int val);

    /*
    methods to implement
    IPQ()   ==
    ~IPQ()  ==
    printIPQ()  ==
    push()  ==
    swim()  ==
    sink()  ==

    remove(key) ==
    hatao(ki) == 
    top()   ==
    pop()   ==
    valueof(ki)     ==
    contains(ki)
    peekMinKeyIndex()
    pollMinKeyIndex()
    peekMinValue()
    insert(ki, value)   ==
    update(ki, value)   
    decreaseKey(ki, value)
    increaseKey(ki, value)
    */
};

#endif