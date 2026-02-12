#include<stdio.h>

int factorial(int a, int result){
    if (a==0)
    {
        return result;
    }else{
        return factorial(a-1, a*result);
    }
    
}

int main(){
    int n;
    printf("Enter the number to find the factorial of:");
    scanf("%d",&n);
    printf("Factorial of %d is %d\n",n,factorial(n,1));
    return 0;
}