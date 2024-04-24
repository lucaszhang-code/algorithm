#include <iostream>
using namespace std;

class MyLinkedList{
public:
    struct NodeList{
        int val;
        NodeList* next;
        NodeList(int x):val(x),next(NULL){}
    };

//初始化
    MyLinkedList() {
        _dummyHead = new NodeList(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
       _size = 0;
    }

    //获取第n个链表的值
    int get(int index) {
        if(index<0||index> _size-1)
            return -1;
        NodeList* cur=_dummyHead->next;
        while(index)
        {
            cur=cur->next;
            index--;
        }
        return cur->val;
    }

    //头部插入节点
    void addAtHead(int val) {
        NodeList* newNode=new NodeList(val);
        //注意顺序问题
       newNode->next=_dummyHead->next;
       _dummyHead->next=newNode;
       _size++;
    }

    //在尾部插入节点
    void addAtTail(int val) {
        NodeList* cur=_dummyHead;
        NodeList* newNode=new NodeList(val);
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=newNode;
        _size++;
    }

    //在第index个节点添加元素
    void addAtIndex(int index, int val) {
        if(index > _size) return;
        if(index < 0) index = 0;
        NodeList* cur=_dummyHead;
        NodeList* newNode=new NodeList(val);
        while(index--)
        {
            cur=cur->next;
        }
        newNode->next=cur->next;
        cur->next=newNode;
        _size++;
    }

    //在index节点之前删除节点
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        NodeList* cur=_dummyHead;
        while(index--)
        {
            cur=cur->next;
        }
        NodeList* tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        _size--;
    }


private:
    int _size;
   NodeList* _dummyHead;
};



int main()
{

    return 0;
}
