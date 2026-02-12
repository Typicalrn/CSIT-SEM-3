//implementing Doubly Linked List in C
#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void display(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void displayFromLast(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->prev;
    }
}

void insertAtBeginning( struct Node **head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;    
}
void insertAtLast( struct Node **head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = *head;
    if (*head != NULL){
        struct Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    } else {
        *head = newNode;
    }
}

void insertAtPosition(struct Node **head){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    int position,dat;
    printf("Enter the position to enter:");
    scanf("%d",&position);
    printf("Enter data to enter:");
    scanf("%d",&dat);
    newNode->data= dat;
    struct Node *temp = *head;
    for (int i = 0; i < position-1; i++)
    {
        temp = temp->next;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;

}

void DeleteBegining(struct Node **head){
    *head= (*head)->next;
    (*head)->prev=NULL;
}

int DeleteLast(struct Node **head){
    struct Node *temp= *head;
    if (*head == NULL)
    {
        printf("List Underflow");
        return 0;
    }
    while(temp->next != NULL){
        temp->next=temp;
    }
    temp->prev->next=NULL;
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

    n1->prev = NULL;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;


    insertAtBeginning(&Head,5);
    insertAtLast(&Head, 50);
    insertAtPosition(&Head);


    printf("Displaying from the beggining:\n");
    display(Head);
    DeleteBegining(&Head);
    

    Head=n4;
    printf("Displaying from the last:\n");
    displayFromLast(Head);
    DeleteLast(&Head);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(Head);

    return 0;
}