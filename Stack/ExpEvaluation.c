#include "Stack.h"

int main(int argc,char* argv[])
{
	Stack s = createStack(10);
	Push(s,'a');
	Push(s,'b');
	printf("%c\t%c\n",Pop(s),Pop(s));
	return 0;
}
