#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
    //使用数组做哈希表
    int hash[26]={0};
    for(char i : s){
        hash[i-'a']++;
    }
    for(char i : t){
        hash[i-'a']--;
    }
    for(int i=0;i<26;i++){
        if(hash[i]!=0){
            return false;
        }
    }
    return true;
}

int main(){

    string s="anagram";
    string t="nagaram";
    cout<<isAnagram(s,t)<<endl;


    return 0;
}
