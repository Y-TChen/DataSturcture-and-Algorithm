#ifndef _BST_H_
#define _BST_H_

#include "TreeNode.h"

TreeNode* SearchBST(TreeNode*, int);
void InsertBST(TreeNode**, int, char*);	// key and element
void deleteBST(TreeNode**, int);
void Levelorder(TreeNode*);

#endif /* _BST_H_ */
