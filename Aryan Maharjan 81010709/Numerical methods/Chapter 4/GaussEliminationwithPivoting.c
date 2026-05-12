// Lab Assignment #4.2 - Gauss Elimination with Partial Pivoting
#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
    int n, i, j, k, maxRow;
    float a[MAX][MAX + 1], x[MAX], temp, ratio, maxVal;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter augmented matrix [A|b] row by row:\n");
    for (i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j <= n; j++)
            scanf("%f", &a[i][j]);
    }

    // Forward Elimination with Partial Pivoting
    for (k = 0; k < n - 1; k++) {
        // Find max pivot
        maxVal = fabs(a[k][k]);
        maxRow = k;
        for (i = k + 1; i < n; i++) {
            if (fabs(a[i][k]) > maxVal) {
                maxVal = fabs(a[i][k]);
                maxRow = i;
            }
        }
        // Swap rows
        if (maxRow != k) {
            for (j = 0; j <= n; j++) {
                temp = a[k][j];
                a[k][j] = a[maxRow][j];
                a[maxRow][j] = temp;
            }
            printf("Swapped row %d and row %d\n", k + 1, maxRow + 1);
        }

        for (i = k + 1; i < n; i++) {
            ratio = a[i][k] / a[k][k];
            for (j = k; j <= n; j++)
                a[i][j] -= ratio * a[k][j];
        }
    }

    // Back Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        x[i] = a[i][n];
        for (j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("  x[%d] = %.6f\n", i + 1, x[i]);

    return 0;
}