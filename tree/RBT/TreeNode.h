#ifndef _TREE_NODE_
#define _TREE_NODE_

typedef struct treeNode{
	struct treeNode* leftChild;
	struct treeNode* rightChild;
	struct treeNode* parent;
	char data[20];	// element
	int key;	// key, used for comparision
	int color;	// 0:red  1:black
}TreeNode;

TreeNode* neel;	// NIL node

TreeNode* createNode(int, char*);
void inOrder(TreeNode*);
void inOrderRBT(TreeNode*);
TreeNode* leftMost(TreeNode*);
TreeNode* rightMost(TreeNode*);
void LeftRotation(TreeNode*);
void RightRotation(TreeNode*);
TreeNode* Successor(TreeNode*);
void InorderPrint(TreeNode*);
void deleteTree(TreeNode*);

#endif /* _TREE_NODE_ */
