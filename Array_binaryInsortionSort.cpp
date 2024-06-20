#include <iostream>
#include <vector>
#include <array>
using namespace std;

void binaryInsertionSort(array<int, 10> &arr) {
    for (int i = 1; i < 10; ++i) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;

        // 使用二分查找找到插入位置
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // 将元素插入到正确位置，并将后续元素右移
        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

int main() {
    array<int, 10> arr = {9, 13, 8, 2, 5, 13, 7, 1, 15, 11};
    binaryInsertionSort(arr);
    cout << "折半插入排序后的数组：";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << std::endl;
    return 0;
}
