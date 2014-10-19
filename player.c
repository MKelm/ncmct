#include <string.h>
#include "player.h"

struct st_player_company player_company;

void player_init(void) {
  strncpy(player_company.title, "ControlInc", sizeof(player_company.title));
  player_company.tl = 1;
  int i;
  for (i = 0; i < PLAYER_MAX_TPS; i++) {
    player_company.tps[i] = 0.0;
  }
  player_company.cash = 10000;
}

int player_get_tl(void) {
  return player_company.tl;
}

int player_get_cash(void) {
  return player_company.cash;
}