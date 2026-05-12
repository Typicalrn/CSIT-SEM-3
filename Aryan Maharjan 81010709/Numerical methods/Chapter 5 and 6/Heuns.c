// Lab Assignment #5.4 - ODE by Heun's Method (Improved Euler)
// Predictor: y*    = y_n + h * f(x_n, y_n)
// Corrector: y_n+1 = y_n + h/2 * [f(x_n, y_n) + f(x_n+1, y*)]
// Example: dy/dx = x + y,  y(0) = 1
#include <stdio.h>

float f(float x, float y) {
    return x + y;  // Change this to your equation
}

int main() {
    float x0, y0, h, xn, x, y, k1, k2, y_pred;

    printf("Equation: dy/dx = x + y\n\n");
    printf("Enter initial x (x0): ");  scanf("%f", &x0);
    printf("Enter initial y (y0): ");  scanf("%f", &y0);
    printf("Enter step size h: ");     scanf("%f", &h);
    printf("Enter final x (xn): ");    scanf("%f", &xn);

    x = x0;
    y = y0;

    printf("\n%-12s %-12s %-12s %-12s\n", "x", "k1", "k2", "y");
    printf("------------------------------------------------\n");
    printf("%-12.4f %-12s %-12s %-12.6f\n", x, "-", "-", y);

    while (x < xn - 1e-6) {
        k1     = f(x, y);
        y_pred = y + h * k1;
        k2     = f(x + h, y_pred);

        y = y + (h / 2.0) * (k1 + k2);
        x += h;
        printf("%-12.4f %-12.6f %-12.6f %-12.6f\n", x, k1, k2, y);
    }

    return 0;
}