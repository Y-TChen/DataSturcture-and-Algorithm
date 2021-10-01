#include<stdio.h>
void swap(int *, int *);
void heapify(int *, int, int);
void heapSort(int *, unsigned int);
void printArr(int *, unsigned int);

void swap(int *dst, int *src){
	*src = *src + *dst;
	*dst = *src - *dst;
	*src = *src - *dst;
}

void heapify(int *arr, int start, int end){
	int parent = start;
	int son = 2*parent + 1;	// leftSon = 2*parent+1 rightSon = 2*parent+2

	while(son <= end){
		if(son+1 <= end && arr[son+1] > arr[son]){
			son++; //point to max son position
		}
		if(arr[parent] > arr[son]){
			return;  // don't need heapify
		}
		else{
			swap(&arr[parent], &arr[son]);
			parent = son;	// continue heapify
			son = 2*parent + 1; 
		}
	}	
}

void heapSort(int *arr, unsigned int size){
	int i;
	for(i = size/2 - 1; i >= 0; i--){ //heapify from last parent node arr[size/2-1]
		heapify(arr, i, size-1);
	}
	for(i = size-1; i > 0 ; i--){
		printArr(arr, size);
		swap(&arr[0], &arr[i]);	//put biggest element(root node)to array's tail
		heapify(arr, 0, i-1);
	}
	printArr(arr, size);
}

void printArr(int *arr, unsigned int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[] = {5,4,7,1,8,3,2,9,6};
	heapSort(arr, sizeof(arr)/sizeof(arr[0]));

	return 0;
}
