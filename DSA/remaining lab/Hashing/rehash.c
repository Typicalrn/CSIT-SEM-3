#include <stdio.h>
#include <stdlib.h>

#define LOAD_FACTOR 0.7f
#define EMPTY -1

int *table, size, count = 0;

void display(int *t, int s) {
    for (int i = 0; i < s; i++) printf("%d ", t[i]);
    printf("\n");
}
int hash(int key) { return key % size; }
void rehash() {
    int oldSize = size, *oldTable = table;
    printf("Original hash table (size = %d): ", oldSize);
    display(oldTable, oldSize);

    size *= 2;
    table = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) table[i] = EMPTY;

    count = 0;
    for (int i = 0; i < oldSize; i++) {
        if (oldTable[i] != EMPTY) {
            int k = oldTable[i];
            int j = hash(k);
            while (table[j] != EMPTY)
                j = (j + 1) % size;
            table[j] = k;
            count++;
        }
    }

    printf("Rehashed table (size = %d): ", size);
    display(table, size);

    free(oldTable);
}
void insert(int key) {
    if ((float)(count + 1) / size >= LOAD_FACTOR)
        rehash();   // OK now

    int i = hash(key);
    while (table[i] != EMPTY)
        i = (i + 1) % size;
    table[i] = key;
    count++;
}

int main() {
    int arr[] = {50, 76, 85, 92, 73, 63};
    int n = sizeof(arr) / sizeof(arr[0]);

    size = 5;
    table = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) table[i] = EMPTY;

    for (int i = 0; i < n; i++) insert(arr[i]);

    printf("Final hash table (size = %d): ", size);
    display(table, size);

    free(table);
    return 0;
}