#include <iostream>

void mergeSort(int arr[], int length);
void merge(int leftArr[], int rightArr[], int arr[], int arrlength);

int main(){

    int arr[] = {22, 12, 5, 2, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, size);

    for (int i = 0; i<size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void mergeSort(int arr[], int length){
    //int length = sizeof(arr) / sizeof(arr[0]);

    if (length <= 1) return;

    int mid = length/2;
    int *leftArr = new int[mid];
    int *rightArr = new int[length - mid];

    int l = 0; // for left array
    int r = 0; // for right array

    for (l; l<length; l++){
        if (l<mid){
            leftArr[l] = arr[l];
        }
        else{
            rightArr[r] = arr[l];
            r++;
        }
    }
    mergeSort(leftArr, mid);
    mergeSort(rightArr, length-mid);
    merge(leftArr, rightArr, arr, length);
}

void merge(int leftArr[], int rightArr[], int arr[], int arrlength){
    //int arrlength = sizeof(arr)/sizeof(arr[0]);
    int leftsize =  arrlength / 2;                   // sizeof(leftArr)/sizeof(leftArr[0]);
    int rightsize = arrlength - leftsize;            // sizeof(rightArr)/sizeof(rightArr[0]);

    int i = 0, l = 0, r = 0;                         // indices
    while (l < leftsize && r < rightsize){
        if (leftArr[l] <= rightArr[r]){
            arr[i] = leftArr[l];
            i++;
            l++;
        }
        else{
            arr[i] = rightArr[r];
            i++;
            r++;
        }
    }

    while (l<leftsize){
        arr[i] = leftArr[l];
        i++;
        l++;
    }
    while (r<rightsize){
        arr[i] = rightArr[r];
        i++;
        r++;
    }    
}




