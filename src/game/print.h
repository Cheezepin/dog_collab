#ifndef PRINT_H
#define PRINT_H

#include <PR/ultratypes.h>

#define GLYPH_SPACE           ' '
#define GLYPH_U               'U'
#define GLYPH_EXCLAMATION_PNT '!'
#define GLYPH_TWO_EXCLAMATION 0x0
#define GLYPH_QUESTION_MARK   '?'
#define GLYPH_AMPERSAND       '&'
#define GLYPH_PERCENT         '%'
#define GLYPH_MULTIPLY        '*'
#define GLYPH_COIN            '+'
#define GLYPH_MARIO_HEAD      ','
#define GLYPH_STAR            '-'
#define GLYPH_PERIOD          '.'
#define GLYPH_BETA_KEY        0x0
#define GLYPH_APOSTROPHE      '\''
#define GLYPH_DOUBLE_QUOTE    '"'
#define GLYPH_UMLAUT          0x0

#define PRINT_TEXT_ALIGN_LEFT 0
#define PRINT_TEXT_ALIGN_CENTRE 1
#define PRINT_TEXT_ALIGN_RIGHT 2
#define PRINT_ALL -1

void print_text_fmt_int(s32 x, s32 y, const char *str, s32 n);
void print_text(s32 x, s32 y, const char *str);
void print_text_centered(s32 x, s32 y, const char *str);
void render_text_labels(void);
extern void print_text_fmt_int_centered(s32 x, s32 y, const char *str, s32 n);


#endif // PRINT_H
