#include <stdio.h>

int main(int argc,char** argv)
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",add(reverse(a),reverse(b)));
	return 0;
}

int reverse(int a)
{
	if(a == 0)
		return 0;
	int result = 0;
	int x = 0;
	while(a > 0)
	{
		x = a % 10;
		a = a / 10;
		result = result*10 + x;
	}
	return result;
}

int add(int a,int b)
{
	return a + b;
}
