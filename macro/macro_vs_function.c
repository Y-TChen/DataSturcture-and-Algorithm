#include<stdio.h>

float devide(float, float);
#define devide(a, b) (b)/(a)

int main(){
	
	// macro > function
	printf("%f/%f = %.2f\n", 10.0, 5.0, devide(10.0, 5.0));	// 

	#undef devide
	printf("%f/%f = %.2f\n", 10.0, 5.0, devide(10.0, 5.0));

	return 0;
}

float devide(float a, float b){
	return a/b;
}

