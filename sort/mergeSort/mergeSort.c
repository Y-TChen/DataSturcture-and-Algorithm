#include<stdio.h>
#include<stdlib.h>

void mergeSort(int [], int ,int);
void printArray(int [], int, int);
void merge(int [], int, int, int);

void mergeSort(int data[], int front, int end){
	int mid = (front + end)/2;
	
	if(end - front > 1){	// cut array into 2 parts until there are only 1 or 2 element in array	
		mergeSort(data, front, mid);
		mergeSort(data, mid + 1, end);	
	}
	// start to merge
	merge(data, front, mid, end);
}

void merge(int data[], int front, int mid, int end){	// compare left, right array and reassemble

	int leftArray[20], rightArray[20];	// copy left and right array
	int* dst = leftArray;	// use to copy array
	int* src = &data[front];

	while(src - &data[mid + 1]){	// copy until src = right array
		*dst++ = *src++;
	}
	*dst = 99999;	// stop compare here
	
	dst = rightArray;
	while(src - &data[end + 1]){	// continue copy into right array
		*dst++ = *src++;
	}
	*dst = 99999;	// stop compare here
	
	printf("\nLeft Array: ");
	printArray(leftArray, 0, (mid - front));
	printf("\nRight Array: ");
	printArray(rightArray, 0, (end - mid - 1));
	printf("\n");
	
	int indexL = 0, indexR = 0;	// index of two array
	for(int i = front; i <= end; i++){ // compare left and right array, fill in data array with smaller one
		data[i] = (leftArray[indexL] <= rightArray[indexR])? leftArray[indexL++]: rightArray[indexR++];
	}
}

void printArray(int data[], int front, int end){
	for(int i = front; i <= end; i++){
		printf("%d ", data[i]);
	}
}

int main(){
	int data[] = {9,5,3,8,6,2,7,1,4};
	printf("========== Merge Sort ==========\nOrigin:\n");
	printArray(data, 0, sizeof(data)/sizeof(int) - 1);

	mergeSort(data, 0, (sizeof(data)/sizeof(int) - 1));
	printf("\nAfter merge sort:\n");
	printArray(data, 0, sizeof(data)/sizeof(int) - 1);
	printf("\n");
	return 0;
}
