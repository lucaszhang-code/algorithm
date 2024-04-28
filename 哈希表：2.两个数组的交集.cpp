#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

//使用unordered_set
//vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//    unordered_set<int>result_set;
//    unordered_set<int>num_set(nums1.begin(),nums1.end());
//    for(int i:nums2){
//        if(num_set.find(i)!=num_set.end()){
//            result_set.insert(i);
//        }
//    }
//    return vector<int>(result_set.begin(),result_set.end());
//}

//使用数组
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int>result_set;
    int hash[1005]={0};
    for(int i:nums1){
        hash[i]=1;
    }
    for(int i:nums2){
        if(hash[i]==1){
            result_set.insert(i);
        }
    }
    return vector<int>(result_set.begin(),result_set.end());
}

int main(){

    vector<int> nums1 {1,2,2,1};
    vector<int> nums2 {2,2};
     for(int num:intersection(nums1,nums2)){
         cout<<num<<" ";
     }
     cout<<endl;

    return 0;
}