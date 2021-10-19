#include<stdio.h>

#define INCREMENT(x) ++x
#define MUL1(a, b) a*b
#define MUL2(a, b) (a)*(b)
#define MERGE(a, b) a##b //  tocken pasting
#define GET(a) #a // tocken convert to string
int main(){
	char *ptr = "ABCDE";
	int x = 11;
	// Macro don't care data type
	printf("%s\n", INCREMENT(ptr));
	printf("%d\n", INCREMENT(x));
	
	printf("a*b = %d\n", MUL1(2+3, 4+5));
	printf("(a)*(b) = %d\n", MUL2(2+3, 4+5));

	printf("%d\n", MERGE(12, 34));
	printf("%s\n", GET(Mark));
	return 0;
}
