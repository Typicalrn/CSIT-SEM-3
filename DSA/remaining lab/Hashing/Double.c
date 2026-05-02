//implementing double hashing in hashing
#include <stdio.h>
#define size 7
int a[size]={-1};

void init(){
    for(int i = 0; i <  size; i++) {
        a[i] = -1;
    }
}

int h1(int key) {
    return key % size;
}

int h2(int key) {
    return 1 + (key % (size - 1));
}
void insert(int key) {
    int i = 0;
    int index = h1(key);
    while (a[index] != -1) {
        index = (h1(key) + i * h2(key)) % size;
        i++;
    }
    a[index] = key;   
}

int search(int key) {
    int i = 0;
    int index = h1(key);
    while (a[index] != -1) {
        if (a[index] == key) return index;
        index = (h1(key) + i * h2(key)) % size;
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