// Lab Assignment #4.5 - Doolittle LU Decomposition
// A = L * U where L has 1s on diagonal
#include <stdio.h>

#define MAX 10

int main() {
    int n, i, j, k;
    float a[MAX][MAX], L[MAX][MAX], U[MAX][MAX];
    float y[MAX], x[MAX], sum;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter coefficient matrix A:\n");
    for (i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j < n; j++)
            scanf("%f", &a[i][j]);
    }

    float b[MAX];
    printf("Enter RHS vector b:\n");
    for (i = 0; i < n; i++) {
        printf("  b[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    // Initialize L and U
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            L[i][j] = U[i][j] = 0;

    // Doolittle Decomposition
    for (i = 0; i < n; i++) {
        // Upper triangular U
        for (k = i; k < n; k++) {
            sum = 0;
            for (j = 0; j < i; j++)
                sum += L[i][j] * U[j][k];
            U[i][k] = a[i][k] - sum;
        }
        // Lower triangular L (diagonal = 1)
        L[i][i] = 1;
        for (k = i + 1; k < n; k++) {
            sum = 0;
            for (j = 0; j < i; j++)
                sum += L[k][j] * U[j][i];
            L[k][i] = (a[k][i] - sum) / U[i][i];
        }
    }

    // Print L and U
    printf("\nLower triangular matrix L:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%10.4f ", L[i][j]);
        printf("\n");
    }
    printf("\nUpper triangular matrix U:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%10.4f ", U[i][j]);
        printf("\n");
    }

    // Forward substitution: L*y = b
    for (i = 0; i < n; i++) {
        y[i] = b[i];
        for (j = 0; j < i; j++)
            y[i] -= L[i][j] * y[j];
    }

    // Back substitution: U*x = y
    for (i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (j = i + 1; j < n; j++)
            x[i] -= U[i][j] * x[j];
        x[i] /= U[i][i];
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("  x[%d] = %.6f\n", i + 1, x[i]);

    return 0;
}