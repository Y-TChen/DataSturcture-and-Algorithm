#include<stdio.h>
#include<stdlib.h>
#include"hash.h"


//int len = 6;	// table size

int main(){

	htNode** ht = (htNode**)malloc(6 * sizeof(htNode*));	// create hash table with 10 table size
	htInit(ht);
	
	htInsert(ht, "tom", 63);
	htInsert(ht, "Stevie", 777);
	htInsert(ht, "elesa", 10);
	htInsert(ht, "Peter", 45);
	htInsert(ht, "Jennie", 128);
	htInsert(ht, "Stevie", 987);
	htPrint(ht);
	
	printf("\n\n");
	char key[5][20] = {"mark", "tom", "Stevie1", "elesa"};
	for(int i = 0; i < 4; i++){
		htNode* node = htSearch(ht, key[i]);
		if(node)
			printf("Find [%s]: %d\n", node->keyString, node->data);
		else
			printf("[%s] doesn't found!\n", key[i]);
	}	

//	htRemove(ht, key[3]);
	htRemove(ht, key[1]);
	htPrint(ht);


	htDelete(ht);
	free(ht);

	return 0;
}
