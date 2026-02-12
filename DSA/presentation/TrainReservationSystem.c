#include <stdio.h>
#include <stdlib.h>

#define MAXSEATS 3
#define MAXWAIT 5

// CONFIRMED LIST (Linked List) 
struct Node {
    int ticketNo;
    struct Node* next;
};

struct Node* head = NULL;
int confirmedCount = 0;

// WAITING QUEUE 
int waiting[MAXWAIT];
int front = -1, rear = -1;

// Ticket Number 
int ticketNo = 1;

// Queue Functions 
int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAXWAIT - 1;
}

void enqueue(int t) {// add to Waiting List
    if (isFull()) {
        printf("Waiting list full\n");
        return;
    }
    if (isEmpty())
        front = 0;
    rear++;
    waiting[rear] = t;
}

int dequeue() {//remove from Waiting List(to promote to confirmed)
    if (isEmpty())
        return -1;

    int t = waiting[front];// get the ticket number at the front of the queue
    front++;

    if (front > rear)
        front = rear = -1;// reset queue if empty

    return t;
}

// Remove from Waiting List(to cancel a ticket from waiting list)
int cancelFromWaiting(int t) {
    if (isEmpty())
        return 1;
// search for the ticket in the waiting list
// if found, remove it and shift remaining tickets forward
    for (int i = front; i <= rear; i++) {
        if (waiting[i] == t) {
            for (int j = i; j < rear; j++)
                waiting[j] = waiting[j + 1];

            rear--;
            if (rear < front)
                front = rear = -1;

            printf("Ticket %d cancelled from WAITING list\n", t);
            return 0;   // found
        }
    }
    return 1;   // not found
}

// Confirmed List Functions 
// Add to Confirmed List(to book a ticket or promote from waiting list)
void addConfirmed(int t) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->ticketNo = t;
    newNode->next = NULL;
// add new node to the end of the confirmed list 
    if (head == NULL)
        head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    confirmedCount++;
}

// Remove from Confirmed List(to cancel a ticket from confirmed list)
void removeConfirmed(int t) {
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL) {
        if (temp->ticketNo == t) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            confirmedCount--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Cancel from Confirmed 
int cancelFromConfirmed(int t) {
    struct Node* temp = head;

    while (temp != NULL) {// search for ticket in confirmed list
        if (temp->ticketNo == t) {
            removeConfirmed(t);// if found, remove from confirmed list
            printf("Ticket %d cancelled from CONFIRMED\n", t);

            int promoted = dequeue();// promote from waiting list if available
            if (promoted != -1) {
                addConfirmed(promoted);
                printf("Ticket %d promoted from WAITING to CONFIRMED\n", promoted);
            }
            return 0;   // found
        }
        temp = temp->next;
    }
    return 1;   // not found
}

// Book Ticket 
void bookTicket() {
    if (confirmedCount < MAXSEATS) {// if seats available, confirm ticket
        addConfirmed(ticketNo);
        printf("Ticket %d CONFIRMED\n", ticketNo);
    }
    else if (!isFull()) {// if no seats but waiting list has space, add to waiting list
        enqueue(ticketNo);
        printf("Ticket %d added to WAITING LIST\n", ticketNo);
    }
    else {
        printf("No tickets available\n");// if no seats and waiting list full, cannot book
        return;
    }
    ticketNo++;
}

// Cancel Ticket 
void cancelTicket() {
    int t;
    printf("Enter ticket number to cancel: ");
    scanf("%d", &t);

    if (cancelFromConfirmed(t) == 0){// try to cancel from confirmed list first
        return;
    }
    if (cancelFromWaiting(t) == 0){// if not found in confirmed, try to cancel from waiting list
        return;
    }
    printf("Ticket not found\n");
}

// Display 
void display() {
    struct Node* temp = head;

    printf("\nConfirmed Tickets:\n");
    if (temp == NULL)
        printf("None\n");
    else {
        while (temp != NULL) {
            printf("Ticket %d\n", temp->ticketNo);
            temp = temp->next;
        }
    }

    printf("\nWaiting List:\n");
    if (isEmpty())
        printf("None\n");
    else {
        for (int i = front; i <= rear; i++)
            printf("Ticket %d\n", waiting[i]);
    }
}


int main() {
    int choice;

    do {
        printf("\n--- Train Reservation System ---\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: display(); break;
            case 4: printf("Thank you for using the system!\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
