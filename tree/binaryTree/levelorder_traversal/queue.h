#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "levelOrder_traversal.h"


void Push(Node**, Node**, TreeNode*);
void Pop(Node**, Node**);
TreeNode* getFront(Node*);
TreeNode* getBack(Node*);
void getSize(Node*);
int empty(Node*);
void deleteQueue(Node*);

#endif /* _QUEUE_H_ */
