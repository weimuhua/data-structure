#include <stdio.h>

static char string[] = "We are happy";

void ReplaceBlank(char string[],int length)
{
	if(string == NULL || length <= 0)
		return;
	
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	int newLength = 0;
	int indexOfOriginal,indexOfNew;
	while(string[i] != '\0')
	{
		++originalLength;
		if(string[i] == ' ')
			++numberOfBlank;
		++i;
	}
	newLength = originalLength + 2*numberOfBlank;
	if(newLength > length)
		return;
	indexOfOriginal = originalLength;
	indexOfNew = newLength;

	while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if(string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}

int main(int argc,char** argv)
{
	printf("Original string:%s\n",string);
	ReplaceBlank(string,30);
	printf("replace blank:%s\n",string);
	return 0;
}
