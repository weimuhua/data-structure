#include "Sort.h"

void StraightInsertionSort(int *arr);

int main(int argc,char** argv)
{
	pri(arr);
	printf("StraightInsertionSort:\n");
	StraightInsertionSort(arr);
	pri(arr);
	return 0;
}

void StraightInsertionSort(int *arr)
{
	int i,j,temp;
	for(i = 1;i < len;i++)
	{
		for(j = i - 1;j >= 0 && arr[j] > arr[j + 1];j--)
		{
			swap(&arr[j],&arr[j + 1]);
		}
	}
}
