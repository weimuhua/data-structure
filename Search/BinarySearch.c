#include "Sort.h"

int BinarySearch(int* arr,int length,int v);

int main(int argc,char** argv)
{
	pri(arr);
	printf("BinarySearch result:%d\n",BinarySearch(arr,len - 1,65));
	return 0;
}

int BinarySearch(int* arr,int length,int v)
{
	int left,right,middle;
	left = -1,right = length;

	while(left + 1 != right)
	{
		middle = left + (right - left)/2;
		if(arr[middle] < v)
		{
			left = middle;
		}
		else
		{
			right = middle;
		}
	}

	if(right >= length || arr[right] != v)
	{
		right = -1;
	}
	return right;
}
