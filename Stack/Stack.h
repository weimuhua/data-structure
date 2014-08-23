#include <stdio.h>
#include <stdlib.h>

typedef struct StackRecord
{
	int capacity;
	int topofstack;
	char* array;
}StackRecord;
typedef struct StackRecord* Stack;

Stack createStack(int num);
int isEmpty(Stack s);
int isFull(Stack s);
void Push(Stack s,char c);
char Pop(Stack s);
void ExpEvaluation(char* str);
