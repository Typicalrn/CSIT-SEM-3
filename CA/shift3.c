//to perform shift operations(logical, arithmetic and circular) on a given number
#include <stdio.h>

int logicalLeft(int n) {
    return n << 1;
}

int logicalRight(int n) {
    return (unsigned int)n >> 1;
}

int arithmeticLeft(int n) {
    return n << 1;
}

int arithmeticRight(int n) {
    return n >> 1;
}

int circularLeft(int n) {
    return ((n << 1) | (n >> 7)) & 0xFF;
}

int circularRight(int n) {
    return ((n >> 1) | (n << 7)) & 0xFF;
}

int main() {
    int n, choice, sub, result;

    printf("Aryan Maharjan\n");

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\nSelect Shift Type:\n");
    printf("1. Logical Shift\n");
    printf("2. Arithmetic Shift\n");
    printf("3. Circular Shift\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("\n1. Left Shift\n2. Right Shift\nEnter sub-choice: ");
    scanf("%d", &sub);

    switch (choice) {
        case 1:
            if (sub == 1)
                result = logicalLeft(n);
            else
                result = logicalRight(n);

            printf("Logical Shift Result = %d\n", result);
            break;

        case 2:
            if (sub == 1)
                result = arithmeticLeft(n);
            else
                result = arithmeticRight(n);

            printf("Arithmetic Shift Result = %d\n", result);
            break;

        case 3:
            if (sub == 1)
                result = circularLeft(n);
            else
                result = circularRight(n);

            printf("Circular Shift Result = %d\n", result);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}