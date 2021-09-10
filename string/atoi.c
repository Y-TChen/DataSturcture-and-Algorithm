#include<stdio.h>

// '0' => 48
// '9' => 57
int atoi(const char* str){
	int num = 0;
	int flag = 0;
	while(*str){
		if(*str >= '0' && *str <= '9'){ // is number
			flag = 1;
			num = num*10 + (*str-48);	
		}
		else{	// not number
			if(flag == 1){	// end of atoi
				return num;
			}
		}
		str++;
	}

	return num;
}

int main(){
	char str1[] = "12345";
	char str2[] = "12345abc";
	char str3[] = "abc12345def";
	char str4[] = "abc123de45f";
	char str5[] = " There are 7845abcde321 apples!";

	printf("str1: \"%s\", atoi => %d\n", str1, atoi(str1));
	printf("str2: \"%s\", atoi => %d\n", str2, atoi(str2));
	printf("str3: \"%s\", atoi => %d\n", str3, atoi(str3));
	printf("str4: \"%s\", atoi => %d\n", str4, atoi(str4));
	printf("str5: \"%s\", atoi => %d\n", str5, atoi(str5));



	return 0;
}

