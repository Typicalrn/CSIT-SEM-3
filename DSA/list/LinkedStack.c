#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *top){
    struct Node *temp = top;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void Push(struct Node **top, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    if (top==NULL){
        newNode->next = NULL;
        *top = newNode;
    }else{
        newNode->next = *top;
        *top= newNode;
    }
    
    *top = newNode;
}

void pop(struct Node **top){
    if(*top == NULL){
        printf("Stack Underflow\n");
        return;
    }
    struct Node *temp=*top;
    *top = (*top)->next;
    free(temp);
}


int main(){
    struct Node *n1,*n2,*n3,*n4;
    struct Node *top;
    n1=(struct Node*)malloc(sizeof(struct Node));
    n2=(struct Node*)malloc(sizeof(struct Node));
    n3=(struct Node*)malloc(sizeof(struct Node));
    n4=(struct Node*)malloc(sizeof(struct Node));
    n1->data=10;
    n2->data=20;
    n3->data=30;
    n4->data=40;
    top = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next=n4;
    n4->next = NULL;

    Push(&top,50);
    printf("Before pop operation:\n");
    display(top);
    pop(&top);
    printf("After pop operation:\n");
    display(top);

    return 0;
}