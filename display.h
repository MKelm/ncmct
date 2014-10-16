void dsp_init(void);
void dsp_end(void);

void dsp_windows_init(void);

void dsp_set_meta(char *title, char *version, char *author, char *year);
void dsp_set_location(char *location);
void dsp_set_round_info(int current_round, int remaining_round_seconds);
void dsp_set_output(char *str);

char *dsp_word_wrap(char* buffer, char* string, int line_width);

#define DSP_INPUT_MODE_CHAR 0
#define DSP_INPUT_MODE_LINE 1

char *dsp_get_input(void);