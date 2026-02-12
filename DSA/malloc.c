#include<stdio.h>
#include<stdlib.h>

int main(){
    float *a,sum=0,avg;
    int n,i;
    printf("How many numbers:");
    scanf("%d",&n);
    a=(float*)malloc(n*sizeof(float));
    printf("Enter numbers:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f",(a+i));
        sum=sum+*(a+i);
    }
    avg=sum/n;;
    printf("Sum=%.2f\n",sum);
    printf("Average=%.2f\n",avg);
    free(a);
    return 0;
}

//dma,calloc,malloc,realloc ko theory then the code(hand written) and the output screenshot 