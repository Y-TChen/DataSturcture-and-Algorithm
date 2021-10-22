#include<stdio.h>
#include<stdlib.h>

typedef struct Node{		// data structure for tree
	int data;
	struct Node *lNode;
	struct Node *rNode;
}Node;

typedef struct qNode{		// data structure for queue
	Node *node;	// enqueue and dequeue node
	struct qNode *next;
}qNode;

void enQueue(qNode **front, qNode **back, Node *node){
	if(node == NULL)	// enQueue empty data => return
		return;

	qNode *qnode = (qNode *)malloc(sizeof(qNode));
	qnode->node = node;
	qnode->next = NULL;

	if(*front == NULL){	// empty queue
		*front = qnode;
		*back = qnode;
		return;
	}
	
	(*back)->next = qnode;	// enqueue
	*back = qnode;
}

Node* deQueue(qNode **front){	// dequeue and return front node
	if(*front == NULL){	//empty queue
		return NULL;
	}
	Node* node = (*front)->node;	// node wants return
	*front = (*front)->next;
	
	return node;
}

void deleteQueue(qNode **front){
	qNode *ptr;
	while(*front != NULL){
		ptr = *front;
		*front = (*front)->next;
		free(ptr);
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

void bfs(qNode **front, qNode **back, Node *root){	// breadth first search alg
	
	Node *current = NULL;
	enQueue(front, back, root);	// enqueue root node first
	
	while(current = deQueue(front)){	// if queue isn't empty => dequeue
		printf("dequeue(%d)\n", current->data);
		enQueue(front, back, current->lNode);		// enqueue left and right child
		enQueue(front, back, current->rNode);
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
	qNode *front = NULL;	//queue head	for dfs Alg
	qNode *back = NULL;	//queue tail
	int arr[] = {7,3,10,2,5,9,12,1,4,6};
	
	for(int i = 0; i < 10; i++){
		insertNode(&root, arr[i]);
	}

	printNode(root);
	printf("\n========= Breadth First Search ========\n");
	
	bfs(&front, &back, root);	

	deleteNode(root);
	deleteQueue(&front);
	return 0;
}
