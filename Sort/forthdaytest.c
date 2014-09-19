#include "Sort.h"

void bubble_sort(int *arr,int len);
int partition(int *arr,int left,int right);
void quick_sort(int *arr,int left,int right);
void insertion_sort(int *arr,int len);
void shell_sort(int *arr,int len);
void heap_sort_fix(int *arr,int len,int i);
void heap_sort(int *arr,int len);
void selection_sort(int *arr,int len);

int main(int argc,char** argv)
{
	pri(arr);
	//bubble_sort(arr,len);
	//quick_sort(arr,0,len - 1);
	//insertion_sort(arr,len);
	//shell_sort(arr,len);
	//heap_sort(arr,len);
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
		for(j = i + 1;j < len;j++)
		{
			if(arr[j] < arr[min])
				min = j;
		}
		if(min != i)
			swap(&arr[i],&arr[min]);
	}
}

void heap_sort(int *arr,int len)
{
	int i;
	for(i = len/2 - 1;i >=0;i--)
	{
		heap_sort_fix(arr,len,i);
	}
	for(i = len - 1;i > 0;i--)
	{
		swap(&arr[0],&arr[i]);
		heap_sort_fix(arr,i,0);
	}
}

void heap_sort_fix(int *arr,int len,int i)
{
	int j,temp;
	temp = arr[i];
	j = i*2 + 1;
	while(j < len)
	{
		if(j + 1 < len && arr[j + 1] > arr[j])
			j++;
		if(arr[j] <= temp)
			break;
		arr[i] = arr[j];
		i = j;
		j = i*2 + 1;
	}
	arr[i] = temp;
}

void shell_sort(int *arr,int len)
{
	int gap,i,j;
	for(gap = len/2;gap > 0;gap /=2)
	{
		for(i = gap;i < len;i++)
		{
			for(j = i - gap;j >= 0 && arr[j] > arr[j + 1];j--)
			{
				swap(&arr[j],&arr[j + 1]);
			}
		}
	}
}

void insertion_sort(int *arr,int len)
{
	int i,j;
	for(i = 1;i < len;i++)
	{
		for(j = i - 1;j >= 0&& arr[j] > arr[j + 1];j--)
		{
			swap(&arr[j],&arr[j + 1]);
		}
	}
}

void quick_sort(int *arr,int left,int right)
{
	int i = partition(arr,left,right);
	if(i - left > 1)
		quick_sort(arr,left,i - 1);
	if(right - i > 1)
		quick_sort(arr,i + 1,right);
}

int partition(int *arr,int left,int right)
{
	int i = (left + right)/2;
	swap(&arr[i],&arr[right]);
	int small = left;
	for(i = left;i < right;i++)
	{
		if(arr[i] < arr[right])
		{
			swap(&arr[i],&arr[small++]);
		}
	}
	swap(&arr[small],&arr[right]);
	return small;
}

void bubble_sort(int *arr,int len)
{
	int i,j;
	for(i = 0;i < len - 1;i++)
	{
		for(j = 0;j < len - 1 - i;j++)
		{
			if(arr[j] > arr[j + 1])
				swap(&arr[j],&arr[j + 1]);
		}
	}
}
