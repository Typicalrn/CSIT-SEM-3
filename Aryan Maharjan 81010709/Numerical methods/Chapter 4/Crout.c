// Lab Assignment #4.7 - Crout's LU Decomposition
// A = L * U where U has 1s on diagonal
#include <stdio.h>

#define MAX 10

int main() {
    int n, i, j, k;
    float a[MAX][MAX], L[MAX][MAX], U[MAX][MAX];
    float y[MAX], x[MAX], sum;
    float b[MAX];

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter coefficient matrix A:\n");
    for (i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j < n; j++)
            scanf("%f", &a[i][j]);
    }

    printf("Enter RHS vector b:\n");
    for (i = 0; i < n; i++) {
        printf("  b[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    // Initialize
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            L[i][j] = U[i][j] = 0;

    // Crout Decomposition: U has 1s on diagonal
    for (j = 0; j < n; j++) {
        U[j][j] = 1;  // diagonal of U = 1

        // Lower triangular L
        for (i = j; i < n; i++) {
            sum = 0;
            for (k = 0; k < j; k++)
                sum += L[i][k] * U[k][j];
            L[i][j] = a[i][j] - sum;
        }

        // Upper triangular U
        for (i = j + 1; i < n; i++) {
            sum = 0;
            for (k = 0; k < j; k++)
                sum += L[j][k] * U[k][i];
            U[j][i] = (a[j][i] - sum) / L[j][j];
        }
    }

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
        y[i] /= L[i][i];
    }

    // Back substitution: U*x = y
    for (i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (j = i + 1; j < n; j++)
            x[i] -= U[i][j] * x[j];
        // U[i][i] = 1, so no division needed
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("  x[%d] = %.6f\n", i + 1, x[i]);

    return 0;
}