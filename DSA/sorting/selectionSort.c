#include<stdio.h>

void selectionSort(int a[],int n){
    int i,j,MIN_INDEX,temp;
    for(i=0;i<n-1;i++){
        MIN_INDEX=i;
        for (j=i+1;j<n;j++)
        {
            if(a[j]<a[MIN_INDEX]){
                MIN_INDEX=j;
            }
        }
        temp=a[i];
        a[i]=a[MIN_INDEX];
        a[MIN_INDEX]=temp;
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

    selectionSort(arr,n);
    

    return 0;
}