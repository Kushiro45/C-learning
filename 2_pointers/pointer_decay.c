#include <stdio.h>

int main(){
	char s[] = "Hello World";
	char *t = s;
	printf(&s == s);
	printf(&t != t);
	return 0;
}
