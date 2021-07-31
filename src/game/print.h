#ifndef PRINT_H
#define PRINT_H

#include <PR/ultratypes.h>

#define GLYPH_SPACE           -1
#define GLYPH_U               30
#define GLYPH_EXCLAMATION_PNT 36
#define GLYPH_TWO_EXCLAMATION 37
#define GLYPH_QUESTION_MARK   38
#define GLYPH_AMPERSAND       39
#define GLYPH_PERCENT         40
#define GLYPH_MULTIPLY        50
#define GLYPH_COIN            51
#define GLYPH_MARIO_HEAD      52
#define GLYPH_STAR            53
#define GLYPH_PERIOD          54
#define GLYPH_BETA_KEY        55
#define GLYPH_APOSTROPHE      56
#define GLYPH_DOUBLE_QUOTE    57
#define GLYPH_UMLAUT          58

#define PRINT_TEXT_ALIGN_LEFT 0
#define PRINT_TEXT_ALIGN_CENTRE 1
#define PRINT_TEXT_ALIGN_RIGHT 2
#define PRINT_ALL -1

void print_text_fmt_int(s32 x, s32 y, const char *str, s32 n);
void print_text(s32 x, s32 y, const char *str);
void print_text_centered(s32 x, s32 y, const char *str);
void render_text_labels(void);
void prepare_blank_box(void);
void finish_blank_box(void);
void render_blank_box(s16 x1, s16 y1, s16 x2, s16 y2, u8 r, u8 g, u8 b, u8 a);
extern void print_text_fmt_int_centered(s32 x, s32 y, const char *str, s32 n);
void print_small_text(s32 x, s32 y, u8 *str, s32 align, s32 amount);
void render_multi_image(Texture *image, s32 x, s32 y, s32 width, s32 height, s32 scaleX, s32 scaleY, s32 mode);
s32 get_text_height(u8 *str);
s32 get_text_width(u8 *str);

#endif // PRINT_H
