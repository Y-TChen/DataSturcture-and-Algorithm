#include<stdio.h>

void deleteWord(char *s, char w, unsigned int len){
	int i;
	for(i = 0; i < len; i++){
		if(s[i] == w){	//delete word and shift rest word in array
			for(int j = i; j < len-1; j++){
				s[j] = s[j+1];	// left shift remain word
			}	
		}
	}
}

void print(char *s){
	while(*s){
		printf("%c", *s++);
	}
	printf("\n");
}

int main(){
	char s[] = "Delete word in string";
	print(s);

	deleteWord(s, 'e', sizeof(s)/sizeof(s[0]));
	print(s);
	return 0;
}
