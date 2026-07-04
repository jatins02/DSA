    #ifndef SINGLY_LINKED_LIST
    #define SINGLY_LINKED_LIST

    template <typename T>
    struct Node{
        T value;
        Node<T> *next;     // self referencing pointer to the next node
    };

    template <typename T>
    class SLL{
        private:
            int length;
            Node<T> *head;
            Node<T> *tail;

        public:
            SLL();
            ~SLL();
            void prependNode(T value);
            void appendNode(T value);
            void deleteNodeAt(int ind);
            void deleteByVal(T val);
            void printSLL();
            void reverseSLL();
            void insertAt(T value, int ind);
            int getLength();
            T getNode(int ind);
            int getIndex(T value);
    };

    #include "singly_linkedlist.cpp"
    
    #endif