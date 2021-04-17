#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct node{
	char key[10];	 
	char data[10];	
	struct node* next;
}Node;

void Insert(Node**, char [], char []);	// insert node front of the list


#endif /* _LINKEDLIST_H_ */
