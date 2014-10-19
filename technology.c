#include <stdio.h>
#include <string.h>
#include "technology.h"

struct st_tech_level tech_levels[MAX_TECH_LEVELS];

int user_tech_level = 0;

void technology_init(void) {
  tech_levels[0].min_points = 0;
  tech_levels[0].max_points = 10;
  tech_levels[0].base_costs = 1000;
  tech_levels[0].point_costs = 10;

  tech_levels[1].min_points = 10;
  tech_levels[1].max_points = 20;
  tech_levels[1].base_costs = 2000;
  tech_levels[1].point_costs = 20;

  tech_levels[2].min_points = 30;
  tech_levels[2].max_points = 40;
  tech_levels[2].base_costs = 3000;
  tech_levels[2].point_costs = 30;

  tech_levels[3].min_points = 40;
  tech_levels[3].max_points = 50;
  tech_levels[3].base_costs = 4000;
  tech_levels[3].point_costs = 40;

  tech_levels[4].min_points = 50;
  tech_levels[4].max_points = 60;
  tech_levels[4].base_costs = 5000;
  tech_levels[4].point_costs = 50;

  tech_levels[5].min_points = 60;
  tech_levels[5].max_points = 70;
  tech_levels[5].base_costs = 6000;
  tech_levels[5].point_costs = 60;

  tech_levels[6].min_points = 70;
  tech_levels[6].max_points = 80;
  tech_levels[6].base_costs = 7000;
  tech_levels[6].point_costs = 70;
}

double technology_get_min_points(int tl) {
  return (double)tech_levels[tl-1].min_points;
}

double technology_get_max_points(int tl) {
  return (double)tech_levels[tl-1].max_points;
}

double technology_get_costs(int tl, double points) {
  int i = tl - 1;
  return (double)tech_levels[i].base_costs +
    points * (double)tech_levels[i].point_costs;
}

int technology_get_type_id(char *type_str) {
  if (strcasecmp(type_str, "Hardware") == 0) {
    return TECH_TYPE_HARDWARE;
  } else if (strcasecmp(type_str, "Software") == 0) {
    return TECH_TYPE_SOFTWARE;
  } else if (strcasecmp(type_str, "Ads") == 0) {
    return TECH_TYPE_ADS;
  } else if (strcasecmp(type_str, "Drugs") == 0) {
    return TECH_TYPE_DRUGS;
  }
  return -1;
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