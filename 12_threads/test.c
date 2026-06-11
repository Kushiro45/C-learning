void* do_stuff(void* param)
{
	long thread_no = (long)param;
	/*creating a long variable and saving typecasted value of the void param into this long var*/
	printf("Thread number %ld\n", thread_no);
	return (void*)(thread_no + 1);
	/*returning the value again after adding 1 to it and typecasting it again as void ptr*/
}

int main(){
	pthread_t threads[20];
	long t;
	for(t = 0; t < 3; t++){
		pthread_create(&threads[t], NULL, do_stuff, (void*)t)
		/*doing this the roundabout way since threas only understand and deal with void pointers*/
	}
	void *result;
	for (t = 0; t < 3; t++){
		pthread_join(threads[t], &result);
		printf("Thread %ld returned %ld\n", t, (long)result);
		/*finally typecasting the value again to long to print*/
	}
	return 0;
}


