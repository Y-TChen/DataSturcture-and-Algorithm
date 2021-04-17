#include<stdio.h>
#include<stdlib.h>


void InsertionSort(int* arr, int size){
	for(int i = 1; i < size; i++){
		int j = i - 1;
		int key = arr[i];
		while(j > -1 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void printArray(int* arr, int size){
	for(int i = 0; i < size; i++){
		printf("%3d", *(arr + i));
	}
	printf("\n");
}

int main(){
	//int array[2] = {5, 3, 1, 2, 6, 4};
	int array[10] = {54, 3, 1, 2, 6, 4, 14, 3, 25, 5};
	int size = sizeof(array) / sizeof(int);

	printArray(array, size);
	InsertionSort(array, size);
	printArray(array, size);
	return 0;
}
