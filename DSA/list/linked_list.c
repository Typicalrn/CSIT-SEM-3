#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void insertAtBeginning(struct Node **head, int newData){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
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


    //insert node at the end
    struct Node *endNode;
    endNode = (struct Node*)malloc(sizeof(struct Node));
    endNode->data=50;
    endNode->next=NULL;
    if (Head==NULL)
    {
        Head=endNode;
    }else{
        struct Node *temp=Head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=endNode;
    }

    
    
    

    insertAtBeginning(&Head, 5);
    //insert node at specified position
    struct Node *posNode;
    posNode=(struct Node*)malloc(sizeof(struct Node));
    posNode->data=25;
    int position;
    printf("Enter the position to insert the node:");
    scanf("%d",&position);
    struct Node *temp=Head;
    for (int i = 0; i < position-1; i++)
    {
        temp=temp->next;
    }
    posNode->next=temp->next;
    temp->next=posNode;

    display(Head);
    
    //deleting first node
    struct Node *toDelete=Head;
    Head=Head->next;
    free(toDelete);

    //deleting last node
    struct Node *temp2=Head;
    struct Node *prev;
    if (Head==NULL)
    {
        printf("List Underflow");
        return 0;
    }    
    while (temp2->next!=NULL)
    {
        prev=temp2;
        temp2=temp2->next;
    }
    prev->next=NULL;
    free(temp2);

    //deleting at specified position
    int delposition;
    printf("Enter the position to delete the node:");
    scanf("%d",&delposition);
    struct Node *temp3=Head;
    if (Head==NULL)
    {
        printf("List Underflow");
        return 0;
    }
    for (int i = 0; i < position-1; i++)
    {
        
        prev=temp3;
        temp3=temp3->next;
    }
    prev->next=temp3->next;
    free(temp3);
    

    display(Head);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(endNode);
    free(posNode);
    return 0;
}