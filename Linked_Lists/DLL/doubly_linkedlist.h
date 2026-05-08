#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

struct Node{
    int value;
    Node *prev;
    Node *next;
};

class DLL{
    private:
        Node *head;
        Node *tail;
        int length;

    public:
        DLL();
        ~DLL();
        void prependNode(int val);
        void printDLL();
        void appendNode(int val);
        void insertAt(int ind, int val);
        void deleteAt(int ind);
        void deleteVal(int val);
        int getLength();
        int getNode(int ind);
        int getIndex(int val);
};

#endif