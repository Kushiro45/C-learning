#include <stdio.h>

void go_southeast(int *lat, int *lon){
	*lat = *lat - 1;
	*lon = *lon + 1;

}

int main(){
	int latitude = 32;
	int longitude = -64;

	go_southeast(&latitude, &longitude);
	printf("Now at %i, %i", latitude, longitude);
	return 0;
}
