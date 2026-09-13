#include "stuff.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void py_lstrip(char inp[]) {
  int original_length = strlen(inp);
  int i;
  int count = 0;
  for (i = 0; i < original_length; i++) {
    if (inp[i] == ' ') {
      count++;
      continue;
    } else {
      break;
    }
  }
  int diff = original_length - count;
  char temp[diff];
  for (i = 0; i < diff; i++){
    temp[i] = inp[i + count];
  }
  temp[diff] = '\0';
  strcpy(inp, temp);  
}

int main(void) {
  char s1[] = "   Hello   World    ";
  py_lstrip(s1);
  printf("-%s-\n", s1);
}
