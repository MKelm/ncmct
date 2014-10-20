#include "profit.h"
#include "helper.h"
#include "technology.h"

struct st_profit_level profit_levels[MAX_TECH_LEVELS];

void profit_init(void) {
  profit_levels[0].min_cash = 500.0;
  profit_levels[0].max_cash = 1000.0;
  profit_levels[0].p_profit = 0.7;

  profit_levels[1].min_cash = 1000.0;
  profit_levels[1].max_cash = 2000.0;
  profit_levels[1].p_profit = 0.725;

  profit_levels[2].min_cash = 2000.0;
  profit_levels[2].max_cash = 3000.0;
  profit_levels[2].p_profit = 0.75;

  profit_levels[3].min_cash = 3000.0;
  profit_levels[3].max_cash = 4000.0;
  profit_levels[3].p_profit = 0.775;

  profit_levels[4].min_cash = 4000.0;
  profit_levels[4].max_cash = 5000.0;
  profit_levels[4].p_profit = 0.8;

  profit_levels[5].min_cash = 5000.0;
  profit_levels[5].max_cash = 6000.0;
  profit_levels[5].p_profit = 0.825;

  profit_levels[6].min_cash = 6000.0;
  profit_levels[6].max_cash = 7000.0;
  profit_levels[6].p_profit = 0.85;
}

float profit_get(int tech_level) {
  if (tech_level < MAX_TECH_LEVELS) {
    float cash = helper_random_float_min_max(
      profit_levels[tech_level].min_cash, profit_levels[tech_level].max_cash
    );
    if (helper_random_probability(profit_levels[tech_level].p_profit) == 1) {
      return cash;
    } else {
      return -1.0 * cash;
    }
  }
  return 0.0;
}