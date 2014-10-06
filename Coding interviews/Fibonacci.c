#include <stdio.h>

long Fibonacci(int x);

int main(int argc,char** argv)
{
	printf("%ld\n",Fibonacci(5));
	return 0;
}

long Fibonacci(int x)
{
	if(x == 0)
		return 0;
	if(x == 1)
		return 1;
	long p = 0;
	long q = 1;
	long result = 0;
	int i;
	for(i = 2;i < x;i++)
	{
		result = p + q;
		p = q;
		q = result;
	}
	return result;
}
