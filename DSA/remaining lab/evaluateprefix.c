#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int n)  { stack[++top] = n; }
int  pop()        { return stack[top--]; }
int  isEmpty()    { return top == -1; }

int evPre(char* prefix) {
    int n = strlen(prefix);

    // Step 2 — scan RIGHT TO LEFT
    for(int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        // Step 2.1 — operand
        if(isdigit(c)) {
            push(c - '0');
        }
        // Step 2.2 — operator
        else {
            int op1 = pop();
            int op2 = pop();
            switch(c) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }
    return pop();
}

int main() {
    char prefix[MAX];
    printf("Enter prefix: ");
    scanf("%s", prefix);
    printf("Result: %d\n", evPre(prefix));
    return 0;
}