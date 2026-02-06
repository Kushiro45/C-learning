
#include  <stdio.h>

int main(){
	char x[] = "Hello World";
	char *p = x;
	printf("The first character in the string is: %c and %i is the size of the pointer p \n", *p, sizeof(p));

	int y[] = {1, 2, 3};
	int *t = y;
	printf("The first element is %i, and size of pointer is %i \n, and the address is %p", *t, sizeof(t), t);
	printf("The next element is %i and address is %p", *(t+1), t+1);


	return 0;
}
