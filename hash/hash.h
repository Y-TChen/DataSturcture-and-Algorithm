#ifndef _HASH_H_
#define _HASH_H_
#include "linkedList.h"


#define TABLE_SIZE 5

typedef struct ht{	// use hash table to store slots 
	Node** slot;	// nodes entry;
}HashTable;

unsigned int Hash(const char *);	// get hash value
HashTable* createHT(void);	// create hash table
void printSlot(Node*);
void deleteSlot(Node*);

#endif /* _HASH_H_ */

