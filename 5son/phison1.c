#include<stdio.h>


void function(const int *a, unsigned int size){
	for(unsigned int i = 0; i < 21; i++){
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
	int a[5] = {1, 3, 8, 12, 19};

	function(a, sizeof(a)/sizeof(a[0]));

	return 0;
}
