#include<stdio.h>
#include<conio.h>

void binary(int a){
    int i,k;
    for (i = 3; i>=0; i--)
    {
        k=(a>>i)&1;
        printf("%d",k);
    }
    
}

int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("Hex equivalent is :%X\n",n);
    printf("Octal equivalent is :%o\n",n);
    printf("Binary equivalent is :");
    binary(n);
    printf("\n");
    printf("1's complement of %d is:\n",n);
    binary(-n-1);
    printf("2's complement of %d is:\n",n);
    binary(-n);
    return 0;
}