#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>


void error(char *msg){
	fprintf(stderr, "%s: %s", msg, strerror(errno));
}

int main(int argc, char *argv[]){
	char *phrase = argv[1];
	char *vars[] = {"RSS_FEED=https://research.checkpoint.com/feed/", NULL};
	FILE *f = fopen("stories.txt", "w");
	if(!f){
		error("Cant open stories.txt");
	}
	pid_t pid = fork();
	int pid_status;
	if (waitpid(pid, &pid_status, 0) == -1){
		error("Error waiting for child process");
	}
	if(pid == -1){
		if(dup2(fileno(f), 1) == -1){
			error("Cant redirect to Standard Output");
		}
		if(execle("/usr/bin/python", "/usr/bin/python", "../dog*/rssfeed.py", phrase, NULL, vars) == -1){
			error("Cant run Script");
		}
	}
	return 0;

}
