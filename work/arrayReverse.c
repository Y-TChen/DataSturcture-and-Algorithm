#include<stdio.h>

void swap(char *, char *);
void reverse(char *, unsigned int);
void print(char *);


void swap(char *dst, char *src){
	*dst ^= *src;
	*src ^= *dst;
	*dst ^= *src;
}

void reverse(char *s, unsigned int len){
	char *left = s, *right = (s + len-1);
	while(left < right){
		if(*left == *right)
			continue;

		swap(left++, right--);
	}
}

void print(char *s){
	while(*s){
		printf("%c", *s++);
	}
	printf("\n");
}

unsigned int strLen(char *s){
	unsigned int len = 0;
	while(*s++){
		++len;
	}

	return len;
}

int main(){
	char s[50] = "Reverse String";
	print(s);

	reverse(s, strLen(s));
	print(s);

	return 0;
}
