#include <stdio.h>
#include <math.h>

/*
   Romberg Integration

   Uses trapezoidal rule + Richardson extrapolation

   R(i,0) = trapezoidal approximation
   R(i,j) = R(i,j-1) + (R(i,j-1) - R(i-1,j-1)) / (4^j - 1)
*/

// Function to integrate (modify as needed)
double f(double x) {return 1.0 / x;}

// Trapezoidal rule
double trapezoid(double a, double b, int n) {
    double h = (b - a) / n,sum = f(a) + f(b);
    for(int i = 1; i < n; i++) {sum += 2 * f(a + i * h);}
    return (h / 2.0) * sum;
}

int main() {
    double a, b,R[10][10];
    int n, i, j;

    printf("Enter lower limit (a): ");scanf("%lf", &a);

    printf("Enter upper limit (b): ");scanf("%lf", &b);

    printf("Enter number of levels (n <= 10): ");scanf("%d", &n);

    // Build Romberg table
    for(i = 0; i < n; i++) {
        int intervals = pow(2, i);
        R[i][0] = trapezoid(a, b, intervals);
    }

    for(j = 1; j < n; j++) {
        for(i = j; i < n; i++) {
            R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(4, j) - 1);
        }
    }

    printf("\nRomberg Integration Table:\n\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {printf("%10.6f ", R[i][j]);}
        printf("\n");
    }
    printf("\nFinal Answer = %.6f\n", R[n-1][n-1]);

    return 0;
}