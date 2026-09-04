#include <stdio.h>

/*
   Gaussian Quadrature (2-point formula)

   Approximation:
   ∫(a to b) f(x) dx ≈ (b-a)/2 [ f(x1) + f(x2) ]

   where:
   x1 = (a+b)/2 - (b-a)/(2√3)
   x2 = (a+b)/2 + (b-a)/(2√3)
*/
// Example function: f(x) = 1 / (1 + x^2)
double f(double x) {return 1.0 / (1.0 + x * x);}

int main() {
    double a, b, x1, x2, t1, t2, result;

    printf("Enter lower limit (a): ");    scanf("%lf", &a);

    printf("Enter upper limit (b): ");    scanf("%lf", &b);

    // 2-point Gaussian Quadrature
    t1 = -1.0 / 1.73205080757;t2 =  1.0 / 1.73205080757;

    x1 = (a + b) / 2 + (b - a) / 2 * t1; x2 = (a + b) / 2 + (b - a) / 2 * t2;
    result = (b - a) / 2 * (f(x1) + f(x2));
    printf("\nApproximate integral = %.6f\n", result);

    return 0;
}