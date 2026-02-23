#include <stdio.h>

typedef struct {
	float weight;
	int count;
}cupcake;

int main(){
	cupcake order = {2};
	printf("Cupcake quantity: %i\n", order.count);
	return 0;
}
