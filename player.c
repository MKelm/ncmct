#include <stdio.h>
#include <string.h>
#include "player.h"
#include "technology.h"

struct st_player_company player_company;

void player_init(void) {
  strncpy(player_company.title, "ControlInc", sizeof(player_company.title));
  player_company.tl = 1;
  int i;
  for (i = 0; i < PLAYER_MAX_TPS; i++) {
    player_company.tps[i] = 0.0;
  }
  player_company.cash = 10000.00;
  for (i = 0; i < PLAYER_MAX_CIS; i++) {
    player_company.cis[i] = NULL;
  }
  player_company.cis_idx = 0;
}

int player_add_company_investment(struct st_company *company) {
  if (company != NULL) {
    int i;
    for (i = 0; i < PLAYER_MAX_CIS; i++) {
      if (player_company.cis[i] != NULL && player_company.cis[i]->id == company->id) {
        return -1;
      }
    }
    float costs = technology_get_costs(company->tl, company->points);
    if (costs <= player_company.cash && player_company.cis_idx < PLAYER_MAX_CIS) {
      player_company.cash -= costs;
      player_company.cis[player_company.cis_idx] = company;
      player_company.cis_idx++;
      return 1;
    }
  }
  return -1;
}

char *player_get_company_investments(int type) {
  static char str[1024];
  char ch_str[512], type_str[128];
  int i, j, k = 0;

  technology_get_type_str(type_str, type);
  snprintf(str, 1024, "Company investments [%s / TL %d]:\n", type_str, player_get_tl());
  for (i = 0; i < PLAYER_MAX_CIS; i++) {
    if (player_company.cis[i] != NULL) {
      snprintf(ch_str, 512, "%d. ", i+1);
      strcat(str, ch_str);
      strcat(str, player_company.cis[i]->name);
      snprintf(ch_str, 512, " / Points %.2f ", player_company.cis[i]->points);
      strcat(str, ch_str);

      strcat(str, "\n|-- ");
      for (j = 0; j < 3; j++) {
        if (j > 0)
          strcat(str, "-- ");

        technology_get_sub_type_str(type_str, player_company.cis[i]->sub_types[j].type);
        snprintf(
          ch_str, 512, "%s = %.2f ",
          type_str, player_company.cis[i]->sub_types[j].points
        );
        strcat(str, ch_str);
      }
      strcat(str, "\n");
      k++;
    }
  }
  if (k == 0) {
    strcat(str, "No investments available.\n");
  }
  strcat(str, "\n");
  return str;
}

int player_get_tl(void) {
  return player_company.tl;
}

float player_get_cash(void) {
  return player_company.cash;
}