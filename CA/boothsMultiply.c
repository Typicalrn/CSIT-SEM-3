#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

void printTable(int step, int A, int Q, int Q_1, int Q0, char* action, int count) {
    printf("Step %2d | A=%04d | Q=%04d | Q-1=%d | Q0=%d | %-10s | Count=%d\n",
           step, A, Q, Q_1, Q0, action, count);
}

int main() {
    printf("Aryan Maharjan\n");
    int M, Q, A = 0, Q_1 = 0;
    int count = 4;
    int Q0;

    printf("Enter multiplicand (M): ");
    scanf("%d", &M);
    printf("Enter multiplier (Q): ");
    scanf("%d", &Q);
    printf("BOOTH'S MULTIPLICATION ALGORITHM (4-bit)\n");
    printf("Step | A     | Q     | Q-1 | Q0 | Action     | Count\n");
    printf("----------------------------------------------------\n");

    printTable(0, A, Q, Q_1, 0, "Initial", count);

    while (count > 0) {
        Q0 = Q & 1;

        char* action = "Arithmetic";
        if (Q0 == 1 && Q_1 == 0) {
            A = subtract(A, M);
            action = "Subtract";
        } else if (Q0 == 0 && Q_1 == 1) {
            A = add(A, M);
            action = "Add";
        }

        printTable(4-count+1, A, Q, Q_1, Q0, action, count);

        Q_1 = Q0;
        Q = (Q >> 1) | ((A & 1) << 3);
        A = A >> 1;
        count--;
    }

    printf("----------------------------------------------------\n");
    printf("Result:\nA = %04d, Q = %04d\n", A, Q);
    printf("Final Product = %d\n", (A << 4) | (Q & 0xF));

    return 0;
}