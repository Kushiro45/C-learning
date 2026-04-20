#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


void error(char *msg){
	fprintf(stderr, "%s:%s", msg, strerror(errno));
}

void open_url(char *url){
	char launch[255];
	sprintf(launch, "cmd /c start %s", url);
	system(launch);
	sprintf(launch, "x-www-browser '%s' &", url);
	system(launch);
	sprintf(launch, "open '%s'", url);
	system(launch);
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
		if (execle("/usr/bin/python", "/usr/bin/python", "./rssfeed.py", "-u", phrase, NULL, vars) == -1){
			error("cant run script");
		}
	}
	dup2(fd[0], 0);
	close(fd[1]);
	char line[255];
	while (fgets(line, 255, stdin)){
		if(line[0] == '\t')
			open_url(line + 1 );
	}
	return 0;

}
