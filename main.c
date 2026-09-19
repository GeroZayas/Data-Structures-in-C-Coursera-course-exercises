#include "stuff.h"
#include <assert.h>
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

int mainArena(void) {
    // Arena my_arena = arena_new();
    // printf("BUFFER %s\n", my_arena.buffer);

    return 0;
}

int main(void) {
    uint8_t amount_people = 3;
    Human  *people        = calloc(amount_people, sizeof(Human));
    people[0].age         = 34;
    people[1].age         = 25;
    people[2].age         = 40;

    for (int i = 0; i < amount_people; i++) {
        printf("PEOPLE %d with NAME %s and AGE %d\n", i, people[i].name, people[i].age);
    }

    assert(people[0].age == 34);

    free(people);

    return 0;
}




