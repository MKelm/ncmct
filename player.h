#include "companies.h"

#define PLAYER_MAX_TITLE_CHARS 256
#define PLAYER_MAX_TPS 12
#define PLAYER_MAX_CIS 20

struct st_player_company {
  char title[PLAYER_MAX_TITLE_CHARS];
  int tl; // tech level
  float tps[PLAYER_MAX_TPS]; // tech points for each tech sub type
  float cash;
  int cids_idx;
  int cids[PLAYER_MAX_CIS]; // company investments ids
  struct st_company *cis[PLAYER_MAX_CIS]; // company investments
};

// index values for tech points array
#define PLAYER_TPS_IDX_HARDWARE_NET 0 // network
#define PLAYER_TPS_IDX_HARDWARE_COM 1 // computer
#define PLAYER_TPS_IDX_HARDWARE_SAT 2 // satellite

#define PLAYER_TPS_IDX_SOFTWARE_SCI 3 // science
#define PLAYER_TPS_IDX_SOFTWARE_SEC 4 // security
#define PLAYER_TPS_IDX_SOFTWARE_PRD 5 // production

#define PLAYER_TPS_IDX_ADS_ACO 6 // acoustic
#define PLAYER_TPS_IDX_ADS_VIS 7 // visual
#define PLAYER_TPS_IDX_ADS_THO 8 // thoughts

#define PLAYER_TPS_IDX_DRUGS_MOO 9 // mood variations
#define PLAYER_TPS_IDX_DRUGS_HAL 10 // hallucinations
#define PLAYER_TPS_IDX_DRUGS_AHA 11 // acoustic hallucinations

void player_init(void);
void player_update_company_investments(void);

int player_add_company_investment(struct st_company *company);
char *player_get_company_investments(int type);

int player_get_tl(void);
float player_get_cash(void);