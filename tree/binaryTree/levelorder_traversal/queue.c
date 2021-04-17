#include<stdio.h>
#include<stdlib.h>
#include "levelOrder_traversal.h"


void Push(Node** front, Node** back, TreeNode* treenode){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = treenode;
	node->next = NULL;

	if(*front == NULL){	
		*front = node;
		*back = node;
	}
	else{
		Node* temp = *back;
		temp->next = node;
		*back = node;
	}
}

void Pop(Node** front, Node** back){
	if(*front == NULL){
		printf("Empty queue!\n");
		getchar();
		return;
	}
	if(*front == *back){	// if pop last data => *front and *back = NULL
		*back = NULL;
	}
	Node* node = *front;
	*front = node->next;	// pop front data

	free(node);
}

TreeNode* getFront(Node* front){
	if(front == NULL){
		printf("Empty queue!\n");
		getchar();
		return NULL;
	}
	
	return front->data;
}

TreeNode* getBack(Node* back){
	if(back == NULL){
		printf("Empty queue!\n");
		getchar();
		return NULL;
	}

	return back->data;
}


void getSize(Node* front){
	Node* node = front;
	int size = 0;
	while(node != NULL){
		size++;
		node = node->next;
	}
	printf("size of queue: %d\n", size);
	getchar();
}
int empty(Node* front){
	return (front == NULL)?1:0;
}

void deleteQueue(Node* front){
	Node* node;
	int sum = 0;
	while(front != NULL){
		node = front;
		front = front->next;
		free(node);
		sum++;
	}
	printf("free %d nodes\n", sum);
	getchar();
} 

