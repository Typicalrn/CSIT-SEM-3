#include<stdio.h>

void shellSort(int a[],int n){
    int i,j,increment,temp;
    for (increment = n/2; increment > 0; increment /= 2){
        for (i = increment; i < n; i++){
            temp = a[i];
            j = i;
            while (j >= increment && a[j - increment] > temp){
                a[j] = a[j - increment];
                j = j - increment;
            }
            a[j] = temp;
        }
    }

    
    printf("The sorted array is:");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d:",i);
        scanf("%d",&arr[i]);
    }

    shellSort(arr,n);
    

    return 0;
}