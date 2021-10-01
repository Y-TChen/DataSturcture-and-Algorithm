#include<stdio.h>

unsigned int same(const unsigned short S){
	unsigned char c;
	unsigned short s = S;

	c = (s & 0xff) ^ ((s >> 8) & 0xff);
	if(c)
		return 0;
	c = (s & 0xf0f) ^ ((s & 0xf0f0) >> 4);
	
	return (c == 0)? 1 : 0;
}

int main(){
	unsigned short s[] = {0xffff, 0xaabb, 0xabcd, 0xc00c, 0x3333};
	for(int i = 0; i < 5; i++){
		printf("0x%x same ? %d\n", s[i], same(s[i]));
	}

	return 0;
}
