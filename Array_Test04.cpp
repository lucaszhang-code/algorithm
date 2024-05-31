#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int i,j,sum,result;
    //result要设一个很大的值
    i=0; sum=0; result=INT32_MAX;
    for(j=0;j<nums.size();j++)
    {
        sum+=nums[j];
        while(sum>=target)
        {
            int subL=j-i+1;
            result=min(subL,result);
            sum-=nums[i];
            i++;
        }
    }
    //如果result没有更新，就返回0
    return result==INT32_MAX?0:result;
}

int main()
{

    vector<int>nums={2,3,1,2,4,3};
    int target=7;
    cout<<minSubArrayLen(target,nums);

    return 0;
}
