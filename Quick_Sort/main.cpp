#include <iostream>
#include <vector>

// implementation fails, infinite loop made incase of an already sorted array

void quickSort(std::vector<int> &arr, int arrSize);

int main(){

    std::vector<int> arr = {2, 2, 2};//{22, 12, 5, 2, 1, 7, 14, 2};
    int arrSize = arr.size();
    quickSort(arr, arrSize);

    for (int i : arr){
        std::cout << i << " ";
    }
    return 0;
}

void quickSort(std::vector<int> &arr, int arrSize){
    if (arrSize <= 1) return;

    int *a = nullptr;
    int *b = nullptr;

    int *pivot = &arr[arrSize - 1];
    
    int swapped = 0;
    for (int i = 0; i < arrSize; i++){
        b = &arr[i];
        if (*b <= *pivot){
            a = &arr[swapped];
            // now swap the values at a and b
            int temp = *b;
            *b = *a;
            *a = temp;
            swapped++;
        }
    }

    swapped = (swapped > 0) ? swapped - 1 : 0;       // to counter the last increment of swapped.

    // after this pass, all elements to the right of the pivot should be greater than or equal to the pivot
    // and elements to the left are less than the pivot.


    // now we create two partitions of the array, the left side of the pivot and the right side, then call quicksort on them

    // creating the left and right subarrays:
    std::vector<int> leftArr;
    std::vector<int> rightArr;

    for (int i = 0; i < arrSize; i++){
        if (i < swapped) leftArr.push_back(arr[i]);
        else if (i > swapped) rightArr.push_back(arr[i]);
        else continue;
    }

    quickSort(leftArr, leftArr.size());
    quickSort(rightArr, rightArr.size());

    for (int i = 0; i < arrSize; i++){
        if (i < swapped) arr[i] = leftArr[i];
        else if (i > swapped) arr[i] = rightArr[i - swapped - 1];
        else continue;
    }
}


