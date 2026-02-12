#include<stdio.h>

void merge(int a[],int begin,int mid,int end){
    int i=begin,j=mid+1,index =0;
    int temp[end-begin+1];
    while (i<=mid && j<=end){
        if (a[i]<a[j]){
            temp[index]=a[i];
            i++;
        }else{
            temp[index]=a[j];
            j++;
        }
        index++;
    }
    //merging right half
    if (i>mid){
        while (j<=end)
        {
            temp[index]=a[j];
            j++;
            index++;
        }  
    }
    //merging left half
    else{
        while (i<=mid)
        {
            temp[index]=a[i];
            i++;
            index++;
        }
        
    }
    int k=0;
    while (k<index){
        a[begin+k]=temp[k];
        k++;
    }
    
    
}

void mergeSort(int a[],int begin,int end){
    if (begin<end){
        int mid=(begin+end)/2;
        mergeSort(a,begin,mid);//left part dividing
        mergeSort(a,mid+1,end);//right part dividing

        merge(a,begin,mid,end);//merging the divided parts

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

    mergeSort(arr,0,n-1);


    
    printf("The sorted array is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    

    return 0;
}