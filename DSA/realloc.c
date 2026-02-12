#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a,n1 = 3,n2 = 6;
    a = (int *)malloc(n1 * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n1; i++) {
        a[i] = (i + 1) * 10;
    }

    printf("Array before realloc:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    a = (int *)realloc(a, n2 * sizeof(int));

    if (a == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }
    for (int i = n1; i < n2; i++) {
        a[i] = (i + 1) * 10;
    }

    printf("Array after realloc:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);

    return 0;
}
