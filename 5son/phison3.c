#include<stdio.h>

struct ListStruct{
	unsigned int dataH;
	unsigned int dataL;
	unsigned int NextPtr;
};

struct ListStruct ListArray[1000];

#define NULL 0xFFFF

unsigned int ListHead = 0;

void function(unsigned int Data_A, unsigned int Data_B){
	unsigned int foundEntry = ListHead, preEntry = NULL;
	while(foundEntry != NULL){  
		if(ListArray[foundEntry]->dataH == Data_A && ListArray[foundEntry]->data_L == Data_B){
			printf("Data found\n");
			break;
		}
		preEntry = foundEntry;
		foundEntry = ListArray[foundEntry]->NextPtr;		
	}
	printf("Not found\n");
}


