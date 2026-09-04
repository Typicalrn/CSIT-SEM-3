// Lab Assignment #2.4c - Exponential Regression
// Fits: y = A * e^(B*x)  => ln(y) = ln(A) + B*x
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float x[100], y[100], lny[100];
    float sX = 0, sLnY = 0, sXLnY = 0, sX2 = 0;
    float A, B, lnA;

    printf("Fits: y = A * e^(B*x)\n\n");
    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values (y must be positive):\n");
    for (int i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
        if (y[i] <= 0) {
            printf("Error: y values must be positive for exponential regression.\n");
            return 1;
        }
        lny[i] = log(y[i]);
    }

    for (int i = 0; i < n; i++) {
        sX    += x[i];
        sLnY  += lny[i];
        sXLnY += x[i] * lny[i];
        sX2   += x[i] * x[i];
    }

    B   = (n * sXLnY - sX * sLnY) / (n * sX2 - sX * sX);
    lnA = (sLnY - B * sX) / n;
    A   = exp(lnA);

    printf("\nFitted Model: y = %.4f * e^(%.4f * x)\n", A, B);

    printf("\nVerification:\n");
    printf("%-10s %-10s %-12s %-10s\n", "x", "y", "y_fitted", "error");
    for (int i = 0; i < n; i++) {
        float yf = A * exp(B * x[i]);
        printf("%-10.4f %-10.4f %-12.4f %-10.4f\n", x[i], y[i], yf, y[i] - yf);
    }

    return 0;
}