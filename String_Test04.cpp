#include <iostream>
using namespace std;
#include <algorithm>

//hello world


void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
    int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
    for (int i = 0; i < s.size(); ++i) { //
        if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
            if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0 说明不是第一个单词，需要在单词前添加空格。
            while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow); //slow的大小即为去除多余空格后的大小。
}

string reverseWords(string s) {
    removeExtraSpaces(s);
    reverse(s.begin(), s.end());
    int slow = 0;
    for(int fast = 0; fast < s.size(); fast++){
        if(s[fast] == ' '){
            reverse(s.begin() + slow, s.begin() + fast);
            slow = fast + 1;
        }
        if(fast == s.size() - 1){
            reverse(s.begin() + slow, s.end());
        }
    }
    return s;
}

int main(){

    string s = "  the sky is  blue  ";
    cout<<reverseWords(s)<<endl;

    return 0;
}