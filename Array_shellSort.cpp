#include <iostream>
using namespace std;
#include <array>
#include <algorithm>

//void shellSort(array<int,10> &arr){
//    int gap = arr.size();
//    while (true){
//        gap = gap / 2;
//        for(int i = 0; i < gap; i++){
//            for(int j = i + gap; j < arr.size(); j += gap){
//                int temp = arr[j];
//                int k;
//                for(k = j - gap; k >= 0 && arr[k] > temp; k = k - gap){
//                    arr[k + gap] = arr[k];
//                }
//                arr[k + gap] = temp;
//            }
//        }
//        if(gap == 1) break;
//    }
//}


void shellSort(array<int, 10> &arr) {
    int gapArr[3] = {5, 3, 1};
    int n = arr.size();
    int index = 0;
    // 初始化间隔值
   while(index < 3){
       int gap = gapArr[index++];
        // 从间隔值开始进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // 将arr[i]插入到已排序的子数组中
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        for(int num : arr) cout<<num<<" ";
        cout<<endl;
    }
}



int main(){

    array<int,10> arr = {9,13,8,2,5,13,7,1,15,11};
    shellSort(arr);
    for(int num : arr){
        cout<<num<<" ";
    }

    return 0;
}