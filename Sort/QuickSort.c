#include "Sort.h"

int Partition(int data[],int start,int end);
void QuickSort(int data[],int start,int end);

int main(int argc,char* argv[])
{
	pri(arr);
	printf("QuickSort:\n");
	QuickSort(arr,0,17);
	pri(arr);
	return 0;
}

int Partition(int data[],int start,int end)
{
	int index = (start + end)/2;
	swap(&data[index],&data[end]);
	int small = start - 1;
	for(index = start;index < end;index++)
	{
		if(data[index] < data[end])
		{
			small++;
			if(small != index)
			{
				swap(&data[index],&data[small]);
			}
		}
	}
	++small;
	swap(&data[small],&data[end]);
	return small;
}

void QuickSort(int data[],int start,int end)
{
	int index = Partition(data,start,end);
	if(index > start)
		QuickSort(data,start,index - 1);
	if(index < end)
		QuickSort(data,index + 1,end);
}
