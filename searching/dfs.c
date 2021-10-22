#include<stdio.h>
#include<stdlib.h>

typedef struct Node{		// data structure for tree
	int data;
	struct Node *lNode;
	struct Node *rNode;
}Node;

typedef struct sNode{		// data structure for stack
	Node *node;	// push and pop node
	struct sNode *next;
}sNode;

void push(sNode **top, Node *node){	// pusj new node in stack
	if(node == NULL)
		return;

	sNode *snode = (sNode *)malloc(sizeof(sNode));
	snode->node = node;
	snode->next = NULL;

	if(*top == NULL){	// empty stack
		*top = snode;
		return;
	}

	snode->next = *top;	// point to old top node
	*top = snode;		// top point to new node
}

Node* pop(sNode **top){
	if(*top == NULL)	// empty stack
		return NULL;
	Node *ptr = (*top)->node;	// node to return
	*top = (*top)->next;		// pop out top node
	
	return ptr;
}

void deleteStack(sNode *top){
	sNode *ptr;
	while(top != NULL){
		ptr = top;
		top = top->next;
		free(ptr);
	}
}

void dfs(sNode **top, Node *root){		// depth first search alg
	Node *current;

	push(top, root);
	while(current = pop(top)){	// if stack isn't empty => pop and push
		printf("pop(%d)\n", current->data);
		push(top, current->lNode);
		push(top, current->rNode);
	}
}

void insertNode(Node **root, int data){
	Node *prev, *node, *newNode;
	int left;

	newNode = (Node *)malloc(sizeof(Node)); 
	newNode->data = data;
	newNode->lNode = NULL;
	newNode->rNode = NULL;

	if(*root == NULL){
		*root = newNode;
		return;
	}
	node = *root;
	while(node != NULL){
		prev = node;
		left = 0;	// newNode = prev->leftNode => left = 1, else = 0

		if(data < node->data){
			node = node->lNode;
			left = 1;
		}
		else{
			node = node->rNode;
		}
	}
	if(left == 1) 
		prev->lNode = newNode; 
	else
		prev->rNode = newNode;

}


void printNode(Node *node){		// inOrder traversal
	if(node != NULL){
		printNode(node->lNode);
		printf("%3d", node->data);
		printNode(node->rNode);	
	}
}


void deleteNode(Node *node){
	if(node != NULL){
		deleteNode(node->lNode);
		deleteNode(node->rNode);
		free(node);	
	}
}



int main(){
	Node *root = NULL;	// root node of tree
	sNode *top = NULL;	// top node for stack
	int arr[] = {7,3,10,2,5,9,12,1,4,6};
	
	for(int i = 0; i < 10; i++){
		insertNode(&root, arr[i]);
	}

	printNode(root);
	printf("\n========= Depth First Search ========\n");
	dfs(&top, root);

	deleteStack(top);
	deleteNode(root);
	return 0;
}
