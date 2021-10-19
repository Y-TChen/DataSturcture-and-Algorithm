#include<stdio.h>

void add(int, int);
void minus(int, int);
void mul(int, int);
void divide(int, int);
void callFunction(void (*)()); //function pointer
void (*mathCalculate[])(int,int)={add,minus,mul,divide};  //function pointer array

int main(){

	int a = 5, b = 7;
	void (* fptr)(int, int);	
	fptr = add;
	fptr(a, b);

	callFunction(divide);
	
	mathCalculate[3](a, b);
	mathCalculate[2](a, b);


	return 0;
}
void callFunction(void (*fptr)(int, int)){
	fptr(2, 4);
}
void add(int a, int b){
	printf("%d + %d = %d\n", a, b, a+b);
}

void minus(int a, int b){
	printf("%d - %d = %d\n", a, b, a-b);

}
void mul(int a, int b){
	printf("%d x %d = %d\n", a, b, a*b);
}
void divide(int a, int b){
	printf("%d / %d = %.2f\n", a, b, (float)a/b);
}
