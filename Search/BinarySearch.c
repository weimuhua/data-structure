#include "Search.h"

int BinarySearch(int* arr,int len,int v);

int main(int argc,char** argv)
{
	pri(arr);
	printf("BinarySearch result:%d\n",BinarySearch(arr,len - 1,65));
	return 0;
}

int BinarySearch(int* arr,int len,int v)
{
	int low,high,mid;
	low = 0;
	high = len;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(arr[mid] == v)
			return mid;
		else if(v < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
}
