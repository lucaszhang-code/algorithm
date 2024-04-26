///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
//    string input(ListNode* l);
//};
//
//string Solution::input(ListNode* l) {
//    ListNode* dummyHead = new ListNode(0);
//    dummyHead->next = l;
//    ListNode* cur = dummyHead;
//    string str;
//    while (cur->next != nullptr) {
//        str += to_string(cur->next->val);
//        cur = cur->next;
//    }
//    reverse(str.begin(), str.end()); // 反转字符串
//    return str;
//}
//
//
//ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
//    string result;
//    int carry = 0; // 进位
//    string num1=input(l1);
//    string num2=input(l2);
//
//    // 从个位开始逐位相加
//    int i = num1.size() - 1, j = num2.size() - 1;
//    while (i >= 0 || j >= 0 || carry > 0) {
//        int digit1 = (i >= 0) ? (num1[i--] - '0') : 0;
//        int digit2 = (j >= 0) ? (num2[j--] - '0') : 0;
//        int sum = digit1 + digit2 + carry;
//        carry = sum / 10; // 计算进位
//        result.push_back('0' + (sum % 10)); // 将当前位的数字加入结果字符串
//    }
//
//
//    ListNode dummy(0);
//    ListNode* tail = &dummy;
//
//    for (char c : result) {
//        int digit = c - '0'; // 将字符转换为数字
//        tail->next = new ListNode(digit);
//        tail = tail->next;
//    }
//
//    return dummy.next;
//}