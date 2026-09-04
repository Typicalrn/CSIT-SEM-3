// Lab Assignment #2.4a - Linear Least Square Method
#include <stdio.h>

int main() {
    int n, i;
    float X[100], Y[100];
    float sX = 0, sY = 0, sXY = 0, sX2 = 0, a, b;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("  X[%d] Y[%d]: ", i, i);
        scanf("%f %f", &X[i], &Y[i]);
    }

    for (i = 0; i < n; i++) {
        sX  += X[i];
        sY  += Y[i];
        sXY += X[i] * Y[i];
        sX2 += X[i] * X[i];
    }

    // Normal equations: solve for a (slope) and b (intercept)
    // y = a*x + b
    a = (n * sXY - sX * sY) / (n * sX2 - sX * sX);
    b = (sY - a * sX) / n;

    printf("\nFitted Line: y = %.4fx + %.4f\n", a, b);
    printf("\nVerification:\n");
    printf("%-10s %-10s %-12s %-10s\n", "X", "Y", "Y_Fitted", "Error");
    for (i = 0; i < n; i++) {
        float yf = a * X[i] + b;
        printf("%-10.4f %-10.4f %-12.4f %-10.4f\n", X[i], Y[i], yf, Y[i] - yf);
    }

    return 0;
}