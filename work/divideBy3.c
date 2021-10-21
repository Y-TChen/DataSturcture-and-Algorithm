#include<stdio.h>

int divideBy3(int n){
	int ans = 0;
	while(n > 0){
		ans += (n & 1);
		printf("%d\n", n);
		n >>= 1;
		ans -= (n & 1);
		printf("%d\n", n);
		n >>= 1;
	}

	return ans;	// ans = 0 => can divide , ans != 0 => can't divide
}

int main(){
	int n = 27;
	printf("%d divide by 3: %d\n", n, divideBy3(n));
	printf("%d divide by 3: %d\n", n+2, divideBy3(n+2));
	printf("%d divide by 3: %d\n", n+3, divideBy3(n+3));
	printf("%d divide by 3: %d\n", n+4, divideBy3(n+4));
	
	return 0;
}
