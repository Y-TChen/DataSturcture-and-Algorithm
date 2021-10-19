#include<stdio.h>

#if !defined(DEBUG)
	#warning "DEBUG isn't defined"
#endif
int main(){

#ifdef DEBUG 
	printf("Debug now...\n");
	#if (DEBUG == 10)
		printf("DEBUG = %d\n", DEBUG);
	#else
		printf("DEBUG = 100");
	#endif
#else
	#error "There isn't any debug macro!"
#endif


	printf("%s\n", __FILE__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	printf("%d\n", __LINE__);

	return 0;
}

