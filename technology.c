#include <stdio.h>
#include "technology.h"

struct company_tech_level company_tech_levels[MAX_TECH_LEVELS];

int user_tech_level = 0;

void technology_init(void) {
  company_tech_levels[0].min_points = 0;
  company_tech_levels[0].min_costs = 0;

  company_tech_levels[1].min_points = 100;
  company_tech_levels[1].min_costs = 1000;

  company_tech_levels[2].min_points = 250;
  company_tech_levels[2].min_costs = 2000;

  company_tech_levels[3].min_points = 500;
  company_tech_levels[3].min_costs = 4000;

  company_tech_levels[4].min_points = 1000;
  company_tech_levels[4].min_costs = 8000;

  company_tech_levels[5].min_points = 2500;
  company_tech_levels[5].min_costs = 16000;
}

int technology_get_company_level(double points) {
  int i = 0, tl = 0;
  for (i = 0; i < MAX_TECH_LEVELS; i++) {
    if (points > company_tech_levels[i].min_points) {
      tl++;
    }
  }
  return tl;
}

int technology_get_user_level(void) {
  return user_tech_level + 1;
}