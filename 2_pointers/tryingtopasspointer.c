#include <stdio.h>


void array_size(char t){
	printf("%i bytes for t  in function", sizeof(t));
}

int main(){
	char s[] = "How big is it?";
	char *t = s;
	printf("size of array 's' %i\n", sizeof(s));
	array_size(*t); /* Dereferencing, will pass the value at pointer address stored in t. i.e. "H" then it gets passed to sizeof operator which gives 1 byte the size of char datatype*/
}

