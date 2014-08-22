#include "BitTree.h"

Tree MakeEmpty(Tree T)
{
    if(T!=NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

TreeNode* Find(int x,Tree T)
{
    if(T != NULL)
    {
        if(T->data == x)
                return T;
        else if(T->data > x)
                return Find(x,T->left);
        else if(T->data < x)
                return Find(x,T->right);
        else
                return NULL;
    }
    else
            return NULL;
}

int FindMax(Tree T)
{
    if(T != NULL)
    {
        if(T->right == NULL)
                return T->data;
        else
	{
                return FindMax(T->right);
	}
    }
}

int FindMin(Tree T)
{
    if(T != NULL)
    {
        if(T->left == NULL)
                return T->data;
        else
	{
                return FindMin(T->left);
	}
    }
}

TreeNode* Insert(int x,Tree T)
{
    if(T == NULL)
    {
        T = (Tree)malloc(sizeof(TreeNode));
        T->data = x;
        T->left=T->right=NULL;
    }
    else if(T->data > x)
    {
        T->left = Insert(x,T->left);
    }
    else if(T->data < x)
    {
        T->right = Insert(x,T->right);
    }
    return T;
}

TreeNode* Delete(int x,Tree T)
{
    if(T == NULL)
    {
            printf("ELement not found!\n");
            return NULL;
    }
    else if(x<T->data)
    {
        T->left = Delete(x,T->left);
    }
    else if(x>T->data)
    {
        T->right = Delete(x,T->right);
    }
    else if(T->left && T->right)//two children
    {
        int temp = FindMin(T->right);
        T->data = temp;
        T->right = Delete(T->data,T->right);
    }
    else//one or zero child
    {
        Tree temp = T;
        if(T->left == NULL)
                T = T->right;
        else if(T->right == NULL)
                T = T->left;
        free(T);
    }
    return T;
}

Stack createStack(int n)
{
	Stack s;
	s = (Stack)malloc(sizeof(StackRecord));
	s->array = (TreeNode**)malloc(n*sizeof(TreeNode*));
	s->capacity = n;
	s->topofstack = -1;
	return s;
}

int isEmpty(Stack s)
{
	return s->topofstack == -1;
}

int isFull(Stack s)
{
	return s->topofstack == s->capacity-1;
}

void Push(Stack s,TreeNode* node)
{
	if(isFull(s))
		printf("The Stack is full...\n");
	else
		s->array[++s->topofstack] = node;
}

TreeNode* Pop(Stack s)
{
	TreeNode* node = NULL;
	if(isEmpty(s))
	{
		printf("The Stack is empty...\n");
		return node;
	}
	else
	{
		node = s->array[s->topofstack];
		s->topofstack--;
		return node;
	}
}
