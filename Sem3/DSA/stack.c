#include<stdio.h>
#define SIZE 50

int stack[SIZE];
int top=-1;

void push(int value) {
    if(top==SIZE-1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    top++;
    stack[top]=value;
}

void pop() {
    if(top==-1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }
    top--;
}

void peek() {
    if(top==-1) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void display() {
    if(top==-1) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("STACK: [");
    for(int i=top; i>0; i--)
    printf("%d, ", stack[i]);
    printf("%d]\n",stack[0]);
}