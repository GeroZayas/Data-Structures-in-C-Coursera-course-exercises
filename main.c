#include "stuff.h"
#include <stdbool.h>
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

int main(void) {
  int c; 
  c = getchar();
  while(c != EOF){
    putchar(c);
    c = getchar();
  }
}