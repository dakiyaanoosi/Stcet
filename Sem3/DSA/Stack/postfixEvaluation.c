#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50

struct Stack {
    int top;
    double operands[MAX];
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

void push(struct Stack *s, double value) {
    if(isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->operands[(++(s->top))] = value;
}

double pop(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->operands[(s->top)--];
}

void display(struct Stack *s) {
    printf("\nStack\n");
    for(int i=s->top; i>=0; i--) {
        printf("%.2f\n", s->operands[i]);
    }
    printf("\n");
}

int isDigit(char c) {
    return (c>='0' && c<='9');
}

double evaluate(double a, double b, char op) {
    switch(op) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': if(b==0) {
                    printf("Division by zero not possible\n");
                    exit(1);
                }
        return a/b;
        case '$' :  return pow(a, b);
        default: printf("Invalid Operation: %f %c %f", a, op, b);
        exit(1);
    }
}

int main() {
    char postfix[MAX] = "623+-382/+*2$3+";
    struct Stack s;
    initialize(&s);

    for(int i=0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if(isDigit(c)) {
            push(&s, c-'0');
            display(&s);
        }
        else if(c=='+' || c=='-' || c=='*' || c== '/' || c=='$') {
            double b = pop(&s);
            double a = pop(&s);
            push(&s, evaluate(a, b, c));
            printf("Operation: %c\n", c);
            display(&s);
        }
    }
    printf("Answer: %.1f\n", s.operands[s.top]);
    return 0;
}
