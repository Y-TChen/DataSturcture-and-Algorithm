#include<stdio.h>
#include<stdlib.h>

typedef struct s{
	char c1; // 1
	int i1;	// 4
	char c2;  //1
	char c3;  //1
	int i2;	// 4
}s; 

int main(){
	s *ms = malloc(sizeof(s));
	ms->c1 = 0x11;
	ms->i1 = 0x2345;
	ms->c2 = 0x22;
	ms->c3 = 0x33;
	ms->i2 = 0x4567;
	
	printf("%ld\n", sizeof(s));
	printf("0x%x\n", ms->c1);
	printf("0x%x\n", ms->i1);
	printf("0x%x\n", ms->c2);
	printf("0x%x\n", ms->c3);
	printf("0x%x\n", ms->i2);
	
	void *ptr = ms;
	for(int i =0; i< 16; i++ ){
		printf("%p ---- %x\n", ptr, *(char *)ptr); 
		ptr++;
	}

	return 0;
}
