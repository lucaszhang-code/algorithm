#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int size;
}Queue;

//初始化队列
void initQueue(Queue* q){
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

//判断队列是否为空
int isEmpty(Queue* q){
    return q->size == 0;
}

//判断队列是否已满
int isFull(Queue* q){
    return q->size == MAX - 1;
}

//入队操作
void push(Queue* q, int value){
    if(isFull(q)){
        printf("队列已满，无法入队\n");
    }
    else{
        q->data[q->rear] = value;
        q->rear = (q->rear + 1) % MAX;
        q->size++;
    }
}

//出队操作
int pop(Queue* q){
    if(isEmpty(q)){
        printf("队列已空，无法出队\n");
        return -1;
    }
    else{
        int value = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->size--;
        return value;
    }
}

//获取队列头部元素
int front(Queue* q){
    if(isEmpty(q)){
        printf("队列已空，无法出队\n");
        return -1;
    }
    else{
        return q->data[q->front];
    }
}

int main(){

    Queue q;
    initQueue(&q);

    //入队操作
    push(&q,10);
    push(&q,20);
    push(&q,30);
    push(&q,40);
    push(&q,50);

    //获取队首元素
    printf("队首元素是： %d\n", front(&q));

    //出队操作
    pop(&q);
    printf("队首元素是： %d\n", front(&q));

    return 0;
}
