#include <stdio.h>
#define MAXSIZE 5

int queue[MAXSIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear == MAXSIZE - 1);
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void Enqueue() {
    int data;
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter element to enqueue: ");
    scanf("%d", &data);

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear] = data;
    printf("Enqueued %d\n", data);
}

void Dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    int data = queue[front];
    printf("Dequeued %d\n", data);

    front++;

    // Queue becomes empty
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

int main() {
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
