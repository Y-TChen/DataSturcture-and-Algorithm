#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
	int temp = *a;	// a's value
	*a = *b;
	*b = temp;
}

int partition(int* arr, int front, int end){
	int pivot = arr[end];	// choose last number of array to be pivot
	int smaller = front - 1;	// assume that all numbers are bigger/equal to pivot at first
	for(int i = front; i < end; i++){
		if(arr[i] < pivot){
			smaller ++;	
			swap(&arr[smaller], &arr[i]);	// swap this and first bigger number	
		}	
	}
	swap(&arr[smaller + 1], &arr[end]);	// swap pivot with first bigger number
	
	return smaller + 1;	// return pivot position
}

void quickSort(int* arr, int front, int end){
	if(front < end){	
		int pivot = partition(arr, front, end);
		quickSort(arr, front, pivot - 1);	// left side
		quickSort(arr, pivot + 1, end);	// right size
	}
}
void printArray(int* arr, int size){
	for(int i = 0; i < size; i++){
		printf("%3d", *(arr + i));
	}
	printf("\n");
}

int main(){
	int array[] = {9, 4, 1, 6, 7, 3, 8, 2, 5, 13, 2, 434, 14, 55, 67, 34, 2, 44, 1};
	int size = sizeof(array)/sizeof(int);

	printArray(array, size);
	quickSort(array, 0, size);
	printArray(array, size);

	return 0;
}
