#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char str[] = "Mark";
	printf("Len of \"%s\" is %ld\n", str, strlen(str));
	printf("Size of array str[] is %ld\n", sizeof(str)/sizeof(str[0]));
	return 0;
}
