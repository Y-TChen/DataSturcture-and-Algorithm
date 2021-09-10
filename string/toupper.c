#include<stdio.h>

// 'a' - 'A' = 32 (2^5)
int toupper(int c){
	if(c >= 'a' && c <= 'z'){
		return c-32;	
	}

	else return c;
}

int tolower(int c){
	if(c >= 'A' && c <= 'Z'){
		return c+32;
	}

	else return c;
}

void upperPrint(const char* str){
	while(*str){
		printf("%c", toupper(*str++));
	}

	printf("\n");
}

void lowerPrint(const char* str){
	while(*str){
		printf("%c", tolower(*str++));
	}

	printf("\n");
}

int main(){
	char str1[] = "toupper Test!";
	char str2[] = "TOLOWER Test!";
	printf("Before: %s\n", str1);
	printf("After: ");
	upperPrint(str1);

	printf("Before: %s\n", str2);
	printf("After: ");
	lowerPrint(str2);

	return 0;
}
