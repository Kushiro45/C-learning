#include <stdio.h>

int main(){
	char food[5];
	printf("Enter your fav food: ");
	fgets(food, sizeof(food), stdin);
	printf("your fav food is: %s", food);
}
