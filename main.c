#include "stuff.h"
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
    Person gero = {"Gero", 35, "Barcelona City"};
    print_person(&gero);
    return 0;
}
