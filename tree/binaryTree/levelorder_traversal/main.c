#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "levelOrder_traversal.h"

// from top to down, from left to right
// if current node != NULL => push into queue
// if leftChild or rithtChild != NULL => push into queue

int main(){
	// create queue
	Node* front = NULL;
	Node* back = NULL;
	
	//	create tree nodes
	TreeNode* node1 = createNode(1);	
	TreeNode* node2 = createNode(2);
	TreeNode* node3 = createNode(3);	
	TreeNode* node4 = createNode(4);	
	TreeNode* node5 = createNode(5);	
	TreeNode* node6 = createNode(6);	
	TreeNode* node7 = createNode(7);	
	TreeNode* node8 = createNode(8);	
	TreeNode* node9 = createNode(9);	

	// level 1
	node1->leftChild = node2;
	node1->rightChild = node3;
	// level 2
	node2->leftChild = node4;
	node2->rightChild = node5;
	node3->leftChild = node6;
	// level 3
	node5->leftChild = node7;
	node5->rightChild = node8;
	node6->rightChild = node9;

	printf("============== Level Order Traversal\n");
	levelOrder(front, back, node1);
	printf("============== Pre Order Traversal\n");
	preOrder(node1);
	printf("\n============== In Order Traversal\n");
	inOrder(node1);
	printf("\n============== Post Order Traversal\n");
	postOrder(node1);

	printf("\ndelete tree:\n");
	deleteTree(node1);
	printf("\n");
	return 0;
}











