#include<stdio.h>
#define MAX 50

struct Stack {
    int top;
    char parenthesis[MAX];
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
    s->parenthesis[(++(s->top))] = value;
}

int pop(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->parenthesis[(s->top)--];
}

int peek(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->parenthesis[s->top];
}

int main() {
    char expression[MAX] = "(((((((((())))))))))";
    int valid=1;
    struct Stack s;
    initialize(&s);
    for(int i=0; expression[i]!='\0'; i++) {
        char c = expression[i];
        if(c=='[' || c=='{' || c=='(') {
            push(&s, c);
        }
        else if(c==']' && pop(&s)!='[' || c=='}' && pop(&s) != '{' || c==')' && pop(&s) != '(') {
            valid=0;
            break;
        }
    }
    if(valid && isEmpty(&s)) printf("Balanced.\n");
    else printf("Unbalanced.\n");

    return 0;
}
