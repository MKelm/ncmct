#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "companies.h"

struct investment_company investment_companies[MAX_INVESTMENT_COMPANIES];

void investment_companies_init(void) {
  srand(time(NULL));
  int i, j, r;

  for (i = 0; i < MAX_INVESTMENT_COMPANIES; i++) {
    r = rand() % 4;
    switch (r) {
      case 0:
        investment_companies[i].type = COMPANY_TYPE_HARDWARE;
        investment_companies[i].sub_types[0].type = COMPANY_SUB_TYPE_HARDWARE_NET;
        investment_companies[i].sub_types[1].type = COMPANY_SUB_TYPE_HARDWARE_COM;
        investment_companies[i].sub_types[2].type = COMPANY_SUB_TYPE_HARDWARE_SAT;
        break;
      case 1:
        investment_companies[i].type = COMPANY_TYPE_SOFTWARE;
        investment_companies[i].sub_types[0].type = COMPANY_SUB_TYPE_SOFTWARE_SCI;
        investment_companies[i].sub_types[1].type = COMPANY_SUB_TYPE_SOFTWARE_SEC;
        investment_companies[i].sub_types[2].type = COMPANY_SUB_TYPE_SOFTWARE_PRD;
        break;
      case 2:
        investment_companies[i].type = COMPANY_TYPE_ADS;
        investment_companies[i].sub_types[0].type = COMPANY_SUB_TYPE_ADS_ACO;
        investment_companies[i].sub_types[1].type = COMPANY_SUB_TYPE_ADS_VIS;
        investment_companies[i].sub_types[2].type = COMPANY_SUB_TYPE_ADS_THO;
        break;
      case 3:
        investment_companies[i].type = COMPANY_TYPE_DRUGS;
        investment_companies[i].sub_types[0].type = COMPANY_SUB_TYPE_DRUGS_MOO;
        investment_companies[i].sub_types[1].type = COMPANY_SUB_TYPE_DRUGS_HAL;
        investment_companies[i].sub_types[2].type = COMPANY_SUB_TYPE_DRUGS_AHA;
        break;
    }
    investment_companies[i].strength = 0.0;
    for (j = 0; j < 3; j++) {
      investment_companies[i].sub_types[j].strength = companies_f_rand(0.0, 10.0);
      investment_companies[i].strength += investment_companies[i].sub_types[j].strength;
    }
  }

  investment_companies_sort();

  for (i = 0; i < MAX_INVESTMENT_COMPANIES; i++) {
    printf("company %d strength %f\n", i, investment_companies[i].strength);
  }
}

void investment_companies_sort(void) {
  int i, has_change = 0;
  struct investment_company tmp_company;

  for (i = 0; i < MAX_INVESTMENT_COMPANIES - 1; i++) {
    if (investment_companies[i].strength < investment_companies[i+1].strength) {
      has_change = 1;

      tmp_company = investment_companies[i];
      investment_companies[i] = investment_companies[i+1];
      investment_companies[i+1] = tmp_company;
    }
  }
  if (has_change == 1) investment_companies_sort();
}

double companies_f_rand(double f_min, double f_max) {
    double f = (double)rand() / RAND_MAX;
    return f_min + f * (f_max - f_min);
}