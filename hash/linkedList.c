#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"

void Insert(Node** front, char key[], char data[]){	// insert node front of the list
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;

	char* d = node->data;
	char* s = data;
	while(*d++ = *s++);	//	copy data

	d = node->key;
	s = key;
	while(*d++ = *s++);	// copy key


	if(*front == NULL){	// if list is empty => front = node
		*front = node;
	}
	else{	// insert front
		node->next = *front;	
		*front = node;
	}
}



