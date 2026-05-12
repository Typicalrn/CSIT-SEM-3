// Lab Assignment #3.2 - Numerical Differentiation: Backward Difference
#include <stdio.h>

#define MAX 20

int main() {
    float x[MAX], y[MAX];
    int n, i;
    float h, xp;

    printf("===== Derivative by Backward Difference Formula =====\n");
    printf("f'(x) = [3f(x) - 4f(x-h) + f(x-2h)] / (2h)  [O(h^2)]\n\n");

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

    if (pos == -1) {
        printf("Error: x = %.4f not found in table.\n", xp);
        return 1;
    }

    float dy;
    if (pos - 2 >= 0) {
        dy = (3*y[pos] - 4*y[pos-1] + y[pos-2]) / (2 * h);
        printf("\nUsing second-order backward difference:\n");
    } else if (pos - 1 >= 0) {
        dy = (y[pos] - y[pos-1]) / h;
        printf("\nUsing first-order backward difference:\n");
    } else {
        printf("Error: Not enough backward points.\n");
        return 1;
    }

    printf("f'(%.4f) = %.6f\n", xp, dy);

    return 0;
}