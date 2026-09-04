#include <stdio.h>

void halfAdder(int a, int b){
  int sum = a^b;
  int carry = a&b;

  printf("sum = %d\ncarry = %d\n", sum, carry);
}

int main(){
    printf("Aryan Maharjan\n");

  int a, b;

  printf("Enter a binary bit A (0 or 1): ");
  scanf("%d", &a);

  printf("Enter a binary bit B (0 or 1): ");
  scanf("%d", &b);

  printf("\nHALF ADDER\n");
  halfAdder(a,b);

  return 0;
}