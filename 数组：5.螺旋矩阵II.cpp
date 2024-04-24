//#include <iostream>
//#include <vector>
//using namespace std;
//
//    vector<vector<int>> generateMatrix(int n) {
//        vector<vector<int>>nums(n,vector<int>(n,0));
//        int startX=0;
//        int startY=0;
//        int offset=1;
//        int count=1;
//        int loop=n/2;
//        int i,j;
//        i=0; j=0;
//        while(loop--)
//        {
//            j=startY;
//            i=startX;
//            for(j;j<n-offset;j++)
//            {
//                nums[i][j]= count;
//                count++;
//            }
//            for(i;i<n-offset;i++)
//            {
//                nums[i][j]=count;
//                count++;
//            }
//            for(;j>startY;j--)
//            {
//                nums[i][j]=count;
//                count++;
//            }
//            for(;i>startX;i--)
//            {
//                nums[i][j]=count;
//                count++;
//            }
//            startX++;
//            startY++;
//
//            offset+=1;
//        }
//        if(n%2!=0)
//        {
//            nums[n/2][n/2]=count;
//        }
//        return nums;
//    }
//
//int main()
//{
//    int n=3;
//
//    for(int i=0;i<generateMatrix(n).size();i++)
//    {
//        for(int j=0;j<generateMatrix(n)[0].size();j++)
//        {
//            cout<<generateMatrix(n)[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//
//    return 0;
//}