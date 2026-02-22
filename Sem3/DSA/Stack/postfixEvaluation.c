#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50

struct stack {
    int top;
    double operands[MAX];
};

void printStack(struct stack *s) {
    printf("Stack: ");
    for (int i=0; i<=s->top; i++) {
        printf("%.2f ", s->operands[i]);
    }
    printf("\n\n");
}

void push(struct stack *s, double element) {
    if(s->top >= MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    s->operands[++(s->top)] = element;
}

double pop(struct stack *s) {
    if(s->top <= -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->operands[(s->top)--];
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
    struct stack s;
    s.top=-1;

    for(int i=0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if(isDigit(c)) {
            push(&s, c-'0');
            printStack(&s);
        }
        else if(c=='+' || c=='-' || c=='*' || c== '/' || c=='$') {
            double b = pop(&s);
            double a = pop(&s);
            push(&s, evaluate(a, b, c));
            printf("Operation: %c\n", c);
            printStack(&s);
        }
    }
    printf("Answer: %.1f\n", s.operands[s.top]);
    return 0;
}
