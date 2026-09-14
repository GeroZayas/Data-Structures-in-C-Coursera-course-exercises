#include "stuff.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
 The program will create a 10 element array and read in 10 integers into the array.
 Then the program will print the integers backwards.
 Then the program will scan for entries in the array which contain the value 100 and print out the
 index of the entries with the number 100. T he program will also count the number of entries which
 equal 100. The program should work even if there are no entries which equal 100. See the sample
 output for the expect format of the output.
 */

int main(void) {
  int i, v, arr[10];
  int hundred_counter = 0;
  for (i = 0; i < 10; i++) {
    scanf("%d", &v);
    arr[i] = v;
    if (v == 100) {
      hundred_counter++;
    }
  }

  for (i = 10 - 1; i >= 0; i--) {
    printf("numb[%d] = %d\n", i, arr[i]);
  }
  puts("");
  puts("Searching for entries equal to 100\n");
  for (i = 0; i < 10; i++) {
    if (arr[i] == 100) {
      printf("Found 100 at %d\n", i);
    }
  }
  puts("");
  printf("Found %d entries with 100\n", hundred_counter);
}
