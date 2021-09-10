#include<stdio.h>

int strcmp(const char* str1, const char* str2){
	// if str1 == str2 => return 0
	// if str1 < str2 => return -1
	// if str1 > str2 => return 1
	

	while(*str1 == *str2){	// compare until different
		if(*str1 == 0){	// both are null string
			return 0;
		}
		str1++;
		str2++;
	}
	
	int result = 0;
	(*str1 - *str2 > 0) ? (result = 1) : (result = -1);
		
	return result;
	//return (*str1-*str2);
}

int main(){
	char str1[] = "string on", str2[] = "string one";
	printf("str1 = \"%s\"\n",str1);
	printf("str2 = \"%s\"\n",str2);
	printf("strcmp(s1, s2) = %d\n", strcmp(str1, str2));

	return 0;
}
