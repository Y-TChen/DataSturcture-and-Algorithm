#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}Node;

void pushFront(int);
void pushBack(int);
void insertNode(int, int);
void deleteNode(int num);
void searchNode(int num);
void printList(Node *);
void freeList(Node *);


Node *head = NULL;

void pushFront(int num){
	Node *node = (Node *)malloc(sizeof(Node));
	if(node == NULL){
		printf("Out of memory!\n");
		return;
	}
	if(head != NULL){
		head->prev = node;
	}
	node->data = num;
	node->next = head;
	node->prev = NULL;
	head = node;
}

void pushBack(int num)
{
	Node *node = (Node *)malloc(sizeof(Node));
	if(node == NULL){
		printf("Out of memory!\n");
		return;
	}
	node->data = num;
	node->next = NULL;
	node->prev = NULL;
	
	if(head == NULL){
		head = node;
	}
	else{
		Node *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = node;
		node->prev = temp;
	}
}

void insertNode(int pos, int num){
	if(pos <= 0){
		printf("Insert position must > 0\n");
		getchar();
		return;
	}
	Node *temp, *previous, *node; 
	
	node = (Node *)malloc(sizeof(Node));
	node->data = num;
	node->next = NULL;
	node->prev = NULL;
	
	if(head == NULL){
		head = node;
		return;
	}
	
	temp = head;	
	while(pos > 0 && temp != NULL){
		previous = temp;
		temp = temp->next;
		pos--;
	}
	if(pos > 0){
		printf("Insert position out of list!\n");
		free(node);
		getchar();
		return;
	}
	previous->next = node;
	node->prev = previous;
	node->next = temp;
	if(temp != NULL){	
		temp->prev = node;
	}
}

void deleteNode(int num){
	Node *temp, *previous;
	temp = head;

	while(temp != NULL && temp->data != num){
		previous = temp;
		temp = temp->next;
	}
	if(temp == NULL){ // no finding result
		printf("Can't find %d in list!\n", num);
		getchar();
		return;
	}
	else if(temp == head){ // delete first node
		if(temp == NULL){
			printf("Empty list!!\n");
			getchar();
			return;
		}
		else{
			if(temp->next != NULL){
				head = temp->next;
				head->prev = NULL;
				free(temp);
			}
			else{
				head = NULL;
				free(temp);
			}
		}
	}
	else{ // find node
		previous->next = temp->next;
		if(temp->next != NULL){
			temp->next->prev = previous;
		}
		free(temp);
	}
}

void searchNode(int num){
	int pos = 0;
	Node *temp = head;

	while(temp != NULL && temp->data != num){
		temp = temp->next;
		pos++;
	}
	if(temp != NULL){
		printf("%d's pos: %d\n",num, pos);
	}
	else{
		printf("No result!\n");
	}
	getchar();
}

void printList(Node *head){
	int num = 0;
	Node *prev, *temp = head;
	if(temp == NULL){
		printf("Empty list!\n");
		return;
	}
	while(temp != NULL){
		printf("Node%d %d\n", ++num, temp->data);
		prev = temp;
		temp = temp->next;
	}	
	printf("=========== Reverse ============\n");
	while(prev != NULL){
		temp = prev;
		printf("Node%d %d\n", --num, temp->data);
		prev = prev->prev;
	}
	getchar();
}

void freeList(Node *head){
	int num = 0;
	Node *temp, *current;
	current = head;
	if(current == NULL){
		printf("Empty list!\n");
		return;
	}
	while(current->next != NULL){
		temp = current->next;
		free(current);
		current = temp;
	    num++;	
	}
	free(current);
	printf("free %d nodes\n", ++num);
	getchar();
}

int main()
{
	int exit, opt, data, pos;
	exit = 1;
	while(exit){
		system("clear");
		printf("======================Linked List========================\n\n");
		printf("< Option Menu >\n\n");
		printf("(1) pushFront(int num)\n");
		printf("(2) pushBack(int num)\n");
		printf("(3) insertNode(int pos, int num)\n");
		printf("(4) deleteNode(int num)\n");
		printf("(5) searchNode(int num)\n");
		printf("(6) exit\n");
	
		printf("lastest list:\n");
		printList(head);

		printf("option: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Please enter input data: ");
				scanf("%d", &data);
				pushFront(data);
				break;
		
			case 2:
				printf("Please enter input data: ");
				scanf("%d", &data);
				pushBack(data);
				break;

			case 3:
				printf("Please enter input position: ");
				scanf("%d", &pos);
				printf("Please enter input data: ");
				scanf("%d", &data);
				insertNode( pos, data);
				break;

			case 4:
				printf("Please enter delete data: ");
				scanf("%d", &data);
				deleteNode(data);
				break;

			case 5:
				printf("Please enter search data: ");
				scanf("%d", &data);
				searchNode(data);
				getchar();
				break;

			case 6:
				freeList(head);
				exit = 0;
				break;
		}
	}
	return 0;
}
