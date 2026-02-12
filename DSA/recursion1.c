#include<stdio.h>

int factorial(int n){
    if(n==0){
        printf("Base case reached\n");
        return 1;
    }else{
        int step=n*factorial(n-1);
        printf("%d\n",step);
        return step;
    }
}

int main(){
    int n;
    printf("Enter the number to find the factorial of:");
    scanf("%d",&n);
    printf("Factorial of %d is %d\n",n,factorial(n));
    return 0;
}