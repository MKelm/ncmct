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

int player_add_company(struct st_company *company) {
  if (company != NULL) {
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

int player_get_tl(void) {
  return player_company.tl;
}

float player_get_cash(void) {
  return player_company.cash;
}