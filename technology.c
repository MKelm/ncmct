#include <stdio.h>
#include <string.h>
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

void technology_get_type_str(char *type_str, int type) {
  switch (type) {
    case TECH_TYPE_HARDWARE:
      snprintf(type_str, 128, "Hardware");
      break;
    case TECH_TYPE_SOFTWARE:
      snprintf(type_str, 128, "Software");
      break;
    case TECH_TYPE_ADS:
      snprintf(type_str, 128, "Ads");
      break;
    case TECH_TYPE_DRUGS:
      snprintf(type_str, 128, "Drugs");
      break;
  }
}

void technology_get_sub_type_str(char *sub_type_str, int sub_type) {
  switch (sub_type) {
    case TECH_TYPE_HARDWARE_NET:
      snprintf(sub_type_str, 128, "NET");
      break;
    case TECH_TYPE_HARDWARE_COM:
      snprintf(sub_type_str, 128, "COM");
      break;
    case TECH_TYPE_HARDWARE_SAT:
      snprintf(sub_type_str, 128, "SAT");
      break;
    case TECH_TYPE_SOFTWARE_SCI:
      snprintf(sub_type_str, 128, "SCI");
      break;
    case TECH_TYPE_SOFTWARE_SEC:
      snprintf(sub_type_str, 128, "SEC");
      break;
    case TECH_TYPE_SOFTWARE_PRD:
      snprintf(sub_type_str, 128, "PRD");
      break;
    case TECH_TYPE_ADS_ACO:
      snprintf(sub_type_str, 128, "ACO");
      break;
    case TECH_TYPE_ADS_VIS:
      snprintf(sub_type_str, 128, "VIS");
      break;
    case TECH_TYPE_ADS_THO:
      snprintf(sub_type_str, 128, "THO");
      break;
    case TECH_TYPE_DRUGS_MOO:
      snprintf(sub_type_str, 128, "MOO");
      break;
    case TECH_TYPE_DRUGS_HAL:
      snprintf(sub_type_str, 128, "HAL");
      break;
    case TECH_TYPE_DRUGS_AHA:
      snprintf(sub_type_str, 128, "AHA");
      break;
  }
}