#include <iostream>
#include "bst.h"

int main(){

    BinarySearchTree bst;
    bst.insertNode(22);
    bst.insertNode(12);
    bst.insertNode(5);
    bst.insertNode(44);
    bst.insertNode(18);
    bst.insertNode(2);

    std::cout << "Height of tree: " << bst.getHeight() << std::endl;

    std::cout << "In order traversal: ";
    bst.inorderTrav();

    std::cout << "Pre order traversal: ";
    bst.preorderTrav();

    std::cout << "Post order traversal: ";
    bst.postorderTrav();
    
    std::cout << "In order traversal: ";
    bst.levelorderTrav();
    std::cout << std::endl;

    int tosearch = 121;
    Node *result = bst.searchNode(tosearch);
    if (result != nullptr){
        std::cout << result->value << " is found in the BST" << std::endl;
    }
    else{
        std::cout << tosearch << " was not found in the BST" << std::endl;
    }

    bst.containsNode(44);
    bst.containsNode(121);

    bst.insertNode(69);

    std::cout << "Size: " << bst.getSize() << std::endl;
    std::cout << "Is empty: " << bst.isEmpty() << std::endl;

    std::cout << "height: " << bst.getHeight() << std::endl;
    std::cout << "Min: " << bst.getMin() << std::endl;
    std::cout << "Max: " << bst.getMax() << std::endl;

    return 0;
}