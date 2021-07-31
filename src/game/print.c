#include <ultra64.h>

#include "config.h"
#include "game_init.h"
#include "memory.h"
#include "print.h"
#include "segment2.h"
#include "string.h"
#include "engine/math_util.h"
#include "engine/behavior_script.h"

/**
 * This file handles printing and formatting the colorful text that
 * appears when printing things such as "PRESS START".
 */

struct TextLabel {
    u32 x;
    u32 y;
    s16 length;
    char buffer[50];
};

/**
 * Stores the text to be rendered on screen
 * and how they are to be rendered.
 */
struct TextLabel *sTextLabels[52];
s16 sTextLabelsCount = 0;

/**
 * Returns n to the exponent power, only for non-negative powers.
 */
s32 int_pow(s32 n, s32 exponent) {
    s32 result = 1;
    s32 i;

    for (i = 0; i < exponent; i++) {
        result = n * result;
    }

    return result;
}

/**
 * Formats an integer n for print by fitting it to width, prefixing with a negative,
 * and converting the base.
 */
void format_integer(s32 n, s32 base, char *dest, s32 *totalLength, u8 width, s8 zeroPad) {
    u32 powBase;
    s32 numDigits = 0;
    s32 i;
    s32 len = 0;
    s8 digit;
    s8 negative = FALSE;
    char pad;

    if (zeroPad == TRUE) {
        pad = '0';
    } else {
        pad = -1;
    }

    if (n != 0) {
        // Formats a negative number for negative prefix.
        if (n < 0) {
            n = -n;
            negative = TRUE;
        }

        // Increments the number of digits until length is long enough.
        while (TRUE) {
            powBase = int_pow(base, numDigits);

            if (powBase > (u32) n) {
                break;
            }

            numDigits++;
        }

        // Add leading pad to fit width.
        if (width > numDigits) {
            for (len = 0; len < width - numDigits; len++) dest[len] = pad;

            // Needs 1 length to print negative prefix.
            if (negative == TRUE) {
                len--;
            }
        }

        // Use 'M' prefix to indicate negative numbers.
        if (negative == TRUE) {
            dest[len] = 'M';
            len++;
        }

        // Transfer the digits into the proper base.
        for (i = numDigits - 1; i >= 0; i--) {
            powBase = int_pow(base, i);
            digit = n / powBase;

            // FIXME: Why doesn't [] match?
            if (digit < 10) {
                *(dest + len + numDigits - 1 - i) = digit + '0';
            } else {
                *(dest + len + numDigits - 1 - i) = digit + '7';
            }

            n -= digit * powBase;
        }
    } else // n is zero.
    {
        numDigits = 1;
        if (width > numDigits) {
            for (len = 0; len < width - numDigits; len++) dest[len] = pad;
        }
        dest[len] = '0';
    }

    *totalLength += numDigits + len;
}

/**
 * Determines the width of the number for printing, writing to 'width'.
 * Additionally, this determines if a number should be zero-padded,
 * writing to 'zeroPad'.
 */
void parse_width_field(const char *str, s32 *srcIndex, u8 *width, s8 *zeroPad) {
    s8 digits[12]; // unknown length
    s8 digitsLen = 0;
    s16 i;

    // If first character is 0, then the string should be zero padded.
    if (str[*srcIndex] == '0') {
        *zeroPad = TRUE;
    }

    // Read width digits up until the 'd' or 'x' format specifier.
    while (str[*srcIndex] != 'd' && str[*srcIndex] != 'x') {
        digits[digitsLen] = str[*srcIndex] - '0';

        if (digits[digitsLen] < 0 || digits[digitsLen] >= 10) // not a valid digit
        {
            *width = 0;
            return;
        }

        digitsLen++;
        (*srcIndex)++;
    }

    // No digits
    if (digitsLen == 0) {
        return;
    }

    // Sum the digits to calculate the total width.
    for (i = 0; i < digitsLen - 1; i++) {
        *width = *width + digits[i] * ((digitsLen - i - 1) * 10);
    }

    *width = *width + digits[digitsLen - 1];
}

/**
 * Takes a number, finds the intended base, formats the number, and prints it
 * at the given X & Y coordinates.
 *
 * Warning: this fails on too large numbers, because format_integer has bugs
 * related to overflow. For romhacks, prefer sprintf + print_text.
 */
