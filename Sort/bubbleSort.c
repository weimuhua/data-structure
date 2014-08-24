#include "Sort.h"

void sort(int* arr);

int main(int argc,char** argv)
{
	printf("Before:\n");
	pri(arr);
	printf("after:\n");
	sort(arr);
	pri(arr);
	return 0;
}

void sort(int* arr)
{
	int i,j;
	int temp;
	for(i = 0;i<len - 1;i++)
	{
		for(j = 0;j<len -1 - i;j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
