#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void error(char *msg){
	printf("Error: %s -- %s", msg, strerror(errno));
	exit(1);
}


int main(int argc, char *argv[]){
	char *advice[] = {
		"Take Smaller bites\r\n",
		"Go for the tight jeans. No they do NOT make you look fat. \r\n",
		"Dont go for the girl you like, go for the girl who likes you\r\n",
		"You might wanna consider getting that cool bike\r\n"
	};
	int listener_d = socket(PF_INET, SOCK_STREAM, 0);
	int reuse = 1;
	if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *) &reuse, sizeof(int)) == -1)
		error("Cant set the reuse option on the socket");
	if(listener_d == -1)
		error("Cannot create listener socket");
	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(30000);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(listener_d, (struct sockaddr *) &name, sizeof(name)) == -1 )
		error("Can't bind the port");

	if(listen(listener_d, 10) == -1)
		error("unable to listen on the port");
	puts("Waiting for connection");
while(1){
	struct sockaddr_storage client_addr;
	unsigned int address_size = sizeof(client_addr);
	int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &address_size);
	char *msg = advice[rand() % 5];
	if(send(connect_d, msg, strlen(msg), 0) == -1)
		error("unable to send message");
	close(connect_d);
	}
	return 0;
}