void print_text_fmt_int(s32 x, s32 y, const char *str, s32 n) {
    char c = 0;
    s8 zeroPad = FALSE;
    u8 width = 0;
    s32 base = 0;
    s32 len = 0;
    s32 srcIndex = 0;

    // Don't continue if there is no memory to do so.
    if ((sTextLabels[sTextLabelsCount] = mem_pool_alloc(gEffectsMemoryPool,
                                                        sizeof(struct TextLabel))) == NULL) {
        return;
    }

    sTextLabels[sTextLabelsCount]->x = x;
    sTextLabels[sTextLabelsCount]->y = y;

    c = str[srcIndex];

    while (c != 0) {
        if (c == '%') {
            srcIndex++;

            parse_width_field(str, &srcIndex, &width, &zeroPad);

            if (str[srcIndex] != 'd' && str[srcIndex] != 'x') {
                break;
            }
            if (str[srcIndex] == 'd') {
                base = 10;
            }
            if (str[srcIndex] == 'x') {
                base = 16;
            }

            srcIndex++;

            format_integer(n, base, sTextLabels[sTextLabelsCount]->buffer + len, &len, width, zeroPad);
        } else // straight copy
        {
            sTextLabels[sTextLabelsCount]->buffer[len] = c;
            len++;
            srcIndex++;
        }
        c = str[srcIndex];
    }

    sTextLabels[sTextLabelsCount]->length = len;
    sTextLabelsCount++;
}

/**
 * Prints text in the colorful lettering at given X, Y coordinates.
 */
void print_text(s32 x, s32 y, const char *str) {
    char c = 0;
    s32 length = 0;
    s32 srcIndex = 0;

    // Don't continue if there is no memory to do so.
    if ((sTextLabels[sTextLabelsCount] = mem_pool_alloc(gEffectsMemoryPool,
                                                        sizeof(struct TextLabel))) == NULL) {
        return;
    }

    sTextLabels[sTextLabelsCount]->x = x;
    sTextLabels[sTextLabelsCount]->y = y;

    c = str[srcIndex];

    // Set the array with the text to print while finding length.
    while (c != 0) {
        sTextLabels[sTextLabelsCount]->buffer[length] = c;
        length++;
        srcIndex++;
        c = str[srcIndex];
    }

    sTextLabels[sTextLabelsCount]->length = length;
    sTextLabelsCount++;
}

/**
 * Prints text in the colorful lettering centered at given X, Y coordinates.
 */
void print_text_centered(s32 x, s32 y, const char *str) {
    char c = 0;
    UNUSED s8 unused1 = 0;
    UNUSED s32 unused2 = 0;
    s32 length = 0;
    s32 srcIndex = 0;

    // Don't continue if there is no memory to do so.
    if ((sTextLabels[sTextLabelsCount] = mem_pool_alloc(gEffectsMemoryPool,
                                                        sizeof(struct TextLabel))) == NULL) {
        return;
    }

    c = str[srcIndex];

    // Set the array with the text to print while finding length.
    while (c != 0) {
        sTextLabels[sTextLabelsCount]->buffer[length] = c;
        length++;
        srcIndex++;
        c = str[srcIndex];
    }

    sTextLabels[sTextLabelsCount]->length = length;
    sTextLabels[sTextLabelsCount]->x = x - length * 12 / 2;
    sTextLabels[sTextLabelsCount]->y = y;
    sTextLabelsCount++;
}

/**
 * Converts a char into the proper colorful glyph for the char.
 */
s8 char_to_glyph_index(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 55;
    }

    if (c >= 'a' && c <= 'z') {
        return c - 87;
    }

    if (c >= '0' && c <= '9') {
        return c - 48;
    }

    if (c == ' ') {
        return GLYPH_SPACE;
    }

    if (c == '!') {
        return GLYPH_EXCLAMATION_PNT; // !, JP only
    }

    if (c == '#') {
        return GLYPH_TWO_EXCLAMATION; // !!, JP only
    }

    if (c == '?') {
        return GLYPH_QUESTION_MARK; // ?, JP only
    }

    if (c == '&') {
        return GLYPH_AMPERSAND; // &, JP only
    }

    if (c == '%') {
        return GLYPH_PERCENT; // %, JP only
    }

    if (c == '*') {
        return GLYPH_MULTIPLY; // x
    }

    if (c == '+') {
        return GLYPH_COIN; // coin
    }

    if (c == ',') {
        return GLYPH_MARIO_HEAD; // Imagine I drew Mario's head
    }

    if (c == '-') {
        return GLYPH_STAR; // star
    }

    if (c == '.') {
        return GLYPH_PERIOD; // large shaded dot, JP only
    }

    if (c == '/') {
        return GLYPH_BETA_KEY; // beta key, JP only. Reused for Ü in EU.
    }

    return GLYPH_SPACE;
}

