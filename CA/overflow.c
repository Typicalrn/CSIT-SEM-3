#include <stdio.h>

int add(int a, int b, int cin, int* sum, int* cout){
    *sum = a ^ b ^ cin;
    *cout = (a & b) | (b & cin) | (a & cin);
}

int main(){
    int A[4], B[4], S[4];
    int carry = 0;
    int carry_into_msb;

    printf("Enter signed 4 bit binary number A: ");
    fflush(stdout);  // Force prompt display
    for(int i = 3; i >= 0; i--) {
        if (scanf("%d", &A[i]) != 1) {
            printf("Invalid input for A[%d]\n", i);
            return 1;
        }
        printf("A[%d] = %d\n", i, A[i]);  // Debug
    }

    printf("Enter signed 4 bit binary number B: ");
    fflush(stdout);
    for(int i = 3; i >= 0; i--) {
        if (scanf("%d", &B[i]) != 1) {
            printf("Invalid input for B[%d]\n", i);
            return 1;
        }
        printf("B[%d] = %d\n", i, B[i]);  // Debug
    }

    for(int i = 0; i < 4; i++) {
        if (i == 3) {
            carry_into_msb = carry;
        }
        add(A[i], B[i], carry, &S[i], &carry);
    }

    if (carry_into_msb != carry) {
        printf("OVERFLOW\n");
    } else {
        printf("NO OVERFLOW\n");
    }

    printf("result = ");
    for(int i = 3; i >= 0; i--) {
        printf("%d", S[i]);
    }
    printf("\ncarry: %d\n", carry);

    return 0;
}