#include "Sort.h"

void shell_sort(int *arr,int len);

int main(int argc,char** argv)
{
	pri(arr);
	shell_sort(arr,len);
	pri(arr);
	return 0;
}

void shell_sort(int *arr,int len)
{
	int i,j,gap;
	for(gap = len/2;gap > 0;gap /= 2)
	{
		for(i = gap;i < len;i++)
		{
			for(j = i - gap;j >= 0 && arr[j] > arr[j + gap];j -= gap)
			{
				swap(&arr[j],&arr[j + gap]);
			}
		}
	}
}
