#include "stuff.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void calcpay(float *p, float r, float h) {
  if (h > 40) {
    int diff;
    diff = h - 40;
    printf("diff is %i\n", diff);
    *p = (r * 40) + diff * (r * 1.5);
  } else {
    *p = r * h;
  }
  // printf("%f\n", *p);
}

int main(void) {
  float pay;
  calcpay(&pay, 5.25, 10);
}
