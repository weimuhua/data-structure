#include "Sort.h"

void sort(int* arr);

int main(int argc,char* argv[])
{
	printf("Before sort the array:\n");
	pri(arr);
	printf("After:\n");
	sort(arr);
	pri(arr);
	printf("\n");
	return 0;
}

void sort(int* arr)
{
	int i,j,temp;
	for(i = 1;i<len;i++)
	{
		if(arr[i] < arr[i-1])
		{
			temp = arr[i];
			for(j = i-1;j >= 0 && arr[j] > temp;j--)
				arr[j+1] = arr[j];
			arr[j+1] = temp;
		}
	}
}
