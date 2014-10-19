#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "helper.h"

void helper_set_random_seed(void) {
  srand(time(NULL));
}

int helper_random_int_min_max(int i_min, int i_max) {
  return floor(helper_random_float_min_max((float)i_min, (float)i_max));
}

double helper_random_float_min_max(float f_min, float f_max) {
  float f = (float)rand() / RAND_MAX;
  return f_min + f * (f_max - f_min);
}

int helper_random_probability(float p) {
  if (rand() < (RAND_MAX * p)) {
    return 1;
  }
  return 0;
}