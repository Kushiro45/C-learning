#include <stdio.h>

typedef union {
	short count;
	float weight;
	float volume;
} quantity;


typedef struct{
        const char *name;
        const char *country;
        quantity amount; 
} fruit_order;

int main(){
	fruit_order apples = {"apples", "England", .amount.weight=4.2};
}


