#include<stdio.h>
#include<stdlib.h>
#include "InOrder_byParent.h"

void inOrder(TreeNode* current){	// LVR
	if(current->leftChild != NULL)	// L
		inOrder(current->leftChild);
	printf("-> (%d) ", current->data);	// V
	if(current->rightChild != NULL)	// R
		inOrder(current->rightChild);
}

TreeNode* leftMost(TreeNode* current){
	
	while(current->leftChild != NULL){
		current = current->leftChild;
	}

	return current;
}

TreeNode* rightMost(TreeNode* current){
	
	while(current->rightChild != NULL)
		current = current->rightChild;

	return current;
}

TreeNode* InOrderSuccessor(TreeNode* current){
	//	if current node have rightChild => successor = right's leftMost node
	//	if current node doesn't have rightChild => find ancestor of the node which is leftChild
	//	special case: if current node is root and doesn't have rightChild => return NULL

	if(current->rightChild != NULL){
		return leftMost(current->rightChild);
	}

	
	TreeNode* successor = current->parent;	//	find ancestor
	while(successor != NULL && successor->leftChild != current){	//	ancestor = NULL => root node
		current = successor;
		successor = successor->parent;
	}
	return successor;
}

void InOrder_byParent(TreeNode* root){	//	traversal by while loop not recursion!
	TreeNode* current = leftMost(root);
		
	while(current){
		printf("-> (%d) ", current->data);
		current = InOrderSuccessor(current);	
	}
}

TreeNode* InOrderPredecessor(TreeNode* current){
	//	if current node have rightChild => successor = right's leftMost node
	//	if current node doesn't have rightChild => find ancestor of the node which is leftChild
	//	special case: if current node is root and doesn't have rightChild => return NULL

	if(current->leftChild != NULL){
		return rightMost(current->leftChild);
	}

	
	TreeNode* predecessor = current->parent;	//	find ancestor
	while(predecessor != NULL && predecessor->rightChild != current){	//	ancestor = NULL => root node
		current = predecessor;
		predecessor = predecessor->parent;
	}
	return predecessor;
}

void InOrder_Reverse(TreeNode* root){	// use predecessor traversal tree
	TreeNode* current = rightMost(root);

	while(current){
		printf("-> (%d) ", current->data);
		current = InOrderPredecessor(current);
	}
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
	
	printf(" -> free(%d)",node->data);
	free(node);
}