/**
 * Adds an individual glyph to be rendered.
 */
void add_glyph_texture(s8 glyphIndex) {
    const u8 *const *glyphs = segmented_to_virtual(main_hud_lut);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, glyphs[glyphIndex]);
    gSPDisplayList(gDisplayListHead++, dl_hud_img_load_tex_block);
}

/**
 * Renders the glyph that's set at the given position.
 */
void render_textrect(s32 x, s32 y, s32 pos) {
    s32 rectBaseX = x + pos * 12;
    s32 rectBaseY = 224 - y;
    s32 rectX;
    s32 rectY;

    rectX = rectBaseX;
    rectY = rectBaseY;
    gSPTextureRectangle(gDisplayListHead++, rectX << 2, rectY << 2, (rectX + 15) << 2,
                        (rectY + 15) << 2, G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);
}

/**
 * Renders the text in sTextLabels on screen at the proper locations by iterating
 * a for loop.
 */
void render_text_labels(void) {
    s32 i;
    s32 j;
    s8 glyphIndex;
    Mtx *mtx;

    if (sTextLabelsCount == 0) {
        return;
    }

    mtx = alloc_display_list(sizeof(*mtx));

    if (mtx == NULL) {
        sTextLabelsCount = 0;
        return;
    }

    guOrtho(mtx, 0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);
    gSPPerspNormalize((Gfx *) (gDisplayListHead++), 0xFFFF);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);

    for (i = 0; i < sTextLabelsCount; i++) {
        for (j = 0; j < sTextLabels[i]->length; j++) {
            glyphIndex = char_to_glyph_index(sTextLabels[i]->buffer[j]);

            if (glyphIndex != GLYPH_SPACE) {
                add_glyph_texture(glyphIndex);
                render_textrect(sTextLabels[i]->x, sTextLabels[i]->y, j);
            }
        }

        mem_pool_free(gEffectsMemoryPool, sTextLabels[i]);
    }

    gSPDisplayList(gDisplayListHead++, dl_hud_img_end);

    sTextLabelsCount = 0;
}

#define BLANK 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT

void prepare_blank_box(void)
{
    gDPSetCombineMode(gDisplayListHead++, BLANK, BLANK);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
}

void finish_blank_box(void)
{
    gDPSetEnvColor(gDisplayListHead++,255,255,255,255);
    gSPDisplayList(gDisplayListHead++,dl_hud_img_end);
}

void render_blank_box(s16 x1, s16 y1, s16 x2, s16 y2, u8 r, u8 g, u8 b, u8 a)
{
    gDPSetEnvColor(gDisplayListHead++, r, g, b, a);
    gSPScisTextureRectangle(gDisplayListHead++, x1 << 2, y1 << 2, x2 << 2, y2 << 2, 0, 0 << 5, 0 << 5,  4096, 1024);
    gDPPipeSync(gDisplayListHead++);
}


u8 textLen[] = {
    /*0*/ 6, /*1*/ 5, /*2*/ 7, /*3*/ 7, /*4*/ 7, /*5*/ 7, /*6*/ 8, /*7*/ 7, /*8*/ 7, /*9*/ 6, /*-*/ 8, /*+*/ 8, /*(*/ 5, /*)*/ 5, /*!*/ 4, /*?*/ 6,
    /*A*/ 7, /*B*/ 7, /*C*/ 7, /*D*/ 7, /*E*/ 6, /*F*/ 5, /*G*/ 8, /*H*/ 6, /*I*/ 6, /*J*/ 5, /*K*/ 7, /*L*/ 6, /*M*/ 7, /*N*/ 7, /*O*/ 7, /*P*/ 6,
    /*Q*/ 8, /*R*/ 6, /*S*/ 7, /*T*/ 7, /*U*/ 7, /*V*/ 7, /*W*/ 8, /*X*/ 7, /*Y*/ 7, /*Z*/ 7, /*"*/ 5, /*'*/ 2, /*:*/ 3, /*;*/ 3, /*.*/ 3, /*,*/ 3,
    /*a*/ 7, /*b*/ 7, /*c*/ 6, /*d*/ 7, /*e*/ 7, /*f*/ 7, /*g*/ 7, /*h*/ 7, /*i*/ 3, /*j*/ 5, /*k*/ 8, /*l*/ 4, /*m*/ 7, /*n*/ 7, /*o*/ 7, /*p*/ 7,
    /*q*/ 7, /*r*/ 6, /*s*/ 6, /*t*/ 6, /*u*/ 6, /*v*/ 7, /*w*/ 8, /*x*/ 6, /*y*/ 8, /*z*/ 7, /*~*/ 8, /*..*/ 7, /*^*/ 8, /*/*/ 8, /*%*/ 8, /*&*/ 8,
};

