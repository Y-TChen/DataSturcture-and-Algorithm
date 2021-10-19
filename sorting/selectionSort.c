#include<stdio.h>
void printArr(int *, unsigned int);
void selectionSort(int *, unsigned int);
void swap(int *, int *);

void swap(int *dst, int *src){
	*src = *src + *dst;
	*dst = *src - *dst;
	*src = *src - *dst;
}

void selectionSort(int *arr, unsigned int size){
	int min;  // position of min key
	for(int i = 0; i < size - 1; i++){ // record sorted list's tail
		printArr(arr, size);

		min = i; // min = sorted list's tail
		for(int j = (i + 1); j < size; j++){
			if(arr[j] < arr[min]){
				min = j; // record min key position
			}	
		}

		if(min != i){
			printf("swap(%d,%d)\n", arr[i], arr[min]);
			swap(&arr[i], &arr[min]);  //swap min value to sorted list's tail
		}
	}

}

void printArr(int *arr, unsigned int size){
	while(size){
		printf("%d ",*arr);
		arr++;
		size--;
	}
	printf("\n");
}

int main(){
	int arr[9] = {7,1,6,9,2,8,4,3,5};

	selectionSort(arr, sizeof(arr)/ sizeof(arr[0]));

	return 0;
}
