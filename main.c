#include "stuff.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define NAME "Gero"

void print_with_arrows(char *text) {
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] != text[strlen(text) - 1]) {
      printf("%c->", text[i]);
    } else {
      printf("%c", text[i]);
    }
  }
  printf("\n");
}

void print_reverse_string(char *text, bool arrows) {
  int len_of_text = strlen(text);
  // printf("The len of the string is %d\n", len_of_text);

  if (arrows) {
    printf("Arrows true\n");
    for (int i = len_of_text; i >= 0; i--) {
      if (i != 0 && i != len_of_text) {
        printf("%c->", text[i]);
      } else {
        printf("%c\n", text[i]);
      }
    }

  } else {
    for (int i = len_of_text; i >= 0; i--) {
      printf("%c", text[i]);
    }
    printf("\n");
  }
}

const char *get_user_input(void) {
  static char user_input[100];
  printf("INSERT SOMETHING HERE:\n");
  fgets(user_input, sizeof(user_input), stdin);
  return user_input;
}

int main(void) {
  print_with_arrows(NAME);
  print_reverse_string(NAME, 1);
  const char *res = get_user_input();
  printf("%s\n", res);

  float farray[3];
  memset(farray, 1, sizeof(farray));
  printf("%f\n", farray[0]);
  printf("%f\n", farray[1]);
  printf("%f\n", farray[2]);

  puts("Something Else Here");
  puts("Some new line here");

  char new_name[20];
  puts("Insert name here:");
  scanf("%5s", new_name);
  puts("This is the new name:");
  puts(new_name);

}










