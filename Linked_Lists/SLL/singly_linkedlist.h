#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

struct Node{
    int value;
    Node *next;     // self referencing pointer to the next node
};

class SLL{
    private:
        int length;
        Node *head;
        Node *tail;

    public:
        SLL();
        ~SLL();
        void prependNode(int value);
        void appendNode(int value);
        void deleteNodeAt(int ind);
        void deleteByVal(int val);
        void printSLL();
        void reverseSLL();
        void insertAt(int value, int ind);
        int getLength();
        int getNode(int ind);
        int getIndex(int value);
};

#endif