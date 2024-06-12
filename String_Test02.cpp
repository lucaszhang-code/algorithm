#include <iostream>
using namespace std;
#include<algorithm>

string reverseStr(string s, int k) {
    for(int i = 0; i < s.size(); i += 2 * k){
        if(i + k <= s.size())
            reverse(s.begin() + i, s.begin() + i + k);
        else
            reverse(s.begin() + i, s.end());
    }
    return s;
}

int main(){

    string s = "abcdefg";
    cout << reverseStr(s, 2) << endl;

    return 0;
}