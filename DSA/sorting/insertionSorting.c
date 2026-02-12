#include<stdio.h>

void insertionSort(int a[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while (j>=0 && temp<= a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;        
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

    insertionSort(arr,n);
    

    return 0;
}