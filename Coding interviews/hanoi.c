#include <stdio.h>

static int result = 0;

void move(char a,char b);
int hanoi(int n,char a,char b,char c);

int main(int argc,char** argv)
{
	int n;
	printf("Please input a number:\n");
	scanf("%d",&n);
	char a = 'a',b = 'b',c = 'c';
	result = hanoi(n,a,b,c);
	printf("Totally move %d steps!\n",result);
	return 0;
}

int hanoi(int n,char a,char b,char c)
{
	if(n > 0)
	{
		hanoi(n-1,a,c,b);
		move(a,b);
		result++;
		hanoi(n-1,c,b,a);
	}
	return result;
}

void move(char a,char b)
{
	printf("%c->%c\n",a,b);
}
