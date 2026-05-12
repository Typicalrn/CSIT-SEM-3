// Lab Assignment #3.7 - Maxima and Minima of a Tabulated Function
#include <stdio.h>

#define MAX 20

int main() {
    float x[MAX], y[MAX];
    int n, i;
    float h;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values (equal spacing):\n");
    for (i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    h = x[1] - x[0];

    printf("\nNumerical Derivatives:\n");
    printf("%-10s %-12s %-12s\n", "x", "f'(x)", "f''(x)");
    printf("--------------------------------------\n");

    int found = 0;
    for (i = 1; i < n - 1; i++) {
        float dy  = (y[i+1] - y[i-1]) / (2 * h);
        float dy2 = (y[i+1] - 2*y[i] + y[i-1]) / (h * h);
        printf("%-10.4f %-12.6f %-12.6f\n", x[i], dy, dy2);

        // Check sign change in first derivative (zero crossing)
        float dy_prev = (y[i] - y[i-2]) / (2 * h);  // may be invalid at i=1, handled below
        if (i >= 2) {
            float dy_l = (y[i] - y[i-2]) / (2 * h);
            float dy_c = dy;
            if (dy_l * dy_c < 0) {
                // Sign change: extremum between x[i-1] and x[i]
                float x_ext = x[i-1] - dy_l * (x[i] - x[i-1]) / (dy_c - dy_l);
                if (dy2 < 0)
                    printf("  >> LOCAL MAXIMA near x = %.4f\n", x_ext);
                else if (dy2 > 0)
                    printf("  >> LOCAL MINIMA near x = %.4f\n", x_ext);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("\nChecking by direct comparison of y values:\n");
        for (i = 1; i < n - 1; i++) {
            if (y[i] > y[i-1] && y[i] > y[i+1])
                printf("Local MAXIMA at x = %.4f, f(x) = %.4f\n", x[i], y[i]);
            else if (y[i] < y[i-1] && y[i] < y[i+1])
                printf("Local MINIMA  at x = %.4f, f(x) = %.4f\n", x[i], y[i]);
        }
    }

    return 0;
}