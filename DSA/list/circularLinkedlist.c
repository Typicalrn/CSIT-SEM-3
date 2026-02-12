#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int newData){
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    newNode->data = newData;
    newNode->next = *head;
    if (head!= NULL)
    {
        while (temp->next!= *head)
        {
            temp = temp->next;

        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
        
    }
    
}

void insertAtLast(struct Node **head, int newData){
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    newNode->data = newData;
    newNode->next = *head;
    if (head!= NULL)
    {
        while (temp->next!= *head)
        {
            temp = temp->next;

        }
        newNode->next = *head;
        temp->next = newNode;
        
    }
    
}

void DeleteFirstNode(struct Node **head){
    struct Node *temp= *head;
    struct Node *toDelete= *head;
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = toDelete->next;
    free(toDelete);
    *head = temp->next;
}

void DeleteLastNode(struct Node **head){
    struct Node *temp;
    struct Node *LastNode=*head;
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (LastNode->next != *head)
    {
        temp = LastNode;
        LastNode = LastNode->next;
    }
    temp->next = LastNode->next;
    free(LastNode);
}

void display(struct Node *head){
    struct Node *temp = head;
    if(head == NULL) return;
    do{
        printf("%d\n", temp->data);
        temp = temp->next;
    }while(temp != head);
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
    Head=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n1;

    insertAtBeginning(&Head,5);
    insertAtLast(&Head,50);

    DeleteFirstNode(&Head);
    DeleteLastNode(&Head);

    display(Head);
}