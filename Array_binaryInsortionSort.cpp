#include <iostream>
#include <vector>
#include <array>
using namespace std;

void binaryInsertionSort(array<int, 10> &arr) {
    for (int i = 1; i < 10; ++i) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;

        // ʹ�ö��ֲ����ҵ�����λ��
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // ��Ԫ�ز��뵽��ȷλ�ã���������Ԫ������
        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

int main() {
    array<int, 10> arr = {9, 13, 8, 2, 5, 13, 7, 1, 15, 11};
    binaryInsertionSort(arr);
    cout << "�۰�������������飺";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << std::endl;
    return 0;
}
