#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	printf("The value of INT MAX is %i\n", INT_MAX);
	printf("The value of INT_MIN is %i \n", INT_MIN);
	printf("An int takes %i bytes \n", sizeof(int));

	printf("The value of FLT_MAX is %f\n", FLT_MAX);
	printf("The value of flt_min is .50f\n", FLT_MIN);
	printf("A float takes %i bytes\n", sizeof(float));
	return 0;


}
