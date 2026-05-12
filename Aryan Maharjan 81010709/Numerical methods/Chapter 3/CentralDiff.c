// Lab Assignment #3.3 - Numerical Differentiation: Central Difference
#include <stdio.h>

#define MAX 20

int main() {
    float x[MAX], y[MAX];
    int n, i;
    float h, xp;

    printf("===== Derivative by Central Difference Formula =====\n");
    printf("First  derivative: f'(x)  = [f(x+h) - f(x-h)] / (2h)\n");
    printf("Second derivative: f''(x) = [f(x+h) - 2f(x) + f(x-h)] / h^2\n\n");

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values (equal spacing):\n");
    for (i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    h = x[1] - x[0];

    printf("\nEnter x at which derivative is required: ");
    scanf("%f", &xp);

    int pos = -1;
    for (i = 0; i < n; i++) {
        if ((int)(x[i] * 1000) == (int)(xp * 1000)) {
            pos = i;
            break;
        }
    }

    if (pos == -1 || pos - 1 < 0 || pos + 1 >= n) {
        printf("Error: Need at least one point on each side of x.\n");
        return 1;
    }

    float dy1 = (y[pos + 1] - y[pos - 1]) / (2 * h);
    printf("\nFirst  derivative f'(%.4f)  = %.6f\n", xp, dy1);

    if (pos - 1 >= 0 && pos + 1 < n) {
        float dy2 = (y[pos + 1] - 2*y[pos] + y[pos - 1]) / (h * h);
        printf("Second derivative f''(%.4f) = %.6f\n", xp, dy2);
    }

    return 0;
}