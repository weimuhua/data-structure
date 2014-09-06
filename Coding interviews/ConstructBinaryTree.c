#include <stdio.h>

typedef struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}BinaryTreeNode;

BinaryTreeNode* ConstructCore(int* startPreOrder,int* endPreOrder,int* startInOrder,int* endInOrder);
BinaryTreeNode* Construct(int* preorder,int* inorder,int length);

int main(int argc,char** argv)
{

	return 0;
}

BinaryTreeNode* Construct(int* preorder,int* inorder,int length)
{
	if(preorder == NULL || inorder == NULL || length <= 0)
		return;
	else
		ConstructCore(preorder,preorder + length - 1 ,inorder,inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreOrder,int* endPreOrder,int* startInOrder,int* endInOrder)
{
	int rootValue = startPreOrder[0];
	BinaryTreeNode* root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNOde));
	root->value = rootValue;
	root->left = NULL;
	root->right = NULL;

	if(startPreOrder == endPreOrder && *startPreOr == *endPreOrder)
	{
		return root;
	}

	int* rootInorder = startInOrder;
	while(startInOrder <= endInOrder && *startInOrder != *)
		++ rootInorder;
	if(rootInorder == endInOrder && *rootInorder != rootValue)
		return;
	
	int leftLength = rootInorder - startInOrder;
	int* leftPreorderEnd = startPreOrder + leftLength;
	if(leftLength > 0)
	{
		root->left = ConstructCore(startPreOrder + 1,leftPreorder,startInOrder,rootInorder - 1);
	}
	if(leftLength < endPreorder - startPreorder)
	{
		root->right = ConstructCore(leftPreorderEnd + 1,endPreOrder,rootInorder + 1,endInorder);
	}
	return root;
}
