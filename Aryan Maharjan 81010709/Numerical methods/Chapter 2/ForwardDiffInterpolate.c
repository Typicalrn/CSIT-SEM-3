// Lab Assignment #2.2 - Newton's Forward Difference Formula
#include <stdio.h>

#define MAX 20

float x[MAX], y[MAX], delta[MAX][MAX];
int n;

void forward_diff_table() {
    int i, j;
    for (i = 0; i < n; i++)
        delta[i][0] = y[i];

    for (j = 1; j < n; j++)
        for (i = 0; i < n - j; i++)
            delta[i][j] = delta[i + 1][j - 1] - delta[i][j - 1];
}

void print_table() {
    int i, j;
    printf("\nForward Difference Table:\n");
    printf("%-10s %-12s", "x", "y");
    for (j = 1; j < n; j++)
        printf("D%-11d", j);
    printf("\n");
    for (i = 0; i < 60; i++) printf("-");
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%-10.4f %-12.4f", x[i], delta[i][0]);
        for (j = 1; j < n - i; j++)
            printf("%-12.4f", delta[i][j]);
        printf("\n");
    }
}

float interpolate(float xp) {
    float h = x[1] - x[0];
    float s = (xp - x[0]) / h;
    float result = delta[0][0];
    float s_term = s;
    float factorial = 1.0;
    int r;

    for (r = 1; r < n; r++) {
        factorial *= r;
        result += (s_term / factorial) * delta[0][r];
        s_term *= (s - r);
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

    forward_diff_table();
    print_table();

    printf("\nEnter value to interpolate at: ");
    scanf("%f", &xp);

    printf("Interpolated value f(%.4f) = %.6f\n", xp, interpolate(xp));

    return 0;
}