#include "level_update.h"

void get_char_from_byte(u8 letter, s32 *textX, s32 *textY, s32 *spaceX, s32 *offsetY)
{
    *offsetY = 0;
    //Line 1
    if (letter >= '0' && letter <= '9')
    {
        *textX = (letter - '0') * 4;
        *textY = 0;
        *spaceX = textLen[letter - '0'];
    }
    else
    //Line 2
    if (letter >= 'A' && letter <= 'P')
    {
        *textX = ((letter - 'A') * 4);
        *textY = 6;
        *spaceX = textLen[letter - 'A'+16];
    }
    else
    //Line 3
    if (letter >= 'Q' && letter <= 'Z')
    {
        *textX = ((letter - 'Q') * 4);
        *textY = 12;
        *spaceX = textLen[letter - 'Q'+32];
    }
    else
    //Line 4
    if (letter >= 'a' && letter <= 'p')
    {
        *textX = ((letter - 'a') * 4);
        *textY = 18;
        *spaceX = textLen[letter - 'a'+48];
    }
    else
    //Line 5
    if (letter >= 'q' && letter <= 'z')
    {
        *textX = ((letter - 'q') * 4);
        *textY = 24;
        *spaceX = textLen[letter - 'q'+64];
    }
    else
    {
        *textX = 128;
        *textY = 0;
        *spaceX = 2;
    }

    switch (letter)
    {
        case '-': *textX = 40; *textY = 0; *spaceX = textLen[10]; break;
        case '+': *textX = 44; *textY = 0; *spaceX = textLen[11]; break;
        case '(': *textX = 48; *textY = 0; *spaceX = textLen[12]; break;
        case ')': *textX = 52; *textY = 0; *spaceX = textLen[13]; break;
        case '!': *textX = 56; *textY = 0; *spaceX = textLen[14]; break;
        case '?': *textX = 60; *textY = 0; *spaceX = textLen[15]; break;

        case '"': *textX = 40; *textY = 12; *spaceX = textLen[42]; break;
        case 0x27: *textX = 44; *textY = 12; *spaceX = textLen[43]; break; //Apostrophe.
        case ':': *textX = 48; *textY = 12; *spaceX = textLen[44]; break;
        case ';': *textX = 52; *textY = 12; *spaceX = textLen[45]; break;
        case '.': *textX = 56; *textY = 12; *spaceX = textLen[46]; break;
        case ',': *textX = 60; *textY = 12; *spaceX = textLen[47]; break;

        case '~': *textX = 40; *textY = 24; *spaceX = textLen[74]; break;
        case '@': *textX = 44; *textY = 24; *spaceX = textLen[75]; break;
        case '^': *textX = 48; *textY = 24; *spaceX = textLen[76]; break;
        case '/': *textX = 52; *textY = 24; *spaceX = textLen[77]; break;
        case '_': *textX = 56; *textY = 24; *spaceX = textLen[78]; break;
        case '&': *textX = 60; *textY = 24; *spaceX = textLen[79]; break;

        case 'g': *offsetY = 1; break;
        case 'q': *offsetY = 1; break;
        case 'p': *offsetY = 3; break;
        case 'y': *offsetY = 1; break;
    }
}

u8 shakeToggle = 0;
u8 waveToggle = 0;

