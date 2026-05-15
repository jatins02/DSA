#include <iostream>

void merge(int arr[], int left[], int leftsize, int right[], int rightsize){
    int i = 0, j = 0, k = 0;
    while (i < leftsize && j < rightsize){
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    }
    while (i < leftsize) arr[k++] = left[i++];
    while (j < rightsize) arr[k++] = right[j++];
}

void recursiveMergeSort(int arr[], int left, int right){
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    recursiveMergeSort(arr, left, mid);         // sort left half
    recursiveMergeSort(arr, mid+1, right);      // sort right half

    int leftArr[mid - left + 1], rightArr[right - mid];

    for (int i = 0; i <= mid-left; i++){
        leftArr[i] = arr[left+i];
    }
    for (int j = 0; j < right-mid; j++){
        rightArr[j] = arr[mid+1+j];
    }
    merge(arr, leftArr, mid-left+1, rightArr, right-mid);
}


int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    for (int i = 0; i<size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    recursiveMergeSort(arr, 0, size-1);

    std::cout << "Sorted Array: ";
    for (int i = 0; i<size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

