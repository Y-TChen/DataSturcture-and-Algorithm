#include<stdio.h>


void print(int arr[], unsigned int len){
	for(int i = 0; i < len; i++){
		printf(" %3d", arr[i]);
	}
	printf("\n");
}

int maxSub(int arr[], unsigned int len){
	int sum = 0, maxSum = 0;
	for(int i = 0; i < len; i++){
		if(sum + arr[i] > 0){
			sum += arr[i];
		}
		else{
			sum = 0;
		}
		printf(" %3d", sum);
		if(sum > maxSum){		//record maxSum
			maxSum = sum;
		}
	}
	printf("\n");
	
	return maxSum;
}


int main(){
	int arr[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int maxSum;
	print(arr, sizeof(arr)/sizeof(arr[0]));
	maxSum = maxSub(arr, sizeof(arr)/sizeof(arr[0]));
	printf("Max SubArray is %d\n", maxSum);

	return 0;
}
