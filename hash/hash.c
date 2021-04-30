#include<stdio.h>
#include<stdlib.h>
#include "hash.h"

int len = 6;	// table size

void htInit(htNode** ht){	// initiate hash table 
	printf("\n============== Hash Table Init ===================\n");
	printf("table size: %d\n", len);

	htNode* node;
	
	for(int i = 0; i < len; i++){
		node = (htNode*)malloc(sizeof(htNode));
		node->data = i;
		node->next = NULL;
		
		int pos = 20;
		while(pos--){
			*(node->keyString) = 0;
		}
		
		ht[i] = node;
	}
}

void htDelete(htNode** ht){	// delete all data in hash table 
	int count = 0;	// record number of delete nodes
	htNode* node, * temp;

	for(int i = 0; i < len; i++){	// traversal
		node = ht[i]; 

		while(node){	// delete all tables
			temp = node;
			node = node->next;
			free(temp);
			count++;
		}	 
	}

	printf("\nDelete %d nodes ~\n", count);
}

unsigned long djb2Hash(char* key){	// hash function
	unsigned long hash = 5381;
	int c;
	char* keyString = key;
	while(c = *keyString++){
		hash = ((hash << 5) + hash) + c;
	}

	return hash;
}

void htInsert(htNode** ht, char* keyString, int data){	// insert data according keyString
	
	unsigned long hash = djb2Hash(keyString);
	htNode* node = ht[hash % len];	// find insert table by (hash % table size)
	
	while(node && node->next){	// find insert position
		node = node->next;
	}
	htNode* temp = (htNode*)malloc(sizeof(htNode));
	temp->data = data;
	temp->next = NULL;
	
	char* dst = temp->keyString;
    char* src = keyString;
	while(*dst++ = *src++);	// copy keyString

	node->next = temp;	// insert back of node

	printf("\nInsert hash(%s) = %ld\n", temp->keyString, hash);
}
//	use keyString to find index, then traversal the linkedList to find node
htNode* htSearch(htNode** ht, char* keyString){
	unsigned long index = djb2Hash(keyString);	// use keyString to find index
	
	htNode* node = ht[index % len]->next;	// find linkedList head node
	
	while(node){	// traversal until find node or end of list
		char* dst = node->keyString;
		char* src = keyString;
		int counter = 0;

		while(*dst++ && *src++){	// compare before EOF
			if(*dst - *src){	// compare two world, different => counter++
				counter++;
			}
		}
		
		if(!counter){	// counter = 0 => find
			return node;	// return find node
		}
		node = node->next;	// continue traversal
	}
	
	return NULL;	// not found
}

void htRemove(htNode** ht, char* keyString){	// remove node according keyString
	
	unsigned long index = djb2Hash(keyString);	// use keyString to find index
	
	htNode* prv = ht[index % len];	// remember previous node (table)
	htNode* node = prv->next;	// find linkedList head node

	while(node){	// traversal until find node or end of list
		char* dst = node->keyString;
		char* src = keyString;
		int counter = 0;

		while(*dst++ && *src++){	// compare before EOF
			if(*dst - *src){	// compare two world, different => counter++
				counter++;
			}
		}
		
		if(!counter){	// counter = 0 => find 
			printf("Find %s! Removing...\n", node->keyString);
			prv->next = (prv->next) ? node->next : NULL;	// link prvious and next nodes
			free(node);	// free node
			return;
		}

		prv = node;
		node = node->next;	// continue traversal
	}
	
	printf("Not found!\n");	// not found
}

void htPrint(htNode** ht){
	printf("\n============== Print Hash Table ================\n");

	htNode* node;
	for(int i = 0; i < len; i ++){	// traversal 20 tables
		node = ht[i];
		//if(!node->next)	// skip NULL tables
		//	continue;

		printf("(%2d)", i);
		node = node->next;	// traversal linkedList from first node
		while(node){
			printf(" [%s %d]", node->keyString, node->data);
			node = node->next;
		}
		printf("\n");
	}
}

