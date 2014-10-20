#include <stdio.h>
#include <string.h>
#include "player.h"
#include "technology.h"

struct st_player_company player_company;

void player_init(void) {
  strncpy(player_company.title, "ControlInc", sizeof(player_company.title));
  player_company.tl = 1;
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      player_company.tps[i][j] = 0.0;
    }
  }
  player_company.cash = 10000.00;
  for (i = 0; i < PLAYER_MAX_CIS; i++) {
    player_company.cis[i] = NULL;
    player_company.cids[i] = -1;
  }
  player_company.cids_idx = 0;
}

void player_update_company_investments(void) {
  int i;
  for (i = 0; i < PLAYER_MAX_CIS; i++) {
    if (player_company.cids[i] > -1) {
      if (player_company.cis[i]->id != player_company.cids[i]) {
        player_company.cis[i] = companies_get_company_by_id(player_company.cids[i]);
      }
      if (player_company.cis[i] != NULL) {
        if (player_company.cis[i]->age == 0 ||
            player_company.cis[i]->tl > player_company.tl) {
          player_remove_company_investment(i);

        } else {
          if (player_company.cis[i]->last_profit > 0.0) {
            // 10% profit share
            player_company.cash += 0.1 * player_company.cis[i]->last_profit;
            player_company.cis[i]->cash -= 0.1 * player_company.cis[i]->last_profit;
            player_company.cis[i]->last_profit -= 0.1 * player_company.cis[i]->last_profit;
          }

          switch (player_company.cis[i]->type) {
            case TECH_TYPE_HARDWARE:
              player_company.tps[PLAYER_TPS_IDX_HARDWARE][PLAYER_TPS_IDX_HARDWARE_NET] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_HARDWARE_NET].points;
              player_company.tps[PLAYER_TPS_IDX_HARDWARE][PLAYER_TPS_IDX_HARDWARE_COM] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_HARDWARE_COM].points;
              player_company.tps[PLAYER_TPS_IDX_HARDWARE][PLAYER_TPS_IDX_HARDWARE_SAT] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_HARDWARE_SAT].points;
              break;
            case TECH_TYPE_SOFTWARE:
              player_company.tps[PLAYER_TPS_IDX_SOFTWARE][PLAYER_TPS_IDX_SOFTWARE_SCI] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_SOFTWARE_SCI].points;
              player_company.tps[PLAYER_TPS_IDX_SOFTWARE][PLAYER_TPS_IDX_SOFTWARE_SEC] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_SOFTWARE_SEC].points;
              player_company.tps[PLAYER_TPS_IDX_SOFTWARE][PLAYER_TPS_IDX_SOFTWARE_PRD] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_SOFTWARE_PRD].points;
              break;
            case TECH_TYPE_ADS:
              player_company.tps[PLAYER_TPS_IDX_ADS][PLAYER_TPS_IDX_ADS_ACO] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_ADS_ACO].points;
              player_company.tps[PLAYER_TPS_IDX_ADS][PLAYER_TPS_IDX_ADS_VIS] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_ADS_VIS].points;
              player_company.tps[PLAYER_TPS_IDX_ADS][PLAYER_TPS_IDX_ADS_THO] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_ADS_THO].points;
              break;
            case TECH_TYPE_DRUGS:
              player_company.tps[PLAYER_TPS_IDX_DRUGS][PLAYER_TPS_IDX_DRUGS_MOO] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_DRUGS_MOO].points;
              player_company.tps[PLAYER_TPS_IDX_DRUGS][PLAYER_TPS_IDX_DRUGS_HAL] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_DRUGS_HAL].points;
              player_company.tps[PLAYER_TPS_IDX_DRUGS][PLAYER_TPS_IDX_DRUGS_AHA] +=
                player_company.cis[i]->sub_types[COMPANY_ST_IDX_DRUGS_AHA].points;
              break;
          }
        }
      }
    }
  }
}

void player_remove_company_investment(int i) {
  int j, has_change = 0;
  for (j = 0; j < PLAYER_MAX_CIS; j++) {
    if (j == i) {
      has_change = 1;
    } else if (has_change == 1) {
      player_company.cis[i-1] = player_company.cis[i];
      player_company.cids[i-1] = player_company.cids[i];
      player_company.cis[i] = NULL;
      player_company.cids[i] = -1;
    }
  }
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
    if (costs <= player_company.cash && player_company.cids_idx < PLAYER_MAX_CIS) {
      player_company.cash -= costs;
      player_company.cids[player_company.cids_idx] = company->id;
      player_company.cis[player_company.cids_idx] = company;
      player_company.cids_idx++;
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
    if (player_company.cis[i] != NULL && player_company.cis[i]->type == type) {
      snprintf(ch_str, 512, "%d. ", i+1);
      strcat(str, ch_str);
      strcat(str, player_company.cis[i]->name);
      snprintf(
        ch_str, 512, " / Points %.2f / Cash %.2f",
        player_company.cis[i]->points, player_company.cis[i]->cash
      );
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

char *player_get_company_technology_points(void) {
  static char str[1024];
  char ch_str[512], type_str[128];
  int i, j;

  for (i = 0; i < 4; i++) {
    technology_get_type_str(type_str, i);
    snprintf(ch_str, 512, "%s: ", type_str);
    strcat(str, ch_str);
    strcat(str, "\n|-- ");
    for (j = 0; j < 3; j++) {
      if (j > 0)
        strcat(str, "-- ");

      technology_get_sub_type_str(type_str, (i+1)*3+j+1);
      snprintf(
        ch_str, 512, "%s = %.2f ", type_str, player_company.tps[i][j]
      );
      strcat(str, ch_str);
    }
    strcat(str, "\n");
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