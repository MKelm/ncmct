#define MAX_TECH_LEVELS 6

struct company_tech_level {
  double min_points;
  double min_costs;
};

void technology_init(void);

int technology_get_company_level(double points);

int technology_get_user_level(void);