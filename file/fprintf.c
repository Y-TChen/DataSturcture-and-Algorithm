#include<stdio.h>


int main(){
	
	FILE *file;
	char *str = "My name is Marks";
	
	file = fopen("writeFile.txt", "w");

	fprintf(file, "%s", str);
	
	fclose(file);
	
	return 0;
}
