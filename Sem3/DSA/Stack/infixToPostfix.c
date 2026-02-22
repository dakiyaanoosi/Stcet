#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50

struct Stack {
    int top;
    char operators[MAX];
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

void push(struct Stack *s, char value) {
    if(isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->operators[(++(s->top))] = value;
}

char pop(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return (s->operators[(s->top)--]);
}

char peek(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->operators[s->top];
}

void display(struct Stack *s) {
    printf("\nStack\n");
    for(int i=s->top; i>=0; i--) {
        printf("%c\n", s->operators[i]);
    }
    printf("\n");
}

int isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='$' || c=='^');
}

int isVariable(char c) {
    return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

int isOpeningParen(char c) {
    return (c=='[' || c=='{' || c=='(');
}

int isClosingParen(char c) {
    return (c==']' || c=='}' || c==')');
}

int priority(char c) {
    if(c=='$' || c=='^') return 3;
    if(c=='*' || c=='/') return 2; 
    if(c=='+' || c=='-') return 1;
    return 0;
}

int main() {    
    char infix[MAX] = "((A-(B+C))*D)$(E+F)";
    char postfix[MAX] = "";
    int length = 0;
    struct Stack s;
    initialize(&s);

    for(int i=0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if(isOpeningParen(c)) push(&s, c);
        else if(isClosingParen(c)) {
            while(!isOpeningParen(peek(&s))) {
                postfix[length++] = pop(&s);
            }
            pop(&s);
        }
        if(isVariable(c)) postfix[length++] = c;
        else if(isOperator(c)) {
            while(!isEmpty(&s) && priority(c) <= priority(peek(&s))) {
                postfix[length++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (!isEmpty(&s)) {
        postfix[length++] = pop(&s);
    }
    postfix[length] = '\0';

    printf("Postfix: %s", postfix);
    return 0;
}
