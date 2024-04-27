//#include <iostream>
//using namespace std;
//#include <vector>
//#include <algorithm>
//
//void print(vector<int> &vec){
//    for(auto num:vec){
//        cout<<num<<" ";
//    }
//    cout<<endl;
//}
//
//int main(){
//
//    vector<int>vec {0,11,3,19,22,7,1,5};
//    auto f=[](int a,int b){
//        return a>b;
//    };
//    sort(vec.begin(),vec.end(),f);
//    print(vec);
//
//    auto sum=[](int x,int y)->int{
//        return x+y;
//    };
//    cout<<sum(1,2)<<endl;
//
//    //变量捕获
//    int N=10;
//    int M=100;
//    auto g=[&N,M,K=5](int i)->int{
//        N=20;
//        //=10;
//        cout<<K<<endl;
//        return M*i;
//    };
//    cout<<g(2)<<endl; //200
//    cout<<N<<endl; //20
//    cout<<M<<endl;
//
//
//    return 0;
//}