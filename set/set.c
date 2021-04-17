#include<stdio.h>
#include<stdlib.h>


void printArray(int*, int);
void unionSet(int*, int, int);	// put two elements into same set
int findSet(int* ,int);	// find subset that element belongs to  =>  O(n)
int findSetCollapsing(int* ,int);	// find subset and doing collapsing concurrently  => O(1)

int main(){
	int num = 6;	// number of elements
	int array[num];
	for(int i = 0; i < num; i++){	// initialize
		*(array + i) = -1;
	}

	int elemX, elemY, select, exit = 1;
	while(exit){
		printf("=========== Set =============\n");
		printArray(array, num);
		printf("(1) find set\n");
		printf("(2) find set collapsing\n");
		printf("(3) union set\n");
		printf("(4) exit\n");
		printf("Enter selection:");
		scanf("%d", &select);

		switch(select){
			case 1:
				printf("Enter element: ");
				scanf("%d", &elemX);
				findSet(array, elemX);
				getchar();
				break;
			case 2:
				printf("Enter element: ");
				scanf("%d", &elemX);
				findSetCollapsing(array, elemX);
				getchar();
				break;
			case 3:
				printf("Enter two elements: ");
				scanf("%d %d", &elemX, &elemY);
				unionSet(array, elemX, elemY);
				break;
			case 4:
				exit = 0;
				break;				
		}
		getchar();
		system("clear");
	}

	return 0;
}

int findSet(int* array, int element){
	int root = element;
	printf("%d", root);
	while(array[root] >= 0){
		root = array[root];
		printf(" -> %d", root);
	}
	return root;
}

int findSetCollapsing(int* array, int element){
	int root = array[element];
	for(root = element; array[root] >= 0; root = array[root]);

	while(element != root){
		int parent = array[element];
		array[element] = root;
		element = parent;
	}
	return root;
}

void unionSet(int* array, int X, int Y){
	int elemX = array[X] * -1;	//	find which subset have less elements
	int elemY = array[Y] * -1;
	printf("Union (%d) and (%d)\n", X, Y);
	if(elemX >= elemY){
		array[Y] = X;
		array[X] -= elemY;	
	}
	else{
		array[X] = Y;
		array[Y] -= elemX;	
	}
}	

void printArray(int* array, int len){
	for(int i = 0; i < len; i++){
		printf("%3d", i);
	}	
	printf("\n");
	for(int i = 0; i < len; i++){
		printf("%3d", *(array + i));
	}	
	printf("\n");
}
