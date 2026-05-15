#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int left, int mid, int right){
    std::vector<int> leftArr(arr.begin()+left, arr.begin()+mid+1);
    std::vector<int> rightArr(arr.begin()+mid+1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    while ( i < leftArr.size() && j < rightArr.size()){
        arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];
    }

    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];
}

void iterativeMergeSort(std::vector<int> &arr){
    int n = arr.size();
    for (int currsize = 1; currsize < n; currsize *= 2){
        for (int left  = 0; left < n; left += 2*currsize){
            int mid = std::min(left+currsize - 1, n-1);
            int right = std::min(left + 2 * currsize -1, n-1);
            merge(arr, left, mid, right);
        }
    }
}

int main(){
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Original Array: ";
    for (int i : arr){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    iterativeMergeSort(arr);

    std::cout << "Sorted Array: ";
    for (int i : arr){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}