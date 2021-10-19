#include<stdio.h>

#define MAX 10000

void mergeSort(int *, int, int);
void merge(int *, int, int, int);
void printArr(int *, int, int);


void mergeSort(int *arr, int start, int end){
	if(end > start){
		int mid = (end+start)/2;
		mergeSort(arr, start, mid);  // divide 2 sub-array
		mergeSort(arr, mid+1, end);
		merge(arr, start, end, mid);  // merge 2 sub-array
		printf("merge(start:%d, end:%d, mid:%d)\n", start, end, mid);
	}
}

void merge(int *arr, int start, int end, int mid){
	int leftNum = mid-start+1, rightNum = end-mid;  // elements in 2 sub-array
	int leftSub[leftNum + 1], rightSub[rightNum + 1];  //elements num + 1 more space
	int indexL, indexR;

	for(int i = start, j = 0; i <= mid; i++, j++){  //copy into 2 sub-arrays
		leftSub[j] = arr[i];
	}
	for(int i = mid+1, j = 0; i <= end; i++, j++){
		rightSub[j] = arr[i];
	}

	leftSub[leftNum] = MAX; // end of left sub-array
	rightSub[rightNum] = MAX;  // end of right sub-array

	printArr(leftSub, 0, leftNum);
	printArr(rightSub, 0, rightNum);

	for(int i = start, indexL = 0, indexR = 0; i <= end; i++){
		arr[i] = (leftSub[indexL] <= rightSub[indexR])?leftSub[indexL++]:rightSub[indexR++];
	}
}

void printArr(int *arr, int start, int end){
	for(int i = start; i <= end; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[] = {4,7,1,6,8,2,5,9,3};
	
	printArr(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	printArr(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	
	return 0;
}
