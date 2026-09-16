#include "stuff.h"
#include <stdio.h>
#include <string.h>

/*
This is a subset of an important concept in Computer Science called a Turing
Machine. We call it a "Touring Machine" because it "wanders around and does
things in memory" similar to a Turing Machine. Your computer has 256 characters
of memory. The machine keeps track of the "position" or the "head" where data is
to be written. The starting position is zero. You are to read a sequence of
instructions from input and perform those instructions. When there are no more
instructions, print the memory out as a zero-terminated C character array All of
the numbers should be in the range of 0-255 so they fit into a C char variable.
42     Store this value into the memory at the current position
>      Move the "position" one to the right (i.e. position++);
<      Move the "position" one to the left (i.e. position--);
 */

/* Note 1A:
-----------
The struggle here (due to lack of C knowledge) was this making the token an int
that we could place in `memory` so as to represent a character, and print the
wanted string in the end.
- IMPORTANT: check if it is a digit => `if (token[i] - '0' >= 0 && token[i] - '0' <= 9){ ...`
  To convert to digit => token[i] - '0' -> char - '0' Then, as we get bigger numbers,
  we multiply the previous `value` by 10 and then we add the new `value`
- ex A: value is 4 -> then new token is 2, value is (4 * 10) + 2 = 42
- ex B: value is 6 -> then new token is 3,value is (6 * 10) + 3 = 63
  -> then new token is 7, value is (63 * 10) + 7 = 630 + 7 = 637
*/

int main(void) {
    char memory[256];
    char token[256];
    int  position = 0;
    int  value    = 0;
    int  i;

    while (scanf("%s", token) == 1) {
        /* printf("INSERTED TOKEN = %s\n", token); */
        /* printf("POSITION = %d\n", position); */
        /* printf("LEN of token %lu\n", strlen(token)); */

        /* See Note 1A */
        for (i = 0; i < strlen(token); i++) {
            if (token[i] - '0' >= 0 && token[i] - '0' <= 9) {
                value            = (value * 10) + token[i] - '0';
                memory[position] = value;
            } else if (token[i] == '<') {
                position--;
            } else if (token[i] == '>') {
                position++;
            }
        }
        /*  printf("VALUE =  %d\n", value); */
        /*  printf("POSITION NOW =  %d\n", position); */
        value = 0;
    };
    printf("Memory:\n%s\n", memory);

    return 0;
}
