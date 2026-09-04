#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
    int n, i, j, k, p, q,colIndex[MAX];
    float A[MAX][MAX+1], x[MAX];

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {scanf("%f", &A[i][j]);}
        colIndex[i] = i; // track column swaps
    }

    // Forward elimination with complete pivoting
    for(i = 0; i < n - 1; i++) {
        // Find pivot (max element in submatrix)
        float max = fabs(A[i][i]);
        p = i;q = i;

        for(k = i; k < n; k++) {
            for(j = i; j < n; j++) {
                if(fabs(A[k][j]) > max) {
                    max = fabs(A[k][j]);
                    p = k;q = j;
                }
            }
        }

        // Swap rows
        if(p != i) {
            for(j = 0; j <= n; j++) {
                float temp = A[i][j];
                A[i][j] = A[p][j];
                A[p][j] = temp;
            }
        }

        // Swap columns (excluding RHS column)
        if(q != i) {
            for(k = 0; k < n; k++) {
                float temp = A[k][i];
                A[k][i] = A[k][q];
                A[k][q] = temp;
            }

            // track column swaps
            int temp = colIndex[i];
            colIndex[i] = colIndex[q];
            colIndex[q] = temp;
        }

        // Elimination
        for(j = i + 1; j < n; j++) {
            float ratio = A[j][i] / A[i][i];

            for(k = i; k <= n; k++) {
                A[j][k] = A[j][k] - ratio * A[i][k];
            }
        }
    }

    // Back substitution
    for(i = n - 1; i >= 0; i--) {
        x[i] = A[i][n];

        for(j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }

        x[i] = x[i] / A[i][i];
    }

    // Reorder solution according to column swaps
    float finalX[MAX];
    for(i = 0; i < n; i++) {
        finalX[colIndex[i]] = x[i];
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, finalX[i]);
    }

    return 0;
}