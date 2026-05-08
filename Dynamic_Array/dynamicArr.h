#ifndef DYNAMIC_ARRAY_H  // Header guard start
#define DYNAMIC_ARRAY_H

// create the class structure inside here

class DynamicArr{
    private:
        int outSize = 0;
        int inSize = 8;
        int *arr;

    public:
        // write the function prototypes here
        DynamicArr(int inSize);
        ~DynamicArr();

        void reverseArr();
        void insertEle(int ele, int ind);
        void printArr();
        void deleteEle(int ind);
        int searchEle(int ind);
        void clearArr();
        void appendEle(int ele);
        void popEle();
        void sortArr(int flag);

};

#endif  // Header guard end