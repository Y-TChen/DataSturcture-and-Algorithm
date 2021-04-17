// use array to make a circular queue
// circular queue => avoid wasting array space
#include<stdio.h>
#include<stdlib.h>

typedef struct circularArrayQueue{
	int front, back, qSize;
	int* queue;
}CAQueue;

void printQueue(CAQueue*);
void Push(CAQueue*, int);
void Pop(CAQueue*);
void freeQueue(CAQueue*);

int main(){
	CAQueue* q = (CAQueue*)malloc(sizeof(CAQueue));
	q->front = 0;
	q->back = 0;
	q->qSize = 5;
	q->queue = malloc(q->qSize*sizeof(int));

	int data, select, exit = 1;
	while(exit){
		printf("============== Circular Array Queue ===============\n\n");
		printQueue(q);	// print queue data
		printf("(1) Push data\n");
		printf("(2) Pop data\n");
		printf("(3) exit\n");
		//printf("(4)\n");
		//printf("(5)\n");
		//printf("(6)\n");
		printf("Enter selection:");
		scanf("%d", &select);
		switch(select){
			case 1:
				printf("Enter data: ");
				scanf("%d", &data);
				Push(q, data);
				break;
			case 2:
				Pop(q);
				break;
			case 3:
				exit = 0;
				freeQueue(q);
				break;
		}
		getchar();
		system("clear");
	}
	return 0;
}

void Push(CAQueue* q, int data){
	int* array = q->queue;
	if((q->back + 1) % q->qSize == q->front){	// queue is full => double queue size
		printf("create double size (%d) queue!\n", 2 * q->qSize);
		int* doubleArray = malloc(2 * q->qSize * sizeof(int));
		int len = (q->front < q->back) ? (q->back - q->front) : (q->back + q->qSize - q->front); 
		int j = 0;
		for(int i = (q->front + 1) % q->qSize; i < q->front + len + 1; i++){
			j++;
			doubleArray[j] = array[i % q->qSize];	// shift data from array to doubleArray(from pos 0)
		}
		q->front = 0;	// reset front and back 
		q->qSize *= 2; 
		q->back = j % q->qSize;
		free(array);	// free old array
		q->queue = doubleArray; // point to new array
	}
	q->queue[(q->back+1) % q->qSize] = data;
	q->back = (q->back + 1) % q->qSize;
	
}

void Pop(CAQueue* q){
	if(q->front == q->back){	// empty queue
		printf("Empty queue !\n");
	}
	else{
		printf("Pop %d\n", *(q->queue + q->front + 1));
		q->front = (q->front + 1) % q->qSize;
	}
}

void printQueue(CAQueue* q){
	printf("Queue front:%d back:%d size: %d\n", q->front, q->back, q->qSize);
	if(q->front == q->back){
		printf("empty queue!\n");
		getchar();
		return;
	}

	int len = (q->front < q->back) ? (q->back - q->front) : (q->back + q->qSize - q->front); 
	for(int i = q->front + 1; i < q->front + len + 1; i++){
		printf("%d ", q->queue[i % (q->qSize)]);
	}
	printf("\n");
}

void freeQueue(CAQueue* q){

	int* array = q->queue;
	free(array);
}

