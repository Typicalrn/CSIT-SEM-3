// Lab Assignment #1 - Synthetic Division
#include <stdio.h>

#define MAX 20

void syn_Div(float coeff[], int deg, float root) {
    float result[MAX];
    int i;

    result[0] = coeff[0];
    for (i = 1; i <= deg; i++) {
        result[i] = result[i - 1] * root + coeff[i];
    }

    printf("\nSynthetic Division by (x - %.2f)\n", root);
    printf("-----------------------------------\n");
    printf("Coefficients: ");
    for (i = 0; i <= deg; i++)
        printf("%.2f  ", coeff[i]);

    printf("\nResult row:   ");
    for (i = 0; i <= deg; i++)
        printf("%.2f  ", result[i]);

    printf("\nQuotient coefficients: ");
    for (i = 0; i < deg; i++)
        printf("%.2f  ", result[i]);

    printf("\nRemainder: %.2f\n", result[deg]);

    if (result[deg] == 0)
        printf("x = %.2f is a root of the polynomial.\n", root);
    else
        printf("x = %.2f is NOT a root of the polynomial.\n", root);
}

int main() {
    float coeff[MAX];
    float root;
    int deg, i;

    printf("Enter degree of polynomial: ");
    scanf("%d", &deg);

    printf("Enter %d coefficients (highest degree first): ", deg + 1);
    for (i = 0; i <= deg; i++) {
        scanf("%f", &coeff[i]);
    }

    printf("Enter the root (divisor value): ");
    scanf("%f", &root);

    syn_Div(coeff, deg, root);

    return 0;
}