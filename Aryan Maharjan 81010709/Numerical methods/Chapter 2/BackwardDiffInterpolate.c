// Lab Assignment #2.3 - Newton's Backward Difference Formula
#include <stdio.h>

#define MAX 20

float x[MAX], y[MAX], nabla[MAX][MAX];
int n;

void backward_diff_table() {
    int i, j;
    for (i = 0; i < n; i++)
        nabla[i][0] = y[i];

    for (j = 1; j < n; j++)
        for (i = j; i < n; i++)
            nabla[i][j] = nabla[i][j - 1] - nabla[i - 1][j - 1];
}

void print_table() {
    int i, j;
    printf("\nBackward Difference Table:\n");
    printf("%-10s %-12s", "x", "y");
    for (j = 1; j < n; j++)
        printf("D%-11d", j);
    printf("\n");
    for (i = 0; i < 60; i++) printf("-");
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%-10.4f %-12.4f", x[i], nabla[i][0]);
        for (j = 1; j <= i; j++)
            printf("%-12.4f", nabla[i][j]);
        printf("\n");
    }
}

float interpolate(float xp) {
    float h = x[1] - x[0];
    float s = (xp - x[n - 1]) / h;
    float result = nabla[n - 1][0];
    float s_term = s;
    float factorial = 1.0;
    int r;

    for (r = 1; r < n; r++) {
        factorial *= r;
        result += (s_term / factorial) * nabla[n - 1][r];
        s_term *= (s + r);
    }
    return result;
}

int main() {
    int i;
    float xp;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values (equal spacing required):\n");
    for (i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    backward_diff_table();
    print_table();

    printf("\nEnter value to interpolate at: ");
    scanf("%f", &xp);

    printf("Interpolated value f(%.4f) = %.6f\n", xp, interpolate(xp));

    return 0;
}