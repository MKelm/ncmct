#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "display.h"
#include "helper.h"
#include "round.h"
#include "technology.h"
#include "companies.h"
#include "player.h"

void *main_timer(void *val);
void main_split_input(char *input, char input_arr[4][256]);

int player_info_change = 0;

int main(void) {
  helper_set_random_seed();

  technology_init();
  companies_init();

  player_init();

  dsp_init();
  dsp_windows_init();

  dsp_set_meta("Mass Control Tycoon", "0.0.1 alpha", "Martin Kelm", "2014");

  dsp_set_player_info("Anuka", player_get_cash(), player_get_tl());
  dsp_set_output("Welcome to Mass Control Tycoon ...\n\n");

  pthread_t pt_main_timer;
  pthread_create(&pt_main_timer, NULL, &main_timer, NULL);

  char input[4][256];
  do {
    main_split_input(dsp_get_input(), input);
    if (strcmp(input[0], "top5") == 0 && strlen(input[1]) > 0) {
      int type_id = technology_get_type_id(input[1]);
      if (type_id > -1) {
        dsp_set_output(companies_get_top5(type_id, player_get_tl()));
      }
    } else if (strcmp(input[0], "invest") == 0 && strlen(input[1]) > 0) {
      int cid = companies_get_cid(atoi(input[1])-1, player_get_tl());
      if (cid > -1 && player_add_ci(cid, companies_get_ccosts(cid)) == 1) {
        player_info_change = 1;
        dsp_set_output("Company investment done.\n\n");
      }
    }
  } while (strcmp(input[0], "quit") != 0);

  dsp_end();
  return 0;
}

void main_split_input(char *input, char input_arr[4][256]) {
  char *ptr;
  ptr = strtok(input, " ");
  int i = 0;
  while (ptr != NULL) {
    if (i < 4) {
      strcpy(input_arr[i], ptr);
      ptr = strtok(NULL, " ");
      i++;
    }
  }
}

void *main_timer(void *val) {
  while (1) {
    // do main timer logic
    if (round_get_current() == 0 || round_get_current_end() == 1) {
      if (round_get_current_end() == 1) {
        companies_recalculate();
      }
      round_init();
    }
    if (player_info_change == 1) {
      dsp_set_player_info("Anuka", player_get_cash(), player_get_tl());
    }
    sleep(1);
  }
  pthread_exit(NULL);
}