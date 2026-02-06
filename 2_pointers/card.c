/*
* Program to evaluate face values.
* Released under the Vegas Public License.
* (c)2014 The College Blackjack Team.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	char card_name[3];
	int val = 0;
	int count = 0;
	while(card_name[0] != 'X'){
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
	
		switch(card_name[0]){
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			puts("Exiting");
			continue;
		default:
			val = atoi(card_name);
			if (val < 1 || val > 10){
					puts("Wrong value");
					continue;
				}
			else
				break;
		}
		printf("The card value is: %i\n", val);
	/* checking for low card value */
		if (val >= 3 && val <= 6){
			puts("count has gone up");
			count++;
		}
	/* if val = 10 */
		else if (val == 10){
			puts("count has gone down");
			count--;
		}
		printf("Current count: %i\n", count);
	}
	return 0;
}
