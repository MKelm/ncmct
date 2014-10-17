#include <stdio.h>
#include "technology.h"

struct tech_level tech_levels[MAX_TECH_LEVELS];

void technology_init(void) {
  tech_levels[0].min_points = 0;
  tech_levels[0].min_costs = 0;

  tech_levels[1].min_points = 100;
  tech_levels[1].min_costs = 1000;

  tech_levels[2].min_points = 250;
  tech_levels[2].min_costs = 2000;

  tech_levels[3].min_points = 500;
  tech_levels[3].min_costs = 4000;

  tech_levels[4].min_points = 1000;
  tech_levels[4].min_costs = 8000;

  tech_levels[5].min_points = 2500;
  tech_levels[5].min_costs = 16000;
}

int technology_level_get(double points) {
  int i = 0, tl = 0;
  for (i = 0; i < MAX_TECH_LEVELS; i++) {
    if (points > tech_levels[i].min_points) {
      tl++;
    }
  }
  return tl;
}