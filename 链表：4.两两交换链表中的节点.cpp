#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* dummyHead=new ListNode(0);
    dummyHead->next=head;
    ListNode* cur=dummyHead;
    while(cur->next != nullptr && cur->next->next != nullptr)
    {
        ListNode* tmp=cur->next;
        ListNode* tmp1=cur->next->next->next;
        cur->next=cur->next->next;
        cur->next->next=tmp;
        tmp->next=tmp1;
        cur=cur->next->next;
    }
    return dummyHead->next;
}

int main(){

        //1->2->6->3->4->5->6
    ListNode* n0=new ListNode(1);
    ListNode* n1=new ListNode(2);
    ListNode* n2=new ListNode(6);
    ListNode* n3=new ListNode(3);
    ListNode* n4=new ListNode(4);
    ListNode* n5=new ListNode(5);
    ListNode* n6=new ListNode(6);
    n0->next=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;

    ListNode* head=swapPairs(n0);
    while(head!= nullptr)
    {
        cout<<head->val<<" ";
        head=head->next;
    }

    return 0;
}