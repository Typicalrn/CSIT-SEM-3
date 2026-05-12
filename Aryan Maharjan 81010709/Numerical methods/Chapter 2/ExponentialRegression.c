// Lab Assignment #2.4c - Exponential Regression
// Fits: y = A * e^(B*x)  => ln(y) = ln(A) + B*x
#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    float x[100], y[100], lny[100];
    float sumX = 0, sumLnY = 0, sumXLnY = 0, sumX2 = 0;
    float A, B, lnA;

    printf("Fits: y = A * e^(B*x)\n\n");
    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values (y must be positive):\n");
    for (i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
        if (y[i] <= 0) {
            printf("Error: y values must be positive for exponential regression.\n");
            return 1;
        }
        lny[i] = log(y[i]);
    }

    for (i = 0; i < n; i++) {
        sumX    += x[i];
        sumLnY  += lny[i];
        sumXLnY += x[i] * lny[i];
        sumX2   += x[i] * x[i];
    }

    B   = (n * sumXLnY - sumX * sumLnY) / (n * sumX2 - sumX * sumX);
    lnA = (sumLnY - B * sumX) / n;
    A   = exp(lnA);

    printf("\nFitted Model: y = %.4f * e^(%.4f * x)\n", A, B);

    printf("\nVerification:\n");
    printf("%-10s %-10s %-12s %-10s\n", "x", "y", "y_fitted", "error");
    for (i = 0; i < n; i++) {
        float yf = A * exp(B * x[i]);
        printf("%-10.4f %-10.4f %-12.4f %-10.4f\n", x[i], y[i], yf, y[i] - yf);
    }

    return 0;
}