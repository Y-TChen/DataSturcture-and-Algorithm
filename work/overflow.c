#include<stdio.h>

int overflow(int a, int b){
	int c = a+b;
	if((a > 0) && (b > 0) && (c < 0))
		return 1;
	if((a < 0) && (b < 0) && (c > 0))
		return 1;
	else
		return 0;
}

int main(){
	int a, b;
	printf("Enter 2 number:");
	scanf("%d %d", &a, &b);
	printf("%d + %d = %d\n overflow: %d\n", a, b, a+b, overflow(a, b));

	return 0;
}
