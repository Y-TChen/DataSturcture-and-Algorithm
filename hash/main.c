#include<stdio.h>
#include<stdlib.h>
#include "hash.h"
#include "linkedList.h"

int main(){
	Node* slot1 = NULL;
	Insert(&slot1, "Markchen", "Value 1");
	Insert(&slot1, "Data", "Value 2");
	Insert(&slot1, "12", "Value 3");
	Insert(&slot1, "mkar", "Value 4");
	Insert(&slot1, "Ha ha", "Value 5");
	Insert(&slot1, "1462", "Value 6");
	

	printSlot(slot1);
	deleteSlot(slot1);
	return 0;
}
