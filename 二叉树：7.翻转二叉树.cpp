//#include <iostream>
//#include<queue>
//#include<vector>
//#include <algorithm>
//using namespace std;
//
//struct TreeNode{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
//};
//
//TreeNode* invertTree(TreeNode* root) {
//    queue<TreeNode*> que;
//    if(root != nullptr) que.push(root);
//    while(!que.empty()){
//        int size=que.size();
//        for(int i=0;i<size;i++){
//            TreeNode* node=que.front();
//            que.pop();
//            if(node->left) que.push(node->left);
//            if(node->right) que.push(node->right);
//
//            swap(node->left,node->right);
//        }
//    }
//    return root;
//}
//
//vector<vector<int>> printTree(TreeNode* root){
//    queue<TreeNode*> que;
//    vector<vector<int>> result;
//    if(root != nullptr) que.push(root);
//    while(!que.empty()){
//        int size = que.size();
//        vector<int> vec;
//        for(int i=0;i<size;i++){
//            TreeNode* node=que.front();
//            que.pop();
//            vec.push_back(node->val);
//            if(node->left) que.push(node->left);
//            if(node->right) que.push(node->right);
//        }
//        result.push_back(vec);
//    }
//    return result;
//}
//
//
//int main(){
//
//    /* 初始化二叉树 */
//// 初始化节点
//    TreeNode* n1 = new TreeNode(1);
//    TreeNode* n2 = new TreeNode(2);
//    TreeNode* n3 = new TreeNode(3);
//    TreeNode* n4 = new TreeNode(4);
//    TreeNode* n5 = new TreeNode(5);
//// 构建节点之间的引用（指针）
//    n1->left = n2;
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//
//    TreeNode* newRoot=invertTree(n1);
//    vector<vector<int>> vec= printTree(newRoot);
//
//    for(auto &i : vec){
//        for(auto &j : i){
//            cout<<j<<" ";
//        }
//    }
//    cout<<endl;
//
//    return 0;
//}
//
//
