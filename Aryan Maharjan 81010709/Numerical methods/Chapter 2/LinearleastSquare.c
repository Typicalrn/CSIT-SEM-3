// Lab Assignment #2.4a - Linear Least Square Method
#include <stdio.h>

int main() {
    int n, i;
    float x[100], y[100];
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    float a, b;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    for (i = 0; i < n; i++) {
        sumX  += x[i];
        sumY  += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Normal equations: solve for a (slope) and b (intercept)
    // y = a*x + b
    a = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    b = (sumY - a * sumX) / n;

    printf("\nFitted Line: y = %.4fx + %.4f\n", a, b);
    printf("\nVerification:\n");
    printf("%-10s %-10s %-12s %-10s\n", "x", "y", "y_fitted", "error");
    for (i = 0; i < n; i++) {
        float yf = a * x[i] + b;
        printf("%-10.4f %-10.4f %-12.4f %-10.4f\n", x[i], y[i], yf, y[i] - yf);
    }

    return 0;
}