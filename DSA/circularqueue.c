#include<stdio.h>
#define MAXSIZE 5

int queue[MAXSIZE];
int front=-1,rear=-1;

int isfull(){
    return((rear+1)%MAXSIZE==front);
}
int isEmpty(){
    return (front == -1);
}

void Enqueue(){
    int data;
    if (isfull())
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter element to enqueue: ");
    scanf("%d", &data);

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear=(rear+1)%MAXSIZE;
    }
    queue[rear] = data;
    printf("Enqueued %d\n", data);
    
}

void Dequeue(){
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }else{
        int data=queue[front];
        printf("Dequeued %d\n", data);
        if(front==rear){
            front=rear=-1;
        }else{
            front=(front+1)%MAXSIZE;
        }
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are:\n");
    for (int i = 0; i <= MAXSIZE; i++) {
        printf("%d\n", queue[i]);
    }
}

int main(){
    int choice;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Enqueue(); break;
            case 2: Dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}