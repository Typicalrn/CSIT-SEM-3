// Lab Assignment #5.7 - Boundary Value Problem using Shooting Method
// Solves y'' = f(x, y, y'),  y(a) = alpha,  y(b) = beta
// Uses RK4 for IVP and bisection to find correct initial slope
// Example: y'' = -y,  y(0) = 0,  y(pi/2) = 1  => exact: y = sin(x)
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979

// System: y1 = y,  y2 = y'
// y1' = y2
// y2' = f(x, y1, y2)
float f2(float x, float y1, float y2) {
    return -y1;  // y'' = -y  (change as needed)
}

// Solve IVP with RK4, return y(b) given y(a)=alpha, y'(a)=s
float shoot(float a, float alpha, float b, float s, int steps) {
    float h = (b - a) / steps;
    float x  = a;
    float y1 = alpha;
    float y2 = s;
    float k1a, k1b, k2a, k2b, k3a, k3b, k4a, k4b;
    int i;

    for (i = 0; i < steps; i++) {
        k1a = h * y2;
        k1b = h * f2(x, y1, y2);

        k2a = h * (y2 + k1b / 2);
        k2b = h * f2(x + h/2, y1 + k1a/2, y2 + k1b/2);

        k3a = h * (y2 + k2b / 2);
        k3b = h * f2(x + h/2, y1 + k2a/2, y2 + k2b/2);

        k4a = h * (y2 + k3b);
        k4b = h * f2(x + h, y1 + k3a, y2 + k3b);

        y1 += (k1a + 2*k2a + 2*k3a + k4a) / 6.0;
        y2 += (k1b + 2*k2b + 2*k3b + k4b) / 6.0;
        x  += h;
    }
    return y1;
}

int main() {
    float a, b, alpha, beta;
    float s_lo, s_hi, s_mid, f_lo, f_mid;
    int steps = 100, iter;
    float tol = 1e-6;

    printf("Equation: y'' = -y\n\n");
    printf("Enter left boundary a: ");   scanf("%f", &a);
    printf("Enter y(a) = alpha: ");      scanf("%f", &alpha);
    printf("Enter right boundary b: ");  scanf("%f", &b);
    printf("Enter y(b) = beta: ");       scanf("%f", &beta);
    printf("Enter initial slope guess s_lo: "); scanf("%f", &s_lo);
    printf("Enter initial slope guess s_hi: "); scanf("%f", &s_hi);

    f_lo = shoot(a, alpha, b, s_lo, steps) - beta;

    printf("\nBisection iterations:\n");
    printf("%-6s %-12s %-12s\n", "Iter", "s_mid", "f(b)-beta");
    printf("------------------------------\n");

    for (iter = 1; iter <= 100; iter++) {
        s_mid = (s_lo + s_hi) / 2.0;
        f_mid = shoot(a, alpha, b, s_mid, steps) - beta;
        printf("%-6d %-12.6f %-12.6f\n", iter, s_mid, f_mid);

        if (fabs(f_mid) < tol) break;

        if (f_lo * f_mid < 0) {
            s_hi = s_mid;
        } else {
            s_lo = s_mid;
            f_lo = f_mid;
        }
    }

    printf("\nFound initial slope y'(a) = %.6f\n", s_mid);
    printf("Printing solution:\n\n");
    printf("%-10s %-12s\n", "x", "y");
    printf("------------------------\n");

    float h = (b - a) / steps;
    float x = a, y1 = alpha, y2 = s_mid;
    float k1a, k1b, k2a, k2b, k3a, k3b, k4a, k4b;
    int i;
    printf("%-10.4f %-12.6f\n", x, y1);

    for (i = 0; i < steps; i++) {
        k1a = h * y2;
        k1b = h * f2(x, y1, y2);
        k2a = h * (y2 + k1b/2);
        k2b = h * f2(x+h/2, y1+k1a/2, y2+k1b/2);
        k3a = h * (y2 + k2b/2);
        k3b = h * f2(x+h/2, y1+k2a/2, y2+k2b/2);
        k4a = h * (y2 + k3b);
        k4b = h * f2(x+h, y1+k3a, y2+k3b);
        y1 += (k1a + 2*k2a + 2*k3a + k4a) / 6.0;
        y2 += (k1b + 2*k2b + 2*k3b + k4b) / 6.0;
        x  += h;
        if (i % 10 == 9) printf("%-10.4f %-12.6f\n", x, y1);
    }

    return 0;
}