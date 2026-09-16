#include "stuff.h"
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

/*

p
0 1 2 3 4 5 6 7 8 9 
[][][][][][][][][][]
*/

int main(void) {
  char  memory        [256];
  char  token         [256];
  int   position  =       0; 
  int   value     =       0;
  int   i                  ;

  while (scanf("%s", token) == 1) {
    /* printf("INSERTED TOKEN = %s\n", token); */ 
    /* printf("POSITION = %d\n", position); */
    /* printf("LEN of token %lu\n", strlen(token)); */

    for (i=0;i<strlen(token);i++){
      if (token[i] - '0' >= 0 && token[i] - '0' <= 9){
        value = (value * 10) + token[i] - '0';
        memory[position] = value;
      } else if (token[i] == '<'){
        position--;
      } else if (token[i] == '>'){
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


