#include <stdio.h>

struct exercise {
	const char *description;
	float duration;
};

struct meal {
	const char *ingredients;
	float weight;
};

struct preferences{
	struct meal food;
	struct exercise exsercise;
};

struct fish{
	const char *name;
	const char *species;
	int teeth;
	int age;
	struct preferences care;

}
