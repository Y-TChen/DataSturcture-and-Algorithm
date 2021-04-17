#include<stdlib.h>
#include<stdio.h>

void printCount(int[]);
void radixSort(int[], int[], int);

int main(){
	int data[12] = {143, 453, 632, 765, 85, 243, 657, 933, 6, 543, 27, 149};
	int output[12];
	int i, len;

	printf("=========== Before Sorting =============\n");
	for(i = 0; i < 12; i++){
		printf("%-3d ", data[i]);
	}
	printf("\n");

	len = sizeof(data) / sizeof(int);
	radixSort(data, output, len);

	printf("\n=========== After Sorting =============\n");
	for(i = 0; i < 12; i++){
		printf("%-3d ", output[i]);
		//printf("%-3d ", data[i]);
	}
	printf("\n");

	return 0;
}

void printCount(int counts[]){
	printf("\n================ Counts ===================\n");
	for(int i = 0; i < 10; i++){
		printf("%-3d ", i);
	}
	printf("\n");	
	for(int i = 0; i < 10; i++){
		printf("%-3d ", counts[i]);
	}
	printf("\n");	
}

void radixSort(int data[], int output[], int len){
	int divide = 1, digit, biggest = 0;
	int counts[10] = {0};
	// find biggest data in the array first
	for(int i = 0; i < len; i++){
		if(data[i] >= biggest){
			biggest = data[i];
		}
	}
	printf("\nBiggest data is %d\n", biggest);

	// start to get LSD and sum the prefix
	do{
		int i;	
		for(i = 0; i < len; i++){
			digit = ((data[i] / divide) % 10);	// get Least Significant Data
			counts[digit] ++;	// correspond counts ++
		}

		for(i = 1; i < 10; i++){	// sum the prefix
			counts[i] += counts[i - 1];	 
		}
		printCount(counts);
		
		// recovery / rebuild array
		for(i = len - 1; i>= 0; i--){
			digit = ((data[i] / divide) % 10);	// get LSD
			counts[digit]--;	// counts minus 1 first
			output[counts[digit]] = data[i];	// rebuild output array		
		}
		
		for(i = 0; i < len; i++){	// after rebuild, copy to data array
			data[i] = output[i];
		}

		for(i = 0; i< 10; i++){	// clear the counts
			counts[i] = 0;
		}
		divide *= 10;

	}while(biggest /= 10);	// while biggest data > 0
}






