#include<stdio.h>
int partition(int *, int, int);
void qsort(int *, int, int);
void printArr(int *, int, int);
void swap(int *, int *);

void swap(int *dst, int *src){
	*src = *src + *dst;
	*dst = *src - *dst;
	*src = *src - *dst;
}

int partition(int *arr, int front, int end){
	int pivot = arr[end];  // pivot = arr[end] by default  
	int smaller = front - 1;  // assume all elements are bigger than pivot 
	
	for(int i = front; i < end ; i++){
		if(arr[i] < pivot){
			smaller++;  // 1 more element smaller than pivot
			if(smaller != i){
				swap(&arr[smaller], &arr[i]); // swap pivot with first bigger element
			}
		}
	}
	if(smaller + 1 != end){
		swap(&arr[smaller + 1], &arr[end]); // swap pivot with first bigger element
	}

	return smaller + 1;
}

void qsort(int *arr, int front, int end){
	if(front < end){
		printf("Before parition:\n");
		printArr(arr, front, end);
		int pivot = partition(arr, front, end);  // find pivot first
		printf("left sub-array:\n");
		printArr(arr, front, pivot-1);
		printf("right sub-array:\n");
		printArr(arr, pivot+1, end);
		qsort(arr, front, pivot-1);  //left side
		qsort(arr, pivot+1, end);  //right side
	}
}

void printArr(int *arr, int front, int end){
	for(int i = front; i <= end; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[] = {1,7,6,4,8,2,5,9,3};
	qsort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	
	printf("After qsort:\n");
	printArr(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	return 0;
}
