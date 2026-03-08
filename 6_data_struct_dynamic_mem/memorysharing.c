#include <stdio.h>
#include <stdlib.h>

int main() {
    char *a = malloc(100);
    char *b = malloc(100);

    free(a);

    char *c = malloc(100);

    printf("%p %p\n", a, c);
}
