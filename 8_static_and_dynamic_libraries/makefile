#security program for bank
encrypt.o: encrypt.c 
	gcc -c encrypt.c

checksum.o: checksum.c 
	gcc -c checksum.c

libhfsecurity.a: encrypt.o checksum.o
	ar -rcs libhfsecurity.a encrypt.o checksum.o

bank_security_prog: bank_security_prog.c libhfsecurity.a 
	gcc bank_security_prog.c -I . -L . -lhfsecurity -o bank_security_prog


#program for the gym
hfcal.o: hfcal.c
	gcc -c hfcal.c -I ./includes

elliptical.o: elliptical.c hfcal.o
	gcc -c elliptical.c -I ./includes

libhfcal.a: hfcal.o
	ar -rcs ./libs/libhfcal.a hfcal.o

elliptical: elliptical.o libhfcal.a
	gcc elliptical.o -I ./includes -L ./libs -lhfcal -o elliptical

