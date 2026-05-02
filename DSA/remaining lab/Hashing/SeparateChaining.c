#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *chain[SIZE] = {0};  // same as NULL, no need for init

void insert(int val) {
    Node *new = malloc(sizeof(Node));
    new->data = val;
    new->next = NULL;

    int k = val % SIZE;
    Node **p = &chain[k];
    while (*p) p = &(*p)->next;
    *p = new;
}

void print() {
    for (int i = 0; i < SIZE; i++) {
        printf("chain[%d] --> ", i);
        for (Node *t = chain[i]; t; t = t->next)
            printf("%d --> ", t->data);
        puts("NULL");
    }
}

int main() {
    insert(7);insert(0);insert(3);
    insert(10);insert(4);insert(5);
    print();
    return 0;
}