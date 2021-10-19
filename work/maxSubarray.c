#include<stdio.h>

void maxSub(int arr[], unsigned int len){
	int arrSum[len];
	int sum = 0, maxSum = 0;
	for(int i = 0; i < len; i++){
		arrSum[i] = 0;
		printf(" %3d", arr[i]);
	}
	printf("\n");
	for(int i = 0; i < len; i++){
		if(sum + arr[i] > 0){
			sum += arr[i];
		}
		else{
			sum = 0;
		}
		arrSum[i] = sum;
	}
	for(int i = 0; i < len; i++){
		printf(" %3d", arrSum[i]);
		if(arrSum[i] > maxSum){
			maxSum = arrSum[i];
		}
	}
	printf("\n");
	
	printf("Max SubArray is %d\n", maxSum);
}


int main(){
	int arr[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	maxSub(arr, sizeof(arr)/sizeof(arr[0]));

	return 0;
}
