#include<stdio.h>

float mysqrt(float num){	// use Newton's method

	float sqrt = num;
	for(int i = 0; i < 6; i++){
		sqrt = (sqrt + (num/sqrt))/2;
		printf("(%d) sqrt = (%f)\n", i+1, sqrt);
	}
	printf("\n");
	return sqrt; 
}

int main(){
	for(float i = 14; i < 18; i++){
		printf("square root(%.3f) = %.3f\n", i, mysqrt(i));
	
	}

	return 0;
}
