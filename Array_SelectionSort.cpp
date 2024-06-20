#include <iostream>
#include <array>
using namespace std;

void selectionSort(array<int, 9> &arr){
    for(int i = 0; i < arr.size() - 1; i++){
        int min = i;
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}

int main(){

    array<int, 9> arr = {8, 49, 38, 65, 97, 13, 76, 27, 49};
    selectionSort(arr);

    return 0;
}