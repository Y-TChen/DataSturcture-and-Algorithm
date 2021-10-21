#include<stdio.h>

int prefixCheck(char *prefix, char *s){
	int match = 0;
	while(*prefix){
		if(*s++ != *prefix++){	// not match
			return match;
		}
	}
	match = 1;

	return match;
}

int main(){
	char *s = "Prefix matching test!";
	char *prefix = "Prefix";

	printf("string: %s\nprefix: %s\nmatch: %d\n", s, prefix, prefixCheck(prefix, s));

	return 0;
}
