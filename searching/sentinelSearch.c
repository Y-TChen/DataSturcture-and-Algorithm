#include<stdio.h>

#define SIZE 10

void printArr(int *, unsigned int);
int sentinelSearch(int *, int);
int sequentialSearch(int *, int, unsigned int);

int sentinelSearch(int *arr, int key){	// return index
	int i = 0;  // index 
	arr[SIZE-1] = key;	// insert sentinel 
	while(arr[i++] != key);

	return i-1;
}

int sequentialSearch(int *arr, int key, unsigned int size){
	for(int i = 0; i < size; i++){  // need a loop to check array size => slower
		if(arr[i] == key){	
			return i;
		}
	}

	return -1; 
}

void printArr(int *arr, unsigned int size){
	while(size--){
		printf("%d ", *arr++);
	}
	printf("\n");
}

int main(){
	int arr[SIZE] = {7,5,1,9,4,6,8,2,3,0};
	int key = 7;

	printArr(arr, SIZE-1);
	printf("key: %d\n", key);

	int index = sentinelSearch(arr, key);
	printf("%d\n", index);
	
	index = sequentialSearch(arr, key, SIZE-1);
	printf("%d\n", index);
	
	return 0;
}
