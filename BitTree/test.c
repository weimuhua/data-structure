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
	T = Insert(1,T);
	printf("findMaxHeight = %d\n",findMaxHeight(T));
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
	printf("find the lowest ancestor between 1 and 7:\n");
	printf("%d\n",findLowestAncestor(T,1,7));
	return 0;
}
