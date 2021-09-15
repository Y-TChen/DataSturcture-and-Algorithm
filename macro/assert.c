#include<stdio.h>
#ifndef NDEBUG
	#define NDEBUG	// to cancel assert.h
#endif
#include<assert.h>

int minus(int a, int b){
	assert(a > b);	//see whether a > b
	return a-b;
}

int main(){
	int a = 5, b = 3;
	printf("%d - %d = %d\n", a, b, minus(a, b));
	b = 7; //error occur, unless gcc -D NODEBUG to remove assert
	printf("%d - %d = %d\n", a, b, minus(a, b));

	return 0;
}
