#include <iostream>
#include "bst.h"

BinarySearchTree::BinarySearchTree(){       // constructor implementation
    height = 0;
    root = nullptr;
    size = 0;
}

BinarySearchTree::~BinarySearchTree(){      // destructor implementation
    destroyTree(root);
}

void BinarySearchTree::destroyTree(Node *node){
    if (node != nullptr){
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BinarySearchTree::insertNode(int val){
    Node *newnode = new Node();
    newnode->value = val;
    newnode->left = nullptr;
    newnode->right = nullptr;

    if (size == 0){
        // tree is empty
        root = newnode;
        size++;
        return;
    }

    Node *parent = nullptr;
    Node *curr = root;          // you'll have to follow the two pointer approach, because the curr node could traverse to either the left or the right

    while (curr != nullptr){
        parent = curr;
        if (val < curr->value){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }

    // you reach the correct leaf node, now you add in the newnode to this node
    if (val < parent->value){
        parent->left = newnode;
    }
    else{
        parent->right = newnode;
    }
    size++;
}

void BinarySearchTree::containsNode(int val){
    if (size == 0 || root == nullptr){
        // no node in the tree, tell the user
        std::cout << "Tree has no node" << std::endl;
        return;
    }
    else{
        // two case, node found or not found
        Node *curr = root;
        while (curr != nullptr){
            if (curr->value == val){
                // node is found, then return, since no node found logic will be outside the while loop
                std::cout << "Node with value: " << val << " is present in the BST." << std::endl;
                return;
            }
            else if (val > curr->value){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        std::cout << "Node with value: " << val << " is present NOT in the BST." << std::endl;
        return;
    }
}

Node *BinarySearchTree::searchNode(int val){
    if (size == 0 || root == nullptr){
        return nullptr;
    }
    else{
        // two case, node found or not found
        Node *curr = root;
        while (curr != nullptr){
            if (curr->value == val){
                return curr;
            }
            else if (val > curr->value){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        return nullptr;
    }
}

int BinarySearchTree::getSize(){
    return size;
}

bool BinarySearchTree::isEmpty(){
    return (root == nullptr);
}

int BinarySearchTree::getHeight(){
    Node *left = root;
    Node *right = root;

    // calculating leftmax
    int leftdepth = 0;
    while (left->left != nullptr){
        leftdepth++;
        left = left->left;
    }

    // calculating rightmax
    int rightdepth = 0;
    while (right->right != nullptr){
        rightdepth++;
        right = right->right;
    }

    return (leftdepth >= rightdepth) ? leftdepth+1 : rightdepth+1;
}

int BinarySearchTree::getMin(){
    Node *curr = root;
    while (curr->left != nullptr){
        curr = curr->left;
    }
    return curr->value;
}

int BinarySearchTree::getMax(){
    Node *curr = root;
    while (curr->right != nullptr){
        curr = curr->right;
    }
    return curr->value;
}

void BinarySearchTree::inorderTrav(){
    inorderTrav(root);
    std::cout << std::endl;
}

void BinarySearchTree::inorderTrav(Node *node){
    if (node == nullptr) return;

    inorderTrav(node->left);
    std::cout << node->value << " ";
    inorderTrav(node->right);
}

void BinarySearchTree::preorderTrav(){
    preorderTrav(root);
    std::cout << std::endl;
}

void BinarySearchTree::preorderTrav(Node *node){
    if (node == nullptr) return;

    std::cout << " " << node->value << " ";
    preorderTrav(node->left);
    preorderTrav(node->right);
}

void BinarySearchTree::postorderTrav(){
    postorderTrav(root);
    std::cout << std::endl;
}

void BinarySearchTree::postorderTrav(Node *node){
    if (node == nullptr) return;

    postorderTrav(node->left);
    postorderTrav(node->right);
    std::cout << " " << node->value << " ";
}


// level order traversal of a binary search tree is done with the help of a queue, the implementation of the queue, that
// I have done is based on the values of the nodes rathar than the nodes themselves, making it not fit for levelorderTrav() here

// update the code of the queue datastructure, so it can be used in this function, till then levelorderTrav is recursion based

void BinarySearchTree::levelorderTrav(){
    int high = getHeight();
    for (int i = 1; i <= high; i++){
        printCurrentLevel(root, i);
    }
}

void BinarySearchTree::printCurrentLevel(Node *node, int level){
    if (node == nullptr) return;

    if (level == 1){
        std::cout << node->value << " ";
    }
    else if (level>1){      // recursively move down, until level becomes one
        printCurrentLevel(node->left, level-1);
        printCurrentLevel(node->right, level-1);
    }
}


