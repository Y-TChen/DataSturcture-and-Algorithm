#include<stdio.h>

#define isdigit(c) (c >= '0' && c <= '9')

double atof(const char* str){
	double num = 0.0;
	int e = 0;	// exponential part
	while(*str && (!isdigit(*str))){	// skip until find integer part
		str++;
	}
	while(isdigit(*str)){	// integer part
		num = num*10 + (*str - '0');
		str++;
	}
	if(*str == '.'){	// floating part 
		str++;
		if(!isdigit(*str)){	// if not digit => end of atof
			return num;
		}
		while(isdigit(*str)){	// start floating part
			num = num*10 + (*str - '0');
			e--;	// adjust exponential
			str++;
		}
	}
	if(*str == 'e' || *str == 'E'){	// exponential part
		str++;
		int sign = 1; // 1 = positive,-1 = negative
		int e_tmp = 0;	// temp exponential
		if(*str == '+'){
			str++;
		}
		else if(*str == '-'){
			sign = -1;
			str++;
		}
		while(isdigit(*str)){	// calculate exponential value
			e_tmp = e_tmp*10 + (*str - '0');
		       *str++;	
		}
		e += sign*e_tmp;	// total exponential
	}		
	if(e > 0){	// use exponential to calculate final answer
		while(e){
			num *= 10;
			e--;
		}
	}
	else if(e < 0){
		while(e){
			num /= 10;
			e++;
		}
	}

	return num;
}

int main(){
	char str1[] = "1. 2345";
	char str2[] = "12Eab345";
	char str3[] = "Test 123 4ab5";
	char str4[] = "12.34";
	char str5[] = "12.34e5";
	char str6[] = "12.34e-5";

	printf("Before: %s\t After: %f\n", str1, atof(str1));
	printf("Before: %s\t After: %f\n", str2, atof(str2));
	printf("Before: %s\t After: %f\n", str3, atof(str3));
	printf("Before: %s\t After: %f\n", str4, atof(str4));
	printf("Before: %s\t After: %f\n", str5, atof(str5));
	printf("Before: %s\t After: %f\n", str6, atof(str6));

	return 0;
}
