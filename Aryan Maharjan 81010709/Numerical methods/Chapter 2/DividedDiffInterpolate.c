// Lab Assignment #2.1 - Newton's Divided Difference Interpolation
#include <stdio.h>

#define MAX 20

float x[MAX], y[MAX], dd[MAX][MAX];
int n;

void div_diff() {
    int i, j;
    for (i = 0; i < n; i++)
        dd[i][0] = y[i];

    for (j = 1; j < n; j++)
        for (i = 0; i < n - j; i++)
            dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (x[i + j] - x[i]);
}

void print() {
    int i, j;
    printf("\nDivided Difference Table:\n");
    printf("%-10s %-12s", "x", "f(x)");
    for (j = 1; j < n; j++)
        printf("D%-11d", j);
    printf("\n");
    for (i = 0; i < 60; i++) printf("-");
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%-10.4f %-12.4f", x[i], dd[i][0]);
        for (j = 1; j < n - i; j++)
            printf("%-12.4f", dd[i][j]);
        printf("\n");
    }
}

float inter(float xp) {
    float result = dd[0][0];
    float product = 1.0;
    int i;
    for (i = 1; i < n; i++) {
        product *= (xp - x[i - 1]);
        result += dd[0][i] * product;
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

    div_diff();
    print();

    printf("\nEnter value to interpolate  at: ");
    scanf("%f", &xp);

    printf("Interpolated value f(%.4f) = %.6f\n", xp, inter(xp));

    return 0;
}