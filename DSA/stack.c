
#include <stdio.h>
#define STACK_SIZE 40

int stack[STACK_SIZE];
int top = -1;

int isFull() {
    if (top == STACK_SIZE - 1)
        return 1;
    else
        return 0;
}


int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

void push() {
    int item;
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter element to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("%d pushed into stack.\n", item);
    }
}

void pop() {
    int item;
    if (isEmpty()) {
        printf("Stack Underflow\n");
    } else {
        item = stack[top];
        top--;
        printf("%d popped out of stack.\n", item);
    }
}

/* Display stack */
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
