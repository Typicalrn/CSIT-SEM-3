#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int n)  { stack[++top] = n; }
int  pop()        { return stack[top--]; }
int  isEmpty()    { return top == -1; }

int evaluatePostfix(char* postfix) {
    for(int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];

        // Step 2.1 — operand
        if(isdigit(c)) {
            push(c - '0');    // convert char to int
        }
        // Step 2.2 — operator
        else {
            int op2 = pop();
            int op1 = pop();
            switch(c) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '$': push(pow(op1, op2)); break;
            }
        }
    }
    // Step 3 — final result
    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter postfix: ");
    scanf("%s", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    return 0;
}