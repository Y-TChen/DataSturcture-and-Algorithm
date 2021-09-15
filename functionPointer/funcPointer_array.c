#include<stdio.h>

void run() {printf("Run\n");}
void stop() {printf("Stop\n");}
void Exit() {printf("Exit\n");}

void (*command[])(void) = {run, stop, Exit};

int main(){
	for(int i = 0; i < 3; i++){
		command[i]();
	}

	return 0;
}
