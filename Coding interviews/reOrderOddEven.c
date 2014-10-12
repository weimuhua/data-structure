#include <stdio.h>
//给定一个数组，将所有奇数放到偶数之前
void reOrderOddEven(int *arr,int len);
void pri(int *arr);
int arr[] = {98,76,109,34,67,190,80,12,14,89,1,23,33,65,567,233,190,12};
int len = 18;

int main(int argc,char** argv)
{
	pri(arr);
	reOrderOddEven(arr,len);
	pri(arr);
	return 0;
}

void reOrderOddEven(int *arr,int len)
{
	if(arr == NULL || len == 0)
		return;
	int *begin = arr;
	int *end = arr + len;
	int temp;
	while(begin < end)
	{
		while(begin < end && (*begin & 0x1) != 0)
			begin++;
		while(end > begin && (*end & 0x1) == 0)
			end--;
		if(begin < end)
		{
			temp = *begin;
			*begin = *end;
			*end = temp;
		}
	}
}

void pri(int* arr)
{
	int i;
	for(i = 0;i<len;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
}
