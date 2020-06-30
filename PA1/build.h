typedef struct TNode
{
	struct TNode* left;
	struct TNode* right;
	int* data;
	int dimension;
}TreeNode;


typedef struct LNode
{
	struct LNode *next;
	TreeNode* treenode;
}ListNode;

void Preorder(ListNode * head);
ListNode* CreateNode(int n, int dim, int* arr);
void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr);

