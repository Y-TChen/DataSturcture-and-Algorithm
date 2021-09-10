#include<stdio.h>

void Strcat(char* str1, char* str2){
	// find str1's end ('\0')
	while(*str1){
		str1++;
	}
	while(*str1++ = *str2++);

}


int main(){
	char str1[20] = "First", str2[20] = "Second";
	
	printf("Before:\n str1 = \"%s\"\tstr2 = \"%s\"\n", str1, str2);
	Strcat(str1, str2);
	printf("\nAfter:\n str1 = \"%s\"\tstr2 = \"%s\"\n", str1, str2);

	return 0;
}
