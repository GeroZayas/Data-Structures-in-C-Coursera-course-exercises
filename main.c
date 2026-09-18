#include "stuff.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Example and code by gingerBill here (https://www.gingerbill.org/article/2019/02/08/memory-allocation-strategies-002/)
*/

char  *arena_buffer;
size_t arena_buffer_length;
size_t arena_offset;

void *arena_alloc(size_t size) {
    /* Check to see if the backing memory has space left*/
    if (arena_offset + size <= arena_buffer_length) {
        void *ptr = &arena_buffer[arena_offset];
        arena_offset += size;
        /* Zero new memory by default*/
        memset(ptr, 0, size);
        return ptr;
    }
    /* Return NULL if the areba is out of memory */
    return NULL;
}

int main(void) {
    return 0;
}
