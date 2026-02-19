#include <stdio.h>

typedef struct {
	floar tank_capacity;
	int tank_psi;
	const char *suit_material;
} equipment

typedef struct scuba{
	const char *name;
	equipment kit;
} diver;

