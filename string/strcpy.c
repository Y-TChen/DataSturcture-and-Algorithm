#include<stdio.h>

void Strcpy(char* dst, char* src){
	while(*dst++ = *src++);

}


int main(){
	char str1[20] = "src", str2[20] = "Dst string123";
	
	printf("Before:\n str1 = \"%s\"\tstr2 = \"%s\"\n", str1, str2);
	Strcpy(str2, str1);
	printf("\nAfter:\n str1 = \"%s\"\tstr2 = \"%s\"\n", str1, str2);

	return 0;
}
