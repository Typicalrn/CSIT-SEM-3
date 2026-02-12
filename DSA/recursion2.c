#include<stdio.h>

int fibonacci(int n){
    if (n==0 || n==1)
    {
        printf("Base case reached \n");
        return 1;
    }else{
        int step1=fibonacci(n-1),step2=fibonacci(n-2);
        printf("%d+%d\n",step1,step2);
        return step1+step2;
    }
    
}

int main(){
    int n;
    printf("Enter the number of terms in fibonacci series:");
    scanf("%d",&n);
    printf("Fibonacci series up to %d terms is:\n",n);
    for(int i=0;i<n;i++){
        printf("%d",fibonacci(i));
        if(i!=n-1){
            printf(", ");
        }
    }
    return 0;
}