struct st_profit_level {
  float min_cash; // min cash value in relation to tech level
  float max_cash; // max cash value in relation to tech level
  float p_profit; // probability to get a profit or not
};

void profit_init(void);

float profit_get(int tech_level);