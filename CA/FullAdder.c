#include <stdio.h>

void fullAdder(int A, int B, int cin, int* sum, int* cout) {
    *sum = (A ^ B) ^ cin;
    *cout = (A & B) | (cin & (A ^ B));
}

int main() {
    printf("Aryan Maharjan\n");
    printf("FULL ADDER - Single Bit\n\n");
    
    int a, b, cin, sum, cout;

    printf("Enter a binary bit A (0 or 1): ");
    scanf("%d", &a);

    printf("Enter a binary bit B (0 or 1): ");
    scanf("%d", &b);

    printf("Enter carry in (0 or 1): ");
    scanf("%d", &cin);

    printf("\nFULL ADDER\n");
    printf("Inputs: A=%d, B=%d, Cin=%d\n", a, b, cin);

    fullAdder(a, b, cin, &sum, &cout);

    printf("sum = %d\n", sum);
    printf("carry out = %d\n", cout);

    return 0;
}