#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        int s=target-nums[i];
        auto iter=map.find(s);
        if(iter!=map.end())
            return {iter->second,i};
        map.insert(pair<int,int>(nums[i],i));
    }
    return{};
}

int main(){

    vector<int>nums {2,7,11,15};
    int target=18;
    cout<<twoSum(nums,target).at(0)<<" "<<twoSum(nums,target).at(1)<<endl;


    return 0;
}