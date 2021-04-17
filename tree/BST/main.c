#include<stdlib.h>
#include<stdio.h>
#include "TreeNode.h"
#include "BST.h"


int main(){

	TreeNode* root = NULL;
	InsertBST(&root, 49, "A");
	InsertBST(&root, 9, "B");
	InsertBST(&root, 84, "C");
	InsertBST(&root, 63, "D");
	InsertBST(&root, 95, "E");
	InsertBST(&root, 92, "F");
	InsertBST(&root, 107, "G");
	
	InorderPrint(root);

	deleteBST(&root, 49);	
	InorderPrint(root);
	
	deleteBST(&root, 84);	
	InorderPrint(root);
	
	printf("============== Delete Tree ===============\n");
	deleteTree(root);
	printf("\n");
	return 0;
}
