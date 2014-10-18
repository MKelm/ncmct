#define MAX_TECH_LEVELS 7

#define TECH_TYPE_HARDWARE 1
#define TECH_TYPE_SOFTWARE 2
#define TECH_TYPE_ADS 3
#define TECH_TYPE_DRUGS 4

#define TECH_TYPE_HARDWARE_NET 5 // network
#define TECH_TYPE_HARDWARE_COM 6 // computer
#define TECH_TYPE_HARDWARE_SAT 7 // satellite

#define TECH_TYPE_SOFTWARE_SCI 9 // science
#define TECH_TYPE_SOFTWARE_SEC 10 // security
#define TECH_TYPE_SOFTWARE_PRD 11 // production

#define TECH_TYPE_ADS_ACO 12 // acoustic
#define TECH_TYPE_ADS_VIS 13 // visual
#define TECH_TYPE_ADS_THO 14 // thoughts

#define TECH_TYPE_DRUGS_MOO 15 // mood variations
#define TECH_TYPE_DRUGS_HAL 16 // hallucinations
#define TECH_TYPE_DRUGS_AHA 17 // acoustic hallucinations

struct tech_level {
  int min_points; // minimum of points to get tech level
  int base_costs; // costs for investments in companies
  int point_costs; // costs for each point for investments in companies
};

void technology_init(void);

int technology_get_level(double points);
double technology_get_costs(int tl, double points);

void technology_get_type_str(char *type_str, int type);
void technology_get_sub_type_str(char *sub_type_str, int sub_type);