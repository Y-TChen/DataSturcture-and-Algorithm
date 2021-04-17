#include<stdio.h>
#include<stdlib.h>
#include "InOrder_byParent.h"

int main(){
	TreeNode* root;
	TreeNode* nodeA = createNode(0);
	TreeNode* nodeB = createNode(1);
	TreeNode* nodeC = createNode(2);
	TreeNode* nodeD = createNode(3);
	TreeNode* nodeE = createNode(4);
	TreeNode* nodeF = createNode(5);
	TreeNode* nodeG = createNode(6);
	TreeNode* nodeH = createNode(7);
	TreeNode* nodeI = createNode(8);
	TreeNode* nodeJ = createNode(9);

	// Level 1
	root = nodeA;
	nodeA->leftChild = nodeB;
	nodeA->rightChild = nodeC;

	// Level 2
	nodeB->leftChild = nodeD;
	nodeB->rightChild = nodeE;
	nodeC->leftChild = nodeF;
	nodeC->rightChild = nodeG;

	// Level 3
	nodeD->leftChild = nodeH;
	nodeD->rightChild = nodeI;

	// parents	
	nodeB->parent = nodeA;
	nodeC->parent = nodeA;
	nodeD->parent = nodeB;
	nodeE->parent = nodeB;
	nodeF->parent = nodeC;
	nodeG->parent = nodeC;
	nodeH->parent = nodeD;
	nodeI->parent = nodeD;


	printf("\n============ InOrder Traversal (by Recursion) =============\n");
	inOrder(root);
	printf("\n============ Left Most =============\n");
	printf("Left Most of nodeA : %d\nLeft Most of nodeC : %d\n"	,leftMost(root)->data, leftMost(nodeC)->data);	
	printf("\n================ InOrder Traversal by Successor (while Loop) =================\n");
	InOrder_byParent(root);
	printf("\n================ InOrder Traversal by Predecessor (while Loop, reverse) =================\n");
	InOrder_Reverse(root);
	printf("\n============ Delete Tree =============\n");
	deleteTree(root);
	printf("\n");
	return 0;
}

