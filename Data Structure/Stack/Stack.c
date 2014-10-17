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

int ExpEvaluation(char* str)
{
	int i,result;
	int len = strlen(str);
	Stack s1 = createStack(10);
	Stack s2 = createStack(10);
	for(i = 0;i<len;i++)
	{
		//0~9存在栈s1
		if(str[i]>='0' && str[i] <= '9')
		{
			//printf("push %d\n",str[i] - '0');
			Push(s1,str[i]);
		}
		else
		{
			//1.要入栈的元素为右括号
			if(str[i] == ')')
			{
				//倒数第二个栈顶元素为左括号
				if(s2->array[s2->topofstack - 1] == '(')
				{
					cal(s1,s2);
					//将左括号弹出
					Pop(s2);
				}
				//倒数第三哥栈顶元素为左括号
				else if(s2->array[s2->topofstack - 2] == '(')
				{
					cal(s1,s2);
					cal(s1,s2);
					//将左括号弹出
					Pop(s2);
				}
			}
			//2.栈为空，或要入栈的元素优先级大于等于栈顶元素,或栈顶元素为左括号
			else if(isEmpty(s2) || priority(str[i]) >= priority(s2->array[s2->topofstack]) || s2->array[s2->topofstack] == '(')
			{
				//只入栈，不进行其他操作
				//printf("push %c\n",str[i]);
				Push(s2,str[i]);
			}
			//3.要入栈的元素优先级小于栈顶元素
			else if( priority(str[i]) < priority(s2->array[s2->topofstack]) )
			{
				cal(s1,s2);
				//printf("push %c\n",str[i]);
				Push(s2,str[i]);
			}
		}
	}
	//最后根据栈中剩余元素的个数来运算
	for(i = 0;i<=s1->topofstack+1;i++)
	{
		cal(s1,s2);
	}
	//最后从s1中弹出运算结果
	result  = Pop(s1) - '0';
	return result;
}

//此函数将栈s1的两个数字以及栈s2的运算符弹出并进行计算
//然后再将结果压入栈s1中
void cal(Stack s1,Stack s2)
{
	char a,b,c;
	int result;
	if(!isEmpty(s1))
	{
		b = Pop(s1);
		//printf("pop %d\n",b - '0');
	}
	if(!isEmpty(s1))
	{
		a = Pop(s1);
		//printf("pop %d\n",a - '0');
	}
	if(!isEmpty(s2))
	{
		c = Pop(s2);
		//printf("pop %c\n",c);
	}
	result = calculate( (int)(a-'0'),(int)(b-'0'),c);
	//printf("push %d\n",result);
	Push(s1,(char)(result + '0'));
}

int calculate(int a,int b,char c)
{
	if(c == '+')
		return a+b;
	else if(c == '-')
		return a-b;
	else if(c == '*')
		return a*b;
	else if(c == '/')
		return a/b;

}

int priority(char c)
{
	if( c == '(' || c == ')' )
		return 3;
	else if( c == '*' || c == '/' )
		return 2;
	else if( c == '+' || c == '-')
		return 1;
	else
		return 0;
}
