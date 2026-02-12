//implementing list using array
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
    else{
        return 0;
    }
}

void insert(){
    int value,position;
    if (isFull()){
        printf("Cannot insert");

    }else{
        printf("Enter a value to insert:");
        scanf("%d",&value);
        for (int i = count; i > position; i--)
        {
            list[i]=list[i-1];
        }
        list[position]=value;
        count++;
    }
    
}

void delete(){
    int position;
    if (isEmpty())
    {
        printf("Cannot delete");
    }else{
        printf("Enter the position to delete:");
        scanf("%d",&position);
        for (int i = position; i < count-1; i++)
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
        for (int i = 0; i < count; i++)
        {
            printf("%d",list[i]);
        }
        
    }
    
}

int main(){
    int choice;
    do {
        printf("\n--- List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    

    return 0;
}