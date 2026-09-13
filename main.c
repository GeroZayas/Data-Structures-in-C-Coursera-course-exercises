#include "libs/Forge/forge.h"
#include "stuff.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void) {
  float a[3] = {3.5f, 4.5f, 5.5f};
  float length = f_length3f(a);
  printf("LENGTH of a = {3.5f, 4.5f, 5.5f} IS %f\n", length);
  printf("Forge: %f\n", f_length3f(a));
  printf("C:     %f\n", sqrtf(61.25f));

  float dist;
  float *one, *two;
  one = &a[0]; two = &a[1]; 
  dist = f_distance2f(one, two);
  printf("dist:  %f\n", dist);

}
