#include "Sort.h"

void sort(int* arr,int left,int right);

int main(int argc,char** argv)
{
	printf("Before:\n");
	pri(arr);
	printf("After:\n");
	sort(arr,0,17);
	pri(arr);
	return 0;
}

void sort(int* arr,int left,int right)
{
	int p = (left + right)/2;
	int pivot = arr[p];
	int i = left,j = right;
	while(i<j)
	{
		while(i <= p && arr[i] <= pivot)
			i++;
		if(i < p)
		{
			arr[p] = arr[i];
			p = i;
		}
		while(j >= p && arr[j] >= pivot)
			j--;
		if(j > p)
		{
			arr[p] = arr[j];
			p = j;
		}
	}
	arr[p] = pivot;
	if(p - left > 1)
		sort(arr,left,p-1);
	if(right - p > 1)
		sort(arr,p+1,right);
}
