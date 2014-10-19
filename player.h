#include "companies.h"

#define PLAYER_MAX_TITLE_CHARS 256
#define PLAYER_MAX_CIS 20

struct st_player_company {
  char title[PLAYER_MAX_TITLE_CHARS];
  int tl; // tech level
  float tps[4][3]; // tech points for each tech sub type
  float cash;
  int cids_idx;
  int cids[PLAYER_MAX_CIS]; // company investments ids
  struct st_company *cis[PLAYER_MAX_CIS]; // company investments
};

// index values for tech points array
#define PLAYER_TPS_IDX_HARDWARE 0
#define PLAYER_TPS_IDX_SOFTWARE 1
#define PLAYER_TPS_IDX_ADS 2
#define PLAYER_TPS_IDX_DRUGS 3

// index values for tech points array
#define PLAYER_TPS_IDX_HARDWARE_NET 0 // network
#define PLAYER_TPS_IDX_HARDWARE_COM 1 // computer
#define PLAYER_TPS_IDX_HARDWARE_SAT 2 // satellite

#define PLAYER_TPS_IDX_SOFTWARE_SCI 0 // science
#define PLAYER_TPS_IDX_SOFTWARE_SEC 1 // security
#define PLAYER_TPS_IDX_SOFTWARE_PRD 2 // production

#define PLAYER_TPS_IDX_ADS_ACO 0 // acoustic
#define PLAYER_TPS_IDX_ADS_VIS 1 // visual
#define PLAYER_TPS_IDX_ADS_THO 2 // thoughts

#define PLAYER_TPS_IDX_DRUGS_MOO 0 // mood variations
#define PLAYER_TPS_IDX_DRUGS_HAL 1 // hallucinations
#define PLAYER_TPS_IDX_DRUGS_AHA 2 // acoustic hallucinations

void player_init(void);
void player_update_company_investments(void);

void player_remove_company_investment(int i);

int player_add_company_investment(struct st_company *company);
char *player_get_company_investments(int type);
char *player_get_company_technology_points(void);

int player_get_tl(void);
float player_get_cash(void);