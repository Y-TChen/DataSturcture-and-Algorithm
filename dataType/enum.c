#include<stdio.h>

enum week{Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

int main(){
	enum week w = Wednesday;
	
	printf("%d = Wednesday\n", w);

	return 0;
}
