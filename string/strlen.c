#include<stdio.h>

unsigned long int strlen(const char* str){
	unsigned long int len = 0;

	const char* ptr = str;
	while(*ptr++){	// *ptr = 0 => end of string
		len++;
	}

	return len;
}

int main(){
	char str[] = "Length of string testing!";

	printf("%s\n", str);
	printf("Len: %ld\n", strlen(str));
	return 0;
}
