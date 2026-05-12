// Lab Assignment #5.1 - ODE by Taylor's Series Method
// Solves dy/dx = f(x, y) using Taylor's series up to 4th order
// Example: dy/dx = x + y,  y(0) = 1
#include <stdio.h>

// Define f(x, y) = dy/dx
float f(float x, float y)   { return x + y; }

// f'  = df/dx = 1 + f (using chain rule: f_x + f_y * f)
float f1(float x, float y)  { return 1 + f(x, y); }

// f'' = 1 + f'
float f2(float x, float y)  { return 1 + f1(x, y); }

// f''' = f''
float f3(float x, float y)  { return f2(x, y); }

int main() {
    float x0, y0, h, xn;

    printf("Equation: dy/dx = x + y\n\n");
    printf("Enter initial x (x0): ");  scanf("%f", &x0);
    printf("Enter initial y (y0): ");  scanf("%f", &y0);
    printf("Enter step size h: ");     scanf("%f", &h);
    printf("Enter final x (xn): ");    scanf("%f", &xn);

    float x = x0, y = y0;

    printf("\n%-12s %-12s\n", "x", "y");
    printf("------------------------\n");
    printf("%-12.4f %-12.6f\n", x, y);

    while (x < xn - 1e-6) {
        // 4th order Taylor expansion
        y = y + h * f(x, y)
              + (h*h/2.0)   * f1(x, y)
              + (h*h*h/6.0) * f2(x, y)
              + (h*h*h*h/24.0) * f3(x, y);
        x += h;
        printf("%-12.4f %-12.6f\n", x, y);
    }

    return 0;
}