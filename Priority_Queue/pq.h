#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    int ind;
    
    Node() : val(0), left(nullptr), right(nullptr){};
    Node(int x) : val(x), left(nullptr), right(nullptr){};
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right){};
};

class PQ{
private:
    vector<Node *> v;
    Node *head;
    int size;
    void destroyTree(Node *root){
        if (root == nullptr) return;

        cout << root->val;

        Node *left = root->left;
        Node *right = root->right;

        destroyTree(left);
        destroyTree(right);
    }

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