#include <iostream>
#include "dynamicArr.h"

int main(){
    DynamicArr arr(8);
    arr.insertEle(5, 0);
    arr.insertEle(69, 1);
    arr.insertEle(22, 2);
    arr.insertEle(12, 3);

    arr.reverseArr();
    arr.printArr();

    arr.deleteEle(2);
    arr.printArr();

    int tofind = 22;
    int foundind = arr.searchEle(tofind);
    if (foundind >= 0){
        std::cout << tofind << " found at index "<< foundind << std::endl;
    }
    else if (foundind == -1){
        std::cout << tofind << " was not found" << std::endl;
    }

    arr.clearArr();
    arr.printArr();
    
    arr.insertEle(22, 0);
    arr.insertEle(12, 1);
    arr.insertEle(5, 2);
    arr.appendEle(2);
    arr.appendEle(1);
    arr.appendEle(7);

    arr.popEle();
    arr.appendEle(44);

    arr.printArr();
    arr.sortArr(-1);
    arr.printArr();

    return 0;
}