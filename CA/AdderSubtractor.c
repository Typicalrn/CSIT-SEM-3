#include <stdio.h>

void fullAdder(int a, int b, int cin, int* sum, int* cout) {
    *sum = a ^ b ^ cin;
    *cout = (a & b) | (b & cin) | (a & cin);
}

void readBinary(int arr[], char name) {
    printf("Enter 4 bit binary number %c: ", name);
    for (int i = 3; i >= 0; i--) {
        scanf("%d", &arr[i]);
    }
}

void printResult(int S[], int carry) {
    printf("result = ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", S[i]);
    }
    printf("\nOverflow: %d\n", carry);
}

int main() {
    printf("Aryan Maharjan\n");
    int A[4], B[4], S[4];
    int M, carry;

    readBinary(A, 'A');
    readBinary(B, 'B');

    printf("Enter Mode (0: Addition, 1: Subtraction): ");
    scanf("%d", &M);

    carry = M;

    for (int i = 0; i < 4; i++) {
        int b_input = B[i] ^ M;
        fullAdder(A[i], b_input, carry, &S[i], &carry);
    }

    printResult(S, carry);

    return 0;
}