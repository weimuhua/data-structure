#include <stdio.h>

int numberOfOne(int n);

int main(int argc,char** argv)
{
	printf("numberOfOne(10):%d\n",numberOfOne(10));
	return 0;
}

int numberOfOne(int n)
{
	int count = 0;
	while(n)
	{
		count++;
		n = (n - 1) & n;
	}
	return count;
}
