#ifndef MAX_COMPANIES

#define MAX_COMPANIES 200
#define MAX_COMPANY_NAMES 1000

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