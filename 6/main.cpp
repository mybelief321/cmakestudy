#include<stdio.h>
#include<stdlib.h>
#include"config.h"

#ifdef HAVE_ADD

#else
#include "math/MathAdd.h"
#endif

int main(int argc,char *argv[])
{
	if(argc < 3){
		printf("Usage:%s num1 num2\n",argv[0]);
		return 1;
	}

	double a = atof(argv[1]);
	double b = atof(argv[2]);
#ifdef HAVE_ADD
	double sum = a*b;
	printf("%g * %g = %g\n",a,b,sum);
#else
	double sum = add(a,b);
	printf("%g + %g = %g\n",a,b,sum);
#endif
	return 0;
}
