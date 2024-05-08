#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node != nullptr) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            } else {
                vec.push_back(INT_MIN);
            }
        }
        int left = 0;
        int right = vec.size() - 1;
        while (left < right) {
            if (vec[left] != vec[right]) {
                return false;
            }
            left++;
            right--;
        }
    }
    return true;
}

int main(){
    /* 初始化二叉树 */
// 初始化节点
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
// 构建节点之间的引用（指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    string result=isSymmetric(n1) == 0? "false":"true";
    cout<<result<<endl;

    return 0;
}


