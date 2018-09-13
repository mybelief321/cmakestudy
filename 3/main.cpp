#include<stdio.h>
#include<stdlib.h>
#include "math/MathAdd.h"

int main(int argc,char *argv[])
{
	if(argc < 3){
		printf("Usage:%s num1 num2\n",argv[0]);
		return 1;
	}

	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double sum = add(a,b);
	printf("%g + %g = %g\n",a,b,sum);
	return 0;
}
