#include<stdio.h>

typedef union uni{
	unsigned char allMem;	
	struct{
		unsigned int bit0 : 1;	// use 1 bit
		unsigned int bit1 : 1;
		unsigned int bit2 : 1;
		unsigned int bit3 : 1;
		unsigned int bit4 : 1;
		unsigned int bit5 : 1;
		unsigned int bit6 : 1;
		unsigned int bit7 : 1;
	};
}uni;

void unionPrint(uni myUnion){

	printf("allMem = 0x%x\n", myUnion.allMem);
	printf("bit0 = %d\n", myUnion.bit0);
	printf("bit1 = %d\n", myUnion.bit1);
	printf("bit2 = %d\n", myUnion.bit2);
	printf("bit3 = %d\n", myUnion.bit3);
	printf("bit4 = %d\n", myUnion.bit4);
	printf("bit5 = %d\n", myUnion.bit5);
	printf("bit6 = %d\n", myUnion.bit6);
	printf("bit7 = %d\n\n", myUnion.bit7);
}

int main(){
	uni myUnion;	// all variables in union share same memory (1 byte)

	myUnion.allMem = 0x80; // 1000 0000	
	unionPrint(myUnion);
	
	myUnion.allMem = 0x35; // 0011 0101	
	unionPrint(myUnion);

	return 0;
}
