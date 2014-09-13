#include "Sort.h"

void selection_sort(int *arr,int len);

int main(int argc,char** argv)
{
	printf("Before selection_sort:\n");
	pri(arr);
	printf("After:\n");
	selection_sort(arr,len);
	pri(arr);
	return 0;
}

void selection_sort(int *arr,int len)
{
	int i,j,min;
	for(i = 0;i < len - 1;i++)
	{
		min = i;
		for(j = i;j < len;j++)
		{
			if(arr[min] > arr[j])
			{
				min = j;
			}
		}
		if(min != i)
		{
			swap(&arr[i],&arr[min]);
		}
	}
}
