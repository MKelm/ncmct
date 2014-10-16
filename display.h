void dsp_init(void);
void dsp_end(void);

void dsp_windows_init(void);

void dsp_set_meta(char *title, char *version, char *author, char *year);
void dsp_set_location(char *location);
void dsp_set_output(char *str);

char *dsp_word_wrap(char* buffer, char* string, int line_width);

char *dsp_get_input(void);