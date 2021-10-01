#include<stdio.h>

#define COMMAND_A 1
#define COMMAND_B 2

int demo_funcA(int a, int b){printf("Function A: %d %d\n", a, b);}
int demo_funcB(int a, int b){printf("Function B: %d %d\n", a, b);}

typedef int (*command_handler)(int, int); // function pointer

typedef struct cmd_handler_entry{
	int command;
	command_handler handler;
}cmd_handler_entry;

static cmd_handler_entry cmd_handler_entrys[] = {
	{COMMAND_A, demo_funcA},
	{COMMAND_B, demo_funcB},
	{NULL, NULL}
};


int main(){
	cmd_handler_entry *msg_handler;
	msg_handler = cmd_handler_entrys;

	while(msg_handler->handler != NULL){
		msg_handler->handler(5, 7);	
		msg_handler++;
	}

	return 0;
}
