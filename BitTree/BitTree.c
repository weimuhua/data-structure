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
		T->bepushed = 0;
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
	if(s->topofstack == -1)
		return 1;
	else
		return 0;
}

int isFull(Stack s)
{
	if(s->topofstack == s->capacity-1)
		return 1;
	else
		return 0;
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

void preOrder(Tree T)
{
	Stack s = createStack(20);
	Tree t = T;
	while( t!=NULL || !isEmpty(s) )
	{
		if(t)
		{
			printf("%d\t",t->data);
			Push(s,t);
			t = t->left;
		}
		else
		{
			t = Pop(s);
			t = t->right;
		}
	}
}

void inOrder(Tree T)
{
	Stack s = createStack(20);
	Tree t = T;
	while( t!=NULL || !isEmpty(s) )
	{
		if(t)
		{
			Push(s,t);
			t = t->left;
		}
		else
		{
			t = Pop(s);
			printf("%d\t",t->data);
			t = t->right;
		}
	}
}

void postOrder(Tree T)
{
	Stack s = createStack(20);
	TreeNode* t = T;
	if(T != NULL)
	{
		Push(s,T);
	}
	while(!isEmpty(s))
	{
		t = Pop(s);
		Push(s,t);
		if(t->bepushed)
		{
			printf("%d\t",t->data);
			Pop(s);
		}
		else
		{
			if(t->right)
			{
				Push(s,t->right);
			}
			if(t->left)
			{
				Push(s,t->left);
			}
			t->bepushed = 1;
		}
	}
}


int findLowestAncestor(Tree T,int x,int y)
{
	if(T == NULL)
	{
		printf("The tree is empty...\n");
		return 0;
	}
	else
	{
		if( T->data > x && T->data > y )
		{
			return findLowestAncestor(T->left,x,y);
		}
		else if( T->data < x && T->data < y )
		{
			return findLowestAncestor(T->right,x,y);
		}
		else
			return T->data;
	}
}
