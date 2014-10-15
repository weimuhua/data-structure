#include "BitTree.h"

//二叉树的镜像
void mirrorReverse(Tree T)
{
	if(T == NULL || (T->left == NULL && T->right == NULL))
		return;
	TreeNode* temp = T->left;
	T->left = T->right;
	T->right = temp;
	if(T->left)
		mirrorReverse(T->left);
	if(T->right)
		mirrorReverse(T->right);
}

//判断root2是否为root1的子结构
int hasSubTree(Tree root1,Tree root2)
{
	int result = 0;
	if(root1 != NULL && root2 != NULL)
	{
		if(root1->data == root2->data)
		{
			result = doesTree1HaveTree2(root1,root2);
		}
	if(!result)
		result = hasSubTree(root1->left,root2);
	if(!result)
		result = hasSubTree(root1->right,root2);
	}
	return result;
}

int doesTree1HaveTree2(Tree tree1,Tree tree2)
{
	if(tree2 == NULL)
		return 1;
	if(tree1 == NULL)
		return 0;
	if(tree1->data != tree2->data)
		return 0;
	
	return doesTree1HaveTree2(tree1->left,tree2->left) 
				&& doesTree1HaveTree2(tree1->right,tree2->right);
}

int level(Tree T)
{
	int l1 = 0,l2 = 0;
	if(T == NULL)
		return 0;
	else
	{
		l1 = level(T->left);
		l2 = level(T->right);
		return l1 > l2 ? l1 + 1 : l2 + 1;
	}
}

void preorder(Tree T)
{
	if(T)
	{
		printf("%d\t",T->data);
		preorder(T->left);
		preorder(T->right);
	}
}

int findMaxHeight(Tree T)
{
	int height = 0,maxHeight = 0;
	Stack s = createStack(10);
	while(T != NULL || !isEmpty(s))
	{
		if(T)
		{
			height++;
			if(height > maxHeight)
			{
				maxHeight = height;
			}
			Push(s,T);
			T = T->left;
		}
		else
		{
			height--;
			T = Pop(s);
			T = T->right;
		}
	}
	return maxHeight;
}

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
		if(t->bepushed)
		{
			printf("%d\t",t->data);
		}
		else
		{
			Push(s,t);
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
