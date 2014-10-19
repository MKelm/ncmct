#ifndef MAX_TECH_LEVELS

#define MAX_TECH_LEVELS 7

#define TECH_TYPE_HARDWARE 0
#define TECH_TYPE_SOFTWARE 1
#define TECH_TYPE_ADS 2
#define TECH_TYPE_DRUGS 3

#define TECH_TYPE_HARDWARE_NET 4 // network
#define TECH_TYPE_HARDWARE_COM 5 // computer
#define TECH_TYPE_HARDWARE_SAT 6 // satellite

#define TECH_TYPE_SOFTWARE_SCI 7 // science
#define TECH_TYPE_SOFTWARE_SEC 8 // security
#define TECH_TYPE_SOFTWARE_PRD 9 // production

#define TECH_TYPE_ADS_ACO 10 // acoustic
#define TECH_TYPE_ADS_VIS 11 // visual
#define TECH_TYPE_ADS_THO 12 // thoughts

#define TECH_TYPE_DRUGS_MOO 13 // mood variations
#define TECH_TYPE_DRUGS_HAL 14 // hallucinations
#define TECH_TYPE_DRUGS_AHA 15 // acoustic hallucinations

struct st_tech_level {
  int min_points; // minimum of points for each tech sub type
  int max_points; // maximum of points for each tech sub type
  int base_costs; // costs for investments in companies
  int point_costs; // costs for each point for investments in companies
};

void technology_init(void);

float technology_get_min_points(int tl);
float technology_get_max_points(int tl);

float technology_get_costs(int tl, float points);

int technology_get_type_id(char *type_str);

void technology_get_type_str(char *type_str, int type);
void technology_get_sub_type_str(char *sub_type_str, int sub_type);

#endif