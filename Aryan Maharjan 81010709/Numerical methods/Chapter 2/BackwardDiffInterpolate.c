// Lab Assignment #2.3 - Newton's Backward Difference Formula
#include <stdio.h>

#define MAX 20

float x[MAX], y[MAX], diff[MAX][MAX];
int n;

void backward() {
    for (int i = 0; i < n; i++){diff[i][0] = y[i];}

    for (int j = 1; j < n; j++){
        for (int i = j; i < n; i++){
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];}}
}

void print() {
    printf("\nBackward Difference Table:\n");
    printf("%-10s %-12s", "x", "y");
    for (int j = 1; j < n; j++){printf("D%-11d", j);}
    printf("\n");
    for (int i = 0; i < 60; i++){ printf("-");}
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%-10.4f %-12.4f", x[i], diff[i][0]);
        for (int j = 1; j <= i; j++){ printf("%-12.4f", diff[i][j]);}
        printf("\n");
    }
}

float inter(float xp) {
    float h = x[1] - x[0], s = (xp - x[n - 1]) / h;
    float res = diff[n - 1][0],st = s,fact = 1.0;

    for (int r = 1; r < n; r++) {
        fact *= r;
        res += (st / fact) * diff[n - 1][r];
        st *= (s + r);
    }
    return res;
}

int main() {
    float xp;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values (equal spacing required):\n");
    for (int i = 0; i < n; i++) {
        printf("  x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    backward();print();

    printf("\nEnter value to interpolate at: ");
    scanf("%f", &xp);

    printf("Interpolated value f(%.4f) = %.6f\n", xp, inter(xp));

    return 0;
}