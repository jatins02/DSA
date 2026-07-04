#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template <typename T>
struct Node{
    T value;
    Node<T> *prev;
    Node<T> *next;
};

template <typename T>
class DLL{
    private:
        Node<T> *head;
        Node<T> *tail;
        int length;

    public:
        DLL();
        ~DLL();
        void prependNode(T val);
        void printDLL();
        void appendNode(T val);
        void insertAt(int ind, T val);
        void deleteAt(int ind);
        void deleteVal(T val);
        int getLength();
        T getNodeValue(int ind);
        int getIndex(T val);
        Node<T> *getNode(int ind);
};

#include "doubly_linkedlist.cpp"
#endif