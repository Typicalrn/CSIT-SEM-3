#include<stdio.h>
#include <stdlib.h>

#define SIZE 10

int a[SIZE];

void init() {
    for(int i = 0; i <  SIZE; i++) {
        a[i] = -1;
    }
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    for (int i = 0; i < SIZE; i++)
    {
        if (a[index] == -1)
        {
            a[index] = key;
            return;
        }
        index = (index + 1) % SIZE;
    }
    printf("Hash table is full\n");
}

int search(int key) {
    int index = hash(key);
    int start = index;

    do {
        if(a[index] == key) return index;
        index = (index + 1) % SIZE;
    } while(index != start);
    return -1;
}

void display() {
    for(int i = 0; i <  SIZE; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    init();
    insert(5);
    insert(15);
    insert(25);
    display();
    printf("Search 15: %d\n", search(15));
    return 0;
}