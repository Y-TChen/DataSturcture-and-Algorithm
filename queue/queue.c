#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next; 
};

typedef struct node Node;

void Push(Node**, Node**, int);
void Pop(Node**, Node**);
void getFront(Node*);
void getBack(Node*);
void printQueue(Node*);
void getSize(Node*);
void delete(Node*);

int main(){
	Node* front = NULL;
	Node* back = NULL;
	int data, select, exit = 1;

	while(exit){
		printf("============== queue ================\n");
		printQueue(front);
		printf("(1) Push data\n");
		printf("(2) Pop data\n");
		printf("(3) get front data\n");
		printf("(4) get back data\n");
		printf("(5) get queue size\n");
		printf("(6) exit\n");
		printf("Enter selection: ");
		scanf("%d", &select);
		
		switch(select){
			case 1:
				printf("Enter data:");
				scanf("%d", &data);
				Push(&front, &back, data);	
				break;
			case 2:
				Pop(&front, &back);
				break;
			case 3:
				getFront(front);
				break;
			case 4:
				getBack(back);
				break;
			case 5:
				getSize(front);
				break;
			case 6:
				delete(front);
				exit = 0;
				break;
		}
		getchar();
		system("clear");
	
	}
}

void Push(Node** front, Node** back, int data){
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->next = NULL;

	if(*front == NULL){	
		*front = node;
		*back = node;
	}
	else{
		Node* temp = *back;
		temp->next = node;
		*back = node;
	}
}

void Pop(Node** front, Node** back){
	if(*front == NULL){
		printf("Empty queue!\n");
		getchar();
		return;
	}
	if(*front == *back){	// if pop last data => *front and *back = NULL
		*back = NULL;
	}
	Node* node = *front;

	*front = node->next;	// pop front data
	printf("Pop data: %d\n", node->data);
	getchar();

	free(node);
}

void getFront(Node* front){
	if(front == NULL){
		printf("Empty queue!\n");
		getchar();
		return;
	}
	printf("Front data: %d\n", front->data);
	getchar();
	
}

void getBack(Node* back){
	if(back == NULL){
		printf("Empty queue!\n");
		getchar();
		return;
	}
	printf("Back data: %d\n", back->data);
	getchar();
}

void printQueue(Node* front){
	if(front == NULL){
		printf("Empty queue!\n");
		return;
	}
	Node* node = front;
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void getSize(Node* front){
	Node* node = front;
	int size = 0;
	while(node != NULL){
		size++;
		node = node->next;
	}
	printf("size of queue: %d\n", size);
	getchar();
}

void delete(Node* front){
	Node* node = front;
	int sum = 0;
	while(front != NULL){
		node = front;
		front = front->next;
		free(node);
		sum++;
	}
	printf("free %d nodes\n", sum);
	getchar();
} 

