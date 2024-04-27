//#include <iostream>
//using namespace std;
//
//struct ListNode{
//    int val;
//    ListNode* next;
//    ListNode(int x):val(x),next(nullptr){}
//};
//
//ListNode* removeNthFromEnd(ListNode* head, int n) {
//    ListNode* dummyHead=new ListNode(0);
//    dummyHead->next=head;
//    ListNode* fast=dummyHead;
//    ListNode* slow=dummyHead;
//
//    n++;
//    while(n-- && fast!= nullptr){
//        fast=fast->next;
//    }
//    while (fast)
//    {
//        fast=fast->next;
//        slow=slow->next;
//    }
//    ListNode* tmp=slow->next;
//    slow->next=slow->next->next;
//    //释放内存
//    delete tmp;
//
//    return dummyHead->next;
//}
//
//int main(){
//
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
//    ListNode* head= removeNthFromEnd(n0,2);
//    while(head){
//        cout<<head->val;
//        head=head->next;
//    }
//
//    return 0;
//}