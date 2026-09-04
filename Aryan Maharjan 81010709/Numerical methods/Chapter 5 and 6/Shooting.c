// Lab Assignment #5.7 - Boundary Value Problem using Shooting Method
// Solves y'' = f(x, y, y'),  y(a) = alpha,  y(b) = beta
// Uses RK4 for IVP and bisection to find correct initial slope
// Example: y'' = -y,  y(0) = 0,  y(pi/2) = 1  => exact: y = sin(x)
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979

float f2(float x, float y1, float y2) { return -y1; }

// Solve IVP with RK4, return y(b) given y(a)=alpha, y'(a)=s
// If y_out is not NULL, stores y1 at each step (size: steps+1)
float shoot(float a, float alpha, float b, float s, int steps, float *y_out, float *x_out) {
    float h = (b - a) / steps, x = a, y1 = alpha, y2 = s;
    float k1, l1, k2, l2, k3, l3, k4, l4;

    if (y_out) { y_out[0] = y1; x_out[0] = x; }

    for (int i = 0; i < steps; i++) {
        k1 = h * y2;          l1 = h * f2(x,       y1,          y2);
        k2 = h * (y2 + l1/2); l2 = h * f2(x + h/2, y1 + k1/2,  y2 + l1/2);
        k3 = h * (y2 + l2/2); l3 = h * f2(x + h/2, y1 + k2/2,  y2 + l2/2);
        k4 = h * (y2 + l3);   l4 = h * f2(x + h,   y1 + k3,    y2 + l3);

        y1 += (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        y2 += (l1 + 2*l2 + 2*l3 + l4) / 6.0;
        x  += h;

        if (y_out) { y_out[i+1] = y1; x_out[i+1] = x; }
    }
    return y1;
}

int main() {
    float a, b, alpha, beta, s_lo, s_hi, s_mid, f_lo, f_mid, tol = 1e-6;
    int steps = 100, iter;

    printf("Equation: y'' = -y\n\n");
    printf("Enter left boundary a: ");          scanf("%f", &a);
    printf("Enter y(a) = alpha: ");             scanf("%f", &alpha);
    printf("Enter right boundary b: ");         scanf("%f", &b);
    printf("Enter y(b) = beta: ");              scanf("%f", &beta);
    printf("Enter initial slope guess s_lo: "); scanf("%f", &s_lo);
    printf("Enter initial slope guess s_hi: "); scanf("%f", &s_hi);

    f_lo = shoot(a, alpha, b, s_lo, steps, NULL, NULL) - beta;

    printf("\nBisection iterations:\n");
    printf("%-6s %-12s %-12s\n", "Iter", "s_mid", "f(b)-beta");
    printf("------------------------------\n");

    for (iter = 1; iter <= 100; iter++) {
        s_mid = (s_lo + s_hi) / 2.0;
        f_mid = shoot(a, alpha, b, s_mid, steps, NULL, NULL) - beta;
        printf("%-6d %-12.6f %-12.6f\n", iter, s_mid, f_mid);

        if (fabs(f_mid) < tol) break;

        if (f_lo * f_mid < 0)
            s_hi = s_mid;
        else {
            s_lo = s_mid;
            f_lo = f_mid;
        }
    }

    printf("\nFound initial slope y'(a) = %.6f\n", s_mid);
    printf("\nPrinting solution:\n\n");
    printf("%-10s %-12s\n", "x", "y");
    printf("------------------------\n");

    // Reuse shoot() to get all intermediate values — no duplicate RK4 loop
    static float y_out[101], x_out[101];
    shoot(a, alpha, b, s_mid, steps, y_out, x_out);

    for (int i = 0; i <= steps; i++)
        if (i == 0 || i % 10 == 9)
            printf("%-10.4f %-12.6f\n", x_out[i], y_out[i]);

    return 0;
}