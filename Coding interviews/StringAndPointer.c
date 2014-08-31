#include <stdio.h>

int main(int argc,char** argv)
{
	char str1[]="hello world";
	char str2[]="hello world";
	char* p1="hello world";
	char* p2="hello world";
	if(str1==str2)
		printf("str1 and str2 are same.\n");
	else
		printf("str1 and str2 are not same.\n");
	if(p1==p2)
		printf("p1 and p2 are same.\n");
	else
		printf("p1 and p2 are not same.\n");
	if(str1==p1)
		printf("str1 and p1 are same.\n");
	else
		printf("str1 and p1 are not same.\n");
	if(str2==p1)
		printf("str2 and p1 are same.\n");
	else
		printf("str2 and p1 are not same.\n");
}
