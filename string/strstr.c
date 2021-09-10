#include<stdio.h>

const char* strstr(const char* str, const char* substr){
	const char* s1;
	const char* s2;
	const char* current = str;

	while(*current){
		s1 = current;
		s2 = substr;
		while(*s1++ == *s2++){
			if(*s2== '\0'){
				return current;
			}
		}
		current++;
	}	
	
	return 0;	// no matching result
}

int main(){
	char str1[] = "cdabcdabcdefg", str2[] = "cde";
	printf("str1 = \"%s\"\tstr2 = \"%s\"\n", str1, str2);
	printf("strstr(str1, str2) = \"%s\"\n", strstr(str1, str2));
	return 0;
}
