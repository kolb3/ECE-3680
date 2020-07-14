typedef struct TNode
{
	struct TNode* left;
	struct TNode* right;
	int key;
	//int dimright;
	//int dimleft;
	//int bal; //think i can use this instead of dimright and dimleft, just keep track of balance
	int height;
}TreeNode;


int height(TreeNode * head);
TreeNode * createnode(int num);
TreeNode * insert(TreeNode * head, int key);
int max(int x, int y);
int bal(TreeNode * head);


