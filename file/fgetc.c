#include<stdio.h>


int main(){

	FILE *file;
	char c;

	file = fopen("writeFile.txt", "r");
	
	while((c = fgetc(file)) != EOF){
		printf("%c", c);
		
	}

	fclose(file);
	printf("\n");

	return 0;
}
