// Lab Assignment #5.3 - ODE by Euler's Method
// dy/dx = f(x, y),  y(x0) = y0
// y_(n+1) = y_n + h * f(x_n, y_n)
// Example: dy/dx = x + y,  y(0) = 1
#include <stdio.h>

float f(float x, float y) {
    return x + y;  // Change this to your equation
}

int main() {
    float x0, y0, h, xn, x, y;

    printf("Equation: dy/dx = x + y\n\n");
    printf("Enter initial x (x0): ");  scanf("%f", &x0);
    printf("Enter initial y (y0): ");  scanf("%f", &y0);
    printf("Enter step size h: ");     scanf("%f", &h);
    printf("Enter final x (xn): ");    scanf("%f", &xn);

    x = x0;
    y = y0;

    printf("\n%-12s %-12s\n", "x", "y");
    printf("------------------------\n");
    printf("%-12.4f %-12.6f\n", x, y);

    while (x < xn - 1e-6) {
        y = y + h * f(x, y);
        x += h;
        printf("%-12.4f %-12.6f\n", x, y);
    }

    return 0;
}