#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct Node{
    int value;
    Node *left;
    Node *right;
};

class BinarySearchTree{
private:
    Node *root;
    int size;       // holds the number of nodes in the tree
    int height;

    // preorder, postorder, inorder traversals of the BST, that the user will call, the private functions
    void inorderTrav(Node *node);
    void preorderTrav(Node *node);
    void postorderTrav(Node *node);
    void destroyTree(Node *node);   

    void printCurrentLevel(Node *root, int level);
    //int getHeightRecursively(Node *node);       // required for the recursive BFS approach

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertNode(int val);
    Node *searchNode(int val);
    void containsNode(int val);
    int getSize();
    bool isEmpty();
    int getHeight();
    int getMin();
    int getMax();

    // preorder, postorder, inorder traversals of the BST, that the user will call, the public functions
    void inorderTrav();
    void preorderTrav();
    void postorderTrav();

    void levelorderTrav();
};

#endif