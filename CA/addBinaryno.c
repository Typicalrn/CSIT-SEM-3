//addition of biinary numbers
#include <stdio.h>

void full_adder(int A, int B, int cin, int *sum, int *cout) {
    *sum = A ^ B ^ cin;
    *cout = (A & B) | (B & cin) | (A & cin);
}

int main() {
    printf("Aryan Maharjan\n");
    int A[4], B[4], sum[4];
    int carry = 0;

    printf("Enter a 4 bit binary number A: ");
    for (int i = 3; i >= 0; i--) {
        scanf("%d", &A[i]);
    }

    printf("Enter a 4 bit binary number B: ");
    for (int i = 3; i >= 0; i--) {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < 4; i++) {
        full_adder(A[i], B[i], carry, &sum[i], &carry);
    }

    printf("Result\n");
    printf("Sum = ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", sum[i]);
    }
    printf("\nCarry = %d", carry);

    return 0;
}