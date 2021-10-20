#include<stdio.h>
#include<stdlib.h>


int **D2Array(unsigned int r, unsigned int c){
	int **arr = (int **)malloc(r * sizeof(int *));	// create row element
	for(int i = 0; i < r; i++){
		arr[i] = (int *)malloc(c * sizeof(int));	// create column element
		for(int j = 0; j < c; j++){
			arr[i][j] = i*c + j;
		}
	}

	return arr;
}

void print(int **arr, unsigned r, unsigned c){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
	int **arr;
	int row, col;
	row = 5;
	col = 2;
	arr = D2Array(row, col);
	print(arr, row, col);
	return 0;
}

