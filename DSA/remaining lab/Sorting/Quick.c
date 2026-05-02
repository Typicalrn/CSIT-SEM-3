#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int beg, int end) {
    int pivot = a[end];
    int i = beg - 1;

    for (int j = beg; j < end; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[end]);
    return i + 1;
}

void quickSort(int a[], int beg, int end) {
    if (beg < end) {
        int pi = partition(a, beg, end);
        quickSort(a, beg, pi - 1);
        quickSort(a, pi + 1, end);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {8, 7, 2, 1, 0, 9, 6};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Unsorted array: ");
    printArray(a, n);

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");
    printArray(a, n);

    return 0;
}