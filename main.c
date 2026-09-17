#include "stuff.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/*
Structures - Linked List
*/

typedef struct {
    char name[30];
    int  age;
    char adress[50];
} Person;

void print_person(Person *person) {
    printf("PERSON => name=%s age=%d address=%s\n", person->name, person->age, person->adress);
}

int main(void) {
    Person    gero  = {"Gero", 35, "Barcelona City"};
    Person    mar   = {"Mar", 35, "L'Example"};
    Person    elisa = {"Elisa", 60, "Holguin"};
    Person    people[3];
    size_t    len_array;
    short int i;

    print_person(&gero);
    people[0] = gero;
    people[1] = mar;
    people[2] = elisa;

    len_array = sizeof(people) / sizeof(people[0]);
    for (i = 0; i < len_array; i++) {
        print_person(&people[i]);
    }

    return 0;
}