#include <stdio.h>

enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};
typedef struct{
	char *name;
	enum response_type type;
}response;



void dump(response r){
	printf("Dear %s, \n", r.name);
	puts("DUMPPPPEED");
}

void second_chance(response r){
	printf("Dear %s, \n", r.name);
	puts("see you again");
}

void marriage(response r){
	printf("Dear %s, \n", r.name);
	puts("guess you are stuck with me");
}

void (*replies[])(response) = {dump, second_chance, marriage};

/* main from before
int main(){
	response r[] = {
		{"Mike", DUMP}, {"LUIS", SECOND_CHANCE}, {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
	};
	int i;
	for(i=0;i<4;i++){
		switch(r[i].type){
			case DUMP:
				dump(r[i]);
				break;
			case SECOND_CHANCE:
				second_chance(r[i]);
				break;
			default:
				marriage(r[i]);
		}

	}
	return 0;
}
*/


int main(){
	response r[] = {
                {"Mike", DUMP}, {"LUIS", SECOND_CHANCE}, {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
        };
	int i;
	for(i=0; i<4; i++){
		replies[r[i].type](r[i]);
	}
}
