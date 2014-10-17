#include <stdlib.h>
#include "helper.h"

double helper_random_min_max(double f_min, double f_max) {
  double f = (double)rand() / RAND_MAX;
  return f_min + f * (f_max - f_min);
}

int helper_random_probability(double p) {
  if (rand() < (RAND_MAX * p)) {
    return 1;
  }
  return 0;
}