#include  <stdio.h>
#include "encrypt.h"
/*just adding a comment*/
int main(){
	char msg[80];
	while(fgets(msg, 80, stdin)){
		encrypt(msg);
		printf("%s", msg);
	}

	while(fgets(msg, 80, stdin)){
		encrypt(msg);
		printf("%s", msg);
	}

}
