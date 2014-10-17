#include <stdio.h>
#include "technology.h"

struct tech_level tech_levels[MAX_TECH_LEVELS];

void technology_init(void) {
  int i;
  tech_levels[0].min_points = 0;
  tech_levels[0].min_costs = 0;
  tech_levels[1].min_points = 100;
  tech_levels[1].min_costs = 1000;
  for (i = 2; i < MAX_TECH_LEVELS; i++) {
    tech_levels[i].min_points = tech_levels[i-1].min_points * (i-1) * 1.25;
    tech_levels[i].min_costs = tech_levels[i-1].min_costs * (i-1) * 1.25;
  }
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