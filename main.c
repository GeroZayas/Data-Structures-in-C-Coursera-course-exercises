#include "stuff.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char in_one[50];
  char in_two[50];
  char final_str[100];
  puts("Enter two strings");
  scanf("%s", in_one);
  scanf("%s", in_two);
  strcpy(final_str, in_one);
  strcat(final_str, " & ");
  strcat(final_str, in_two);
  // puts(final_str);
}
