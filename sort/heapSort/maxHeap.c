#include <stdio.h>
#include <stdlib.h>

	
typedef struct MaxHeap{
	int* array;	// array to store data
	int count;	// how many node in heap now
	int capacity;	// heap's capacity
}maxHeap;

maxHeap* createHeap(int);
void insert(maxHeap*, int);
void swap(int*, int*);
void heapify_up(int*, int);
void heapify_down(int*, int, int);
int popMax(maxHeap*);
void printArray(int*, int);
void deleteHeap(maxHeap*);
void buildMaxHeap(int*, int);
void heapSort(int*, int);

maxHeap* createHeap(int capacity){
	maxHeap* heap = (maxHeap*)malloc(sizeof(maxHeap));
	heap->count = 0;
	heap->capacity = capacity;
	heap->array = (int*)malloc(capacity * sizeof(int));

	return heap;
}

void insert(maxHeap* heap, int key){	// add new data into heap
	if(heap->count >= heap->capacity){  // if count exceed => popMax
		popMax(heap);
	}
	heap->array[heap->count] = key;
	heapify_up(heap->array, heap->count);
	heap->count++;
}

void swap(int* dst, int* src){
	int temp = *dst;
	*dst = *src;
	*src = temp;
}

void heapify_up(int* array, int index){
	// parnet = (index - 1)/2; 
	// child = 2*i + 1 , 2*i + 2
	if(array[(index - 1)/2] < array[index]){	// bigger than parent => heapify_up
		swap(&array[index], &array[(index - 1)/2]);
		heapify_up(array, (index - 1)/2);	// continue heapify_up parent node
	}
}

void heapify_down(int* array, int index, int count){
	// find biggest child and swap
	// left child => index * 2 +1
	// right child => index * 2 + 2 
	int biggest;	// index of the bigger child
	if(index*2 + 1 < count - 1){	// have both child
		biggest = (array[2*index + 1] > array[2*index + 2])?(2*index + 1):(2*index + 2);  // find biggest index
	}
	else if(index*2 + 1 == count - 1){	// only have left child
		biggest	= index*2 + 1;
	}
	else{	// have no child
		return;
	}
	if((array[index] < array[biggest]) && (biggest <= count - 1)){  // smaller than child => swap and heapify_down
		swap(&array[index], &array[biggest]);
		heapify_down(array, biggest, count);
	}
}

void buildMaxHeap(int* array, int count){	// transfer the array into max heap
	for(int i = count/2 - 1; i >= 0; i--){	// from count/2 that have child node
		heapify_down(array, i, count);
		printArray(array, count);
	}
}

void heapSort(int* array, int count){
	buildMaxHeap(array, count);	// transfer array into max heap first
	
	for(int i = count - 1; i >= 0; i--){		
		swap(array, (array + i));	// swap root node with the last node
		heapify_down(array, 0, i);	// after swapping, heapify_down the root node
	}
}

int popMax(maxHeap* heap){	// pop the max node
	if(!heap->count){  // count = 0 => return
		printf("Empty heap\n");	
		return -1;
	}  
	int pop = heap->array[0];
	heap->array[0] = heap->array[heap->count - 1];  // swap first and last node
	heap->count--;	// remove 1 node => count - 1
	heapify_down(heap->array, 0, heap->count);

	return pop;
}

void printArray(int* array, int len){
	for(int i = 0; i < len; i++){
		printf(" %d", *(array + i));
	}
	printf("\n");
}

void deleteHeap(maxHeap* heap){
	free(heap->array);
	free(heap);
}

int main(){
	int arr[10] = {13,5,7,4,2,8,1,6,9,10};
	printf("========== Print Array =============\n\n");
	printArray(arr, sizeof(arr)/sizeof(int));

	printf("========== Build Max Heap =============\n\n");
	heapSort(arr, sizeof(arr)/sizeof(int));
	
	printf("========== After Heap Sort =============\n\n");
	printArray(arr, sizeof(arr)/sizeof(int));

	return 0;
}
