// Eigenvalue and Eigenvector using Power Method
#include <stdio.h>
#include <math.h>

#define MAX 10
#define TOL 1e-6
#define ITER 1000

int n;
float A[MAX][MAX];

void mat_vec(float v[], float r[]) {
    for (int i = 0; i < n; i++) {
        r[i] = 0;
        for (int j = 0; j < n; j++)
            r[i] += A[i][j] * v[j];
    }
}

float normalize(float v[], float out[]) {
    float mx = 0;
    for (int i = 0; i < n; i++)
        if (fabs(v[i]) > mx) mx = fabs(v[i]);
    for (int i = 0; i < n; i++)
        out[i] = v[i] / mx;
    return mx;
}

int main() {
    float v[MAX], Mv[MAX], vn[MAX],lam = 0, lam_old = 0;

    printf("===== Eigenvalue & Eigenvector (Power Method) =====\n");
    printf("Enter matrix size n: ");
    scanf("%d", &n);

    printf("Enter matrix A row by row:\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++)
            scanf("%f", &A[i][j]);
    }

    for (int i = 0; i < n; i++) v[i] = 1.0;

    printf("\n%-6s %-14s  Eigenvector\n", "Iter", "Eigenvalue");
    printf("----------------------------------------------------\n");

    for (int iter = 1; iter <= ITER; iter++) {
        mat_vec(v, Mv);
        lam = normalize(Mv, vn);
        printf("%-6d %-14.6f  [ ", iter, lam);
        for (int i = 0; i < n; i++) printf("%.4f ", vn[i]);
        printf("]\n");
        if (fabs(lam - lam_old) < TOL) break;
        lam_old = lam;
        for (int i = 0; i < n; i++) v[i] = vn[i];
    }

    printf("\nDominant Eigenvalue  : %.6f\n", lam);
    printf("Dominant Eigenvector : [ ");
    for (int i = 0; i < n; i++) printf("%.6f ", vn[i]);
    printf("]\n");

    return 0;
}