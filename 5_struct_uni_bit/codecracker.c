#include <stdio.h>

typedef struct {
	const char *description;
	float value;
} swag;

typedef struct {
	swag *swag;
	const char *sequence;
}combination;

typedef struct {
	combination numbers;
	const char *make;
} safe;


swag gold = {"GOLD", 1000000.0};
combination numbers = {&gold, "6502"};
safe s = {numbers, "RAMACON250"}

goal to access: GOLD

soln: 
s.numbers.swag->gold


