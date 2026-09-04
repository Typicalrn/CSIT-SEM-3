#include <stdio.h>

int A[4] = {0,0,0,0}, Q[4], M[4];

// Convert integer to 4-bit binary
void intToBinary(int num, int arr[]) {
    for(int i = 3; i >= 0; i--) {
        arr[i] = num % 2;
        num /= 2;
    }
}

// Convert binary to integer
int binaryToInt(int arr[]) {
    int num = 0;
    for(int i = 0; i < 4; i++)
        num = num * 2 + arr[i];
    return num;
}

// Print array
void printArray(int arr[]) {
    for(int i = 0; i < 4; i++)
        printf("%d", arr[i]);
}

// Left shift (A,Q)
void leftShift() {
    for(int i = 0; i < 3; i++)
        A[i] = A[i+1];

    A[3] = Q[0];

    for(int i = 0; i < 3; i++)
        Q[i] = Q[i+1];
}

// A = A - M
void subtractM() {
    int borrow = 0;
    for(int i = 3; i >= 0; i--) {
        int diff = A[i] - M[i] - borrow;
        if(diff < 0) {
            diff += 2;
            borrow = 1;
        } else borrow = 0;
        A[i] = diff;
    }
}

// A = A + M
void addM() {
    int carry = 0;
    for(int i = 3; i >= 0; i--) {
        int sum = A[i] + M[i] + carry;
        A[i] = sum % 2;
        carry = sum / 2;
    }
}

// Check sign
int isNegative() {
    return A[0] == 1;
}

int main() {
    int dividend, divisor;
    int count = 4;

    printf("Enter Dividend (0-15): ");
    scanf("%d", &dividend);

    printf("Enter Divisor (1-15): ");
    scanf("%d", &divisor);

    intToBinary(dividend, Q);
    intToBinary(divisor, M);

    printf("\nInitial Values:\n");
    printf("A = "); printArray(A);
    printf("  Q = "); printArray(Q);
    printf("  M = "); printArray(M);
    printf("\n");

    printf("\nStep |   A    |   Q    | Operation\n");
    printf("---------------------------------------\n");

    int step = 1;

    while(count--) {
        leftShift();
        printf("%2d   | ", step++);
        printArray(A); printf(" | ");
        printArray(Q); printf(" | Left Shift\n");

        subtractM();
        printf("     | ");
        printArray(A); printf(" | ");
        printArray(Q); printf(" | A = A - M\n");

        if(isNegative()) {
            Q[3] = 0;
            addM();
            printf("     | ");
            printArray(A); printf(" | ");
            printArray(Q); printf(" | Restore (A = A + M), Q0=0\n");
        } else {
            Q[3] = 1;
            printf("     | ");
            printArray(A); printf(" | ");
            printArray(Q); printf(" | Q0 = 1\n");
        }

        printf("---------------------------------------\n");
    }

    printf("\nFinal Result:\n");
    printf("Quotient (Binary) = "); printArray(Q);
    printf("\nRemainder (Binary) = "); printArray(A);

    printf("\nQuotient (Decimal) = %d", binaryToInt(Q));
    printf("\nRemainder (Decimal) = %d\n", binaryToInt(A));

    return 0;
}