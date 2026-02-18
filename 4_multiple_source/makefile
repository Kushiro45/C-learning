encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c

message_hider.o: message_hider.c encrypt.h
	gcc -c message_hider.c

message_hider: encrypt.o message_hider.o
	gcc message_hider.o encrypt.o -o message_hider
