#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int key;
	struct Node *leftChild, *rightChild;
}Node;

Node *createNode(int);
Node *insert(Node *, int);
void treeSort(int *, unsigned int);
void inOrder(Node *, int *, int *);
void printArr(int *, unsigned int);


Node *createNode(int key){
	Node *node = (Node *)malloc(sizeof(Node));
	node->key = key;
	node->leftChild = NULL;
	node->rightChild = NULL;
	
	return node;
}

Node *insert(Node *node, int key){

	if(node == NULL){
		return createNode(key);
	}

	if(key <= node->key){
		node->leftChild = insert(node->leftChild, key);
	}
	else{
		node->rightChild = insert(node->rightChild, key);
	}

	return node;
}

void treeSort(int *arr, unsigned int size){
	Node *root = NULL;
	int index = 0;	// index for array

	for(int i = 0; i < size; i++){
		root = insert(root, arr[i]);
	}

	inOrder(root, arr, &index);
}

void inOrder(Node *node, int *arr, int *index){
	if(node != NULL){
		inOrder(node->leftChild, arr, index);
		arr[(*index)++] = node->key;	// copy tree node into array
		inOrder(node->rightChild, arr, index);
	}
}

void printArr(int *arr, unsigned int size){
	while(size--){
		printf("%d ", *arr++);
	}
	printf("\n");
}
int main(){
	int arr[] = {5,4,3,7,9,1,2,8,6};
	printArr(arr, sizeof(arr)/sizeof(arr[0]));
	treeSort(arr, sizeof(arr)/sizeof(arr[0]));
	printArr(arr, sizeof(arr)/sizeof(arr[0]));
	
	return 0;
}
