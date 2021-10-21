#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;


Node* insertNode(Node *root, int data){
	Node *newNode = (Node *)malloc(sizeof(Node)); 	// create new node first
	newNode->data = data;
	newNode->next = NULL;
	
	if(root == NULL)	// if root = NULL => return new node
		return newNode;
	else{
		Node *ptr = root;
		while(ptr->next != NULL){	// find insert position
			ptr = ptr->next;	
		}
		ptr->next = newNode;
		return root;
	}
}

void delete(Node *root){
	Node *ptr, *node = root;
	while(node != NULL){
		ptr = node;
		node = node->next;
		free(ptr);
	}
}

void print(Node *root){
	Node *node = root;
	while(node != NULL){
		printf("%3d", node->data);
		node = node->next;
	}
	printf("\n");
}


Node* inverseLists(Node *root){
	Node *prev = NULL, *now, *next = NULL;
	now = root;
	while(now != NULL){
		next = now->next;	// remember next node first
		now->next = prev;	// reverse List
		prev = now;		// move to next node
		now = next;		// move to next node
	}

	return prev;	// return the new root node
}

int main(){
	int len = 5;
	Node *root = NULL;
	for(int i = 0; i < len; i++){
		root = insertNode(root, i);
	}

	print(root);

	root = inverseLists(root);
	print(root);

	delete(root);

	return 0;
}
