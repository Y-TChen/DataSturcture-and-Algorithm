// minStack can get the min data of the stack in O(1) time complexity
// use two stack: datastack => store data , minstack => store minimum data

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node* next;
}Node;

void Push(int);
void Pop(void);
void List(void);
void deleteStack(void);
void printMin(void);

Node* dataStack = NULL;
Node* minStack = NULL;

int main(){
	int data, select, exit = 1;

	while(exit){
		printf("============ minStack =============\n");
		List();
		
		printf("(1) Push data\n");
		printf("(2) Pop data\n");
		printf("(3) delete stack\n");
		printf("(4) print minimum data\n");
		printf("(5) exit\n");
		printf("Enter selection: ");
		scanf("%d", &select);

		switch(select){
			case 1:
				printf("Enter data:");
				scanf("%d", &data);
			    Push(data);
				break;
			case 2:
				Pop();
				break;
			case 3:
				deleteStack();
				break;
			case 4:
				printMin();
				break;
			case 5:
				if(dataStack != NULL){
					deleteStack();
				}
				exit = 0;
				break;
		}
		getchar();
		system("clear");
	}

	return 0;
}

void Push(int data){
	// dataStack
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = dataStack;
	dataStack = node;
	// minStack
	Node* minNode = (Node*)malloc(sizeof(Node));
	if(minStack == NULL || data < minStack->data){ // while data < minStack->data => push data
		minNode->data = data;
	}
	else{	// if data > minStack->data => push minStack's top
		minNode->data = minStack->data;
	}
	minNode->next = minStack;
	minStack = minNode;
}

void Pop(){
	if(dataStack == NULL){
		printf("Empty stack !!\n");
		return;
	}
	// pop dataStack
	Node* node = dataStack;
	dataStack = dataStack->next;
	free(node);

	// pop minStack
	Node* minNode = minStack;
	minStack = minStack->next;
	free(minNode);
}

void List(){
	if(dataStack == NULL){
		printf("Empty List!\n");
		return;
	}
	Node* node = dataStack;
	printf("Data stack: ");
	while(node != NULL){
		printf(" %d", node->data);
		node = node->next;
	}
	printf("\n");
	
	Node* minNode = minStack;
	printf("Minimum Stack: ");
	while(minNode != NULL){
		printf(" %d", minNode->data);
		minNode = minNode->next;
	}
	printf("\n");
}

void deleteStack(){
	if(dataStack == NULL){
		printf("Empty stack !\n");
	}
	else{
		Node* node;
		int num = 0;
		while(dataStack != NULL){
			node = dataStack;
			dataStack = dataStack->next;
			free(node);
			num ++;
		}
		printf("free %d nodes\n", num);
	
		Node* minNode;
		num = 0;
		while(minStack != NULL){
			minNode = minStack;
			minStack = minStack->next;
			free(minNode);
			num ++;
		}
		printf("free %d nodes\n", num);
	}
	getchar();
}

void printMin(){
	if(minStack != NULL){
		printf("Minimun data in the stack: %d\n", minStack->data);
		getchar();
	}
}

