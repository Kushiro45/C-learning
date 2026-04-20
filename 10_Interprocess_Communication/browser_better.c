#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


void error(char *msg){
	fprintf(stderr, )
}

int main(int argc, char *argv[]){
	char *phrase = argv[1];
	char *vars[] = {"RSS_FEED=https://research.checkpoint.com/feed/", NULL};
	int fd[2];
	if(pipe(fd) == -1){
		error("Cant create the pipe");
	}
	pid_t pid = fork();
	if (pid == -1){
		error("Cant fork process");
	}
	if(!pid){
		dup2(fd[1], 1);
		close(fd[0]);
		if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars) == -1){
			error("cant run script");
		}
	}

}
