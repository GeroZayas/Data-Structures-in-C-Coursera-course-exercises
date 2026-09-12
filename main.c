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

void reverse(char t[]) {
  int len_of_text = strlen(t);
  int i, j;
  char new[len_of_text];
  for (j = 0, i = len_of_text; i >= 0; i--, j++) {
    new[j] = t[i];
    printf("%c", new[j]);
  }
  printf("\n");
  return;
}

int main(void) {
  reverse("FLORA");
}
