// Lab Assignment #4.3 - Gauss Jordan Method
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

    // Gauss Jordan Elimination (eliminate both above and below pivot)
    for (k = 0; k < n; k++) {
        if (a[k][k] == 0) {
            printf("Error: Zero pivot at row %d.\n", k + 1);
            return 1;
        }
        // Normalize pivot row
        float pivot = a[k][k];
        for (j = 0; j <= n; j++)
            a[k][j] /= pivot;

        // Eliminate column k in all other rows
        for (i = 0; i < n; i++) {
            if (i != k) {
                float factor = a[i][k];
                for (j = 0; j <= n; j++)
                    a[i][j] -= factor * a[k][j];
            }
        }
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("  x[%d] = %.6f\n", i + 1, a[i][n]);

    return 0;
}