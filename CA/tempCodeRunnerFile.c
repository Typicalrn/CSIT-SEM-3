#include <stdio.h>

int A[4] = {0,0,0,0}, Q[4], M[4];

void leftShift() {
    for(int i = 0; i < 3; i++)
        A[i] = A[i+1];

    A[3] = Q[0];

    for(int i = 0; i < 3; i++)
        Q[i] = Q[i+1];
}

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

void addM() {
    int carry = 0;
    for(int i = 3; i >= 0; i--) {
        int sum = A[i] + M[i] + carry;
        A[i] = sum % 2;
        carry = sum / 2;
    }
}

int isNegative() {
    return A[0] == 1; 
}

int main() {
    printf("Aryan Maharjan\n");
    int count = 4;

    printf("Enter 4-bit Dividend:\n");
    for(int i = 3; i >= 0; i--) scanf("%d", &Q[i]);

    printf("Enter 4-bit Divisor:\n");
    for(int i = 3; i >= 0; i--) scanf("%d", &M[i]);

    while(count--) {
        leftShift();
        subtractM();

        if(isNegative()) {
            Q[3] = 0;
            addM(); 
        } else {
            Q[3] = 1;
        }
    }

    printf("\nQuotient = ");
    for(int i = 0; i < 4; i++) printf("%d", Q[i]);

    printf("\nRemainder = ");
    for(int i = 0; i < 4; i++) printf("%d", A[i]);

    return 0;
}