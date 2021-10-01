#include<stdio.h>
void insertionSort(int *, unsigned int);
void printArr(int *, unsigned int);

void insertSort(int *arr, unsigned int size){
	int i, j, key;
	for(i = 1; i < size; i++){
		printArr(arr, size);

		key = arr[i]; // remember key value
		j = i-1;
		while((j >= 0) && (arr[j] > key)){ // insert into sorted list
			arr[j+1] = arr[j]; // move right
			j--;
		}
		arr[j+1] = key;  // insert key value
	}
	printArr(arr, size);
}


void printArr(int *arr, unsigned int size){
	while(size){
		printf("%d ", *arr);
		arr++;
		size--;
	}
	printf("\n");
}

int main(){
	int arr[9] = {9,4,3,7,5,6,1,2,8};
	
	insertSort(arr, sizeof(arr)/sizeof(arr[0]));

	return 0;
}
