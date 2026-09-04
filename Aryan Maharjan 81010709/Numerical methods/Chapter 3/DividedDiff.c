// Lab Assignment #3.6 - Numerical Differentiation: Divided Difference
#include <stdio.h>
#define MAX 20

float x[MAX], y[MAX], dd[MAX][MAX];
int n;

void compute() {
    for (int i = 0; i < n; i++) {dd[i][0] = y[i];}
    for (int j = 1; j < n; j++){
        for (int i = 0; i < n - j; i++){
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);}}
}

// Derivative of Newton's divided difference interpolating polynomial at xp
float deri(float xp) {
    float result = 0.0;
    for (int i = 1; i < n; i++) {
        float sum = 0.0;
        for (int j = 0; j < i; j++) {
            float prod = 1.0;
            for (int k = 0; k < i; k++) {
                if (k != j) prod *= (xp - x[k]);
            }
            sum += prod;
        }
        result += dd[0][i] * sum;
    }
    return result;
}

int main() {
    float xp;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    compute();

    printf("\nEnter x at which derivative is required: ");
    scanf("%f", &xp);

    printf("f'(%.4f) = %.6f\n", xp, deri(xp));

    return 0;
}