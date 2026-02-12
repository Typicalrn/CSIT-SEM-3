#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Enqueue(struct Node **front, struct Node **rear,int value){
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(*front == NULL){
        *front=newNode;
        *rear=newNode;
        (*front)->next = NULL;
        (*rear)->next = NULL;
    }else{
        (*rear)->next = newNode;
        *rear = newNode;
        (*rear)->next= NULL;
    }
}

void Dequeue(struct Node **front, struct Node **rear){
    if(*front == NULL){
        printf("Queue is empty\n");
    }else{
        struct Node *temp = *front;
        *front = (*front)->next;
        free(temp);
        if(*front == NULL){
            *rear = NULL;
        }
    }
}

void display(struct Node *front){
    struct Node *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


int main(){
    struct Node *front = (struct Node*)malloc(sizeof(struct Node));
    struct Node *rear = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n1,*n2,*n3,*n4;
    n1=(struct Node*)malloc(sizeof(struct Node));
    n2=(struct Node*)malloc(sizeof(struct Node));
    n3=(struct Node*)malloc(sizeof(struct Node));
    n4=(struct Node*)malloc(sizeof(struct Node));
    n1->data=10;
    n2->data=20;
    n3->data=30;
    n4->data=40;

    front=NULL;
    rear=NULL;

    Enqueue(&front,&rear,n1->data);
    Enqueue(&front,&rear,n2->data);
    Enqueue(&front,&rear,n3->data);
    Enqueue(&front,&rear,n4->data);
    display(front);

    Dequeue(&front,&rear);
    display(front);


    return 0;
}