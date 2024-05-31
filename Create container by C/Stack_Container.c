#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//定义栈结构
typedef struct {
    int data[MAX];
    int top;
} Stack;
//初始化栈
void initStack(Stack* s){
    s -> top = -1;
}

//判断栈是否为空
int isEmpty(Stack* s){
    return s -> top == -1;
}

//判断栈是否已满
int isFull(Stack* s){
    return s->top == MAX - 1;
}

//入栈操作
void push(Stack* s,int value){
    if(isFull(s)){
        printf("栈已满，无法入栈\n");
    }
    else{
        s->data[++(s->top)] = value;
    }
}

//出栈操作
int pop(Stack* s){
    if(isEmpty(s)){
        printf("栈已空，无法出栈\n");
        return -1;
    }
    else{
        return s->data[(s->top)--];
    }
}

//获取栈顶元素
int peek(Stack* s){
    if(isEmpty(s)){
        printf("栈已空，无法出栈\n");
        return -1;
    }
    else{
        return s->data[s->top];
    }
}


int main(){

    Stack s;
    initStack(&s);

    //入栈
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);

    //查看栈顶元素
    printf("栈顶元素: %d\n", peek(&s));

    //出栈
    pop(&s);
    printf("栈顶元素: %d\n", peek(&s));


    return 0;
}

