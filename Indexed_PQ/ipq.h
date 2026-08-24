#ifndef INDEXED_PRIORITY_QUEUE
#define INDEXED_PRIORITY_QUEUE

// inheriting from stl data structures is not recommended in cpp

#include <vector>
#include <queue>
#include <utility>

using namespace std;

// making an IPQ to take in coordintes of a box in a grid, then do shi on it.
// and making a min heap implementation

struct compareFunc{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;
    }
};

class IPQ : public priority_queue<pair<int, int>, vector<pair<int, int>>, compareFunc>{
private:
    int len = 0;       // not needed as this will be the same as size of this->c
    priority_queue<pair<int, int>> pq;
    vector<int> vals;
    vector<int> pm;
    vector<int> im;

public:
    // no default constructor exists for this class
    // also no destructor exists for ipq, so you shouldn't write destructor for it, to aviod memory leak (read more about this)
    IPQ() = default;
    ~IPQ() = default;
    void addele(const pair<int, int> &p);
    void printpq();
};  

#endif