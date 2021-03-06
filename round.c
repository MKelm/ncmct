#include <unistd.h>
#include <pthread.h>
#include "round.h"
#include "display.h"

int current_round = 0;
int current_round_end = 0;

int max_round_seconds = 180;
int current_round_seconds = 0;

void round_init(void) {
  round_set_next();

  pthread_t pt_round_timer;
  pthread_create(&pt_round_timer, NULL, &round_timer, NULL);
}

void round_set_next(void) {
  current_round++;
  current_round_end = 0;
  current_round_seconds = 0;
}

int round_get_current(void) {
  return current_round;
}

void round_set_current_end(void) {
  current_round_end = 1;
}

int round_get_current_end(void) {
  return current_round_end;
}

int round_get_remaining_seconds(void) {
  return max_round_seconds - current_round_seconds;
}

void *round_timer(void *val) {
  do {
    dsp_set_round_info(round_get_current(), round_get_remaining_seconds());
    sleep(1);
    current_round_seconds++;
  } while (current_round_seconds < max_round_seconds);
  dsp_set_round_info(round_get_current(), round_get_remaining_seconds());
  round_set_current_end();
  pthread_exit(NULL);
}