//#include <iostream>
//using namespace std;
//
///* 链表节点结构体 */
//struct ListNode {
//    int val;  // 节点上存储的元素
//    ListNode *next;  // 指向下一个节点的指针
//    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
//};
//
////ListNode* removeElements(ListNode* head, int val) {
////    //移除头结点
////    while(head!=NULL && head->val==val)
////    {
////        ListNode* tmp=head;
////        head=head->next;
////        delete tmp;
////    }
////    ListNode *cur=head;
////    while(cur!=NULL && cur->next!=NULL)
////    {
////        if(cur->next->val==val)
////        {
////            ListNode* tmp=cur->next;
////            cur->next=cur->next->next;
////            delete tmp;
////        }
////        else
////        {
////            cur=cur->next;
////        }
////    }
////    return head;
////}
//
////虚拟头结点
//ListNode* removeElements(ListNode* head, int val) {
//    ListNode* dummyHead=new ListNode(0); //设置一个虚拟头结点
//    dummyHead->next=head; //把虚拟头结点放在head的前面
//   ListNode* cur=dummyHead;
//   while(cur->next!=NULL)
//   {
//       if(cur->next->val==val)
//       {
//           ListNode* tmp=cur->next;
//           cur->next=cur->next->next;
//           delete tmp;
//       }
//       else
//       {
//           cur=cur->next;
//       }
//   }
//   //返回新链表的头结点
//    return dummyHead->next;
//}
//
//
//int main()
//{
//
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
//    removeElements(n0,6);
//
//
//
//    return 0;
//}