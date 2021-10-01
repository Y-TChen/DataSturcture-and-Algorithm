#include<stdio.h>
void printArr(int *, unsigned int, int);
void shellSort(int *, unsigned int);


void shellSort(int *arr, unsigned int size){
	int i, j, gap, key;
	for(gap = size >> 1; gap > 0; gap >>= 1){
		printf("gap = %d\n", gap);
		printArr(arr, size, gap);
		for(i = gap; i < size; i++){
			key = arr[i];
			j = i;
			while((j-gap) >= 0 && arr[j-gap] > key){
				arr[j] = arr[j-gap];
				j -= gap;
			}
			arr[j] = key;
		}
		printArr(arr, size, gap);
	}
}

void printArr(int *arr, unsigned int size, int gap){
	if(gap != 1){
		for(int i = 0; i < size; i += gap){
			for(int j = i; (j < size) && (j < i+gap); j++){
				printf("%d ", arr[j]);
			}
			printf("\n");
		}	
	}	
	else{
		for(int i = 0; i < size; i++){	
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){

	int arr[9] = {5,6,7,2,1,4,8,9,3};
	shellSort(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
