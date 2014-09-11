#include "Sort.h"

void merge_sort(int *arr,int len);
void merge_array(int *arr1,int len1,int *arr2,int len2);

int main(int argc,char** argv)
{
	pri(arr);
	merge_sort(arr,len);
	pri(arr);
	return 0;
}

void merge_sort(int *arr,int len)
{
	if(len > 1)
	{
		int *arr1 = arr;
		int len1 = len/2;
		int *arr2 = arr + len1;
		int len2 = len - len1;

		merge_sort(arr1,len1);
		merge_sort(arr2,len2);
		merge_array(arr1,len1,arr2,len2);
	}
}

void merge_array(int *arr1,int len1,int *arr2,int len2)
{
	int i,j,k;
	int x;
	i = j = k = 0;
	int *list = (int*)malloc(sizeof(int)*(len1 + len2));
	while(i < len1 && j < len2)
	{
		list[k++] = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
	}
	while(i < len1)
	{
		list[k++] = arr1[i++];
	}
	while(j < len2)
	{
		list[k++] = arr2[j++];
	}
	for(x = 0;x < len1 + len2;x++)
	{
		arr1[x] = list[x];
	}
	free(list);
}
