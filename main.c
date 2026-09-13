#include "stuff.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void py_rstrip(char inp[]) {
  int count = 0;
  int original_length = strlen(inp);
  for (int i = original_length - 1; i >= 0; i--) {
    if (inp[i] == ' ') {
      count += 1;
      printf("count = %d\n", count);
    } else {
      break;
    }
    printf("%c\n", inp[i]);
  }
}

int main(void) {
  char s1[] = "   Hello   World    ";
  py_rstrip(s1);
  printf("-%s-\n", s1);
}
