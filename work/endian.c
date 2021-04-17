#include<stdio.h>
#include<stdlib.h>

int main(){
	printf("=========== Endian comparison =========\n");
	
	unsigned short int i = 0x1234;	// 2 byte (16 bit)
	char* c = (char*)&i;	// 1 byte (8 bit)

	// lenght of heximal number : 4 bit

	printf("short int: 0x%x\n", i);
	printf("char: 0x%x\n", *c);
	
	if(*c == 0x12){
		printf("Big endian\n");
	}
	else{
		printf("Small endian\n");
	}
	return 0;
}
