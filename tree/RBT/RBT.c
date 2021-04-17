#include<stdio.h>
#include<stdlib.h>
#include "TreeNode.h"
#include "RBT.h"

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

void InsertRBT(TreeNode** root, int KEY, char* Element){	// key and element
	TreeNode* insertNode = createNode(KEY, Element);	// create node
	insertNode->leftChild = neel;	// leftChild and rightChild point to neel
	insertNode->rightChild = neel;

	TreeNode* current = *root;	// find insert position
	TreeNode* prvNode = neel;	// find insertNode's parent position
	
	while(current != neel){		// find where to insert node => prvNode's child
		
		prvNode = current;
		
		if(KEY > current->key){  //	search right subtree
			current = current->rightChild;
		}
		else{	//	search left subtree
			current = current->leftChild;	
		}
	}

	insertNode->parent = prvNode;	// start insert node
	if(prvNode == neel){	// insert root node
		insertNode->color = 1;	// root node is always black
		*root = insertNode;
	}
	else if(KEY > prvNode->key){
		prvNode->rightChild = insertNode;	
	}
	else{	
		prvNode->leftChild = insertNode;	
	}

	insertFix(insertNode);	// fix insert node's color
}

void insertFix(TreeNode* current){	// fix insert node's color
	if(current->parent->color){	// parent is neel or black node=> return
		return;
	}

	TreeNode* father = current->parent;
	TreeNode* grandpa = father->parent;
	TreeNode* uncle;
	uncle = (father = grandpa->leftChild)?(grandpa->rightChild):(grandpa->leftChild);
	if(!uncle){
		printf("uncle NULL\n");
		return;
	}

	// case 1: uncle is red	
	//		   => let father and uncle become black
	if(!(father->color) && !(uncle->color)){
		printf("case 1\n");
		father->color = 1;
		uncle->color = 1;
		if(grandpa->parent == neel){	// if grandpa is root => still black
			return;
		}
		grandpa->color = 1;	// grandpa become red
		if(!grandpa->parent){	// if grandpa and his father are both red => fix again
			insertFix(grandpa);
		}	
	}
	// case 3: uncle is black and insert node is father's leftChild 
	//		   => switch grandpa and father's color , then rightRotation
	else if(uncle->color && (father->leftChild == current)){
		printf("case 3\n");
		grandpa->color = 0;
		father->color = 1;

		RightRotation(grandpa);	// right rotation
		
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

void deleteRBT(TreeNode* current){

	if(current == neel){
		return;
	}

	if(current->leftChild != neel){
		deleteRBT(current->leftChild);
	}
	if(current->rightChild != neel){
		deleteRBT(current->rightChild);
	}
	printf("=> (%2d) ", current->key);
	free(current);
}

void inOrderRBT(TreeNode* current){	// LVR
	if(current == neel){
		return;
	}

	if(current->leftChild != neel){	// L
		inOrderRBT(current->leftChild);
	}

	printf("%s(%d)", current->data, current->key);	
	(current->color) ? printf(" black\n") : printf(" red\n");

	if(current->rightChild != neel){	// R
		inOrderRBT(current->rightChild);
	}
}

void preOrderRBT(TreeNode* current){	// VLR
	if(current == neel){
		return;
	}

	printf("%s(%d)", current->data, current->key);	// V
	(current->color) ? printf(" black\n") : printf(" red\n");

	if(current->leftChild != neel){	// L
		preOrderRBT(current->leftChild);
	}
	if(current->rightChild != neel){	// R
		preOrderRBT(current->rightChild);
	}
}
