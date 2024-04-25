#include <iostream>
#include <string>
#include <algorithm> // 添加头文件以使用 reverse 函数

using namespace std;

string add(string str1, string str2) {
    int size1 = str1.size() - 1;
    int size2 = str2.size() - 1;
    int digit = 0;
    string result;
    while (size1 >= 0 || size2 >= 0 || digit > 0) { // 这里应该考虑进位 digit
        int num1 = size1 >= 0 ? (str1[size1] - '0') : 0;
        int num2 = size2 >= 0 ? (str2[size2] - '0') : 0;
        int sum = num1 + num2 + digit; // 这里需要加上 digit
        digit = sum / 10; // 计算进位
        sum = sum % 10; // 取个位数
        result += to_string(sum);
        size1--;
        size2--;
    }
    reverse(result.begin(), result.end());
    return result; // 将结果返回，而不是直接打印
}

int main() {
    string str1 = "1223";
    string str2 = "789";
    cout << add(str1, str2) << endl; // 调用函数后输出结果

    return 0;
}
