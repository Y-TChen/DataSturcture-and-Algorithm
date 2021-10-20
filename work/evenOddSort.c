#include<stdio.h>

void swap(unsigned int *dst, unsigned int *src){
	*dst ^= *src;
	*src ^= *dst;
	*dst ^= *src;
}

void ascendingSort(unsigned int *arr, int start, int end){
	int i, j;
	if(start >= end)
		return;
	for(i = start+1; i <= end; i++){
		j = i-1;
		while((j >= start) && (arr[j] > arr[j+1])){
				swap(&arr[j], &arr[j+1]);
				j--;	
		}	
	}	
}

void descendingSort(unsigned int *arr, int start, int end){
	int i, j;
	if(start >= end)
		return;
	for(i = start+1; i <= end; i++){
		j = i-1;
		while((j >= start) && (arr[j] < arr[j+1])){
				swap(&arr[j], &arr[j+1]);
				j--;	
		}	
	}	
}
void evenOddSort(unsigned int *arr, unsigned int len){
	int i, idx_odd;	// idx_odd => position to swap
	for(i = 0, idx_odd = 0; i < len; i++){
		if(arr[i] & 0x1U){ // odd => True
			if(arr[idx_odd] != arr[i])
				swap(&arr[idx_odd], &arr[i]);	
			idx_odd++;
		}
	}
	ascendingSort(arr, 0, idx_odd - 1);	// odd part => ascending sort
	descendingSort(arr, idx_odd, len-1);	// even part => descending sort
}

void print(unsigned int *arr, unsigned int len){
	while(len--){
		printf("%3d", *arr++);
	}
	printf("\n");
}

int main(){
	unsigned int arr[] = {7,5,1,4,9,8,3,2,6};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	
	evenOddSort(arr, sizeof(arr)/sizeof(arr[0]));	
	print(arr, sizeof(arr)/sizeof(arr[0]));
	
	return 0;
}
