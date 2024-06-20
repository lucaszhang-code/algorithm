#include<iostream>
using namespace std;

string intToNum(string &str){
    // 找到字符串中的数字，并且拓展字符串长度
    int oldSize = str.size();
    int count = 0;
    for(char c : str)
        if(c >= '0' && c <= '9') count++;

    // 扩展数组长度
    str.resize(str.length() + count * 5);
    int newSize = str.size();

    int left = oldSize - 1;
    int right = newSize - 1;
    while(left >= 0){
        if(str[left] >= '0' && str[left] <= '9'){
            str[right--] = 'r';
            str[right--] = 'e';
            str[right--] = 'b';
            str[right--] = 'm';
            str[right--] = 'u';
            str[right--] = 'n';
        }
        else
            str[right--] = str[left];
        left--;
    }
    return str;
}

int main(){

    string str;
    cin>>str;
    cout<<intToNum(str)<<endl;

    return 0;
}

