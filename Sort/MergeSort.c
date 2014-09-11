#include "Sort.h"

void merge_sort(int *list, int list_size);
void merge_array(int *list1, int list1_size, int *list2, int list2_size);

int main(int argc,char** argv)
{
	printf("Before merge sort:\n");
	pri(arr);
	printf("After:\n");
	merge_sort(arr,len);
	pri(arr);
	return 0;
}

void merge_sort(int *list,int list_size)
{
	if(list_size > 1)
	{
		int *list1 = list;
		int list1_size = list_size/2;
		int *list2 = list + list1_size;
		int list2_size = list_size - list1_size;

		merge_sort(list1,list1_size);
		merge_sort(list2,list2_size);
		merge_array(list1,list1_size,list2,list2_size);
	}
}

void merge_array(int *list1,int list1_size,int *list2,int list2_size)
{
	int i = 0,j = 0,k = 0;
	int m;
	int *list = (int*)malloc(sizeof(int)*(list1_size + list2_size));
	while(i < list1_size && j < list2_size)
	{
		list[k++] = list1[i] < list2[j] ? list1[i++] : list2[j++];
	}
	while(i < list1_size)
	{
		list[k++] = list1[i++];
	}
	while(j < list2_size)
	{
		list[k++] = list2[j++];
	}
	for(m = 0;m < list1_size + list2_size;m++)
	{
		list1[m] = list[m];
	}
	free(list);
}
