#include "stuff.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
You will extend the previous assignment with list_add() and list_find() and add a function called list_delete() that
will find and remove the node containing the integer value if it is in the list.

*/

typedef struct lnode {
    int           value;
    struct lnode *next;
} lnode;

typedef struct list {
    lnode *head;
    lnode *tail;
} list;

void list_add(struct list *lst, int value) {
    lnode  new_node = {.value = value, .next = NULL};
    lnode *ptr_node = (lnode *)malloc(1 * sizeof(lnode));
    *ptr_node       = new_node;
    if (lst->head == NULL) {
        lst->head = ptr_node;
        lst->tail = ptr_node;
    } else {
        lst->tail->next = ptr_node;
        lst->tail       = ptr_node;
    }
}

struct lnode *list_find(struct list *lst, int value) {
    for (lnode *node = lst->head; node != NULL; node = node->next) {
        if (node->value == value) {
            return node;
        }
    }
    return NULL;
}

void list_remove(struct list *lst, int value) {
    /* Remove the value from the linked list. */
    // traverse the linked listchecking for values, if value found
    // change the ->next from prev node to the -> next of node with value
    // struct lnode *temp; 
    for (lnode *cur = lst->head; cur->next != NULL; cur = cur->next){
        // temp = cur;
        if(cur->value == value){
            printf("list_remove => VALUE FOUND %d\n", cur->value);
        } else if(cur->next->value == value){
            printf("hey %d\n", cur->value);
        }
    }
}

void list_dump(struct list *lst) {
    printf("\nDump:\n");
    for (lnode *cur = lst->head; cur != NULL; cur = cur->next) {
        printf("  %d\n", cur->value);
    }
}

int main(int argc, char **argv) {
    struct list   mylist;
    // struct lnode *mynode;

    mylist.head = NULL;
    mylist.tail = NULL;

    list_add(&mylist, 10);
    list_add(&mylist, 20);
    list_add(&mylist, 30);
    list_dump(&mylist);

    list_remove(&mylist, 42); // <------------

    list_remove(&mylist, 10); // <------------
    list_dump(&mylist);

    list_remove(&mylist, 30); // <------------
    list_dump(&mylist);

    list_add(&mylist, 40);
    list_dump(&mylist);
    return 0;
}
