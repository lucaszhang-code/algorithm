#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int>result(nums.size(),0);
    int k=nums.size()-1;
    for(int i=0,j=nums.size()-1;i<=j;)
    {
        if(pow(nums[i],2)>pow(nums[j],2))
        {
            result[k--]=pow(nums[i],2);
            i++;
        }
        else
        {
            result[k--]=pow(nums[j],2);
            j--;
        }
    }
    return result;
}

int main()
{

    vector<int>nums={-4,-1,0,3,10};
    sortedSquares(nums);

    return 0;
}

