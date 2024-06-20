#include <iostream>
#include <array>

using namespace std;

void bubbleSort(array<int, 6> arr){
    for (int i = 0; i < 6; ++i) {
        for(int j = i + 1; j < 6; ++j){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int num : arr){
        cout << num << " ";
    }
}

int main(){

    array<int, 6> arr ={11,34,21,34,78,35};
    bubbleSort(arr);

    return 0;
}