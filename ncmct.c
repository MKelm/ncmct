#include <stdio.h>
#include "display.h"
#include "round.h"

int main(void) {

  dsp_init();
  dsp_windows_init();

  dsp_set_meta("Mass Control Tycoon", "0.0.1 alpha", "Martin Kelm", "2014");

  dsp_set_location("Earth");
  dsp_set_output("Welcome to Mass Control Tycoon ...");

  round_init();

  char *input = dsp_get_input();

  dsp_end();
  return 0;
}