#include<iostream>
using namespace std;
#include<vector>
#include <unordered_map>

unordered_map<int,int> add(vector<int>& nums1,vector<int>& nums2){
    unordered_map<int,int>mp;
    for(int num1:nums1){
        for(int num2:nums2){
            mp[num1+num2]++;
        }
    }
    return mp;
}

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int,int> mp=add(nums1,nums2);
    int count=0;
    for(int num3:nums3){
        for(int num4:nums4){
            if(mp.find(0-num3-num4)!=mp.end()){
                count+=mp[0-num3-num4];
            }
        }
    }
    return count;
}

int main(){

    vector<int>nums1,nums2,nums3,nums4;
    nums1={1,2};
    nums2={-2,-1};
    nums3={-1,2};
    nums4={0,2};

    cout<<fourSumCount(nums1,nums2,nums3,nums4);

    return 0;
}