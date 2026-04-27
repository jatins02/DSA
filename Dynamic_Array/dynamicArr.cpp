#include <iostream>
#include <cstdlib>
#include "dynamicArr.h"

DynamicArr::DynamicArr(int size){       // constructor implementation

    inSize = size;
    outSize = 0;

    arr = (int *)calloc(size, sizeof(int));
    if (arr == nullptr){
        std::cerr << "Memory allocation in constructor failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}

DynamicArr::~DynamicArr(){              // destructor implementation
    free(arr);
}

void DynamicArr::reverseArr(){

    int *temp = (int *)calloc(inSize, sizeof(int));
    if (temp == nullptr){
        std::cerr << "Memory allocation for reversing the array failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < outSize; i++){
        *(temp+i) = *(arr+(outSize-1)-i);
    }
    free(arr);
    arr = temp;
}

void DynamicArr::insertEle(int ele, int ind){

    if (ind < 0 || ind > outSize){
        std::cerr << "Invalid Operation" << std::endl;
        return;
    }

    if (outSize+1 >= inSize){
        inSize = inSize*2;
        int *temp = (int *)realloc(arr, inSize * sizeof(int));
        if (temp == nullptr){
            std::cerr << "Memory allocation while resizing inside insertEle function failed" << std::endl;
            return;
        }
        arr = temp;
    }

    // if controller gets here, it is guaranteed to have enough space in it to store the element.
    for (int i = outSize; i > ind; i--){
        *(arr+i) = *(arr+i-1);    
    }
    *(arr+ind) = ele;
    outSize++;
}

void DynamicArr::printArr(){

    if (outSize == 0){
        std::cout << "Array is empty..." << std::endl;
        return;
    }

    for (int i = 0; i<outSize; i++){
        std::cout << *(arr+i) << " ";
    }
    std::cout << std::endl;
}

void DynamicArr::deleteEle(int ind){
    for (int i = ind+1; i <= outSize; i++){
        *(arr+i-1) = *(arr+i);
    }
    outSize--;
}

int DynamicArr::searchEle(int ele){
    for (int i = 0; i<outSize; i++){
        if (*(arr+i) == ele) return i;
    }
    return -1;
}

void DynamicArr::clearArr(){
    free(arr);
    outSize = 0;
    inSize = 5;
    int *temp = (int *)calloc(inSize, sizeof(int));
    arr = temp;
}

void DynamicArr::appendEle(int ele){
    insertEle(ele, outSize);
}

void DynamicArr::popEle(){
    deleteEle(outSize-1);
}

void DynamicArr::sortArr(int flagg){
    int j = 0;

    for (int i = 1; i < outSize; i++){
        int curr = *(arr+i);
        for (j = (i-1); (j>=0) && (*(arr+j) > curr); j--){
            *(arr+j+1) = *(arr+j);
        }
        *(arr+j+1) = curr;
    }

    if (flagg == -1){
        reverseArr();
    }
}
















