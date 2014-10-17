#include "Stack.h"

int main(int argc,char* argv[])
{
	char* str = "5+8*(3-2)-6/2";
	printf("calculate str:%s\n",str);
	printf("result is %d.\n",ExpEvaluation(str));
	return 0;
}
