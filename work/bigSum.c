#include<stdio.h>
#include<string.h>

#define LEN 300

int input(char n[]){
	char s[LEN];
	int len;
	for(int i = 0; i < LEN; i++)  // initialize array
		n[i] = 0;

	if(scanf("%s", s) < 1) return -1;

	len = strlen(s);
	for(int i = 0; i < len; i++){  // store element in int from tail
		n[i] = s[len-i-1] - '0'; 
	}
	return 0;
}

void sum(char n1[], char n2[], char sum[]){
	int carryIn = 0;
	for(int i = 0; i < LEN; i++){  
		sum[i] = n1[i] + n2[i] + carryIn;
		carryIn = sum[i]/10;
	       	sum[i] %= 10;
	}
}

void print(char n[]){
	int i;
	for(i = LEN-1; i>0; i--){
		if(n[i] != 0)	// find start of array
			break;
	}
	for(;i >= 0; i--){
		printf("%d", n[i]);
	}
	printf("\n");
}

int main(){
	char n1[LEN], n2[LEN], bigSum[LEN];

	input(n1);	
	input(n2);	
	sum(n1, n2, bigSum);
	print(n1);
	print(n2);
	print(bigSum);
	return 0;
}
