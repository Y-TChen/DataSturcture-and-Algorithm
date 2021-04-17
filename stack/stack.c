#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node *next;
}Node;

Node* Push(Node*, int);
Node* Pop(Node*);
int IsEmpty(Node*);
void Top(Node*);
void getSize(Node*);
void List(Node*);
void deleteStack(Node*); 

int main(){
	Node *top = NULL;
	int data, select, exit=1;

	while(exit){
		printf("=========== stack ==========\n");

		List(top);

		printf("(1) Push data\n");
		printf("(2) Pop data\n");
		printf("(3) Print top data\n");
		printf("(4) get stack size\n");
		printf("(5) delete stack\n");
		printf("(6) exit\n");
		printf("Enter selection:");
		scanf("%d", &select);	
		
		switch(select){
			case 1:
				printf("Enter data:");
				scanf("%d", &data);
				top = Push(top, data);
				break;
			case 2:
				top = Pop(top);
				break;
			case 3:
				Top(top);
				break;
			case 4:
				getSize(top);
				break;
			case 5:
				deleteStack(top);
				top = NULL;
				break;
			case 6:
				if(top == NULL){
					exit = 0;
				}
				else{
					deleteStack(top);
					top = NULL;
				}
				break;
		}
		getchar();
		system("clear");
	
	}

	return 0;
}

Node* Push(Node *top, int data){
	Node *node = (Node *)malloc(sizeof(Node));
	
	if(node == NULL){
		printf("Out of memory!!\n");
		getchar();
		return NULL;
	}

	node->data = data;	
	node->next = top;
	top = node;

	return top;
}

Node* Pop(Node *top){
	Node *node = top;
	if(node == NULL){
		printf("Empty stack!!\n");
		getchar();
		return NULL;
	}
	top = top->next;
	free(node);

	return top;
}

int IsEmpty(Node *top){
	return (top == NULL);
}

void Top(Node *top){
	if(top == NULL){
		printf("No data!\n");
	}
	else{
		printf("top data: %d\n", top->data);
	}
	getchar();
}

void getSize(Node *top){
	int size = 0;
	Node* node = top;
	while(node != NULL){
		size ++;
		node = node->next;
	}

	printf("size of stack: %d\n", size);
	getchar();
}

void List(Node* top){
	Node* node = top;
	if(node == NULL){
		printf("Empty stack !!\n");
		return;
	}
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");

}

void deleteStack(Node* top){
	Node* node;
	int num = 0;
	while(top != NULL){
		node = top;
		top = top->next;
		free(node);
		num++;
	}
	printf("free %d nodes\n", num);
	getchar();
}

