// Lab Assignment #4.1 - Gauss Elimination Method
#include <stdio.h>

#define MAX 10

int main() {
    int n, i, j, k;
    float a[MAX][MAX + 1], x[MAX], ratio;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter augmented matrix [A|b] row by row:\n");
    for (i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j <= n; j++)
            scanf("%f", &a[i][j]);
    }

    // Forward Elimination
    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            if (a[k][k] == 0) {
                printf("Error: Zero pivot encountered. Try Gauss Elimination with Pivoting.\n");
                return 1;
            }
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