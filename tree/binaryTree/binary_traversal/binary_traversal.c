#include<stdio.h>
#include<stdlib.h>


typedef struct treeNode{
	int data;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
	struct treeNode* parent;
}TreeNode;

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


	printf("============ PreOrder Traversal (VLR) =============\n");
	preOrder(root);
	printf("\n============ InOrder Traversal (LVR) =============\n");
	inOrder(root);
	printf("\n============ PostOrder Traversal (LRV) =============\n");
	postOrder(root);
		

	printf("\n============ Delete Tree =============\n");
	deleteTree(root);
	printf("\n");
	return 0;
}
