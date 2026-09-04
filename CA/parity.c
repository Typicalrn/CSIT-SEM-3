#include <stdio.h>

int countOnes(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 10 == 1)
            count++;
        num = num / 10;
    }
    return count;
}

int generateParityBit(int num, int parityType) {
    int count = countOnes(num);

    if (parityType == 0)   // Even parity
        return (count % 2 == 0) ? 0 : 1;
    else                   // Odd parity
        return (count % 2 == 0) ? 1 : 0;
}

void generateParity() {
    int num, parityType, parityBit;

    printf("Enter binary number: ");
    scanf("%d", &num);

    printf("Choose Parity Type (0 = Even, 1 = Odd): ");
    scanf("%d", &parityType);

    parityBit = generateParityBit(num, parityType);

    if (parityType == 0)
        printf("Even Parity Bit: %d\n", parityBit);
    else
        printf("Odd Parity Bit: %d\n", parityBit);

    printf("Transmitted Data: %d%d\n", num, parityBit);
}

void checkParity() {
    int num, parityType, count;

    printf("Enter received binary data (including parity bit): ");
    scanf("%d", &num);

    printf("Choose Parity Type used (0 = Even, 1 = Odd): ");
    scanf("%d", &parityType);

    count = countOnes(num);

    if (parityType == 0) {
        if (count % 2 == 0)
            printf("No Error Detected (Even Parity)\n");
        else
            printf("Error Detected (Even Parity)\n");
    } else {
        if (count % 2 == 1)
            printf("No Error Detected (Odd Parity)\n");
        else
            printf("Error Detected (Odd Parity)\n");
    }
}

int main() {
    int choice;

    printf("Aryan Maharjan\n");
    printf("===== PARITY PROGRAM =====\n");
    printf("1. Generate Parity Bit (Sender)\n");
    printf("2. Check Parity (Receiver)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            generateParity();
            break;

        case 2:
            checkParity();
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}