#include "stuff.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Structures - Linked List
*/
#define MAXLINE 1000

typedef struct lnode {
    char         *text;
    struct lnode *prev;
    struct lnode *next;
} lnode;

int main(void) {
    lnode *head = NULL;
    lnode *tail = NULL;
    lnode *current;
    char   line[MAXLINE];

    while (fgets(line, MAXLINE, stdin) != NULL) {
        char *save = (char *)malloc(strlen(line) + 1); // void * -> char *
        strcpy(save, line);

        lnode *new = (lnode *)malloc(sizeof(lnode)); // void * -> lnode *
        new->text  = save;
        new->next  = NULL;
        new->prev  = tail;

        if (tail != NULL) {
            tail->next = new;
        }

        tail = new;
    }

    return 0;
}

/*
 |
`'´
tail NULL
new.next = NULL
new.prev = NULL

tail = new
----
new2.next = NULL
new2.prev = new

new.next = new2

tail = new2
----
*/
