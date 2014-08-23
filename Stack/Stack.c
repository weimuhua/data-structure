#include "Stack.h"

Stack createStack(int num)
{
	Stack s = (Stack)malloc(sizeof(StackRecord));
	s->topofstack = -1;
	s->capacity = num;
	s->array = (char*)malloc(num*sizeof(char));
}

int isEmpty(Stack s)
{
	return s->topofstack == -1;
}

int isFull(Stack s)
{
	return s->topofstack == s->capacity - 1;
}

void Push(Stack s,char c)
{
	if(isFull(s))
	{
		printf("The stack is full...\n");
	}
	else
	{
		s->array[++s->topofstack] = c;
	}
}

char Pop(Stack s)
{
	char c;
	if(isEmpty(s))
	{
		printf("The stack is full...\n");
		return c;
	}
	else
	{
		c = s->array[s->topofstack--];
		return c;
	}
}

void ExpEvaluation(char* str)
{
	
}
