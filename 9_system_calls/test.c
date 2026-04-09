#include <string.h>
#include <stdio.h>
#include <errno.h>
int main(int argc, char *argv[]){


	fprintf(stderr, "Can't create order: %s \n", strerror(errno));
		return 1;
	}
	return 0;
}

