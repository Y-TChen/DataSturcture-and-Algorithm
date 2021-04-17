//
//	see whether number is pow of two
//
#include<stdio.h>

int pow_of_two(int num){
	return (num > 0 && !(num&(num-1)));
}

int main(){
	
	int num = 5;
	printf("%d = pow of 2 ? : %d\n", num, pow_of_two(num));	//	5
	printf("%d = pow of 2 ? : %d\n", num+3, pow_of_two(num+3));	//	8
	printf("%d = pow of 2 ? : %d\n", num+10, pow_of_two(num+10));	//	15
	printf("%d = pow of 2 ? : %d\n", num+11, pow_of_two(num+11));	//	16
	return 0;
}
