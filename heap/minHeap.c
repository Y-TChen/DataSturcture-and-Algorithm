#include <stdio.h>
#include <stdlib.h>

	
typedef struct MinHeap{
	int* array;	// array to store data
	int count;	// how many node in heap now
	int capacity;	// heap's capacity
}minHeap;

minHeap* createHeap(int);
void insert(minHeap*, int);
void swap(int*, int*);
void heapify_up(minHeap*, int);
void heapify_down(minHeap*, int);
int popMin(minHeap*);
void printHeap(minHeap*);

minHeap* createHeap(int capacity){
	minHeap* heap = (minHeap*)malloc(sizeof(minHeap));
	heap->count = 0;
	heap->capacity = capacity;
	heap->array = (int*)malloc(capacity * sizeof(int));

	return heap;
}

void insert(minHeap* heap, int key){	// add new data into heap
	if(heap->count >= heap->capacity){  // if count exceed => popMin
		popMin(heap);
	}
	heap->array[heap->count] = key;
	heapify_up(heap, heap->count);
	heap->count++;
}

void swap(int* dst, int* src){
	int temp = *dst;
	*dst = *src;
	*src = temp;
}

void heapify_up(minHeap* heap, int index){
	// parnet = (index - 1)/2; 
	// child = 2*i + 1 , 2*i + 2
	if(heap->array[(index - 1)/2] > heap->array[index]){	// bigger than parent => heapify_up
		swap(&heap->array[index], &heap->array[(index - 1)/2]);
		heapify_up(heap, (index - 1)/2);	// continue heapify_up parent node
	}
}

void heapify_down(minHeap* heap, int index){
	// find smaller child and swap
	// left child => index * 2 +1
	// right child => index * 2 + 2 
	int smaller = (heap->array[2*index + 1] < heap->array[2*index + 2])?(2*index + 1):(2*index + 2);  // find smaller index
	if((heap->array[index] > heap->array[smaller]) && (smaller <= heap->count - 1)){  // smaller than child => swap and heapify_down
		swap(&heap->array[index], &heap->array[smaller]);
		heapify_down(heap, smaller);
	}
}

int popMin(minHeap* heap){	// pop the min node
	if(!heap->count){  // count = 0 => return
		printf("Empty heap\n");	
		return -1;
	}  
	int pop = heap->array[0];
	heap->array[0] = heap->array[heap->count - 1];  // swap first and last node
	heap->count--;	// remove 1 node => count - 1
	heapify_down(heap, 0);

	return pop;
}

void printHeap(minHeap* heap){
	printf("\n");
	for(int i = 0; i < heap->count; i++){
		printf(" %d", *(heap->array + i));
	}
	printf("\n");
}

void printArray(int* array, int len){
	printf("========== Print Array =============\n\n");
	for(int i = 0; i < len; i++){
		printf(" %d", *(array + i));
	}
	printf("\n");
}

void deleteHeap(minHeap* heap){
	free(heap);
}

int main(){
	int arr[10] = {13,5,7,4,2,8,1,6,9,10};
	printArray(arr, sizeof(arr)/sizeof(int));
	
	printf("\n=== Find 3 biggest data in the array ===\n");
	minHeap* heap = createHeap(3); 	// find 3 biggest data in the array
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
		if(arr[i] > heap->array[0] || heap->count < heap->capacity){  // if data > minHeap[0] or count < capacity => insert into minHeap
			insert(heap, arr[i]);
			printHeap(heap);
		}
	}
	
	deleteHeap(heap);
	return 0;
}
