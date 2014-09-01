#include <stdio.h>

int find(int* matrix,int rows,int columns,int number)
{
	int found=0;
	int row=0;
	int column=columns-1;
	if(matrix!=NULL && rows>0 && columns>0)
	{
		while(row<rows && column>0)
		{
			if(matrix[row*columns + column] == number)
			{
				found = 1;
				break;
			}
			else if(matrix[row*columns + column] > number)
				--column;
			else
				++row;
		}
	}
	return found;
}

int main(int argc,char** argv)
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	int result=0;
	result=find((int*)matrix, 4, 4, 7);
	if(result==1)
		printf("passed.\n");
	else
		printf("failed.\n");
	return 0;
}
