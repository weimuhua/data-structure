#include "Sort.h"

int Partition(int *arr,int left,int right);
void quicksort(int *arr,int left,int right);

int main(int argc,char** argv)
{
	pri(arr);
	printf("QuickSort:\n");
	quicksort(arr,0,17);
	pri(arr);
	return 0;
}

int Partition(int *arr,int left,int right)
{
	int i = (left + right)/2;
	int small = left;
	swap(&arr[i],&arr[right]);
	for(i = left;i<right;i++)
	{
		if(arr[i] < arr[right])
		{
			swap(&arr[i],&arr[small]);
			small++;
		}
	}
	swap(&arr[small],&arr[right]);
	small++;
	return small;
}

void quicksort(int *arr,int left,int right)
{
	int index = Partition(arr,left,right);
	if(index - left > 1)
		quicksort(arr,left,index - 1);
	if(right - index > 1)
		quicksort(arr,index + 1,right);
}
