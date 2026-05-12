// Lab Assignment #2.4b - Polynomial Regression (2nd degree)
#include <stdio.h>

#define MAX 100

int main() {
    int n, i, j, k;
    float x[MAX], y[MAX];
    float sumX[5] = {0}, sumXY[3] = {0};
    float a[3][4];  // augmented matrix for 3 unknowns (a0, a1, a2)
    float coeff[3];
    float ratio, temp;

    printf("Fits: y = a0 + a1*x + a2*x^2\n\n");
    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    // Compute sums: sumX[k] = sum of x^k, sumXY[k] = sum of x^k * y
    for (i = 0; i < n; i++) {
        float xp = 1.0;
        for (k = 0; k <= 4; k++) {
            sumX[k] += xp;
            if (k <= 2) sumXY[k] += xp * y[i];
            xp *= x[i];
        }
    }

    // Build augmented matrix for normal equations
    // [n,    sumX1, sumX2 | sumY ]
    // [sumX1,sumX2, sumX3 | sumXY]
    // [sumX2,sumX3, sumX4 | sumX2Y]
    a[0][0] = sumX[0]; a[0][1] = sumX[1]; a[0][2] = sumX[2]; a[0][3] = sumXY[0];
    a[1][0] = sumX[1]; a[1][1] = sumX[2]; a[1][2] = sumX[3]; a[1][3] = sumXY[1];
    a[2][0] = sumX[2]; a[2][1] = sumX[3]; a[2][2] = sumX[4]; a[2][3] = sumXY[2];

    // Gauss Elimination
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = 0; k <= 3; k++)
                a[j][k] -= ratio * a[i][k];
        }
    }

    // Back Substitution
    for (i = 2; i >= 0; i--) {
        coeff[i] = a[i][3];
        for (j = i + 1; j < 3; j++)
            coeff[i] -= a[i][j] * coeff[j];
        coeff[i] /= a[i][i];
    }

    printf("\nFitted Polynomial: y = %.4f + %.4f*x + %.4f*x^2\n",
           coeff[0], coeff[1], coeff[2]);

    printf("\nVerification:\n");
    printf("%-10s %-10s %-12s %-10s\n", "x", "y", "y_fitted", "error");
    for (i = 0; i < n; i++) {
        float yf = coeff[0] + coeff[1]*x[i] + coeff[2]*x[i]*x[i];
        printf("%-10.4f %-10.4f %-12.4f %-10.4f\n", x[i], y[i], yf, y[i] - yf);
    }

    return 0;
}