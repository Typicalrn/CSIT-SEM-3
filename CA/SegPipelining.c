#include <stdio.h>

int pc = 0;

void write_result_to_register_file(float result) {
    printf("Result: %f\n", result);
}

int fetch() {
    int instruction = 0x12345678 + pc * 4;
    pc++;
    printf("FETCH: PC=%d, Instruction=0x%08X\n", pc-1, instruction);
    return instruction;
}

int* decode(int instruction) {
    static int operands[2];
    operands[0] = 1;
    operands[1] = 2;
    printf("DECODE: Op1=%d, Op2=%d\n", operands[0], operands[1]);
    return operands;
}

void execute(float a, float b, float result) {
    printf("EXECUTE: %f %c %f = %f\n", a, (pc%2==1 ? '+' : '-'), b, result);
}

void pipeline_addition(float a, float b, float* result_out) {
    printf("=== Addition Pipeline ===\n");
    
    // Cycle 1: Fetch
    int instr1 = fetch();
    printf("Cycle 1: F\n\n");
    
    // Cycle 2: Fetch + Decode
    int instr2 = fetch();
    decode(instr1);
    printf("Cycle 2: F | D\n\n");
    
    // Cycle 3: Full Pipeline
    int instr3 = fetch();
    decode(instr2);
    float result = a + b;
    execute(a, b, result);
    printf("Cycle 3: F | D | E\n\n");
    
    *result_out = result;
    write_result_to_register_file(result);
}

void pipeline_subtraction(float a, float b, float* result_out) {
    pc = 0;  // Reset PC
    printf("=== Subtraction Pipeline ===\n");
    
    // Same 3-cycle pipeline fill
    int instr1 = fetch();
    printf("Cycle 1: F\n\n");
    
    int instr2 = fetch();
    decode(instr1);
    printf("Cycle 2: F | D\n\n");
    
    int instr3 = fetch();
    decode(instr2);
    float result = a - b;
    execute(a, b, result);
    printf("Cycle 3: F | D | E\n\n");
    
    *result_out = result;
    write_result_to_register_file(result);
}

int main() {
    printf("Aryan Maharjan\n");
    printf("3-Stage Pipeline Simulation (Fetch-Decode-Execute)\n\n");

    float a = 1.0f, b = 2.0f;
    float result_add, result_sub;

    pipeline_addition(a, b, &result_add);
    printf("Addition complete: a + b = %f\n\n", result_add);

    pipeline_subtraction(a, b, &result_sub);
    printf("Subtraction complete: a - b = %f\n", result_sub);

    return 0;
}