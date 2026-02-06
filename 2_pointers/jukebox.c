#include <stdio.h>
#include <string.h>

char tracks[][80] = {
	"Connor: Now",
	"Lost: Markus",
	"Alive: Kara",
};  /* Defining it outside of any fun so that its global and can be accessed everywhere */

void find_track(char search_for[]){
	int i;
	for(i = 0; i < 3; i++){
		if(strstr(tracks[i], search_for))
			printf("Track %i: '%s'\n", i, tracks[i]);
	}
}

int main(){
	char search_for[80];
	printf("Search for: ");
	fgets(search_for, 80, stdin);
	search_for[strcspn(search_for, "\n")] = '\0'; /* since the output of fgets will be something like "input\n\0" we dont need the \n hence we use this, check stringfun.txt for more info*/
	find_track(search_for);
	return 0;
}
