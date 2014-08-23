#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
	int bepushed;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
typedef struct TreeNode* Tree;

typedef struct StackRecord
{
	int capacity;
	int topofstack;
	TreeNode** array;
}StackRecord;
typedef struct StackRecord* Stack;

Tree MakeEmpty(Tree T);
TreeNode* Find(int x,Tree T);
int FindMax(Tree T);
int FindMin(Tree T);
TreeNode* Insert(int x,Tree T);
TreeNode* Delete(int x,Tree T);
void PreOrder(Tree T);
Stack createStack(int n);
int isEmpty(Stack s);
int isFull(Stack s);
void Push(Stack s,TreeNode* node);
TreeNode* Pop(Stack s);
void preOrder(Tree T);
void inOrder(Tree T);
void postOrder(Tree T);
int findLowestAncestor(Tree T,int x,int y);
