#include <iostream>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int record[26] = {0};
    if(ransomNote.size() > magazine.size()) return false;
    for(int i = 0; i < magazine.size(); i++){
        record[magazine[i] - 'a']++;
    }

    for(int i =0; i < ransomNote.size(); i++){
        record[ransomNote[i] - 'a']--;

        if(record[ransomNote[i] - 'a'] < 0) return false;
    }
    return true;
}

int main(){

    string ransomNote = "aa";
    string magazine = "aab";
    bool result = canConstruct(ransomNote, magazine);
    cout << result << endl;

    return 0;
}