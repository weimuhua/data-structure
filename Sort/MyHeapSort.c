#include "Sort.h"

void MaxHeapFix(int *arr,int len,int i);
void HeapSort(int *arr,int len);

int main(int argc,char** argv)
{
	printf("Before:\n");
	pri(arr);
	HeapSort(arr,len);
	printf("After:\n");
	pri(arr);
	return 0;
}

void MaxHeapFix(int *arr,int len,int i)
{
	int j,temp;
	temp = arr[i];
	j = i*2 + 1;
	while(j < len)
	{
		if(j + 1< len && arr[j + 1] > arr[j])
			j++;
		if(arr[j] <= temp)
			break;
		arr[i] = arr[j];
		i = j;
		j = i*2 + 1;
	}
	arr[i] = temp;
}

void HeapSort(int *arr,int len)
{
	int i;
	//从最后一个非终端结点开始建堆
	for(i = len/2 - 1;i >= 0;i--)
	{
		MaxHeapFix(arr,len,i);
	}
	for(i = len - 1;i >= 1;i--)
	{
		swap(&arr[i],&arr[0]);
		MaxHeapFix(arr,i,0);
	}
}
