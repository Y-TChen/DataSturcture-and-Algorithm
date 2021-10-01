#include<stdio.h>
void swap(int *, int *);
void bubleSort(int *, unsigned int);
void printArr(int *, unsigned int);


void swap(int *dst, int *src){
	*dst = *dst + *src;
	*src = *dst - *src;
	*dst = *dst - *src;
}

void bubleSort(int *arr, unsigned int size){
	char finish = 0; // finish = 1 => list is sorted  
	int *_arr = arr; // for print array
	unsigned int _size = size; // for print array

	while(size > 1){
		printArr(_arr, _size);
		finish = 0;
		for(int i = 1; i < size; i++){
			if(arr[i-1] > arr[i]){
				printf("swap(%d,%d)\n", *(arr+i-1), *(arr+i));
				swap(&arr[i-1], &arr[i]);
				finish = 1;
			}
		}

		if(finish == 0){ // finish sorting
			printf("Finish sorting\n");
			break;
		}

		size--;
	}
	printArr(_arr, _size);
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
	int arr[9] = {5,7,3,9,8,1,2,6,4};

	bubleSort(arr, sizeof(arr)/sizeof(arr[0]));

	return 0;
}
