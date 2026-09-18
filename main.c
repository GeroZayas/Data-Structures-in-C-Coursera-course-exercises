#include "stuff.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Example and code by gingerBill here (https://www.gingerbill.org/article/2019/02/08/memory-allocation-strategies-002/)
*/
typedef struct {
    uint8_t *buffer;   // the actual bytes
    size_t   capacity; // numbers describing those bytes
    size_t   offset;

} Arena;

uint8_t buffer[1000];

Arena arena_new(void) {
    Arena arena = {.buffer = buffer, .capacity = 1000, .offset = 0};
    return arena;
}

typedef struct {
    char    name[20];
    char    address[50];
    uint8_t age;
} Human;

// void *arena_alloc(Arena *arena, size_t size, size_t count){
//     size_t cap = arena->capacity;
//     size_t offset = arena->offset;
//     size_t available_space = cap - offset;
//     size_t mem_needed = size * count;
//     if (available_space >= mem_needed){

//     } else {
//         printf("ARENA IS FULL. NOT ASSIGNMENT IS POSSIBLE");
//     }

// }
void *arena_free(Arena *arena);

void *print_human_properties(Human *human) {
    printf("NAME        = %s\n", human->name);
    printf("ADDRESS     = %s\n", human->address);
    printf("AGE         = %d\n", human->age);
    return 0;
}

int main(void) {
    // Arena my_arena = arena_new();
    // printf("BUFFER %s\n", my_arena.buffer);
    Human maca = {"Mar", "Barcelona City", 35};

    print_human_properties(&maca);

    Human *gero = calloc(1, sizeof(Human));
    strcpy(gero->name, "Gero");
    strcpy(gero->address, "BCN TOO");
    gero->age = 34;

    print_human_properties(gero);

    return 0;
}
