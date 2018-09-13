#include<stdio.h>
#include<stdlib.h>
#include"config.h"

#ifdef USE_MYMATH
#include "math/MathAdd.h"
#else

#endif

int main(int argc,char *argv[])
{
	if(argc < 3){
		printf("Usage:%s num1 num2\n",argv[0]);
		return 1;
	}

	double a = atof(argv[1]);
	double b = atof(argv[2]);
#ifdef USE_MYMATH
	double sum = add(a,b);
	printf("%g + %g = %g\n",a,b,sum);
#else
	double sum = a*b;
	printf("%g * %g = %g\n",a,b,sum);
#endif
	return 0;
}
