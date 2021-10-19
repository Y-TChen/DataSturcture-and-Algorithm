#include<stdio.h>

void function(const int *a, unsigned int size, unsigned char b){
	printf("Range: %d ~ %d\n", 10*b, 10*b+9);
	while(size && *a < 10*b){
		size--;
		if(size)
			a++;
	}
	printf("%d\n", *a);
	for(unsigned int i = 10*b; i < 10*b + 10; i++){
		if(*a != i)
			printf("%d ", i);
		else{
			size--;
			if(size > 0)
				a++;
		}
	}
	printf("\n");
}

int main(){
	int a[5] = {1, 3, 7, 16, 22};
	printf("array[] =");
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
		printf(" %d", a[i]);
	}
	printf("\n");

	function(a, 5, 1);

	return 0;
}
