#ifndef _LEVELORDER_TRAVERSAL_
#define _LEVELORDER_TRAVERSAL_


typedef struct treeNode{
	int data;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
	struct treeNode* parent;
}TreeNode;

typedef struct node{
	TreeNode* data;
	struct node* next;
}Node;

void preOrder(TreeNode*);
void inOrder(TreeNode*);
void postOrder(TreeNode*);
void levelOrder(Node*, Node*, TreeNode*);
TreeNode* createNode(int);
void deleteTree(TreeNode*);

#endif /* _LEVELORDER_TRAVERSAL_ */
