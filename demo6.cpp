#include <iostream>
using namespace std;
#include <unordered_map>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

ListNode* removeDuplicates(ListNode* head){
    unordered_map<int, int> nodeNum;
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    while(cur->next){
        nodeNum[cur->next->val]++;
        if(nodeNum[cur->next->val] > 1){
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else{
            cur = cur->next;
        }
    }
    return dummyHead->next;
}

void printNode(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
}

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(6);

    removeDuplicates(head);
    printNode(head);

    return 0;
}