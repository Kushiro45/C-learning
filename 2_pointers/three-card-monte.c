#include <stdio.h>

int main(){
	char *cards = "JQK";  /* initialise a pointer to the string JQK*/
	char a_card = cards[2]; /* a_cards = K */
	cards[2] = cards[1];	/* cards[2] = Q, JQQ*/
	cards[1] = cards[0];	/* cards[1] = J, JJQ */
	cards[0] = cards[2];	/* cards[0] = Q, QJQ */
	cards[2] = cards[1];	/* cards[2] = J, QJJ*/
	cards[1] = a_card;	/* cards[1] = K, QKJ*/
	puts(cards);
	return 0;

}



