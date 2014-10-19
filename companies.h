#ifndef MAX_COMPANIES

#define MAX_COMPANIES 200
#define MAX_COMPANY_NAMES 1000

// index values for tech points array
#define COMPANY_ST_IDX_HARDWARE_NET 0 // network
#define COMPANY_ST_IDX_HARDWARE_COM 1 // computer
#define COMPANY_ST_IDX_HARDWARE_SAT 2 // satellite

#define COMPANY_ST_IDX_SOFTWARE_SCI 0 // science
#define COMPANY_ST_IDX_SOFTWARE_SEC 1 // security
#define COMPANY_ST_IDX_SOFTWARE_PRD 2 // production

#define COMPANY_ST_IDX_ADS_ACO 0 // acoustic
#define COMPANY_ST_IDX_ADS_VIS 1 // visual
#define COMPANY_ST_IDX_ADS_THO 2 // thoughts

#define COMPANY_ST_IDX_DRUGS_MOO 0 // mood variations
#define COMPANY_ST_IDX_DRUGS_HAL 1 // hallucinations
#define COMPANY_ST_IDX_DRUGS_AHA 2 // acoustic hallucinations

struct st_company_sub_type {
  int type;
  float points;
};

struct st_company {
  int id;
  int type;
  int last_rank;
  int age; // in rounds
  int tl; // technology level
  char *name;
  float points; // sum of sub types costs
  struct st_company_sub_type sub_types[3];
};

void companies_init(void);
void companies_add_single(int i);
void companies_recalculate(void);
void companies_recalculate_single(int i);
void companies_sort(void);

struct st_company *companies_get_company(int i, int tl);

char *companies_get_top5(int type, int user_tl);

#endif