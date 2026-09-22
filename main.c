#include "stuff.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GERO "GEROOOO"
#define ELIZABETH "GERO"

int main(int argc, char **argv) {
    int res = strcmp(GERO, ELIZABETH);
    printf("RES = %d\n", res);
    return 0;
}