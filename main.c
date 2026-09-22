#include "stuff.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GERO "GERO"
#define ELIZABETH "ELIZABETH"

int main(int argc, char **argv) {
    int res = strcmp(GERO, ELIZABETH);
    printf("RES = %d\n", res);
    return 0;
}