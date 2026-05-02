#include <stdio.h>

void merge(int arr[], int beg, int mid, int end) {
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++){ 
        L[i] = arr[beg + i];
    }
    for (int j = 0; j < n2; j++){   
        R[j] = arr[mid + 1 + j];
    } 

    int i = 0, j = 0, k = beg;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = beg + (end - beg) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {6, 5, 12, 10, 9, 1};
    printf("Unsorted array: ");
    printArray(arr, 6);
    int n = 6;

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}