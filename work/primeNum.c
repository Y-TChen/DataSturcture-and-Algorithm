#include<stdio.h>

float mysqrt(int num){
	float Sqrt = num;
	for(int i = 0; i < 6; i++){
		Sqrt = (Sqrt + (num/Sqrt))/2;
	}
	return Sqrt;
}

int isPrime(int num){
	int i;
	if(num < 4){
		if(num <= 1)
			return 0;
		else if(num == 2)
			return 1;
		else
			return 1;
	}
	for(i = 2; i <= (int)mysqrt(num); i++){
		if(num % i == 0) // not prime number
			return 0;
	}

	return 1;  // is prime number
}

int NprimeNum(int n){
	int i = 1;
	if(n < 1) 
		return -1;

	while(n){
		i++;
		if(isPrime(i)){	
			n--; //find N prime number
			printf("%4d", i);
		}
	}

	return i;
}

int main(){
	int n = 12;
	printf("\n%dth prime number: %d\n", n, NprimeNum(n));

	return 0;
}
