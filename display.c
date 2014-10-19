#include <ncurses.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include "display.h"

int maxy, maxx;
WINDOW *header_left, *header_right, *footer, *output, *input;

int current_input_mode = DSP_INPUT_MODE_LINE;
int current_input_mode_active = 0;

void dsp_init(void) {
  setlocale(LC_ALL, "");
  initscr();
  getmaxyx(stdscr, maxy, maxx);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE); // for header and footer
  init_pair(2, COLOR_WHITE, COLOR_BLACK); // for regular text
  init_pair(3, COLOR_GREEN, COLOR_BLACK); // for green text
  init_pair(4, COLOR_CYAN, COLOR_BLACK); // for cyan text
  init_pair(5, COLOR_YELLOW, COLOR_BLACK); // for input text
  curs_set(0);
  keypad(stdscr, TRUE);
}

void dsp_end(void) {
  endwin();
}

void dsp_windows_init(void) {
  header_left = newwin(1, ceil((float)maxx*0.8), 0, 0);
  header_right = newwin(1, floor((float)maxx*0.2), 0, ceil((float)maxx*0.8));
  footer = newwin(1, maxx, maxy-1, 0);
  output = newwin(maxy-5, maxx-2, 2, 1);
  input = newwin(1, maxx, maxy-2, 0);
  refresh();

  wbkgd(header_left, COLOR_PAIR(1));
  wrefresh(header_left);
  wbkgd(header_right, COLOR_PAIR(1));
  wrefresh(header_right);

  wbkgd(footer, COLOR_PAIR(1));
  wrefresh(footer);

  wbkgd(output, COLOR_PAIR(2));
  wattrset(output, A_BOLD);
  scrollok(output, TRUE);
  wrefresh(output);

  wbkgd(input, COLOR_PAIR(5));
  wattrset(input, A_BOLD);
  wrefresh(input);
}

void dsp_set_meta(char *title, char *version, char *author, char *year) {
  char chstr[256];

  snprintf(chstr, 256, "%s, %s", title, version);
  mvwaddstr(footer, 0, 1, chstr);
  wrefresh(footer);

  snprintf(chstr, 256, "%s, %s", author, year);
  mvwaddstr(footer, 0, maxx-strlen(chstr)-1, chstr);
  wrefresh(footer);
}

void dsp_set_player_info(char *location, float cash, int tech_level) {
  wclear(header_left);
  char chstr[256];
  snprintf(chstr, 256, "%s / %.2f$ / TL %d", location, cash, tech_level);
  mvwaddstr(header_left, 0, 1, chstr);
  wrefresh(header_left);
}

void dsp_set_round_info(int current_round, int remaining_round_seconds) {
  wclear(header_right);
  char chstr[56];
  snprintf(chstr, 56, "Round %d, %d", current_round, remaining_round_seconds);
  mvwaddstr(header_right, 0, floor((float)maxx*0.2)-strlen(chstr)-1, chstr);
  wrefresh(header_right);
  if (current_input_mode_active == 1)
    wrefresh(input);
}

void dsp_set_output(char *str) {
  char buffer[2048];
  waddstr(output, dsp_word_wrap(buffer, str, maxx-2));
  wrefresh(output);
}

char *dsp_word_wrap(char* buffer, char* string, int line_width) {
  int i = 0;
  int k, counter;

  while (i < strlen(string)) {
    for (counter = 1; counter <= line_width; counter++) {
      if (i == strlen(string)) {
        buffer[i] = 0;
        return buffer;
      }
      buffer[i] = string[i];
      if (buffer[i] == '\n') {
        counter = 1;
      }
      i++;
    }
    if (isspace(string[i])) {
      buffer[i] = '\n';
      i++;
    } else {
      for (k = i; k > 0; k--) {
        if (isspace(string[k])) {
          buffer[k] = '\n';
          i = k + 1;
          break;
        }
      }
    }
  }
  buffer[i] = 0;

  return buffer;
}

char *dsp_get_input(void) {
  current_input_mode_active = 1;
  curs_set(1);
  wclear(input);
  mvwaddstr(input, 0, 1, ">> ");
  wrefresh(input);
  static char str[128];
  if (current_input_mode == DSP_INPUT_MODE_LINE) {
    mvwgetnstr(input, 0, 4, str, 127);
  } else {
    str[0] = wgetch(input);
    str[1] = '\0';
  }
  curs_set(0);
  current_input_mode_active = 0;
  return str;
}