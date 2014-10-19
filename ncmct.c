#include <stdio.h>
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

  char *input;
  do {
    input = dsp_get_input();
    if (strcmp(input, "top5 hardware") == 0) {
      dsp_set_output(companies_get_top5(TECH_TYPE_HARDWARE, player_get_tl()));
    } else if (strcmp(input, "top5 software") == 0) {
      dsp_set_output(companies_get_top5(TECH_TYPE_SOFTWARE, player_get_tl()));
    } else if (strcmp(input, "top5 ads") == 0) {
      dsp_set_output(companies_get_top5(TECH_TYPE_ADS, player_get_tl()));
    } else if (strcmp(input, "top5 drugs") == 0) {
      dsp_set_output(companies_get_top5(TECH_TYPE_DRUGS, player_get_tl()));
    }
  } while (strcmp(input, "quit") != 0);

  dsp_end();
  return 0;
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
    sleep(1);
  }
  pthread_exit(NULL);
}