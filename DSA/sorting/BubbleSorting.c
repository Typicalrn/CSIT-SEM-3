#include<stdio.h>

void bubbleSort(int a[],int n){
    int pass,i,temp,flag=1;
    for ( pass = 0; pass < n-1 && flag==1; pass++){
        flag=0;
        for ( i = 0; i < n-1-pass; i++){
            if (a[i]>a[i+1]){
                flag=1;
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }  
        }
        printf("\n%d pass:",pass);
        for (int k = 0; k < n; k++){
            printf("%d ",a[k]);
        }
        
    }

    printf("\nThe sorted array is:\n");
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    
    
}

int main(){
    int n=5;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d:",i);
        scanf("%d",&arr[i]);
    }

    bubbleSort(arr,n);
    

    return 0;
}