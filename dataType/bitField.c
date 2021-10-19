#include<stdio.h>

typedef struct itField{	
	unsigned int var1 : 3;	// 3 bits
	unsigned int var2 : 3;

}bitField;

int main(){

	bitField bF = {7, 8};

	printf("int var1 : 3 = %d\n", bF.var1);
	printf("int var2 : 3 = %d // overflow (8 > 3bits)\n", bF.var2);
	return 0;
}
