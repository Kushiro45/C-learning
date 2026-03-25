#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char buffer[400];
	fgets(buffer, 400, stdin);
	printf(buffer);
	puts("");
	strdup(buffer);
	exit(0);
}

