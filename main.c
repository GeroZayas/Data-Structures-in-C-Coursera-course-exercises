#include "stuff.h"
#include <_locale_posix2008.h>
#include <_string.h>
#include <_time.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
You will write a function list_add() to append an integer to the end of a linked list.
You will also write a function called list_find() that will return the list node containing the integer value or NULL if
the value is not in the list.
*/

typedef struct lnode {
    int           value;
    struct lnode *next;
} lnode;

typedef struct list {
    lnode *head;
    lnode *tail;
} list;

/*
new_node {10, NULL}
my_list->head = new_node
my_list->tail = new_node

my_list->head->next = new_node;
my_list->tail = new_node;
*/

void list_add(struct list *lst, int value) {
    lnode  new_node = {.value = value, .next = NULL};
    lnode *ptr_node = (lnode *)calloc(1, sizeof(lnode));
    *ptr_node       = new_node;
    if (lst->head == NULL) {
        lst->head = ptr_node;
        lst->tail = ptr_node;
    } else {
        lst->head->next = ptr_node;
        lst->tail       = ptr_node;
    }
}

struct lnode *list_find(struct list *lst, int value) {
    for (lnode *node = lst->head; node->next != NULL; node = node->next) {
        printf("VALUE %d\n", node->value);
    }
    return NULL;
}

void list_dump(struct list *lst) {
    printf("\nDump:\n");
    for (lnode *cur = lst->head; cur != NULL; cur = cur->next) {
        printf("  %d\n", cur->value);
    }
}

int main(int argc, char **argv) {
    struct list   mylist;
    struct lnode *mynode;

    mylist.head = NULL;
    mylist.tail = NULL;

    list_add(&mylist, 10);
    list_add(&mylist, 20);
    list_add(&mylist, 30);

    list_dump(&mylist);

    mynode = list_find(&mylist, 42);
    if (mynode == NULL) {
        printf("Did not find 42\n");
    } else {
        printf("Looked for 42, found %d\n", mynode->value);
    }

    mynode = list_find(&mylist, 30);
    if (mynode == NULL || mynode->value != 30) {
        printf("Did not find 30\n");
    } else {
        printf("Found 30\n");
    }

    list_add(&mylist, 40);
    list_dump(&mylist);
    return 0;
}
