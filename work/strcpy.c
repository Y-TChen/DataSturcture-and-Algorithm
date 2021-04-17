#include<stdio.h>
#include<stdlib.h>


void strcpy1(char* dst, const char* src){
	while(*src != '\0'){
		*dst++ = *src++;
	}
}

void strcpy2(char* dst, const char* src){
	while(*dst++ = *src++);
}

int main(){
	char dst[30];	
	char* src= "String space test!";
	
	strcpy2(dst, src);
	
	printf("Copy string: %s\n", dst);
}