s32 text_iterate_command(u8 *str, s32 i, s32 runCMD)
{
    s32 len = 0;
    while (str[i+len] != '>' && i+len < strlen(str))
        len++;
    len++;

    if (runCMD)
    {
        if (strncmp(str+i, "<COL_xxxxxxxx>", 5) == 0)
        {
            s32 r, g, b, a;
            r = (str[i+5] - '0')*10;
            r += str[i+6] - '0';
            g = (str[i+7] - '0')*10;
            g += str[i+8] - '0';
            b = (str[i+9] - '0')*10;
            b += str[i+10] - '0';
            a = (str[i+11] - '0')*10;
            a += str[i+12] - '0';
            gDPSetEnvColor(gDisplayListHead++, r*2.575f, g*2.575f, b*2.575f, a*2.575f);
        }
        else
        if (strncmp(str+i, "<RAINBOW>", 8) == 0)
        {
            s32 r, g, b;
            r = (coss(gGlobalTimer*600)+1)*127;
            g = (coss((gGlobalTimer*600)+21845)+1)*127;
            b = (coss((gGlobalTimer*600)-21845)+1)*127;
            gDPSetEnvColor(gDisplayListHead++, r, g, b, 0xFF);
        }
        else
        if (strncmp(str+i, "<SHAKE>", 7) == 0)
        {
            shakeToggle^=1;
        }
        else
        if (strncmp(str+i, "<WAVE>", 6) == 0)
        {
            waveToggle^=1;
        }

    }

    return len;
}

s32 get_text_width(u8 *str)
{
    s32 i= 0;
    s32 textPos = 0;
    s32 wideX = 0;
    s32 textX, textY, offsetY, spaceX;

    for (i = 0; i < strlen(str); i++)
    {
    if (str[i] == '#')
    {
        i++;
        textPos = 0;
    }
    if (str[i] == '<')
    {
        i+= text_iterate_command(str, i, FALSE);
    }
    get_char_from_byte(str[i], &textX, &textY, &spaceX, &offsetY);
    textPos+=spaceX+1;
    wideX = MAX(textPos, wideX);
    }
    return wideX;
}

s32 get_text_height(u8 *str)
{
    s32 i= 0;
    s32 textPos = 0;

    for (i = 0; i < strlen(str); i++)
    {
    if (str[i] == '#')
    {
        i++;
        textPos+=12;
    }
    }
    return textPos;
}

