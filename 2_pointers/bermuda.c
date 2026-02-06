#include <stdio.h>


int go_southeast(int latitude, int longitude){
	/* Since we going southeast decrease lat increase long*/
	latitude--;
	longitude++;
}

int main(){
	int latitude = 32;
	int longitude = -64;
	go_southeast(latitude, longitude);
	printf("Now at: [%i, %i]\n", latitude, longitude);
	return 0;
}
