// Lab Assignment #5.9 - Poisson's Equation using Gauss-Seidel
// Solves: d2u/dx2 + d2u/dy2 = f(x, y)
// Example source: f(x, y) = -2 (constant)
#include <stdio.h>
#include <math.h>

#define MAX 10

// Source function f(x, y) for Poisson equation
float source(float x, float y) {
    return -2.0;  // Change as needed
}

int main() {
    int n, i, j, iter;
    float u[MAX][MAX], u_new;
    float tol = 1e-4, maxErr;
    int maxIter = 1000;
    float h;

    printf("Solves: d2u/dx2 + d2u/dy2 = f(x,y),  f(x,y) = -2\n\n");
    printf("Enter number of interior grid points per side (e.g. 3): ");
    scanf("%d", &n);
    printf("Enter grid spacing h: ");
    scanf("%f", &h);

    int N = n + 2;

    // Initialize all to zero
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            u[i][j] = 0;
 
    // Enter boundary conditions
    printf("\nEnter boundary values:\n");
    printf("Top row (left to right, %d values): ", N);
    for (j = 0; j < N; j++) scanf("%f", &u[0][j]);

    printf("Bottom row (left to right, %d values): ", N);
    for (j = 0; j < N; j++) scanf("%f", &u[N-1][j]);

    printf("Left column (top to bottom, %d values, excluding corners): ", n);
    for (i = 1; i < N-1; i++) scanf("%f", &u[i][0]);

    printf("Right column (top to bottom, %d values, excluding corners): ", n);
    for (i = 1; i < N-1; i++) scanf("%f", &u[i][N-1]);

    // Gauss-Seidel iteration
    printf("\nIterating...\n");
    for (iter = 1; iter <= maxIter; iter++) {
        maxErr = 0;
        for (i = 1; i < N-1; i++) {
            for (j = 1; j < N-1; j++) {
                float x = j * h;
                float y = i * h;
                // Poisson update: u = (neighbors - h^2 * f) / 4
                u_new = 0.25 * (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1]
                                - h * h * source(x, y));
                if (fabs(u_new - u[i][j]) > maxErr)
                    maxErr = fabs(u_new - u[i][j]);
                u[i][j] = u_new;
            }
        }
        if (maxErr < tol) {
            printf("Converged in %d iterations (max error = %.6f)\n", iter, maxErr);
            break;
        }
    }

    printf("\nSolution grid u[i][j]:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%10.4f ", u[i][j]);
        printf("\n");
    }

    return 0;
}