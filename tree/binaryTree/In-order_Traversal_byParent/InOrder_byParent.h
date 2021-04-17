
typedef struct treeNode{
	int data;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
	struct treeNode* parent;
}TreeNode;

void inOrder(TreeNode* current);
TreeNode* leftMost(TreeNode*);
TreeNode* rightMost(TreeNode*);
TreeNode* InOrderSuccessor(TreeNode*); 
TreeNode* InOrderPredecessor(TreeNode*);
void InOrder_byParent(TreeNode*);
void InOrder_Reverse(TreeNode*);
TreeNode* createNode(int data);
void deleteTree(TreeNode* current);

