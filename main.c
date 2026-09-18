#include "stuff.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Structures - Linked List
*/
#define MAXLINE 1000
#define String char *

typedef struct lnode {
    String        text;
    struct lnode *prev;
    struct lnode *next;
} lnode;

int main(void) {
    lnode *head;
    lnode *tail;
    lnode *current;
    lnode *new;
    char   line[MAXLINE];
    head = NULL;
    tail = NULL;

    while (fgets(line, MAXLINE, stdin) != NULL) {
        char *save = (char *)malloc(strlen(line) + 1); /* void * -> char * */
        strcpy(save, line);

        new       = (lnode *)malloc(sizeof(lnode)); /* void * -> lnode * */
        new->text = save;
        new->next = NULL;
        new->prev = tail;

        if (head == NULL) {
            head = new;
        }

        if (tail != NULL) {
            tail->next = new;
        }

        tail = new;
    }

    for (current = tail; current != NULL; current = current->prev) {
        printf("%s", current->text);
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
