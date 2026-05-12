// Lab Assignment #5.2 - Picard's Method
// Solves dy/dx = x + y^2,  y(0) = 0
// y_(n+1)(x) = y0 + integral(f(t, y_n(t)) dt, x0 to x)
// Integration done using Trapezoidal rule
#include <stdio.h>

#define STEPS 1000

float f(float x, float y) {
    return x + y * y;  // dy/dx = x + y^2
}

// One Picard iteration:
// Given y_prev as array of values at t = x0, x0+h, ..., x0+n*h
// Returns new approximation at x = xp
float picard_step(float x0, float y0, float xp, float *y_prev, int n) {
    float h = (xp - x0) / n;
    float sum = 0.0;
    int i;
    float xa, xb;

    for (i = 0; i < n; i++) {
        xa = x0 + i * h;
        xb = x0 + (i + 1) * h;
        sum += 0.5 * h * (f(xa, y_prev[i]) + f(xb, y_prev[i + 1]));
    }
    return y0 + sum;
}

int main() {
    float x0, y0, xp;
    int iters, i, iter;

    printf("===== ODE Solution by Picard's Method =====\n");
    printf("Equation: dy/dx = x + y^2\n\n");
    printf("Enter initial x (x0): ");       scanf("%f", &x0);
    printf("Enter initial y (y0): ");       scanf("%f", &y0);
    printf("Enter x to evaluate at (xp): "); scanf("%f", &xp);
    printf("Enter number of iterations: ");  scanf("%d", &iters);

    int n = STEPS;
    float h = (xp - x0) / n;

    // Arrays for current and previous approximations over [x0, xp]
    static float y_prev[STEPS + 1];
    static float y_curr[STEPS + 1];

    // 0th approximation: y_0(t) = y0 for all t
    for (i = 0; i <= n; i++)
        y_prev[i] = y0;

    printf("\n%-12s %-15s\n", "Iteration", "y(xp)");
    printf("---------------------------\n");
    printf("%-12d %-15.6f  (initial guess)\n", 0, y0);

    for (iter = 1; iter <= iters; iter++) {
        // Build new approximation at each sub-point using previous approximation
        y_curr[0] = y0;
        for (i = 1; i <= n; i++) {
            float xi = x0 + i * h;
            // Integrate from x0 to xi using y_prev
            float sum = 0.0;
            int j;
            for (j = 0; j < i; j++) {
                float xa = x0 + j * h;
                float xb = x0 + (j + 1) * h;
                sum += 0.5 * h * (f(xa, y_prev[j]) + f(xb, y_prev[j + 1]));
            }
            y_curr[i] = y0 + sum;
        }

        // Copy curr to prev
        for (i = 0; i <= n; i++)
            y_prev[i] = y_curr[i];

        printf("%-12d %-15.6f\n", iter, y_curr[n]);
    }

    printf("\nFinal approximation: y(%.4f) = %.6f\n", xp, y_prev[n]);
    return 0;
}