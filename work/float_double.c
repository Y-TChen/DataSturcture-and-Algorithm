#include<stdio.h>
#include<stdlib.h>

// 小數後面最多保留6位元，其餘四捨五入
// 有效位數: float 6~7  double 15~16 long double 18~19

int main(){

	float f = 987654321.12345789;
	printf("float: %f\n只有7位有效數字\n", f);
	
	double d = 987654321.12345789;
	printf("double: %f\n最多16位有效數字\n", d);
	printf("小數點一律只保留6位，其餘四捨五入\n");

	double a = 0.6180339887123;
	float b = 0.6180339887123;
	printf("double: %f\n", a*1000000000);
	printf("float: %f\n", b*1000000000);
}
