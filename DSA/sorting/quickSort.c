#include<stdio.h>

int partition(int a[],int begin,int end){
    int left,right,pivot,flag=0;
    pivot=left=begin;
    right=end;

    while(flag==0){
        while(a[pivot]<=a[right] && pivot!=right){
            right--;
        }
        if (pivot==right){
            flag=1;
        }else{
            int temp=a[pivot];
            a[pivot]=a[right];
            a[right]=temp;
            pivot=right;
        }
        if(flag==0){
            while (a[pivot]>=a[left] && pivot!=left)
            {
                left++;
                
            }
            if (pivot==left){
            flag=1;
            }else{
                int temp=a[pivot];
                a[pivot]=a[left];
                a[left]=temp;
                pivot=left;
            }
        }

    }
    return pivot;
}

void quickSort(int a[],int begin,int end){
    if (begin<end){
        int pivot = partition(a,begin,end);
        quickSort(a,begin,pivot-1);
        quickSort(a,pivot+1,end);

    }
    
    
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

    quickSort(arr,0,n-1);

    printf("The sorted array is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    

    return 0;
}