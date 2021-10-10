#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

Node *createList(int len){
	Node *root = NULL;
	if(len == 0){
		return root;
	}
	
	root = malloc(sizeof(Node));
	root->data = len;
	root->next = NULL;

	Node *prv = root;

	while(--len){
		Node *node = malloc(sizeof(Node));
		node->data = len;
		node->next = NULL;

		prv->next = node;
		prv = node;
	}

	return root;
}

void printList(Node *root){
	Node *node = root;

	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}
void freeList(Node *root){
	Node *node = root;
	Node *prv;

	while(node != NULL){
		prv = node;
		node = node->next;
		printf("free(%d)\n", prv->data);
		free(prv);
	}
}

Node *findMidNode(Node *node){
	Node *ptr1 = node, *ptr2 = node;	//ptr1 slow (step = 1)
	int count = 0;		//ptr2 fast (step = 2)
				// count = len of linkedList
	if(node == NULL){
		return node;
	}
	
	do{
		if(count & 1){	// slow
			ptr1 = ptr1->next;
		}

		ptr2 = ptr2->next;	// fast
		
		++count;
		
	}while(ptr2 != NULL);

	printf("Middle of linkedList is (%d)\n", (count+1)/2);

	return ptr1;
}

int main(){
	Node *root = NULL;
	root = createList(11);
	printList(root);
	Node *middle = findMidNode(root);
	printf("Mid Node (%d)\n", middle->data);	
	freeList(root);

	return 0;
}
