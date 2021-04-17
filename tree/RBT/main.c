#include<stdlib.h>
#include<stdio.h>
#include "TreeNode.h"
#include "RBT.h"


int main(){
	neel = createNode(0, "NIL");	// create NIL node
	neel->color = 1;	// NIL node is always black
	TreeNode* root = neel;
	
	InsertRBT(&root, 9, "A");
	InsertRBT(&root, 8, "B");
	printf("\n============== In-Order Traversal ===============\n");
	inOrderRBT(root);
	InsertRBT(&root, 10, "D");
	printf("\n============== In-Order Traversal ===============\n");
	inOrderRBT(root);
	InsertRBT(&root, 6, "E");

	printf("\n============== In-Order Traversal ===============\n");
	inOrderRBT(root);

	printf("============== Delete Tree (Post Order) ===============\n");
	//preOrderRBT(root);
	deleteRBT(root);
	printf("\n");

	free(neel);
	return 0;
}
