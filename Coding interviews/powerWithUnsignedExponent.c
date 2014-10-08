#include <stdio.h>

double powerWithUnsignedExponent(double base,unsigned int exponent);

int main(int argc,char** argv)
{
	printf("pow(2,4) = %lf\n",powerWithUnsignedExponent(2,4));
	return 0;
}

double powerWithUnsignedExponent(double base,unsigned int exponent)
{
	if(exponent == 0)
		return 1;
	if(exponent == 1)
		return base;
	
	double result = powerWithUnsignedExponent(base,exponent >> 1);
	result *= result;
	if(exponent & 0x1 == 1)
		result *= base;
	return result;
}
