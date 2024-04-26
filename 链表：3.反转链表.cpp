//#include <iostream>
//using namespace std;
//
//struct ListNode{
//    int val;
//    ListNode* next;
//    ListNode(int x):val(x),next(nullptr){}
//};
//
////双指针
////ListNode* reverseList(ListNode* head) {
////    ListNode* cur=head;
////    ListNode* pre=NULL;
////    while(cur)
////    {
////        ListNode* tmp=cur->next;
////        cur->next=pre;
////        pre=cur;
////        cur=tmp;
////    }
////    return pre;
////}
//
////递归解法
////ListNode* reverse(ListNode* cur,ListNode* pre){
////    if(cur== nullptr) return pre;
////    ListNode* tmp=cur->next;
////    cur->next=pre;
////    return reverse(tmp,cur);
////}
////
////ListNode* reverseList(ListNode* head) {
////    return reverse(head, nullptr);
////}
//
//
//int main(){
//    //1->2->6->3->4->5->6
//    ListNode* n0=new ListNode(1);
//    ListNode* n1=new ListNode(2);
//    ListNode* n2=new ListNode(6);
//    ListNode* n3=new ListNode(3);
//    ListNode* n4=new ListNode(4);
//    ListNode* n5=new ListNode(5);
//    ListNode* n6=new ListNode(6);
//    n0->next=n1;
//    n1->next=n2;
//    n2->next=n3;
//    n3->next=n4;
//    n4->next=n5;
//    n5->next=n6;
//
//    ListNode* head=reverseList(n0);
//    while(head!= nullptr)
//    {
//        cout<<head->val;
//        head=head->next;
//    }
//
//    return 0;
//}