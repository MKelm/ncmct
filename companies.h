
#define MAX_INVESTMENT_COMPANIES 200

#define MAX_COMPANY_NAMES 1000

#define COMPANY_TYPE_HARDWARE 1
#define COMPANY_TYPE_SOFTWARE 2
#define COMPANY_TYPE_ADS 3
#define COMPANY_TYPE_DRUGS 4

#define COMPANY_SUB_TYPE_HARDWARE_NET 5 // network
#define COMPANY_SUB_TYPE_HARDWARE_COM 6 // computer
#define COMPANY_SUB_TYPE_HARDWARE_SAT 7 // satellite

#define COMPANY_SUB_TYPE_SOFTWARE_SCI 9 // science
#define COMPANY_SUB_TYPE_SOFTWARE_SEC 10 // security
#define COMPANY_SUB_TYPE_SOFTWARE_PRD 11 // production

#define COMPANY_SUB_TYPE_ADS_ACO 12 // acoustic
#define COMPANY_SUB_TYPE_ADS_VIS 13 // visual
#define COMPANY_SUB_TYPE_ADS_THO 14 // thoughts

#define COMPANY_SUB_TYPE_DRUGS_MOO 15 // mood variations
#define COMPANY_SUB_TYPE_DRUGS_HAL 16 // hallucinations
#define COMPANY_SUB_TYPE_DRUGS_AHA 17 // acoustic hallucinations

struct company_sub_type {
  int type;
  double strength;

};

struct investment_company {
  char *name;
  int type;
  double strength;
  struct company_sub_type sub_types[3];
};

void investment_companies_init(void);
void investment_companies_sort(void);

char *investment_companies_get_top5(void);

double companies_f_rand(double f_min, double f_max);