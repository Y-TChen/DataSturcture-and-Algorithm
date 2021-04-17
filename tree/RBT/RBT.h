#ifndef _RBT_H_
#define _RBT_H_

#include "TreeNode.h"

//TreeNode* neel;	// NIL node

TreeNode* SearchBST(TreeNode*, int);
void InsertRBT(TreeNode**, int, char*);	// key and element
void insertFix(TreeNode*);	// fix insert node's color
void deleteBST(TreeNode**, int);
void deleteRBT(TreeNode*);	// delete RB tree
void inOrderRBT(TreeNode*);
void preOrderRBT(TreeNode*);

#endif /* _RBT_H_ */
