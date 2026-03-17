#include <stdio.h>
#include <stdarg.h>

enum drink{
	MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

double price(enum drink d){
	switch(d){
		case MUDSLIDE:
			return 6.79;
		case FUZZY_NAVEL:
			return 5.31;
		case MONKEY_GLAND:
			return 4.82;
		case ZOMBIE:
			return 5.89;
	}
}

double total(int args, ...){
	double total = 0;
	va_list tot;
	va_start(tot, args);
	int i;
	for(i=0; i<args; i++){
		total += price(va_arg(tot, drink));
	}
	va_end(tot);
	return total;
}

int main(){
	printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
}
