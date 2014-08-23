#include "BitTree.h"

int main(int argc,char* argv[])
{
	Tree T;
	T = Insert(5,T);
	T = Insert(3,T);
	T = Insert(2,T);
	T = Insert(4,T);
	T = Insert(6,T);
	T = Insert(7,T);
	printf("Max = %d\n",FindMax(T));
	printf("Minimum = %d\n",FindMin(T));
	printf("PreOrder:\n");
	preOrder(T);
	printf("\n");
	printf("InOrder:\n");
	inOrder(T);
	printf("\n");
	printf("PostOrder:\n");
	postOrder(T);
	printf("\n");
	return 0;
}
