// Array Implementation of list -insert and delete at the Beginning
#include<stdio.h>
#define MAX 5

int list[MAX];
int count=0;

int isFull(){
    if (count==MAX){
        printf("List is full");
        return 1;
    }else{
        return 0;
    }   
}
int isEmpty(){
    if (count==0){
        printf("List is empty");
        return 1;
    }
    else{ return 0;}
}

void insert(){
    int value;
    if (isFull()){
        printf("Cannot insert");

    }else{
        printf("Enter a value to insert:");
        scanf("%d",&value);
        for (int i = count; i > 0; i--)
        {
            list[i]=list[i-1];
        }
        list[0]=value;
        count++;
    }
}
    
void DeleteElement(){
    if (isEmpty()){
        printf("Cannot delete");
    }else{
        printf("Deleted %d\n", list[0]);
        for (int i = 0; i < count-1; i++)
        {
            list[i]=list[i+1];
        }
        count--;
    }
}

void display(){
    if (count==0){
        printf("List is empty\n");
    }else
    {
        printf("List elements: ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ",list[i]);
        }
        printf("\n");
    }
    
}

int main(){
    insert();
    insert();
    insert();
    display();
    DeleteElement();
    display();

    return 0;
}