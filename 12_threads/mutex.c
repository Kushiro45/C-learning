/*This will mostly be showing two different ways to use mutexes */

/* VER 1 */
pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
void* drink_lots(void *a){
	int i;
	pthread_mutex_lock(&beers_lock);
	for(i = 0; i < 100000; i++){
		beers = beers - 1;
	}
	pthread_mutex_unlock(&beers_lock);
	printf("beers = %i\n", beers);
	return NULL;
}
/*a better version since one thread is locked until it is done with its complete thing and then unlocked and next thread is locked, here the threads function serially one after the another and yet this is faster than the second version, so 20 locks and 20 unlocks*/


/* VER 2 */

pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
void* drink_lots(void *a){
	int i;
	for(i = 0; i < 100000; i++){
		pthread_mutex_lock(&beers_lock);
		beers = beers - 1;
		pthread_mutex_unlock(&beers_lock);
	}
	printf("beers = %i\n", beers);
	return NULL;
}


/* In second version, the thread will be locked and unlocked for every subtraction so itll be locked and unlocked 2 mil times, which increases a lot of overhead, obviously, in this case any thread will do this in any order*/

