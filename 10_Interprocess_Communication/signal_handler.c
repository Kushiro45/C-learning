#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void diediedie(int sig){
/* adding a function which gets an integer argument called signal */
	puts("Good bye");
	exit(1);
}

int catch_signal(int sig, void (*handler)(int)){
/* Created a function that accepts the handler function as an argument (here that handler is diediedie function.
 */
	struct sigaction action;
	/* Created an instance of the sigaction struct */
	action.sa_handler = handler;
	/*then we are defining the sa_handler field of action as the handler function that gets passed to the function */
	sigemptyset(&action.sa_mask); /* NON Blocking */
	action.sa_flags = 0; /* no extra flags, default behaviour*/
	return sigaction(sig, &action, NULL);
	/*all of this was done so that we can create a conf for the handler in a struct because kernel needs more than just the handler pointer. then as i said before we are leaving the old conf as NULL*/
}

int main(){
	if (catch_signal(SIGINT, diediedie

}
