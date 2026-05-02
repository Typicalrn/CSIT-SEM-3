//implementing quadratic probing in hashing
#include <stdio.h>
#define size 7

int a[size]={-1,-1,-1,-1,-1,-1,-1};
int h(int key) {return key % size;}

void insert(int key) {
    int i = 0,idx = h(key);
    while (a[idx] != -1) {
        idx = (h(key) + i * i) % size;
        i++;
    }
    a[idx] = key;   
}

int search(int key) {
    int i = 0,idx = h(key);
    while (a[idx] != -1) {
        if (a[idx] == key) return idx;
        idx = (h(key) + i * i) % size;
        i++;
    }
    return -1;
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }printf("\n");
}

int main() {
    insert(5);
    insert(12);
    insert(19);
    insert(26);
    display();
    printf("Search 19: %d\n", search(19));
    printf("Search 20: %d\n", search(20));
    return 0;
}