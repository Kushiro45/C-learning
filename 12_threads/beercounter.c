#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>

int beers = 2000000;
/*global variable saving 2Mil*/

void* drink_lots(void *a){
	int i;
	for(i = 0; i < 100000; i++){
		beers = beers - 1;
	}
	return NULL;
}
/* a function which will return avoid pointer and accepts a void pointer, decreases beer count by 100000 */

void error(char *msg){
	printf("Error %s:%s", msg, strerror(errno));
}

int main(){
	pthread_t threads[20];
	int t;
	printf("%i bottles of beer on the wall\n %i bottles of beer\n", beers, beers);
	for(t = 0; t < 20; t++){
		if(pthread_create(&threads[t], NULL, drink_lots, NULL) == -1)
			error("Couldnt create thread");
	}
	/*idea is if each time drink_lots function decreases the global var by 100000 so if we do it 20 times it should technically give us 0 when we print the beers again but it sometimes doesnt, since theres no mutex in this code  */

	void* result;
	for(t = 0; t < 20; t++){
		pthread_join(threads[t], &result);
	}
	printf("There are now %i bottles of beer on the wall\n", beers);
	return 0;
}

