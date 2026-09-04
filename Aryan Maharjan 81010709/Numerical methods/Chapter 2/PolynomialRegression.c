// Lab Assignment #2.4b - Polynomial Regression (2nd degree)
#include <stdio.h>

#define MAX 100

int main() {
    int n;
    float x[MAX], y[MAX], sX[5] = {0}, sXY[3] = {0};
    float a[3][4], coeff[3], ratio, temp;

    printf("Fits: y = a0 + a1*x + a2*x^2\n\n");
    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    // Compute ss: sX[k] = s of x^k, sXY[k] = s of x^k * y
    for (int i = 0; i < n; i++) {
        float xp = 1.0;
        for (int k = 0; k <= 4; k++) {
            sX[k] += xp;
            if (k <= 2) sXY[k] += xp * y[i];
            xp *= x[i];
        }
    }

    // Build augmented matrix for normal equations
    // [n,    sX1, sX2 | sY ]
    // [sX1,sX2, sX3 | sXY]
    // [sX2,sX3, sX4 | sX2Y]
    a[0][0] = sX[0]; a[0][1] = sX[1]; a[0][2] = sX[2]; a[0][3] = sXY[0];
    a[1][0] = sX[1]; a[1][1] = sX[2]; a[1][2] = sX[3]; a[1][3] = sXY[1];
    a[2][0] = sX[2]; a[2][1] = sX[3]; a[2][2] = sX[4]; a[2][3] = sXY[2];

    // Gauss Elimination
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            ratio = a[j][i] / a[i][i];
            for (int k = 0; k <= 3; k++)
                a[j][k] -= ratio * a[i][k];
        }
    }

    // Back Substitution
    for (int i = 2; i >= 0; i--) {
        coeff[i] = a[i][3];
        for (int j = i + 1; j < 3; j++)
            coeff[i] -= a[i][j] * coeff[j];
        coeff[i] /= a[i][i];
    }

    printf("\nFitted Polynomial: y = %.4f + %.4f*x + %.4f*x^2\n",
           coeff[0], coeff[1], coeff[2]);

    printf("\nVerification:\n");
    printf("%-10s %-10s %-12s %-10s\n", "x", "y", "y_fitted", "error");
    for (int i = 0; i < n; i++) {
        float yf = coeff[0] + coeff[1]*x[i] + coeff[2]*x[i]*x[i];
        printf("%-10.4f %-10.4f %-12.4f %-10.4f\n", x[i], y[i], yf, y[i] - yf);
    }

    return 0;
}