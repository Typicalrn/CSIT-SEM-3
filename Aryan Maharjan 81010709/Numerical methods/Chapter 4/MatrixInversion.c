// Lab Assignment #4.4 - Matrix Inversion using Gauss-Jordan Method
#include <stdio.h>

#define MAX 10

int main() {
    int n, i, j, k;
    float a[MAX][2 * MAX];
    float pivot, factor;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements row by row:\n");
    for (i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j < n; j++)
            scanf("%f", &a[i][j]);
    }

    // Augment with identity matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][n + j] = (i == j) ? 1.0 : 0.0;

    // Gauss Jordan
    for (k = 0; k < n; k++) {
        if (a[k][k] == 0) {
            printf("Error: Zero pivot. Matrix may be singular.\n");
            return 1;
        }
        pivot = a[k][k];
        for (j = 0; j < 2 * n; j++)
            a[k][j] /= pivot;

        for (i = 0; i < n; i++) {
            if (i != k) {
                factor = a[i][k];
                for (j = 0; j < 2 * n; j++)
                    a[i][j] -= factor * a[k][j];
            }
        }
    }

    printf("\nInverse Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++)
            printf("%10.4f ", a[i][j]);
        printf("\n");
    }

    return 0;
}