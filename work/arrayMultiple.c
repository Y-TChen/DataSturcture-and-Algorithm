#include<stdio.h>
#define N 3	// arr[N][N] * arr[N][N]

void print(int arr[N][N]){
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void arrayMultiple(int arr1[N][N], int arr2[N][N], int arrMult[N][N]){
	int i, j, k;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			arrMult[i][j] = 0;
			for(k = 0; k < N; k++){
				arrMult[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
}

int main(){
	int arrMult[N][N];
	int arr1[N][N] = {1,2,3,4,5,6,7,8,9};
	int arr2[N][N] = {2,4,6,8,10,12,14,16,18};

	print(arr1);
	print(arr2);
	arrayMultiple(arr1, arr2, arrMult);
	print(arrMult);

	return 0;
}
