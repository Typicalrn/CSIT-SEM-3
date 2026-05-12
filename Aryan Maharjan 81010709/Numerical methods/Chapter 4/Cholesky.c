// Lab Assignment #4.6 - Cholesky Decomposition
// For symmetric positive definite matrix: A = L * L^T
#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
    int n, i, j, k;
    float a[MAX][MAX], L[MAX][MAX];
    float y[MAX], x[MAX], sum;
    float b[MAX];

    printf("(Matrix must be symmetric and positive definite)\n\n");
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    printf("Enter symmetric matrix A:\n");
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

    // Initialize L to zero
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            L[i][j] = 0;

    // Cholesky Decomposition
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            sum = 0;
            for (k = 0; k < j; k++)
                sum += L[i][k] * L[j][k];

            if (i == j) {
                float val = a[i][i] - sum;
                if (val <= 0) {
                    printf("Error: Matrix is not positive definite.\n");
                    return 1;
                }
                L[i][j] = sqrt(val);
            } else {
                L[i][j] = (a[i][j] - sum) / L[j][j];
            }
        }
    }

    printf("\nLower triangular matrix L:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%10.4f ", L[i][j]);
        printf("\n");
    }

    // Forward substitution: L*y = b
    for (i = 0; i < n; i++) {
        y[i] = b[i];
        for (j = 0; j < i; j++)
            y[i] -= L[i][j] * y[j];
        y[i] /= L[i][i];
    }

    // Back substitution: L^T * x = y
    for (i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (j = i + 1; j < n; j++)
            x[i] -= L[j][i] * x[j];
        x[i] /= L[i][i];
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("  x[%d] = %.6f\n", i + 1, x[i]);

    return 0;
}