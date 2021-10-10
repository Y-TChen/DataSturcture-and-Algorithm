#include<stdio.h>

unsigned int gcf(unsigned int, unsigned int);
unsigned int lcm(unsigned int, unsigned int);


unsigned int gcf(unsigned int num1, unsigned int num2){
	unsigned int remainder = 1;
	while(num2 != 0){
		remainder = num1 % num2;
		num1 = num2;
		num2 = remainder;
	}
	
	return num1;
} 

unsigned int lcm(unsigned int num1, unsigned int num2){
	unsigned int mygcf = gcf(num1, num2);
	
	return (num1*num2)/mygcf; 
}

int main(){	
	unsigned int arr[][2] = {{32,11},{32,28},{15,39}};
	for(int i = 0; i < 3; i++){
		printf("LCM(%d, %d) is %d\n", arr[i][0],arr[i][1], lcm(arr[i][0],arr[i][1]));
	}
}
