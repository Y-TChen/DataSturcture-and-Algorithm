#ifndef _HASH_H_
#define _HASH_H_


typedef struct ht_node{
	struct ht_node* next;	// point to next chain data 
	char keyString[20];	// store key 
	int data;

}htNode;

 
void htInit(htNode**);	// initiate hash table 
unsigned long djb2Hash(char*);	// hash function
void htInsert(htNode** , char*, int);	// insert data according keyString
htNode* htSearch(htNode**, char*);	//	use keyString to find index
void htPrint(htNode**);	// print all data in the hash table
void htDelete(htNode**);	// delete all table
void htRemove(htNode**, char*);	// remove node according keyString
	
#endif /* _HASH_H_ */

