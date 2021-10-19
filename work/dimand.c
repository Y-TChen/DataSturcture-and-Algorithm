#include<stdio.h>

void print(unsigned int num){
	int i, j;
	++num;
	for(i = 0; i < num; i++){
		for(j = 0; j < num-i-1; j++){
			printf(" ");
		}
		for(j = 0; j < 2*i - 1; j++){
			printf("*");
		}
		printf("\n");
	}
}

int main(){
	unsigned int num;
        printf("Enter dimand high:");	
	scanf("%d", &num);

	print(num);
	return 0;
}
