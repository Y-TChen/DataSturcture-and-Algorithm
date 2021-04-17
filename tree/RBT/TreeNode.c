#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "TreeNode.h"

TreeNode* createNode(int KEY, char* Element){
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->parent = NULL;
	node->key = KEY;
	node->color = 0;	// 0:red 1:black	default is red
	
	
	// copy element into data array	
	char* dst = node->data;
	char* src = Element;
	while(*dst++ = *src++);

	return node;
}


void inOrder(TreeNode* current){	// LVR
	if(current == NULL){
		return;
	}

	if(current->leftChild != NULL){	// L
		inOrder(current->leftChild);
	}
	printf("%s(%d)\n", current->data, current->key);	// V
	if(current->rightChild != NULL){	// R
		inOrder(current->rightChild);
	}
}



void InorderPrint(TreeNode* root){	// traversal with successor and leftMost
	TreeNode* current = leftMost(root);
	
	printf("================== In Order Print (with successor) ======================\n");
	while(current){
		printf("%s(%d) ", current->data, current->key);
		current = Successor(current);
	}
	printf("\n\n");
}

TreeNode* leftMost(TreeNode* root){
	TreeNode* current = root;
	
	if(current == NULL){
		return NULL;
	}

	while(current->leftChild != NULL){
		current = current->leftChild;
	}

	return current;
}

TreeNode* rightMost(TreeNode* root){
	TreeNode* current = root;
	while(current->rightChild != NULL){
		current = current->rightChild;
	}
	
	return current;
}

void LeftRotation(TreeNode* current){
	
	if(current == NULL){
		return;
	}

	TreeNode* X = current;
	TreeNode* Y = current->rightChild;
	TreeNode* J = Y->leftChild;
	TreeNode* A = X->parent;

	if(!(J && A)){
		return;
	}
	
	// rotation
	(A->rightChild = X)?(A->rightChild = Y) : (A->leftChild = Y); // whether Y is A's left or rightChild 

	X->rightChild = J;
	X->parent = Y;
	Y->leftChild = X;
	Y->parent = A;

	J->parent = X;
}

void RightRotation(TreeNode* current){
	if(current == neel){
		return;
	}
	
	TreeNode* Y = current;
	TreeNode* X = current->leftChild;
	TreeNode* J = current->leftChild->rightChild;
	TreeNode* A = current->parent;

	// rotation
	(A->rightChild = Y)? (A->rightChild = X) : (A->leftChild = X);
	X->parent = A;
	
	X->rightChild = Y;
	Y->parent = X;

	
	printf("Y %d\n", Y->key);
	printf("X %d\n", X->key);
	printf("A %d\n", A->key);
    
	if(J != neel){	
		J->parent = Y;	// if J is NIL node => parent = NULL
		Y->leftChild = J;
	}
	else{
		printf("J is NIL node\n");
	}
}

TreeNode* Successor(TreeNode* current){	// find next traversal node
	
	if(current == NULL){
		return NULL;
	}

	if(current->rightChild != NULL){	// if right child != NULL => return right subtree's leftMost node
		return leftMost(current->rightChild);
	}
	
	TreeNode* successor = current->parent;
	while((successor != NULL) && (successor->leftChild != current) ){	// return until successor's leftChild = current
		current = successor;
		successor = successor->parent;
	}
	
	return successor;
}

void deleteTree(TreeNode* current){

	if(current == NULL){
		return ;
	}

	if(current->leftChild != NULL){
		deleteTree(current->leftChild);
	}
	if(current->rightChild != NULL){
		deleteTree(current->rightChild);
	}
	printf("=> (%2d) ", current->key);
	free(current);
}

