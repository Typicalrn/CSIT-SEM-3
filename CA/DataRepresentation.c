#include <stdio.h>

void printBinary(unsigned int num)
{
    int bit = 128;   // 2^7 for 8-bit display
    while (bit > 0)
    {
        if (num & bit)
            printf("1");
        else
            printf("0");
        bit /= 2;
    }
}

void printOnesComplement(unsigned int num)
{
    unsigned int ones = ~num;
    printBinary(ones);
}

void printTwosComplement(unsigned int num)
{
    unsigned int twos = ~num + 1;
    printBinary(twos);
}

int main()
{
    printf("Aryan Maharjan\n");
    unsigned int num;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("\nHexadecimal: %X", num);
    printf("\nOctal: %o", num);

    printf("\nBinary: ");
    printBinary(num);

    printf("\n1's Complement: ");
    printOnesComplement(num);

    printf("\n2's Complement: ");
    printTwosComplement(num);

    printf("\n");

    return 0;
}