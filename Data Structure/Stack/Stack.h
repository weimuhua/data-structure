#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int ExpEvaluation(char* str);
int priority(char c);
int calculate(int a,int b,char c);
void cal(Stack s1,Stack s2);
