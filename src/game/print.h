#ifndef PRINT_H
#define PRINT_H

#include <PR/ultratypes.h>

#define GLYPH_SPACE           0x20
#define GLYPH_U               0x55
#define GLYPH_EXCLAMATION_PNT 0x21
#define GLYPH_TWO_EXCLAMATION 0x0
#define GLYPH_QUESTION_MARK   0x3F
#define GLYPH_AMPERSAND       0x26
#define GLYPH_PERCENT         0x25
#define GLYPH_MULTIPLY        0x2A
#define GLYPH_COIN            0x2B
#define GLYPH_MARIO_HEAD      0x2C
#define GLYPH_STAR            0x2D
#define GLYPH_PERIOD          0x2E
#define GLYPH_BETA_KEY        0x0
#define GLYPH_APOSTROPHE      0x27
#define GLYPH_DOUBLE_QUOTE    0x22
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
