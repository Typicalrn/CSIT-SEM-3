#include <stdio.h>

void readInput(int A[], int B[], char nameA, char nameB) {
    printf("Enter 4-bit binary number %c: ", nameA);
    for (int i = 3; i >= 0; i--) scanf("%d", &A[i]);

    printf("Enter 4-bit binary number %c: ", nameB);
    for (int i = 3; i >= 0; i--) scanf("%d", &B[i]);
}

void aluOperation(int A[], int B[], int Result[], int M, int* overflow) {
    int carry = 0;
    int carry_into_msb = 0;

    switch (M) {
        case 0:  // Addition
            for (int i = 0; i < 4; i++) {
                if (i == 3) carry_into_msb = carry;
                Result[i] = A[i] ^ B[i] ^ carry;
                carry = (A[i] & B[i]) | (B[i] & carry) | (A[i] & carry);
            }
            break;

        case 1:  // Subtraction (2's complement)
            carry = 1;
            for (int i = 0; i < 4; i++) {
                int b_input = B[i] ^ 1;
                if (i == 3) carry_into_msb = carry;
                Result[i] = A[i] ^ b_input ^ carry;
                carry = (A[i] & b_input) | (b_input & carry) | (A[i] & carry);
            }
            break;

        case 2:  // AND
            for (int i = 0; i < 4; i++) Result[i] = A[i] & B[i];
            *overflow = 0;
            return;

        case 3:  // OR
            for (int i = 0; i < 4; i++) Result[i] = A[i] | B[i];
            *overflow = 0;
            return;

        default:
            printf("Invalid choice!\n");
            return;
    }
    *overflow = carry_into_msb ^ carry;
}

void printALU(int A[], int B[], int Result[], int M, int overflow) {
    printf("\nA        = ");
    for (int i = 3; i >= 0; i--) printf("%d", A[i]);

    printf("\nB        = ");
    for (int i = 3; i >= 0; i--) printf("%d", B[i]);

    printf("\nResult   = ");
    for (int i = 3; i >= 0; i--) printf("%d", Result[i]);

    if (M == 0 || M == 1) {
        printf("\nOverflow = %d", overflow);
        printf(overflow ? "  (Overflow Detected!)" : "  (No Overflow)");
    }
    printf("\n");
}

int main() {
    printf("Aryan Maharjan\n");
    int A[4], B[4], Result[4];
    int M, overflow = 0;

    printf("\nSelect ALU Operation:\n");
    printf("0 : Addition (A + B)\n");
    printf("1 : Subtraction (A - B)\n");
    printf("2 : AND (A & B)\n");
    printf("3 : OR  (A | B)\n");
    printf("Enter your choice (0-3): ");
    scanf("%d", &M);

    readInput(A, B, 'A', 'B');
    aluOperation(A, B, Result, M, &overflow);
    printALU(A, B, Result, M, overflow);

    return 0;
}