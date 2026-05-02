//implement bucket hashing in c
#include <stdio.h>

#define T_SIZE 5      // number of buckets
#define B_SIZE 3      // size of each bucket

int table[T_SIZE][B_SIZE];
int count[T_SIZE];   // number of elements in each bucket

// Hash function
int hash(int key){
    return key % T_SIZE;
}

// Insert into bucket
void insert(int key){
    int index = hash(key);

    // Check if bucket has space
    if(count[index] < B_SIZE){
        table[index][count[index]] = key;
        count[index]++;
    } else {
        printf("Overflow in bucket %d for key %d\n", index, key);
    }
}

// Display table
void display(){
    for(int i = 0; i < T_SIZE; i++){
        printf("Bucket %d: ", i);
        for(int j = 0; j < count[i]; j++){
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int arr[] = {50, 76, 85, 92, 73, 63};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Initialize counts
    for(int i = 0; i < T_SIZE; i++){
        count[i] = 0;
    }

    // Insert elements
    for(int i = 0; i < n; i++){
        insert(arr[i]);
    }

    // Display table
    printf("Bucket Hash Table:\n");
    display();

    return 0;
}