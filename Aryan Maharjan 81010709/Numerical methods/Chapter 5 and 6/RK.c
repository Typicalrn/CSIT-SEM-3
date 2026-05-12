// Lab Assignment #5.6 - ODE by Runge-Kutta Method (4th Order)
// k1 = h*f(x, y)
// k2 = h*f(x + h/2, y + k1/2)
// k3 = h*f(x + h/2, y + k2/2)
// k4 = h*f(x + h,   y + k3)
// y_(n+1) = y_n + (k1 + 2k2 + 2k3 + k4) / 6
// Example: dy/dx = x + y,  y(0) = 1
#include <stdio.h>

float f(float x, float y) {
    return x + y;  // Change this to your equation
}

int main() {
    float x0, y0, h, xn, x, y;
    float k1, k2, k3, k4;

    printf("Equation: dy/dx = x + y\n\n");
    printf("Enter initial x (x0): ");  scanf("%f", &x0);
    printf("Enter initial y (y0): ");  scanf("%f", &y0);
    printf("Enter step size h: ");     scanf("%f", &h);
    printf("Enter final x (xn): ");    scanf("%f", &xn);

    x = x0;
    y = y0;

    printf("\n%-10s %-12s %-10s %-10s %-10s %-12s\n", "x", "k1", "k2", "k3", "k4", "y");
    printf("------------------------------------------------------------------\n");
    printf("%-10.4f %-12s %-10s %-10s %-10s %-12.6f\n", x, "-", "-", "-", "-", y);

    while (x < xn - 1e-6) {
        k1 = h * f(x,           y);
        k2 = h * f(x + h/2.0,   y + k1/2.0);
        k3 = h * f(x + h/2.0,   y + k2/2.0);
        k4 = h * f(x + h,       y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x += h;
        printf("%-10.4f %-12.6f %-10.6f %-10.6f %-10.6f %-12.6f\n", x, k1, k2, k3, k4, y);
    }

    return 0;
}