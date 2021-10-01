#include<stdio.h>


int binarySearch(int *arr, int key, unsigned int size){
	int front = 0, mid, end = size - 1;

	while(front <= end){
		mid = (end + front)/2;
		if(arr[mid] > key){
			end = mid - 1;
		}
		else if(arr[mid] < key){
			front = mid + 1;
		}
		else{
			return mid;
		}
	}

	return -1;
}

void printArr(int *arr, unsigned int size){
	while(size--){
		printf("%d ", *arr++);
	}
	printf("\n");
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,11};
	int key = 10, index;

	printArr(arr, sizeof(arr)/sizeof(arr[0]));
	printf("key: %d\n", key);
	index = binarySearch(arr, key, sizeof(arr)/sizeof(arr[0]));
	printf("index: %d\n", index);

	key = 5;
	printf("key: %d\n", key);
	index = binarySearch(arr, key, sizeof(arr)/sizeof(arr[0]));
	printf("index: %d\n", index);

	return 0;
}
