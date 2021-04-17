#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"
#include "hash.h"


unsigned int Hash(const char* key){	// get hash value
	unsigned int seed = 131;
	unsigned int hash = 0;
	
	while(*key){	// calculate until end of key
		hash = hash * seed + (*key++);
	}

	hash = hash % TABLE_SIZE; 
		
	return	hash;
}

HashTable* createHT(void){	// create hash table
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable) * 1);	// create 1 hash table
	ht->slot = (Node**)malloc(sizeof(Node*) * TABLE_SIZE);	// according to slots nunber
	
	for(int i = 0; i < TABLE_SIZE; i++){
		ht->slot[i] = NULL;	// all slots initialize to NULL
	}

	return ht;
}

void printSlot(Node* front){
	while(front != NULL){
		printf("key: %s , value: %s\n", front->key, front->data);
		
		printf("Hash: %d\n", Hash(front->key));

		front = front->next;

	}
}

void deleteSlot(Node* front){
	Node* temp;
	int sum = 0;

	while(front != NULL){
		temp = front;
		front = front->next;
		free(temp);
		sum++;
	}
	printf("free %d nodes\n", sum);
}


