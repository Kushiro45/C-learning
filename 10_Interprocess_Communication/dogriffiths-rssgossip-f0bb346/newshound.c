#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char *feeds[] = {"https://research.checkpoint.com/feed/", "https://securelist.com/feed/", "https://unit42.paloaltonetworks.com/feed/", "https://www.mandiant.com/resources/blog/rss.xml"}; 
	int times = 4;
	char *phrase = argv[1];
	int i;
	for(i = 0; i < times; i ++){
		char var[255];
		sprintf(var, "RSS_FEED=%s", feeds[i]);
		char *RSS_FEED[] = {var, NULL};
		pid_t pid = fork();
		if(pid == -1){
			fprintf(stderr, "Cant fork process: %s\n", strerror(errno));
			return 1;	
		}
		
		if(!pid){
			if(execle("/usr/bin/python", "/usr/bin/python", "./rssfeed.py", phrase, NULL, RSS_FEED) == -1){
				fprintf(stderr, "Can't run script: %s\n", strerror(errno));	
		
			return 1;
			}
		}
	}
	return 0;

}
