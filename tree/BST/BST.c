#include<stdio.h>
#include<stdlib.h>
#include "TreeNode.h"


TreeNode* SearchBST(TreeNode* root, int KEY){	// key(L) < key(current) < key(R)
	TreeNode* current = root;
	
	while(current != NULL && current->key != KEY){
		if(current->key > KEY){	// search left subtree
			current = current->leftChild;
		}
		else{
			current = current->rightChild;
		}
	}

	return current;
}

void InsertBST(TreeNode** root, int KEY, char* Element){	// key and element
	TreeNode* insertNode = createNode(KEY, Element);	// create node
	TreeNode* current = *root;	// find insert position
	TreeNode* prvNode = NULL;	// find insertNode's parent position
	
	while(current != NULL){		// find where to insert node => prvNode's child
		
		prvNode = current;
		
		if(KEY > current->key){  //	search right subtree
			current = current->rightChild;
		}
		else{	//	search left subtree
			current = current->leftChild;	
		}
	}

	insertNode->parent = prvNode;	// start insert node
	if(prvNode == NULL){	// insert root node
		*root = insertNode;
	}
	else if(KEY > prvNode->key){
		prvNode->rightChild = insertNode;	
	}
	else{	
		prvNode->leftChild = insertNode;	
	}
}

void deleteBST(TreeNode** root, int KEY){
	TreeNode* current = SearchBST(*root, KEY);	// find node position
	TreeNode* child;	// current's child
	if(current == NULL){
		printf("Error! No result\n");
		return;
	}
	
	printf("delete %s(%d)\n", current->data, current->key);

	// case 1: no child
	if((current->leftChild == NULL) && (current->rightChild == NULL)){	// only need to delete this node
		if(current->parent == NULL){
			*root = NULL;
		}
		else{
			(current->parent->leftChild == current)?(current->parent->leftChild = NULL):(current->parent->rightChild = NULL); 
		}
		free(current);
	}
	// case 2: have only one child
	else if((current->leftChild != NULL) ^ (current->rightChild != NULL)){
		child = (current->leftChild != NULL) ? (current->leftChild) : (current->rightChild);	// find child
		if(current->parent == NULL){
			*root = child;	
		}
		else{
			(current->parent->leftChild == current)?(current->parent->leftChild = child):(current->parent->rightChild = child); 
		}
		child->parent = current->parent;
		free(current);
	}
	// case 3: have two childs => successor of current inherit
	else{
		TreeNode* inherit = Successor(current);	// inherit key and data
		char* p = current->data;
		char* q = inherit->data;
		while((*p++) = (*q++));	//	data copy
		
		int inheritKey = inherit->key;	// remember key

		if(current->rightChild == inherit){
			current->rightChild = NULL;
		}
		deleteBST(root, inherit->key);	// delete successor after inherit	
		current->key = inheritKey;
	}
}

void Levelorder(TreeNode*);


