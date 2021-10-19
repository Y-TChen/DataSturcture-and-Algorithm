#include<stdio.h>

// find greatest common factor
unsigned int gcf(unsigned int num1, unsigned int num2){
	unsigned int remainder = 1;
	while(num2 != 0){
		remainder = num1 % num2;
		num1 = num2;
		num2 = remainder;
	}
	
	return num1;
} 

int main(){
	unsigned int arr[][2] = {{32,11},{32,28},{15,39}};
	for(int i = 0; i < 3; i++){
		printf("GCF(%d, %d) is %d\n", arr[i][0],arr[i][1], gcf(arr[i][0],arr[i][1]));
	}
	return 0;
}
