#include <iostream>
using namespace std;
#include <array>

void insertionSort(array<int, 6> &arr){
   for(int i = 1; i < 6; i++){
       int key = arr[i];
       int j = i - 1;
       while(j >= 0 && arr[j] > key){
           arr[j + 1] = arr[j];
           j--;
       }
       arr[j + 1] = key;
   }
}

int main(){

    array<int, 6> arr = {4,1,3,1,5,2};
    insertionSort(arr);

    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }

    return 0;
};