#include <stdio.h>

int main(){
	int x = 100;
	int *addr_x = &x;
	int y = *addr_x;
	*addr_x = 10;
	printf("x -> %i, y => %i", x, y);

}
