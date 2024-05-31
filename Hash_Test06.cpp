#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++) {
        // 如果数组的第一个值就大于0，我们可以直接返回空数组
        if(nums[i] > 0) return result;
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right) {
            if(nums[i] + nums[left] + nums[right] > 0) right--;
            else if(nums[i] + nums[left] + nums[right] < 0) left++;
            else {
                result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                while(right > left && nums[right] == nums[right - 1]) right--;
                while(right > left && nums[left] == nums[left + 1]) left++;
                right--;
                left++;
            }
        }
    }
    return result;
}

int main(){

    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);
    for(auto i : result){
        cout<<"[";
        for(auto j : i){
            cout<< j <<" ";
        }
        cout<<"]"<<endl;
    }


    return 0;
}