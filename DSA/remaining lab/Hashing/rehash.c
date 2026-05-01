//implementing rehashing in hashing
#include <stdio.h>
#include <stdlib.h>
#define size 7
int a[size];



void init(){
    for(int i = 0; i <  size; i++) {
        a[i] = -1;
    }
}

int hash(int key) {
    return key % size;
}

void insert(int key) {
    int i = 0;
    int index = hash(key);
    while (a[index] != -1) {
        index = (hash(key) + i ) % size;
        i++;
    }
    a[index] = key;   
}

int search(int key) {
    int i = 0;
    int index = hash(key);
    while (a[index] != -1) {
        if (a[index] == key) return index;
        index = (hash(key) + i ) % size;
        i++;
    }
    return -1;
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    init();
    insert(5);
    insert(12);
    insert(19);
    insert(26);
    display();
    printf("Search 19: %d\n", search(19));
    printf("Search 20: %d\n", search(20));
    return 0;
}