void print_small_text(s32 x, s32 y, u8 *str, s32 align, s32 amount)
{
    s32 textX = 0;
    s32 textY = 0;
    s32 offsetY = 0;
    s32 i = 0;
    s32 textPos[2] = {0,0};
    s32 spaceX = 0;
    s32 centreX = 0;
    s32 wideX[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    s32 tx = amount;
    s32 shakePos[2];
    s32 wavePos;
    s32 lines = 0;

    shakeToggle = 0;
    waveToggle = 0;

    if (amount == PRINT_ALL)
        tx = strlen(str);
    gDPSetCombineMode(gDisplayListHead++, G_CC_BLENDI, G_CC_BLENDI);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    if (align == PRINT_TEXT_ALIGN_CENTRE)
    {
        for (i = 0; i < strlen(str); i++)
        {
        if (str[i] == '#')
        {
            i++;
            textPos[0] = 0;
            lines++;
        }
        if (str[i] == '<')
        {
            i+= text_iterate_command(str, i, FALSE);
        }
        get_char_from_byte(str[i], &textX, &textY, &spaceX, &offsetY);
        textPos[0]+=spaceX+1;
        wideX[lines] = MAX(textPos[0], wideX[lines]);
        }
        textPos[0] = -(wideX[0]*0.5f);
    }
    else
    if (align == PRINT_TEXT_ALIGN_RIGHT)
    {
        for (i = 0; i < strlen(str); i++)
        {
        if (str[i] == '#')
        {
            i++;
            textPos[0] = 0;
            lines++;
        }
        else
        {
            textPos[0]+=spaceX+1;
        }
        if (str[i] == '<')
        {
            i+= text_iterate_command(str, i, FALSE);
        }
        get_char_from_byte(str[i], &textX, &textY, &spaceX, &offsetY);

        wideX[lines] = MAX(textPos[0], wideX[lines]);
        }
        textPos[0] = -wideX[0];
    }
    lines = 0;
    gDPLoadTextureBlock_4b(gDisplayListHead++, segmented_to_virtual(small_font), G_IM_FMT_I, 128, 60, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 0, 0, 0, 0, 0);
    for (i = 0; i < tx; i++)
    {
        if (str[i] == '#')
        {
            i++;
            lines++;
            textPos[0] = -(wideX[lines]*0.5f);
            textPos[1] += 12;
        }
        if (str[i] == '<')
        {
            i+= text_iterate_command(str, i, TRUE);
        }
        if (shakeToggle)
        {
            shakePos[0] = -1+(random_u16() % 2);
            shakePos[1] = -1+(random_u16() % 2);
        }
        else
        {
            shakePos[0] = 0;
            shakePos[1] = 0;
        }
        if (waveToggle)
        {
            wavePos = (sins((gGlobalTimer*3000)+(i*10000)))*2;
        }
        else
        {
            wavePos = 0;
        }
        get_char_from_byte(str[i], &textX, &textY, &spaceX, &offsetY);
        gSPScisTextureRectangle(gDisplayListHead++, (x+shakePos[0]+textPos[0]) << 2, (y+shakePos[1]+offsetY+textPos[1]+wavePos) << 2, (x+textPos[0]+shakePos[0]+8) << 2, (y+wavePos+offsetY+shakePos[1]+12+textPos[1]) << 2, G_TX_RENDERTILE, textX << 6, textY << 6, 1 << 10, 1 << 10);
        textPos[0]+=spaceX+1;
    }
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

void render_multi_image(Texture *image, s32 x, s32 y, s32 width, s32 height, s32 scaleX, s32 scaleY, s32 mode)
{
    s32 posW, posH, imW, imH, peakH, maskW, maskH, cycles, num, i, storeMode, modeSC, mOne;
    i = 0;
    num = 256;
    maskW = 1;
    maskH = 1;

    if (mode == G_CYC_COPY)
    {
        gDPSetCycleType(gDisplayListHead++, mode);
        gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
        modeSC = 4;
        mOne = 1;
    }
    else
    {
        gDPSetCycleType(gDisplayListHead++, mode);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        modeSC = 1;
        mOne = 0;
    }


    //Find how best to seperate the horizontal. Keep going until it finds a whole value.
    while (1)
    {
        f32 val =  (f32)width/(f32)num;

        if ((s32)val == val && (s32) val >= 1)
        {
            imW = num;
            break;
        }
        num /= 2;
        if (num == 1)
        {
            print_text(32,32,"IMAGE WIDTH FAILURE");
            return;
        }
    }
    //Find the tile height
    imH = 64/(imW/32); //This gets the vertical amount.

    num = 2;
    //Find the width mask
    while (1)
    {
        if ((s32) num == imW)
            break;

        num*=2;
        maskW++;
        if (maskW == 9)
        {
            print_text(32,32,"WIDTH MASK FAILURE");
            return;
        }
    }
    num = 2;
    //Find the height mask
    while (1)
    {
        if ((s32) num == imH)
            break;

        num*=2;
        maskH++;
        if (maskH == 9)
        {
            print_text(32,32,"HEIGHT MASK FAILURE");
            return;
        }
    }
    num = height;
    //Find the height remainder
    peakH = height - (height % imH);
    cycles = (width*peakH)/(imW*imH);

    //Pass 1
    for (i = 0; i < cycles; i++)
    {
        posW = 0;
        posH = (i*imH);
        while (posH >= peakH)
        {
            posW += imW;
            posH -= peakH;
        }
        gDPLoadSync(gDisplayListHead++);
        gDPLoadTextureTile(gDisplayListHead++, image, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, posW, posH, posW+imW-1, posH+imH-1, 0,  G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, maskW, maskH, 0, 0);
            gSPScisTextureRectangle(gDisplayListHead++, (x + posW) << 2, (y + posH) << 2, (x + posW+imW-mOne) << 2,(y + posH + imH-mOne) << 2, G_TX_RENDERTILE, 0, 0, modeSC << 10, 1 << 10);
    }
    //If there's a remainder on the vertical side, then it will cycle through that too.
    if (height-peakH != 0)
    {
        posW = 0;
        posH = peakH;
        for (i = 0; i < (width/imW); i++)
        {
            posW = i*imW;
            gDPLoadSync(gDisplayListHead++);
            gDPLoadTextureTile(gDisplayListHead++, image, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, posW, posH, posW+imW-1, height-1, 0,  G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, maskW, maskH, 0, 0);
            gSPScisTextureRectangle(gDisplayListHead++, (x + posW) << 2, (y + posH) << 2, (x + posW+imW-mOne) << 2,(y + posH + imH-mOne) << 2, G_TX_RENDERTILE, 0, 0, modeSC << 10, 1 << 10);
        }
    }
}
