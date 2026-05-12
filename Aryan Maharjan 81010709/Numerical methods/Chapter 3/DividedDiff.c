// Lab Assignment #3.6 - Numerical Differentiation: Divided Difference
#include <stdio.h>

#define MAX 20

float x[MAX], y[MAX], dd[MAX][MAX];
int n;

void compute_divided_diff() {
    int i, j;
    for (i = 0; i < n; i++) dd[i][0] = y[i];
    for (j = 1; j < n; j++)
        for (i = 0; i < n - j; i++)
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
}

// Derivative of Newton's divided difference interpolating polynomial at xp
float derivative(float xp) {
    float result = 0.0;
    int i, j;
    for (i = 1; i < n; i++) {
        float sum = 0.0;
        for (j = 0; j < i; j++) {
            float prod = 1.0;
            int k;
            for (k = 0; k < i; k++) {
                if (k != j) prod *= (xp - x[k]);
            }
            sum += prod;
        }
        result += dd[0][i] * sum;
    }
    return result;
}

int main() {
    int i;
    float xp;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    compute_divided_diff();

    printf("\nEnter x at which derivative is required: ");
    scanf("%f", &xp);

    printf("f'(%.4f) = %.6f\n", xp, derivative(xp));

    return 0;
}