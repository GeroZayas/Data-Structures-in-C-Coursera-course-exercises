#include "stuff.h"
/*#include <stdbool.h>*/
#include <stdio.h>
#include <string.h>

/*
This is a subset of an important concept in Computer Science called a Turing Machine.
We call it a "Touring Machine" because it "wanders around and does things in memory" similar to a
Turing Machine. Your computer has 256 characters of memory. The machine keeps track of the
"position" or the "head" where data is to be written. The starting position is zero. You are to read
a sequence of instructions from input and perform those instructions. When there are no more
instructions, print the memory out as a zero-terminated C character array All of the numbers should
be in the range of 0-255 so they fit into a C char variable.
42     Store this value into the memory at the current position
>      Move the "position" one to the right (i.e. position++);
<      Move the "position" one to the left (i.e. position--);
 */

void get_and_put_char(void) {
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

/*
We do all the proper initialization.
We open the while loop. We start getting whatever characters the user inputs.
We check if the char is EOF.
If it's not, then we check if it is a digit between 0 and 9.
When you do digit char - '0' you get the digit in int mode.
Then we use that int digit as the index for the ndigit array.
Everything there was initialized to 0, so when we increment it ++ndigit,
right at that position, it grows by one.
*/

int main(void) {
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    /* initializing to 0 all positions in the array */
    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
        } else {
            ++nother;
        }
    }

    printf("digits = ");
    for (i = 0; i < 10; ++i) {
        printf(" %d ", ndigit[i]);
    }
    printf("\nnwhite space = %d, other = %d\n", nwhite, nother);
    return 0;
}












