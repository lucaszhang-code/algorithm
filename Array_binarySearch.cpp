#include <iostream>
using namespace std;
#include <vector>
#include <array>

int binarySearch(vector<int> &arr, int key){
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] > key) left = mid + 1;
        if(arr[mid] < key) right = mid - 1;
        if(arr[mid] == key) return mid;
    }
    return -1;
}

int main(){

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binarySearch(arr, 5);

    return 0;
}
