#include <stdio.h>

int arr[] = {98,76,109,34,67,190,80,12,14,89,1,23,33,65,567,233,190,12};
int len = 18;

void pri(int* arr)
{
	int i;
	for(i = 0;i<len;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
