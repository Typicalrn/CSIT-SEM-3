//Implemetnation of shell sort in C
#include <stdio.h>
 
int main() {
  int arr[10]={-1},n,flag=1,gap,temp;
  printf("Enter the no of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }
  // Shell Sort
  gap=n;
  while (flag==1||gap>1) {
    flag=0;
    gap=(gap+1)/2;
    for(int i=0;i<n-gap;i++){
      if(arr[i]>arr[i+gap]){
        temp=arr[i+gap];
        arr[i+gap]=arr[i];
        arr[i]=temp;
        flag=0;
      }
    }
  }
  printf("Sorted array: ");
  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}