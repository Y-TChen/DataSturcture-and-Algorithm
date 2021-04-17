#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "levelOrder_traversal.h"


void preOrder(TreeNode* current){	// VLR => visiting, left, right
	printf("-> (%d) ", current->data);	// V
	if(current->leftChild != NULL)	// L
		preOrder(current->leftChild);
	if(current->rightChild != NULL)	// R
		preOrder(current->rightChild);
}

void inOrder(TreeNode* current){	// LVR
	if(current->leftChild != NULL)	// L
		inOrder(current->leftChild);
	printf("-> (%d) ", current->data);	// V
	if(current->rightChild != NULL)	// R
		inOrder(current->rightChild);
}

void postOrder(TreeNode* current){	// LRV
	if(current->leftChild != NULL)	// L
		postOrder(current->leftChild);
	if(current->rightChild != NULL)	// R
		postOrder(current->rightChild);
	printf("-> (%d) ", current->data);	// V
}

void levelOrder(Node* front, Node* back, TreeNode* root){
	if(root != NULL){
		Push(&front, &back, root);
	}
	// while queue is not empty => pop data
	while(!empty(front)){
		TreeNode* current = getFront(front);	// get first queue data
		printf("-> (%d) ", current->data);
		Pop(&front, &back);	// pop first data
		// push leftChild and rightChild into queue
		if(current->leftChild != NULL)	
			Push(&front, &back, current->leftChild);
		if(current->rightChild != NULL)
			Push(&front, &back, current->rightChild);
	}
	printf("\n");
}

TreeNode* createNode(int data){
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->parent = NULL;
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->data = data;

	return node; 
}

void deleteTree(TreeNode* current){
	TreeNode* node = current;
	if(node->leftChild != NULL)
		deleteTree(node->leftChild);
	if(node->rightChild != NULL)
		deleteTree(node->rightChild);
	printf("\n");	
	printf("->free(%d) ",node->data);
	free(node);
}

