#include<stdio.h>
#define MAX 50

struct Stack {
    int top;
    int items[MAX];
};

void initialize(struct Stack *s) {
    s->top=-1;
}

int isEmpty(struct Stack *s) {
    return (s->top)==-1;
}

int isFull(struct Stack *s) {
    return (s->top)==MAX-1;
}

void push(struct Stack *s, int value) {
    if(isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[(++(s->top))] = value;
}

int pop(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

void display(struct Stack *s) {
    printf("\nStack\n");
    for(int i=s->top; i>=0; i--) {
        printf("%d\n", s->items[i]);
    }
    printf("\n");
}
