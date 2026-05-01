//postfix expression to infix expression
#include<stdio.h>
#include<ctype.h>
#include<string.h>


char stack[100][100];
int top = -1;

void push(char *x){
    top++;
    strcpy(stack[top], x);
}

char* pop(){
    if(top == -1)
        return NULL;
    else
        return stack[top--];
}

int main(){
    char exp[100]= "ab+c*";
    char *e, *x, op1[100], op2[100], temp[200];
    
    printf("Postfix expression: %s\n", exp);
    e = exp;
    while(*e != '\0'){
        if(isalnum(*e)){
            temp[0] = *e;
            temp[1] = '\0';
            push(temp);
        }else{
            x = pop();
            strcpy(op2, x);
            x = pop();
            strcpy(op1, x);
            temp[0] = '(';
            temp[1] = '\0';
            strcat(temp, op1);
            strncat(temp, &(*e), 1);
            strcat(temp, op2);
            strcat(temp, ")");
            push(temp);
        }
        e++;
    }
    printf("Infix expression: %s\n", pop());
    return 0;
}