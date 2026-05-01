//singly linkned list implementation in C, insertion and deletion at beginning
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node **head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void deleteAtBeginning(struct Node **head){
    if (*head == NULL){
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main(){
    struct Node *n1,*n2,*n3,*n4;
    struct Node *Head;
    n1=(struct Node*)malloc(sizeof(struct Node));
    n2=(struct Node*)malloc(sizeof(struct Node));
    n3=(struct Node*)malloc(sizeof(struct Node));
    n4=(struct Node*)malloc(sizeof(struct Node));

    n1->data=10;
    n2->data=20;
    n3->data=30;
    n4->data=40;
    Head = n1;

    n1->next = n2;
    n2->next = n3;
    n3->next=n4;
    n4->next = NULL;
    display(Head);
    insertAtBeginning(&Head, 5);
    display(Head);
    deleteAtBeginning(&Head);
    display(Head);
    return 0;
}