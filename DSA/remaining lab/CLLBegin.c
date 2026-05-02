// Circular linked list implementation in C, insertion and deletion at beginning
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void inBe(struct Node **head, int newData){
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    newNode->data = newData;
    newNode->next = *head;
    if (head!= NULL)
    {
        while (temp->next!= *head){temp = temp->next;}
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;  
    }
    
}

void deBE(struct Node **head){
    struct Node *temp= *head;
    struct Node *toDelete= *head;
    if (*head == NULL){printf("List is empty\n");return;}
    while (temp->next != *head){temp = temp->next;}
    temp->next = toDelete->next;
    free(toDelete);
    *head = temp->next;
}

void display(struct Node *head){
    struct Node *temp = head;
    if(head == NULL){printf("List is empty\n");return;}
    do{
        printf("%d\t", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

int main(){
    struct Node *n1,*n2,*n3,*n4;
    struct Node *Head;

    n1=(struct Node*)malloc(sizeof(struct Node));
    n2=(struct Node*)malloc(sizeof(struct Node));
    n3=(struct Node*)malloc(sizeof(struct Node));
    n4=(struct Node*)malloc(sizeof(struct Node));
    n1->data=10;n2->data=20;
    n3->data=30;n4->data=40;Head=n1;
    n1->next=n2;n2->next=n3;
    n3->next=n4;n4->next=n1;

    display(Head);
    inBe(&Head,5);
    display(Head);
    deBE(&Head);
    display(Head);
    return 0;   
}