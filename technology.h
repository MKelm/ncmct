#define MAX_TECH_LEVELS 6

struct tech_level {
  double min_points;
  double min_costs;
};

void technology_init(void);

int technology_level_get(double points);