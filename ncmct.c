#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "display.h"
#include "round.h"
#include "companies.h"

void *main_timer(void *val);

int main(void) {

  investment_companies_init();

  dsp_init();
  dsp_windows_init();

  dsp_set_meta("Mass Control Tycoon", "0.0.1 alpha", "Martin Kelm", "2014");

  dsp_set_location_cash("Anuka", 10000);
  dsp_set_output("Welcome to Mass Control Tycoon ...\n\n");

  pthread_t pt_main_timer;
  pthread_create(&pt_main_timer, NULL, &main_timer, NULL);

  char *input = dsp_get_input();

  dsp_end();
  return 0;
}

void *main_timer(void *val) {
  while (1) {
    // do main timer logic
    if (round_get_current() == 0 || round_get_current_end() == 1) {
      round_init();
      dsp_set_output(investment_companies_get_top5());
    }
    sleep(1);
  }
  pthread_exit(NULL);
}