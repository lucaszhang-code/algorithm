//#include <iostream>
//using namespace std;
//
//struct ListNode{
//    int val;
//    ListNode* next;
//    ListNode(int x):val(x),next(nullptr){}
//};
//
//ListNode *detectCycle(ListNode *head) {
//    ListNode* fast=head;
//    ListNode* slow=head;
//    while(fast != nullptr && fast->next != nullptr){
//        slow = slow->next;
//        fast = fast->next->next;
//        //fast和slow相遇
//        if(fast==slow){
//            ListNode* index1=fast;
//            ListNode* index2=head;
//            //他们不相遇时都向前移动一个节点
//            while(index1 != index2){
//                index1=index1->next;
//                index2=index2->next;
//            }
//            return index1;
//        }
//    }
//    //如果fast和slow不相遇则不是环形链表
//    return nullptr;
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
//    n6->next=n3;
//
//    cout<<"在第"<<detectCycle(n0)->val<<"个节点进入循环"<<endl;
//
//    return 0;
//}