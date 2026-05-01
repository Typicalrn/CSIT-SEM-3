// Array Implementation of list -insert and delete at the End of array
#include<stdio.h>
#define MAX 5

int list[MAX];
int n=0;

int isFull(){
    if (n==MAX){
        printf("List is full");
        return 1;
    }else{
        return 0;
    }
    
}
int isEmpty(){
    if (n==0){
        printf("List is empty");
        return 1;
    }
    else{
        return 0;
    }
}

void insert(int num){
    if (isFull()){
        printf("Cannot insert");

    }else{
        list[n]=num;
        n++;
    }
}

void DeleteElement(){
    if (isEmpty()){
        printf("Cannot delete");
    }else{
        printf("Deleted %d\n", list[n-1]);
        n--;
    }
}

void display(){
    if (n==0){
        printf("List is empty\n");
    }else{
        printf("Elements in the list:");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", list[i]);
        }
        printf("\n");
    }
    
}
int main(){
    insert(10); insert(20); insert(30);
    display();
    DeleteElement();
    display();
    
    return 0;
}