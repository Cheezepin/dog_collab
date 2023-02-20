#include <ultra64.h>

#include "actors/common1.h"
#include "area.h"
#include "audio/external.h"
#include "camera.h"
#include "course_table.h"
#include "dialog_ids.h"
#include "engine/math_util.h"
#include "eu_translation.h"
#include "segment_symbols.h"
#include "game_init.h"
#include "gfx_dimensions.h"
#include "hud.h"
#include "ingame_menu.h"
#include "level_update.h"
#include "levels/castle_grounds/header.h"
#include "memory.h"
#include "print.h"
#include "save_file.h"
#include "segment2.h"
#include "segment7.h"
#include "seq_ids.h"
#include "sm64.h"
#include "text_strings.h.in"
#include "types.h"
#include "config.h"
#include "puppycam2.h"
#include "main.h"
#include "puppyprint.h"
#include "rendering_graph_node.h"
#include "actors/group0.h"

#ifdef VERSION_EU
#undef LANGUAGE_FUNCTION
#define LANGUAGE_FUNCTION gInGameLanguage
#endif

u16 gDialogColorFadeTimer;
s8 gLastDialogLineNum;
s32 gDialogVariable;
u16 gDialogTextAlpha;
s16 gCutsceneMsgXOffset;
s16 gCutsceneMsgYOffset;
s8 gRedCoinsCollected;
#if defined(WIDE) && !defined(PUPPYCAM)
u8 textCurrRatio43[] = { TEXT_HUD_CURRENT_RATIO_43 };
u8 textCurrRatio169[] = { TEXT_HUD_CURRENT_RATIO_169 };
u8 textPressL[] = { TEXT_HUD_PRESS_L };
#endif

#if MULTILANG
#define seg2_course_name_table course_name_table_eu_en
#define seg2_act_name_table act_name_table_eu_en
#define seg2_dialog_table dialog_table_eu_en
#endif

s16 gInGameLanguage = LANGUAGE_ENGLISH;
s16 gLoadedLanguage = LANGUAGE_ENGLISH;

void *languageTable[][3] = {
    {&seg2_dialog_table, &seg2_course_name_table, &seg2_act_name_table}, // In EU, this is just mirroring English.
#if MULTILANG
    {&dialog_table_eu_en, &course_name_table_eu_en, &act_name_table_eu_en},
    {&dialog_table_eu_fr, &course_name_table_eu_fr, &act_name_table_eu_fr},
    {&dialog_table_eu_de, &course_name_table_eu_de, &act_name_table_eu_de},
#endif
};

extern u8 gLastCompletedCourseNum;
extern u8 gLastCompletedStarNum;

enum DialogBoxState {
    DIALOG_STATE_OPENING,
    DIALOG_STATE_VERTICAL,
    DIALOG_STATE_HORIZONTAL,
    DIALOG_STATE_CLOSING
};

enum DialogBoxPageState {
    DIALOG_PAGE_STATE_NONE,
    DIALOG_PAGE_STATE_SCROLL,
    DIALOG_PAGE_STATE_END
};

enum DialogBoxType {
    DIALOG_TYPE_ROTATE, // used in NPCs and level messages
    DIALOG_TYPE_ZOOM    // used in signposts and wall signs and etc
};

#define DEFAULT_DIALOG_BOX_ANGLE 90.0f
#define DEFAULT_DIALOG_BOX_SCALE 19.0f

u8 gDialogCharWidths[256] = { // TODO: Is there a way to auto generate this?
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 0:7, 1:7, 2:7, 3:7, 4:7, 5:7, 6:7, 7:7, 8:7, 9:7, A:6, B:6, C:6, D:6, E:6, F:6,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // G:6, H:6, I:5, J:6, K:6, L:5, M:8, N:8, O:6, P:6, Q:6, R:6, S:6, T:5, U:6, V:6,
    6,  5,  6,  0,  0,  7,  8,  4,  5,  5,  6,  0,  4,  6,  4,  0, // W:8, X:7, Y:6, Z:6, a:6, b:5, c:5, d:6, e:5, f:5, g:6, h:5, i:4, j:5, k:5, l:3,
    7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  4,  0,  0,  0,  0,  7, // m:7, n:5, o:5, p:5, q:6, r:5, s:5, t:5, u:5, v:5, w:7, x:7, y:5, z:5, ':4, .:4,
    0,  6,  6,  6,  6,  6,  6,  6,  6,  5,  6,  6,  5,  8,  8,  6, //  :8,  :6,
    6,  6,  6,  6,  5,  6,  6,  8,  7,  6,  6,  0,  0,  0,  0,  0, // ▲:8, ▼:8, <:8, >:8, A:7, B:7, C:6, Z:7, R:7,
    0,  6,  5,  5,  6,  5,  5,  6,  5,  4,  5,  5,  3,  7,  5,  5, //                                                                            ,:4,
    5,  6,  5,  5,  5,  5,  5,  7,  7,  5,  5,  0,  0,  0,  8,  0, //
    8,  8,  8,  8,  7,  7,  6,  7,  7,  0,  0,  0,  0,  0,  0,  0, //
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //                                                                        :5, -:6,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //
    0,  0,  10, 0,  9,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //  :7, (:5,X:10, ):5, ↔:9, &:8, ::4,
    0,  0,  0,  0,  0,  6,  0,  0,  0,  8,  10, 6,  4,  10, 0,  0  //           !:5, %:7, ?:7, “:6, ”:6, ~:8,      ¢:8, ★:10, *:6, ·:4, ☆:10
};

s8 gDialogBoxState = DIALOG_STATE_OPENING;
f32 gDialogBoxOpenTimer = DEFAULT_DIALOG_BOX_ANGLE;
f32 gDialogBoxScale = DEFAULT_DIALOG_BOX_SCALE;
s16 gDialogScrollOffsetY = 0;
s8 gDialogBoxType = DIALOG_TYPE_ROTATE;
s16 gDialogID = DIALOG_NONE;
s16 gLastDialogPageStrPos = 0;
s16 gDialogTextPos = 0;
s8 gDialogLineNum = 1;
s8 gLastDialogResponse = 0;
u8 gMenuHoldKeyIndex = 0;
u8 gMenuHoldKeyTimer = 0;
s32 gDialogResponse = DIALOG_RESPONSE_NONE;
s8 gDialogCurPage = 0;


void create_dl_identity_matrix(void) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

#ifndef GBI_FLOATS
    matrix->m[0][0] = 0x00010000;    matrix->m[1][0] = 0x00000000;    matrix->m[2][0] = 0x00000000;    matrix->m[3][0] = 0x00000000;
    matrix->m[0][1] = 0x00000000;    matrix->m[1][1] = 0x00010000;    matrix->m[2][1] = 0x00000000;    matrix->m[3][1] = 0x00000000;
    matrix->m[0][2] = 0x00000001;    matrix->m[1][2] = 0x00000000;    matrix->m[2][2] = 0x00000000;    matrix->m[3][2] = 0x00000000;
    matrix->m[0][3] = 0x00000000;    matrix->m[1][3] = 0x00000001;    matrix->m[2][3] = 0x00000000;    matrix->m[3][3] = 0x00000000;
#else
    guMtxIdent(matrix);
#endif

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
}

void create_dl_translation_matrix(s8 pushOp, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guTranslate(matrix, x, y, z);

    if (pushOp == MENU_MTX_PUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    }

    if (pushOp == MENU_MTX_NOPUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    }
}

void create_dl_rotation_matrix(s8 pushOp, f32 a, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guRotate(matrix, a, x, y, z);

    if (pushOp == MENU_MTX_PUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    }

    if (pushOp == MENU_MTX_NOPUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    }
}

void create_dl_scale_matrix(s8 pushOp, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guScale(matrix, x, y, z);

    if (pushOp == MENU_MTX_PUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    }

    if (pushOp == MENU_MTX_NOPUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    }
}

void create_dl_ortho_matrix(void) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    create_dl_identity_matrix();

    guOrtho(matrix, 0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);

    // Should produce G_RDPHALF_1 in Fast3D
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
}

// Unused
#if FALSE
static u8 *alloc_ia8_text_from_i1(u16 *in, s16 width, s16 height) {
    s32 inPos;
    u16 bitMask;
    u8 *out;
    s16 outPos = 0;

    out = (u8 *) alloc_display_list((u32) width * (u32) height);

    if (out == NULL) {
        return NULL;
    }

    for (inPos = 0; inPos < (width * height) / 16; inPos++) {
        bitMask = 0x8000;

        while (bitMask != 0) {
            if (in[inPos] & bitMask) {
                out[outPos] = 0xFF;
            } else {
                out[outPos] = 0x00;
            }

            bitMask /= 2;
            outPos++;
        }
    }

    return out;
}

void render_generic_char(u8 c) {
    void **fontLUT = segmented_to_virtual(main_font_lut);
    void *packedTexture = segmented_to_virtual(fontLUT[c]);
#if defined(VERSION_JP) || defined(VERSION_SH)
    void *unpackedTexture = alloc_ia8_text_from_i1(packedTexture, 8, 16);
#endif

#ifndef VERSION_EU
    gDPPipeSync(gDisplayListHead++);
#endif
#if defined(VERSION_JP) || defined(VERSION_SH)
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, VIRTUAL_TO_PHYSICAL(unpackedTexture));
#else
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(packedTexture));
#endif
    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);
#ifdef VERSION_EU
    gSPTextureRectangleFlip(gDisplayListHead++, gDialogX << 2, (gDialogY - 16) << 2,
                            (gDialogX + 8) << 2, gDialogY << 2, G_TX_RENDERTILE, 8 << 6, 4 << 6, 1 << 10, 1 << 10);
#endif
}
#endif

Texture32 *alloc_ia4_tex_from_i1(Texture *in, s16 width, s16 height) {
    u32 size = (u32) width * (u32) height;
    s32 inPos;
    s16 outPos = 0;
    u8 bitMask;

    Texture *out = (Texture *) alloc_display_list(size);

    if (out == NULL) {
        return NULL;
    }

    for (inPos = 0; inPos < (width * height) / 4; inPos++) {
        bitMask = 0x80;

        while (bitMask != 0) {
            out[outPos] = (in[inPos] & bitMask) ? 0xF0 : 0x00;
            bitMask /= 2;
            out[outPos] = (in[inPos] & bitMask) ? out[outPos] + 0x0F : out[outPos];
            bitMask /= 2;
            outPos++;
        }
    }

    return (Texture32 *)out;
}

void render_generic_char(u8 c) {
    void **fontLUT = segmented_to_virtual(main_font_lut);
    void *packedTexture = segmented_to_virtual(fontLUT[c]);
#if MULTILANG
    void *unpackedTexture = alloc_ia4_tex_from_i1(packedTexture, 8, 8);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(unpackedTexture));
#else
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(packedTexture));
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);
}


struct MultiTextEntry {
    u8 length;
    u8 str[4];
};

#define TEXT_THE_RAW 't', 'h', 'e', 0x00
#define TEXT_YOU_RAW 'y', 'o', 'u', 0x00

enum MultiStringIDs { STRING_THE, STRING_YOU };

/*
 * Place the multi-text string according to the ID passed. (US, EU)
 * 0: 'the'
 * 1: 'you'
 */
void render_multi_text_string(s8 multiTextID) {
    s8 i;
    struct MultiTextEntry textLengths[2] = {
        { 3, { TEXT_THE_RAW } },
        { 3, { TEXT_YOU_RAW } },
    };

    for (i = 0; i < textLengths[multiTextID].length; i++) {
        render_generic_char(textLengths[multiTextID].str[i]);
        create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[textLengths[multiTextID].str[i]]), 0.0f, 0.0f);
    }
}

void render_dog_string(void)
{
    s8 i;
    u8 length = DOG_STRING_LENGTH;
    u8 dogString[DOG_STRING_LENGTH + 1];

    for(i = 0; i < DOG_STRING_LENGTH + 1; i++) {
        dogString[i] = save_file_get_dog_string(gCurrSaveFileNum - 1, i);
        if(dogString[i] == 0x0 && length == 12) {
            length = i;
        }
    }
    dogString[DOG_STRING_LENGTH] = 0x0;
    for (i = 0; i < length; i++) {
        render_generic_char(dogString[i]);
        create_dl_translation_matrix(MENU_MTX_NOPUSH, (gDialogCharWidths[dogString[i]]), 0, 0);
    }
}

#define MAX_STRING_WIDTH 16
#define CHAR_WIDTH_SPACE (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE])
#define CHAR_WIDTH_DEFAULT (f32)(gDialogCharWidths[str[strPos]])

/**
 * Prints a generic white string.
 * In JP/EU a IA1 texture is used but in US a IA4 texture is used.
 */
void print_generic_string(s16 x, s16 y, const u8 *str) {
    UNUSED s8 mark = DIALOG_MARK_NONE; // unused in EU
    s32 strPos = 0;
    u8 lineNum = 1;

    s16 colorLoop;
    u8 rgbaColors[4] = {0, 0, 0, 0};
    u8 customColor = FALSE;
    u8 diffTmp = 0;

    create_dl_translation_matrix(MENU_MTX_PUSH, x, y, 0.0f);

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        switch (str[strPos]) {
            case DIALOG_CHAR_COLOR:
                customColor = TRUE;
                strPos++;
                for (colorLoop = strPos + 8; strPos < colorLoop; ++strPos) {
                    if (str[strPos] >= '0' && str[strPos] <= '9') {
                        diffTmp = 0x30;
                    }
                    else if (str[strPos] >= 'A' && str[strPos] <= 'F') {
                        diffTmp = 0x37;
                    }
                    else if (str[strPos] >= 'a' && str[strPos] <= 'f') {
                        diffTmp = 0x57;
                    }
                    else {
                        customColor = 2;
                        strPos = colorLoop - 8;
                        for (diffTmp = 0; diffTmp < 8; ++diffTmp) {
                            if (str[strPos + diffTmp] != '-')
                                break;
                        }
                        if (diffTmp == 8)
                            strPos += diffTmp;
                        break;
                    }
                    if ((8 - (colorLoop - strPos)) % 2 == 0) {
                        rgbaColors[(8 - (colorLoop - strPos)) / 2] = ((str[strPos] - diffTmp) & 0x0F) << 4;
                    }
                    else {
                        rgbaColors[(8 - (colorLoop - strPos)) / 2] += ((str[strPos] - diffTmp) & 0x0F);
                    }
                }
                strPos--;
                if (customColor == 1) {
                    gDPSetEnvColor(gDisplayListHead++, rgbaColors[0],
                                                    rgbaColors[1],
                                                    rgbaColors[2],
                                                    rgbaColors[3]);
                } else if (customColor == 2) {
                    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255); // TODO: Is it possible to retrieve the original color that was set before print_generic_string was called?
                    customColor = 0;
                }
                break;
            case DIALOG_CHAR_DAKUTEN:
                mark = DIALOG_MARK_DAKUTEN;
                break;
            case DIALOG_CHAR_PERIOD_OR_HANDAKUTEN:
                mark = DIALOG_MARK_HANDAKUTEN;
                break;
            case DIALOG_CHAR_NEWLINE:
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                create_dl_translation_matrix(MENU_MTX_PUSH, x, y - (lineNum * MAX_STRING_WIDTH), 0.0f);
                lineNum++;
                break;
            /*case DIALOG_CHAR_PERIOD:
                create_dl_translation_matrix(MENU_MTX_PUSH, -2.0f, -5.0f, 0.0f);
                render_generic_char(DIALOG_CHAR_PERIOD_OR_HANDAKUTEN);
                print_text(20, 20, "yeah");
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                break;*/
            case DIALOG_CHAR_SLASH:
                create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * 2), 0.0f, 0.0f);
                break;
            case DIALOG_CHAR_MULTI_THE:
                render_multi_text_string(STRING_THE);
                break;
            case DIALOG_CHAR_MULTI_YOU:
                render_multi_text_string(STRING_YOU);
                break;
            case DIALOG_CHAR_SPACE:
                create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE]), 0.0f, 0.0f);
                break; // ? needed to match
            case DIALOG_CHAR_DOG:
                render_dog_string();
                break;
            default:
                render_generic_char(str[strPos]);
                if (mark != DIALOG_MARK_NONE) {
                    create_dl_translation_matrix(MENU_MTX_PUSH, 5.0f, 5.0f, 0.0f);
                    render_generic_char(mark + 0xEF);
                    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                    mark = DIALOG_MARK_NONE;
                }

                create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[str[strPos]]), 0.0f, 0.0f);
                break; // what an odd difference. US added a useless break here.
        }

        strPos++;
    }

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

#ifndef qs510
#define qs510(n) ((s16)((n)*0x0400))
#endif

/**
 * Prints a hud string depending of the hud table list defined.
 */
void print_hud_lut_string(s8 hudLUT, s16 x, s16 y, const u8 *str) {
    s32 strPos = 0;
    void **hudLUT1 = segmented_to_virtual(menu_hud_lut); // Japanese Menu HUD Color font
    void **hudLUT2 = segmented_to_virtual(main_hud_lut); // 0-9 A-Z HUD Color Font
    u8 *kernTable = segmented_to_virtual(delfino_hud_kerning_table);
    u8 *lut244Plus = segmented_to_virtual(main_hud_244_lut);
    u8 character;

    u32 curX = x;
    u32 curY = y;

    u32 xStride; // X separation

    if (hudLUT == HUD_LUT_JPMENU) {
        xStride = 16;
    } else { // HUD_LUT_GLOBAL
        xStride = 12; //? Shindou uses this.
    }

    while (str[strPos] != GLOBAR_CHAR_TERMINATOR) {
        switch (str[strPos]) {
            case GLOBAL_CHAR_SPACE:
                curX += 8;
                break;
            default:
                character = str[strPos];
                if (character >= 244) {
                    character = lut244Plus[character - 244];
                }
                gDPPipeSync(gDisplayListHead++);

                if (hudLUT == HUD_LUT_JPMENU) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT1[character]);
                }

                if (hudLUT == HUD_LUT_GLOBAL) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT2[character]);
                }

                s32 isLower = character >= 'a' && character <= 'z';
                u32 yOffsetL = isLower ? 3 : 0;

                gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
                gSPTextureRectangle(
                    gDisplayListHead++,
                    qu102(curX),
                    qu102(curY + yOffsetL),
                    qu102(curX + 16),
                    qu102(curY + 16),
                    G_TX_RENDERTILE,
                    0, 0,
                    qs510(1),
                    isLower ? qs510(1.25f) : qs510(1)
                );

                curX += kernTable[character];
        }
        strPos++;
    }
}


void print_menu_generic_string(s16 x, s16 y, const u8 *str) {
    UNUSED s8 mark = DIALOG_MARK_NONE; // unused in EU
    s32 strPos = 0;
    u32 curX = x;
    u32 curY = y;
    void **fontLUT = segmented_to_virtual(menu_font_lut);

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        switch (str[strPos]) {
            case DIALOG_CHAR_DAKUTEN:
                mark = DIALOG_MARK_DAKUTEN;
                break;
            case DIALOG_CHAR_PERIOD_OR_HANDAKUTEN:
                mark = DIALOG_MARK_HANDAKUTEN;
                break;
            case DIALOG_CHAR_SPACE:
                curX += 4;
                break;
            default:
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[str[strPos]]);
                gDPLoadSync(gDisplayListHead++);
                gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
                gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 8) << 2,
                                    (curY + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

                if (mark != DIALOG_MARK_NONE) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[mark + 0xEF]);
                    gDPLoadSync(gDisplayListHead++);
                    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
                    gSPTextureRectangle(gDisplayListHead++, (curX + 6) << 2, (curY - 7) << 2,
                                        (curX + 6 + 8) << 2, (curY - 7 + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

                    mark = DIALOG_MARK_NONE;
                }
                curX += gDialogCharWidths[str[strPos]];
        }
        strPos++;
    }
}

void print_credits_string(s16 x, s16 y, const u8 *str) {
    s32 strPos = 0;
    void **fontLUT = segmented_to_virtual(main_credits_font_lut);
    u32 curX = x;
    u32 curY = y;

    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0,
                G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0, G_TX_RENDERTILE, 0,
                G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_CLAMP, 3, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, (8 - 1) << G_TEXTURE_IMAGE_FRAC, (8 - 1) << G_TEXTURE_IMAGE_FRAC);

    while (str[strPos] != GLOBAR_CHAR_TERMINATOR) {
        switch (str[strPos]) {
            case /*GLOBAL_CHAR_SPACE*/ 0x7F:
                curX += 4;
                break;
            default:
                gDPPipeSync(gDisplayListHead++);
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[str[strPos]]);
                gDPLoadSync(gDisplayListHead++);
                gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_16b_BYTES));
                gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 8) << 2,
                                    (curY + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                curX += 7;
                break;
        }
        strPos++;
    }
}

void handle_menu_scrolling(s8 scrollDirection, s8 *currentIndex, s8 minIndex, s8 maxIndex) {
    u8 index = 0;

    if (scrollDirection == MENU_SCROLL_VERTICAL) {
        if ((gPlayer1Controller->rawStickY >  60) || (gPlayer1Controller->buttonDown & (U_CBUTTONS | U_JPAD))) index++;
        if ((gPlayer1Controller->rawStickY < -60) || (gPlayer1Controller->buttonDown & (D_CBUTTONS | D_JPAD))) index += 2;
    } else if (scrollDirection == MENU_SCROLL_HORIZONTAL) {
        if ((gPlayer1Controller->rawStickX >  60) || (gPlayer1Controller->buttonDown & (R_CBUTTONS | R_JPAD))) index += 2;
        if ((gPlayer1Controller->rawStickX < -60) || (gPlayer1Controller->buttonDown & (L_CBUTTONS | L_JPAD))) index++;
    }

    if (((index ^ gMenuHoldKeyIndex) & index) == 2) {
        if (*currentIndex != maxIndex) {
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
            (*currentIndex)++;
        }
    }

    if (((index ^ gMenuHoldKeyIndex) & index) == 1) {
        if (*currentIndex != minIndex) {
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
            (*currentIndex)--;
        }
    }

    if (gMenuHoldKeyTimer == 10) {
        gMenuHoldKeyTimer = 8;
        gMenuHoldKeyIndex = 0;
    } else {
        gMenuHoldKeyTimer++;
        gMenuHoldKeyIndex = index;
    }

    if ((index & 3) == 0) {
        gMenuHoldKeyTimer = 0;
    }
}

s32 get_str_x_pos_from_center(s16 centerPos, u8 *str, UNUSED f32 scale) {
    s16 strPos = 0;
    f32 spacesWidth = 0.0f;

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        spacesWidth += gDialogCharWidths[str[strPos]];
        strPos++;
    }
    // return the x position of where the string starts as half the string's
    // length from the position of the provided center.
    return (s16)(centerPos - (s16)(spacesWidth / 2.0f));
}


s32 get_string_width(u8 *str) {
    s16 strPos = 0;
    s16 width = 0;

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        width += gDialogCharWidths[str[strPos]];
        strPos++;
    }
    return width;
}

// accounts for newlines, gets max width plus height
// void get_string_dimensions(u8 *str, Vec2s dimensions) {
//     s16 strPos = 0;

//     dimensions[0] = 0; // line height apparently
//     dimensions[1] = MAX_STRING_WIDTH; // line height apparently
//     s16 width = 0;

//     while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
//         if (str[strPos] == '\n') {
//             if (width > dimensions[0]) dimensions[0] = width;
//             width = 0;
//             dimensions[1] += MAX_STRING_WIDTH;
//             strPos++;
//             continue;
//         }
//         width += gDialogCharWidths[str[strPos]];
//         strPos++;
//     }
// }


void print_hud_my_score_coins(s32 useCourseCoinScore, s8 fileIndex, s8 courseIndex, s16 x, s16 y) {
    u8 strNumCoins[4];
    s16 numCoins;

    if (!useCourseCoinScore) {
        numCoins = (u16)(save_file_get_max_coin_score(courseIndex) & 0xFFFF);
    } else {
        numCoins = save_file_get_course_coin_score(fileIndex, courseIndex);
    }

    if (numCoins != 0) {
        char buf[8];
        sprintf(buf, "+*%d", numCoins);
        print_hud_lut_string(HUD_LUT_GLOBAL, x, y, buf);
    }
}

void print_hud_my_score_stars(s8 fileIndex, s8 courseIndex, s16 x, s16 y) {
    u8 strStarCount[4];
    s16 starCount;

    starCount = save_file_get_course_star_count(fileIndex, courseIndex);

    if (starCount != 0) {
        char buf[8];
        sprintf(buf, "-*%d", starCount);
        print_hud_lut_string(HUD_LUT_GLOBAL, x, y, buf);
    }
}

void int_to_str(s32 num, u8 *dst) {
    sprintf(dst, "%d", num);
}

s32 get_dialog_id(void) {
    return gDialogID;
}

void create_dialog_box(u32 dialog) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TYPE_ROTATE;
    }
}

void create_dialog_box_with_var(u32 dialog, s32 dialogVar) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogVariable = dialogVar;
        gDialogBoxType = DIALOG_TYPE_ROTATE;
    }
}

void create_dialog_inverted_box(u32 dialog) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TYPE_ZOOM;
    }
}

void create_dialog_box_with_response(u32 dialog) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TYPE_ROTATE;
        gLastDialogResponse = 1;
    }
}

void reset_dialog_render_state(void) {
    level_set_transition(0, NULL);

    gDialogBoxScale = 19.0f;
    gDialogBoxOpenTimer = 90.0f;
    gDialogBoxState = DIALOG_STATE_OPENING;
    gDialogID = DIALOG_NONE;
    gDialogTextPos = 0;
    gLastDialogResponse = 0;
    gLastDialogPageStrPos = 0;
    gDialogResponse = DIALOG_RESPONSE_NONE;
}

void render_dialog_box_type(struct DialogEntry *dialog, s8 linesPerBox) {
    create_dl_translation_matrix(MENU_MTX_NOPUSH, dialog->leftOffset, dialog->width, 0);

    switch (gDialogBoxType) {
        case DIALOG_TYPE_ROTATE: // Renders a dialog black box with zoom and rotation
            if ((gDialogBoxState == DIALOG_STATE_OPENING)
             || (gDialogBoxState == DIALOG_STATE_CLOSING)) {
                create_dl_scale_matrix(MENU_MTX_NOPUSH, (1.0f / gDialogBoxScale), (1.0f / gDialogBoxScale), 1.0f);
                // convert the speed into angle
                create_dl_rotation_matrix(MENU_MTX_NOPUSH, (gDialogBoxOpenTimer * 4.0f), 0, 0, 1.0f);
            }
            gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 150);
            break;
        case DIALOG_TYPE_ZOOM: // Renders a dialog white box with zoom
            if (gDialogBoxState == DIALOG_STATE_OPENING || gDialogBoxState == DIALOG_STATE_CLOSING) {
                create_dl_translation_matrix(MENU_MTX_NOPUSH, (65.0f - (65.0f / gDialogBoxScale)), ((40.0f / gDialogBoxScale) - 40), 0);
                create_dl_scale_matrix(MENU_MTX_NOPUSH, (1.0f / gDialogBoxScale), (1.0f / gDialogBoxScale), 1.0f);
            }
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 150);
            break;
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, -7.0f, 5.0f, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.1f, (((f32) linesPerBox / 5.0f) + 0.1f), 1.0f);

    gSPDisplayList(gDisplayListHead++, dl_draw_text_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void change_and_flash_dialog_text_color_lines(s8 colorMode, s8 lineNum, u8 *customColor) {
    u8 colorFade;

    if (colorMode == 1) {
        if (lineNum == 1) {
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
        } else {
            if (lineNum == gDialogLineNum) {
                colorFade = (gSineTable[gDialogColorFadeTimer >> 4] * 50.0f) + 200.0f;
                gDPSetEnvColor(gDisplayListHead++, colorFade, colorFade, colorFade, 255);
            } else {
                gDPSetEnvColor(gDisplayListHead++, 200, 200, 200, 255);
            }
        }
    } else {
        switch (gDialogBoxType) {
            case DIALOG_TYPE_ROTATE:
                if (*customColor == 2) {
                    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
                    *customColor = 0;
                }
                break;
            case DIALOG_TYPE_ZOOM:
                gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
                break;
        }
    }
}

#define X_VAL3 0.0f
#define Y_VAL3 16



void handle_dialog_scroll_page_state(s8 lineNum, s8 totalLines, s8 *pageState, s8 *xMatrix, s16 *linePos) {
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    if (lineNum == totalLines) {
        *pageState = DIALOG_PAGE_STATE_SCROLL;
        return;
    }
    create_dl_translation_matrix(MENU_MTX_PUSH, 0.0f, 2 - (lineNum * 16), 0);

    *linePos = 0;
    *xMatrix = 1;
}

void render_star_count_dialog_text(s8 *xMatrix, s16 *linePos) {
    s8 tensDigit = gDialogVariable / 10;
    s8 onesDigit = gDialogVariable - (tensDigit * 10); // remainder

    if (tensDigit != 0) {
        if (*xMatrix != 1) {
            create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * *xMatrix), 0, 0);
        }

        render_generic_char(tensDigit);
        create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32) gDialogCharWidths[tensDigit], 0, 0);
        *xMatrix = 1;
        (*linePos)++;
    }

    if (*xMatrix != 1) {
        create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * (*xMatrix - 1)), 0, 0);
    }

    render_generic_char(onesDigit);
    create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32) gDialogCharWidths[onesDigit], 0, 0);
    (*linePos)++;
    *xMatrix = 1;
}

void render_multi_text_string_lines(s8 multiTextId, s8 lineNum, s16 *linePos, s8 linesPerBox, s8 xMatrix, s8 lowerBound) {
    s8 i;
    struct MultiTextEntry textLengths[2] = {
        { 3, { TEXT_THE_RAW } },
        { 3, { TEXT_YOU_RAW } },
    };

    if (lineNum >= lowerBound && lineNum <= (lowerBound + linesPerBox)) {
        if (*linePos != 0 || xMatrix != 1) {
            create_dl_translation_matrix(MENU_MTX_NOPUSH, (gDialogCharWidths[DIALOG_CHAR_SPACE] * (xMatrix - 1)), 0, 0);
        }
        for (i = 0; i < textLengths[multiTextId].length; i++) {
            render_generic_char(textLengths[multiTextId].str[i]);
            create_dl_translation_matrix(MENU_MTX_NOPUSH, (gDialogCharWidths[textLengths[multiTextId].str[i]]), 0, 0);
        }
    }
    linePos += textLengths[multiTextId].length;
}

void render_dog_string_lines(s8 lineNum, s16 *linePos, s8 linesPerBox, s8 xMatrix, s8 lowerBound)
{
    s8 i;
    u8 length = DOG_STRING_LENGTH;
    u8 dogString[DOG_STRING_LENGTH + 1];

    for(i = 0; i < DOG_STRING_LENGTH + 1; i++) {
        dogString[i] = save_file_get_dog_string(gCurrSaveFileNum - 1, i);
        if(dogString[i] == 0x0 && length == 12) {
            length = i;
        }
    }
    dogString[DOG_STRING_LENGTH] = 0x0;

    if (lineNum >= lowerBound && lineNum <= (lowerBound + linesPerBox)) {
        if (linePos[0] != 0 || (xMatrix != 1)) {
            create_dl_translation_matrix(MENU_MTX_NOPUSH, (gDialogCharWidths[DIALOG_CHAR_SPACE] * (xMatrix - 1)), 0, 0);
        }
        for (i = 0; i < length; i++) {
            if(dogString[i] != DIALOG_CHAR_SPACE)
                render_generic_char(dogString[i]);
            create_dl_translation_matrix(MENU_MTX_NOPUSH, (gDialogCharWidths[dogString[i]]), 0, 0);
        }
    }
    linePos += length;
}

u32 ensure_nonnegative(s16 value) {
    return ((value < 0) ? 0 : value);
}

void handle_dialog_text_and_pages(s8 colorMode, struct DialogEntry *dialog, s8 lowerBound) {
    u8 strChar;

    s16 colorLoop;
    u8 rgbaColors[4] = {0, 0, 0, 0};
    u8 customColor = FALSE;
    u8 diffTmp = 0;

    u8 *str = segmented_to_virtual(dialog->str);
    s8 lineNum = 1;

    s8 totalLines;

    s8 pageState = DIALOG_PAGE_STATE_NONE;
    UNUSED s8 mark = DIALOG_MARK_NONE; // unused in US, EU
    s8 xMatrix = 1;

    s8 linesPerBox = dialog->linesPerBox;

    s16 strIdx;
    s16 linePos = 0;

    if (gDialogBoxState == DIALOG_STATE_HORIZONTAL) {
        // If scrolling, consider the number of lines for both
        // the current page and the page being scrolled to.
        totalLines = linesPerBox * 2 + 1;
    } else {
        totalLines = linesPerBox + 1;
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    strIdx = gDialogTextPos;

    if (gDialogBoxState == DIALOG_STATE_HORIZONTAL) {
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 0, (f32) gDialogScrollOffsetY, 0);
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL3, 2 - lineNum * Y_VAL3, 0);

    while (pageState == DIALOG_PAGE_STATE_NONE) {
        if (customColor == TRUE) {
            gDPSetEnvColor(gDisplayListHead++, rgbaColors[0], rgbaColors[1], rgbaColors[2], rgbaColors[3]);
        }
        else {
            change_and_flash_dialog_text_color_lines(colorMode, lineNum, &customColor);
        }
        strChar = str[strIdx];

        switch (strChar) {
            case DIALOG_CHAR_TERMINATOR:
                pageState = DIALOG_PAGE_STATE_END;
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                break;
            case DIALOG_CHAR_COLOR:
                customColor = TRUE;
                strIdx++;
                for (colorLoop = strIdx + 8; strIdx < colorLoop; ++strIdx) {
                    if (str[strIdx] >= '0' && str[strIdx] <= '9') {
                        diffTmp = 0x30;
                    }
                    else if (str[strIdx] >= 'A' && str[strIdx] <= 'F') {
                        diffTmp = 0x37;
                    }
                    else if (str[strIdx] >= 'a' && str[strIdx] <= 'f') {
                        diffTmp = 0x57;
                    }
                    else {
                        customColor = 2;
                        strIdx = colorLoop - 8;
                        for (diffTmp = 0; diffTmp < 8; ++diffTmp) {
                            if (str[strIdx + diffTmp] != '-')
                                break;
                        }
                        if (diffTmp == 8)
                            strIdx += diffTmp;
                        break;
                    }
                    if ((8 - (colorLoop - strIdx)) % 2 == 0) {
                        rgbaColors[(8 - (colorLoop - strIdx)) / 2] = ((str[strIdx] - diffTmp) & 0x0F) << 4;
                    }
                    else {
                        rgbaColors[(8 - (colorLoop - strIdx)) / 2] += ((str[strIdx] - diffTmp) & 0x0F);
                    }
                }
                strIdx--;
                break;
            case DIALOG_CHAR_NEWLINE:
                lineNum++;
                handle_dialog_scroll_page_state(lineNum, totalLines, &pageState, &xMatrix, &linePos);
                break;
            case DIALOG_CHAR_DAKUTEN:
                mark = DIALOG_MARK_DAKUTEN;
                break;
            case DIALOG_CHAR_PERIOD_OR_HANDAKUTEN:
                mark = DIALOG_MARK_HANDAKUTEN;
                break;
            case DIALOG_CHAR_SPACE:
                xMatrix++;
                linePos++;

                break;
            case DIALOG_CHAR_SLASH:
                xMatrix += 2;
                linePos += 2;
                break;
            case DIALOG_CHAR_MULTI_THE:
                render_multi_text_string_lines(STRING_THE, lineNum, &linePos, linesPerBox, xMatrix, lowerBound);
                xMatrix = 1;
                break;
            case DIALOG_CHAR_MULTI_YOU:
                render_multi_text_string_lines(STRING_YOU, lineNum, &linePos, linesPerBox, xMatrix, lowerBound);
                xMatrix = 1;
                break;
            case DIALOG_CHAR_STAR_COUNT:
                render_star_count_dialog_text(&xMatrix, &linePos);
                break;
            case DIALOG_CHAR_DOG:
                render_dog_string_lines(lineNum, &linePos, linesPerBox, xMatrix, lowerBound);
                break;
            default: // any other character
                if (lineNum >= lowerBound && lineNum <= lowerBound + linesPerBox) {
                    if (linePos || xMatrix != 1) {
                        create_dl_translation_matrix(
                            MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * (xMatrix - 1)), 0, 0);
                    }

                    render_generic_char(strChar);
                    create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[strChar]), 0, 0);
                    xMatrix = 1;
                    linePos++;
                }
        }


        strIdx++;
    }
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    if (gDialogBoxState == DIALOG_STATE_VERTICAL) {
        if (pageState == DIALOG_PAGE_STATE_END) {
            gLastDialogPageStrPos = -1;
        } else {
            gLastDialogPageStrPos = strIdx;
        }
    }

    gLastDialogLineNum = lineNum;
}

#define X_VAL4_1 56
#define X_VAL4_2 47
#define Y_VAL4_1  2
#define Y_VAL4_2 16

void render_dialog_triangle_choice(void) {
    if (gDialogBoxState == DIALOG_STATE_VERTICAL) {
        handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, &gDialogLineNum, 1, 2);
    }

    create_dl_translation_matrix(MENU_MTX_NOPUSH, (gDialogLineNum * X_VAL4_1) - X_VAL4_2, Y_VAL4_1 - (gLastDialogLineNum * Y_VAL4_2), 0);

    if (gDialogBoxType == DIALOG_TYPE_ROTATE) {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    }

    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
}

#define X_VAL5 (DIALOG_BOX_WIDTH - 12.0f)
#define Y_VAL5_1 -16
#define Y_VAL5_2 5
#define X_Y_VAL6 0.8f

void render_dialog_string_color(s8 linesPerBox) {
    s32 timer = gGlobalTimer;

    if (timer & 0x08) {
        return;
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL5, (linesPerBox * Y_VAL5_1) + Y_VAL5_2, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, X_Y_VAL6, X_Y_VAL6, 1.0f);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, -DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);

    if (gDialogBoxType == DIALOG_TYPE_ROTATE) { // White Text
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    } else { // Black Text
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    }

    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void render_dialog_triangle_next(s8 linesPerBox) {
    s32 globalTimer = gGlobalTimer;

    if (globalTimer & 0x8) {
        return;
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL5, (linesPerBox * Y_VAL5_1) + Y_VAL5_2, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, X_Y_VAL6, X_Y_VAL6, 1.0f);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, -DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);

    if (gDialogBoxType == DIALOG_TYPE_ROTATE) { // White Text
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    } else { // Black Text
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    }

    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void handle_special_dialog_text(u32 dialogID) { // dialog ID tables, in order
    // King Bob-omb (Start), Whomp (Start), King Bob-omb (throw him out), Eyerock (Start), Wiggler (Start)
    u32 dialogBossStart[] = { DIALOG_017, DIALOG_128, DIALOG_117 };
    // Koopa the Quick (BOB), Koopa the Quick (THI), Penguin Race, Fat Penguin Race (120 stars)
    u32 dialogRaceSound[] = { DIALOG_082/*, DIALOG_009, DIALOG_055*/ };
    // Red Switch, Green Switch, Blue Switch, 100 coins star, Bowser Red Coin Star
    u32 dialogStarSound[] = { DIALOG_010, DIALOG_011, DIALOG_012, DIALOG_013, DIALOG_014 };
    // King Bob-omb (Start), Whomp (Defeated), King Bob-omb (Defeated, missing in JP), Eyerock (Defeated), Wiggler (Defeated)
    u32 dialogBossStop[] = { DIALOG_017, DIALOG_116, DIALOG_118 };
    s16 i;

    for (i = 0; i < (s16) ARRAY_COUNT(dialogBossStart); i++) {
        if (dialogBossStart[i] == dialogID) {
            seq_player_unlower_volume(SEQ_PLAYER_LEVEL, 60);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_EVENT_BOSS), 0);
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogRaceSound); i++) {
        if (dialogRaceSound[i] == dialogID && gDialogLineNum == 1) {
            play_race_fanfare();
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogStarSound); i++) {
        if (dialogStarSound[i] == dialogID && gDialogLineNum == 1) {
            play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogBossStop); i++) {
        if (dialogBossStop[i] == dialogID) {
            seq_player_fade_out(SEQ_PLAYER_LEVEL, 1);
            return;
        }
    }
}

s16 gMenuMode = MENU_MODE_NONE;

u8 gEndCutsceneStrEn0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrEn1[] = { TEXT_POWER_STARS_RESTORED };
u8 gEndCutsceneStrEn2[] = { TEXT_THANKS_TO_YOU };
u8 gEndCutsceneStrEn3[] = { TEXT_THANK_YOU_MARIO };
u8 gEndCutsceneStrEn4[] = { TEXT_SOMETHING_SPECIAL };
u8 gEndCutsceneStrEn5[] = { TEXT_LISTEN_EVERYBODY };
u8 gEndCutsceneStrEn6[] = { TEXT_LETS_HAVE_CAKE };
u8 gEndCutsceneStrEn7[] = { TEXT_FOR_MARIO };
u8 gEndCutsceneStrEn8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsEn[] = {
    gEndCutsceneStrEn0,
    gEndCutsceneStrEn1,
    gEndCutsceneStrEn2,
    gEndCutsceneStrEn3,
    gEndCutsceneStrEn4,
    gEndCutsceneStrEn5,
    gEndCutsceneStrEn6,
    gEndCutsceneStrEn7,
    // This [8] string is actually unused. In the cutscene handler, the developers do not
    // set the 8th one, but use the first string again at the very end, so Peach ends up
    // saying "Mario!" twice. It is likely that she was originally meant to say "Mario?" at
    // the end but the developers changed their mind, possibly because the line recorded
    // sounded more like an exclamation than a question.
    gEndCutsceneStrEn8,
    NULL
};


u16 gCutsceneMsgFade        =  0;
s16 gCutsceneMsgIndex       = -1;
s16 gCutsceneMsgDuration    = -1;
s16 gCutsceneMsgTimer       =  0;
s8  gDialogCameraAngleIndex = CAM_SELECTION_MARIO;
s8  gDialogCourseActNum     =  1;

#define DIAG_VAL1  16
#define DIAG_VAL3 132 // US & EU
#define DIAG_VAL4   5
#define DIAG_VAL2 240 // JP & US

void render_dialog_entries(void) {
    void **dialogTable;
    struct DialogEntry *dialog;
    s8 lowerBound = 0;
    dialogTable = segmented_to_virtual(languageTable[gInGameLanguage][0]);
    dialog = segmented_to_virtual(dialogTable[gDialogID]);
    if (dialog->unused != 1) {
        dialogTable = segmented_to_virtual(languageTable[gInGameLanguage][0]);
        dialog = segmented_to_virtual(dialogTable[gDialogID]);
    }

    // if the dialog entry is invalid, set the ID to -1.
    if (segmented_to_virtual(NULL) == dialog) {
        gDialogID = DIALOG_NONE;
        return;
    }

    switch (gDialogBoxState) {
        case DIALOG_STATE_OPENING:
            if (gDialogBoxOpenTimer == DEFAULT_DIALOG_BOX_ANGLE) {
                play_dialog_sound(dialog->voice, gDialogID);
                play_sound(SOUND_MENU_MESSAGE_APPEAR, gGlobalSoundSource);
            }

            if (gDialogBoxType == DIALOG_TYPE_ROTATE) {
                gDialogBoxOpenTimer -= 7.5f;
                gDialogBoxScale -= 1.5f;
            } else {
                gDialogBoxOpenTimer -= 10.0f;
                gDialogBoxScale -= 2.0f;
            }

            if (gDialogBoxOpenTimer == 0.0f) {
                gDialogBoxState = DIALOG_STATE_VERTICAL;
                gDialogLineNum = 1;
            }
            lowerBound = 1;
            break;
        case DIALOG_STATE_VERTICAL:
            gDialogBoxOpenTimer = 0.0f;

            if ((gPlayer1Controller->buttonPressed & A_BUTTON)
                || (gPlayer1Controller->buttonPressed & B_BUTTON)) {
                    gDialogCurPage += 1;
                if (gLastDialogPageStrPos == -1) {
                    handle_special_dialog_text(gDialogID);
                    gDialogBoxState = DIALOG_STATE_CLOSING;
                } else {
                    gDialogBoxState = DIALOG_STATE_HORIZONTAL;
                    play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gGlobalSoundSource);
                }
            }
            lowerBound = 1;
            break;
        case DIALOG_STATE_HORIZONTAL:
            gDialogScrollOffsetY += dialog->linesPerBox * 2;

            if (gDialogScrollOffsetY >= dialog->linesPerBox * DIAG_VAL1) {
                gDialogTextPos = gLastDialogPageStrPos;
                gDialogBoxState = DIALOG_STATE_VERTICAL;
                gDialogScrollOffsetY = 0;
            }
            lowerBound = (gDialogScrollOffsetY / DIAG_VAL1) + 1;
            break;
        case DIALOG_STATE_CLOSING:
        gDialogCurPage = 0;
            if (gDialogBoxOpenTimer == 20.0f) {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gGlobalSoundSource);

                if (gDialogBoxType == DIALOG_TYPE_ZOOM) {
                    trigger_cutscene_dialog(2);
                }

                gDialogResponse = gDialogLineNum;
            }

            gDialogBoxOpenTimer = gDialogBoxOpenTimer + 10.0f;
            gDialogBoxScale = gDialogBoxScale + 2.0f;

            if (gDialogBoxOpenTimer == DEFAULT_DIALOG_BOX_ANGLE) {
                gDialogBoxState = DIALOG_STATE_OPENING;
                gDialogID = DIALOG_NONE;
                gDialogTextPos = 0;
                gLastDialogResponse = 0;
                gLastDialogPageStrPos = 0;
                gDialogResponse = DIALOG_RESPONSE_NONE;
            }
            lowerBound = 1;
            break;
    }

    render_dialog_box_type(dialog, dialog->linesPerBox);

    gDPSetScissor(
        gDisplayListHead++, G_SC_NON_INTERLACE,
        0,
        ensure_nonnegative(DIAG_VAL2 - dialog->width),
        SCREEN_WIDTH,
        ensure_nonnegative((240 - dialog->width) + (dialog->linesPerBox * 80 / DIAG_VAL4))
    );
    handle_dialog_text_and_pages(0, dialog, lowerBound);

    if (gLastDialogPageStrPos == -1 && gLastDialogResponse == 1) {
        render_dialog_triangle_choice();
    }
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 2, 2, SCREEN_WIDTH - gBorderHeight/2, SCREEN_HEIGHT - gBorderHeight/2);
    if (gLastDialogPageStrPos != -1 && gDialogBoxState == DIALOG_STATE_VERTICAL) {
        render_dialog_string_color(dialog->linesPerBox);
    }
}

// Calls a gMenuMode value defined by render_menus_and_dialogs cases
void set_menu_mode(s16 mode) {
    if (gMenuMode == MENU_MODE_NONE) {
        gMenuMode = mode;
    }
}

void reset_cutscene_msg_fade(void) {
    gCutsceneMsgFade = 0;
}

void dl_rgba16_begin_cutscene_msg_fade(void) {
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);
}

void dl_rgba16_stop_cutscene_msg_fade(void) {
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    if (gCutsceneMsgFade < 250) {
        gCutsceneMsgFade += 25;
    } else {
        gCutsceneMsgFade = 255;
    }
}

u32 ascii_to_credits_char(u8 c) {
    if (c >= 'A' && c <= 'Z') return (c - ('A' - 0xA));
    if (c >= 'a' && c <= 'z') return (c - ('a' - 0xA)); // remap lower to upper case
    if (c == ' ') return /*GLOBAL_CHAR_SPACE*/ 0x7F;
    if (c == '.') return 0x24;
    if (c == '\'') return 0x25;
    if (c == '0') return ASCII_TO_DIALOG('0');
    if (c == '1') return ASCII_TO_DIALOG('1');
    if (c == '2') return ASCII_TO_DIALOG('2');
    if (c == '3') return ASCII_TO_DIALOG('3');
    if (c == '4') return ASCII_TO_DIALOG('4');
    if (c == '5') return ASCII_TO_DIALOG('5');
    if (c == '6') return ASCII_TO_DIALOG('6');
    if (c == '7') return ASCII_TO_DIALOG('7');
    if (c == '9') return ASCII_TO_DIALOG('9');

    return GLOBAL_CHAR_SPACE;
}

void print_credits_str_ascii(s16 x, s16 y, const char *str) {
    s32 pos = 0;
    u8 c = str[pos];
    u8 creditStr[100];

    while (c != 0) {
        creditStr[pos++] = ascii_to_credits_char(c);
        c = str[pos];
    }

    creditStr[pos] = GLOBAR_CHAR_TERMINATOR;

    print_credits_string(x, y, creditStr);
}

void set_cutscene_message(s16 xOffset, s16 yOffset, s16 msgIndex, s16 msgDuration) {
    // is message done printing?
    if (gCutsceneMsgIndex == -1) {
        gCutsceneMsgIndex = msgIndex;
        gCutsceneMsgDuration = msgDuration;
        gCutsceneMsgTimer = 0;
        gCutsceneMsgXOffset = xOffset;
        gCutsceneMsgYOffset = yOffset;
        gCutsceneMsgFade = 0;
    }
}

void do_cutscene_handler(void) {
    // is a cutscene playing? do not perform this handler's actions if so.
    if (gCutsceneMsgIndex == -1) {
        return;
    }
    
    create_dl_ortho_matrix();

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);

    // get the x coordinate of where the cutscene string starts.
    s16 x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex], 10.0f);
    print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex]);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    // if the timing variable is less than 5, increment
    // the fade until we are at full opacity.
    if (gCutsceneMsgTimer < 5) {
        gCutsceneMsgFade += 50;
    }

    // if the cutscene frame length + the fade-in counter is
    // less than the timer, it means we have exceeded the
    // time that the message is supposed to remain on
    // screen. if (message_duration = 50) and (msg_timer = 55)
    // then after the first 5 frames, the message will remain
    // on screen for another 50 frames until it starts fading.
    if (gCutsceneMsgDuration + 5 < gCutsceneMsgTimer) {
        gCutsceneMsgFade -= 50;
    }

    // like the first check, it takes 5 frames to fade out, so
    // perform a + 10 to account for the earlier check (10-5=5).
    if (gCutsceneMsgDuration + 10 < gCutsceneMsgTimer) {
        gCutsceneMsgIndex = -1;
        gCutsceneMsgFade = 0;
        gCutsceneMsgTimer = 0;
        return;
    }

    gCutsceneMsgTimer++;
}

#define PEACH_MESSAGE_TIMER 250

#define STR_X  38
#define STR_Y 142

// "Dear Mario" message handler
void print_peach_letter_message(void) {
#ifdef VERSION_EU
    void **dialogTable;
    gInGameLanguage = eu_get_language();
    switch (gInGameLanguage) {
        default:
        case LANGUAGE_ENGLISH: dialogTable = segmented_to_virtual(dialog_table_eu_en); break;
        case LANGUAGE_FRENCH:  dialogTable = segmented_to_virtual(dialog_table_eu_fr); break;
        case LANGUAGE_GERMAN:  dialogTable = segmented_to_virtual(dialog_table_eu_de); break;
    }
#else
    void **dialogTable = segmented_to_virtual(seg2_dialog_table);
#endif
    struct DialogEntry *dialog = segmented_to_virtual(dialogTable[gDialogID]);
    u8 *str = segmented_to_virtual(dialog->str);

    create_dl_translation_matrix(MENU_MTX_PUSH, 97.0f, 118.0f, 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);
    gSPDisplayList(gDisplayListHead++, castle_grounds_seg7_dl_0700EA58);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 20, 20, 20, gCutsceneMsgFade);

    print_generic_string(STR_X, STR_Y, str);
#ifdef VERSION_JP
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
#else
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    gDPSetEnvColor(gDisplayListHead++, 200, 80, 120, gCutsceneMsgFade);
    gSPDisplayList(gDisplayListHead++, castle_grounds_seg7_us_dl_0700F2E8);
#endif

    // at the start/end of message, reset the fade.
    if (gCutsceneMsgTimer == 0) {
        gCutsceneMsgFade = 0;
    }

    // we're less than 20 increments, so increase the fade.
    if (gCutsceneMsgTimer < 20) {
        gCutsceneMsgFade += 10;
    }

    // we're after PEACH_MESSAGE_TIMER increments, so decrease the fade.
    if (gCutsceneMsgTimer > PEACH_MESSAGE_TIMER) {
        gCutsceneMsgFade -= 10;
    }

    // 20 increments after the start of the decrease, we're
    // back where we are, so reset everything at the end.
    if (gCutsceneMsgTimer > (PEACH_MESSAGE_TIMER + 20)) {
        gCutsceneMsgIndex = -1;
        gCutsceneMsgFade = 0; //! uselessly reset since the next execution will just set it to 0 again.
        gDialogID = DIALOG_NONE;
        gCutsceneMsgTimer = 0;
        return; // return to avoid incrementing the timer
    }

    gCutsceneMsgTimer++;
}

/**
 * Renders the cannon reticle when Mario is inside a cannon.
 * Formed by four triangles.
 */
void render_hud_cannon_reticle(void) {
    create_dl_translation_matrix(MENU_MTX_PUSH, 160.0f, 120.0f, 0);

    gDPSetEnvColor(gDisplayListHead++, 50, 50, 50, 180);
    create_dl_translation_matrix(MENU_MTX_PUSH, -20.0f, -8.0f, 0);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, 20.0f, 8.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 180.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, 8.0f, -20.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, -8.0f, 20.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, -DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void reset_red_coins_collected(void) {
    gRedCoinsCollected = 0;
}

void change_dialog_camera_angle(void) {
    if (cam_select_alt_mode(0) == CAM_SELECTION_MARIO) {
        gDialogCameraAngleIndex = CAM_SELECTION_MARIO;
    } else {
        gDialogCameraAngleIndex = CAM_SELECTION_FIXED;
    }
}

void shade_screen(void) {
    create_dl_translation_matrix(MENU_MTX_PUSH, GFX_DIMENSIONS_FROM_LEFT_EDGE(0), SCREEN_HEIGHT, 0);

    // This is a bit weird. It reuses the dialog text box (width 130, height -80),
    // so scale to at least fit the screen.
#ifdef WIDESCREEN
    create_dl_scale_matrix(MENU_MTX_NOPUSH,
                           GFX_DIMENSIONS_ASPECT_RATIO * SCREEN_HEIGHT / 130.0f, 3.0f, 1.0f);
#else
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.6f, 3.4f, 1.0f);
#endif

    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 110);
    gSPDisplayList(gDisplayListHead++, dl_draw_text_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void shade_screen_amount(int amount) {
    create_dl_translation_matrix(MENU_MTX_PUSH, GFX_DIMENSIONS_FROM_LEFT_EDGE(0), SCREEN_HEIGHT, 0);

    // This is a bit weird. It reuses the dialog text box (width 130, height -80),
    // so scale to at least fit the screen.
#ifndef WIDESCREEN
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.6f, 3.4f, 1.0f);
#else
    create_dl_scale_matrix(MENU_MTX_NOPUSH,
                           GFX_DIMENSIONS_ASPECT_RATIO * SCREEN_HEIGHT / 130.0f, 3.0f, 1.0f);
#endif

    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, amount);
    gSPDisplayList(gDisplayListHead++, dl_draw_text_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void shade_screen_col(int r, int g, int b, int a) {
    create_dl_translation_matrix(MENU_MTX_PUSH, GFX_DIMENSIONS_FROM_LEFT_EDGE(0), SCREEN_HEIGHT, 0);

    // This is a bit weird. It reuses the dialog text box (width 130, height -80),
    // so scale to at least fit the screen.
#ifndef WIDESCREEN
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.6f, 3.4f, 1.0f);
#else
    create_dl_scale_matrix(MENU_MTX_NOPUSH,
                           GFX_DIMENSIONS_ASPECT_RATIO * SCREEN_HEIGHT / 130.0f, 3.0f, 1.0f);
#endif

    gDPSetEnvColor(gDisplayListHead++, r, g, b, a);
    gSPDisplayList(gDisplayListHead++, dl_draw_text_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void print_animated_red_coin(s16 x, s16 y) {
    s32 globalTimer = gGlobalTimer;

    create_dl_translation_matrix(MENU_MTX_PUSH, x, y, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.2f, 0.2f, 1.0f);
    gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

#ifdef IA8_30FPS_COINS
    switch (globalTimer & 0x7) {
        case 0: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_0     ); break;
        case 1: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_22_5  ); break;
        case 2: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_45    ); break;
        case 3: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_67_5  ); break;
        case 4: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_90    ); break;
        case 5: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_67_5_r); break;
        case 6: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_45_r  ); break;
        case 7: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_22_5_r); break;
    }
#else
    switch (globalTimer & 0x6) {
        case 0: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_front     ); break;
        case 2: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_tilt_right); break;
        case 4: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_side      ); break;
        case 6: gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_tilt_left ); break;
    }
#endif

    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void print_animated_red_bone(s16 x, s16 y) {
    s32 globalTimer = gGlobalTimer;

    create_dl_translation_matrix(MENU_MTX_PUSH, x, y, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.25f, 0.25f, 0.1f);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, (f32)(globalTimer*4), 0.0f, 1.0f, 0.0f);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);

    gSPDisplayList(gDisplayListHead++, dog_bone_root_mesh_layer_1);

    gSPDisplayList(gDisplayListHead++, dog_bone_material_revert_render_settings);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void render_pause_red_coins(void) {
    s8 x;
    s32 bonesCollected = save_file_get_dog_bone_count(gCurrSaveFileNum - 1);

    if((gCurrLevelNum == LEVEL_PSS || gCurrLevelNum == LEVEL_BITS) && bonesCollected > 0) {
        for (x = 0; x < bonesCollected; x++) {
            print_animated_red_bone(GFX_DIMENSIONS_FROM_RIGHT_EDGE(34) - x * 20, 20);
        }
    } else {
        for (x = 0; x < gRedCoinsCollected; x++) {
            print_animated_red_coin(GFX_DIMENSIONS_FROM_RIGHT_EDGE(34) - x * 20, 20);
        }
    }
}

/// By default, not needed as puppycamera has an option, but should you wish to revert that, you are legally allowed.

#if FALSE
void render_widescreen_setting(void) {
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    if (!gConfig.widescreen) {
        print_generic_string(10, (SCREEN_HEIGHT - gScreenHeight) + 20, textCurrRatio43);
        print_generic_string(10,  (SCREEN_HEIGHT - gScreenHeight) + 7, textPressL);
    } else {
        print_generic_string(10, (SCREEN_HEIGHT - gScreenHeight) + 20, textCurrRatio169);
        print_generic_string(10,  (SCREEN_HEIGHT - gScreenHeight) + 7, textPressL);
    }
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    if (gPlayer1Controller->buttonPressed & L_TRIG){
        gConfig.widescreen ^= 1;
        save_file_set_widescreen_mode(gConfig.widescreen);
    }
}
#endif

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define CRS_NUM_X1 93
#elif defined(VERSION_US)
    #define CRS_NUM_X1 100
#elif defined(VERSION_EU)
    #define CRS_NUM_X1 get_string_width(LANGUAGE_ARRAY(textCourse)) + 51
#endif

#ifdef VERSION_EU
    #define TXT_COURSE_X      48
    #define TXT_STAR_X        89
    #define ACT_NAME_X        107
    #define LVL_NAME_X        108
    #define SECRET_LVL_NAME_X get_str_x_pos_from_center(159, &courseName[3], 10.0f)
    #define MYSCORE_X         48
#else
    #define TXT_COURSE_X      63
    #define TXT_STAR_X        98
    #define ACT_NAME_X        116
    #define LVL_NAME_X        117
    #define SECRET_LVL_NAME_X 94
    #define MYSCORE_X         62
#endif

u8 coursesFixed[] = {
    0, 3, 4, 6, 5, 2, 9, 8, 7, 10, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void render_pause_my_score_coins(void) {
    u8 textCourse[] = { TEXT_COURSE };
    u8 textMyScore[] = { TEXT_MY_SCORE };
    u8 textStar[] = { TEXT_STAR };
    u8 textUnfilledStar[] = { TEXT_UNFILLED_STAR };
    s16 actNameX;

    u8 strCourseNum[4];

    void **courseNameTbl = segmented_to_virtual(languageTable[gInGameLanguage][1]);
    void    **actNameTbl = segmented_to_virtual(languageTable[gInGameLanguage][2]);

    u8 courseIndex = COURSE_NUM_TO_INDEX(gCurrCourseNum);
    u8 starFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    if (courseIndex <= COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX)) {
        print_hud_my_score_coins(1, gCurrSaveFileNum - 1, courseIndex, 178, 103);
        print_hud_my_score_stars(gCurrSaveFileNum - 1, courseIndex, 118, 103);
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    if (courseIndex <= COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX)
        && (save_file_get_course_star_count(gCurrSaveFileNum - 1, courseIndex) != 0)) {
        print_generic_string(MYSCORE_X, 121, LANGUAGE_ARRAY(textMyScore));
    }

    u8 *courseName = segmented_to_virtual(courseNameTbl[courseIndex]);

    if (courseIndex <= COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX)) {
        u8 concString[64];
        s16 concStringX;
        // print_generic_string(TXT_COURSE_X, 157, LANGUAGE_ARRAY(textCourse));
        int_to_str(coursesFixed[gCurrCourseNum], strCourseNum);
        // print_generic_string(CRS_NUM_X1, 157, strCourseNum);

        if(coursesFixed[gCurrCourseNum] >= 10) {
            sprintf(concString, "%s %s %s", LANGUAGE_ARRAY(textCourse), strCourseNum, &courseName[3]);
        } else {
            sprintf(concString, "%s %s  %s", LANGUAGE_ARRAY(textCourse), strCourseNum, &courseName[3]);
        }

        concStringX = get_str_x_pos_from_center(160, concString, 10.0f);
        print_generic_string(concStringX, 156, concString);

        u8 *actName = segmented_to_virtual(actNameTbl[COURSE_NUM_TO_INDEX(gCurrCourseNum) * 6 + gDialogCourseActNum - 1]);

        actNameX = get_str_x_pos_from_center(160, actName, 10.0f);
        print_generic_string(actNameX + 6, 140, actName);
        if (starFlags & (1 << (gDialogCourseActNum - 1))) {
            print_generic_string(actNameX - 6, 140, textStar);
        } else {
            print_generic_string(actNameX - 6, 140, textUnfilledStar);
        }

        // print_generic_string(LVL_NAME_X, 157, &courseName[3]);
    } else {
        s16 concStringX = get_str_x_pos_from_center(160, &courseName[3], 10.0f);
        print_generic_string(concStringX, 157, &courseName[3]);
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

#define TXT1_X 3
#define TXT2_X 119
#define Y_VAL7 2

void render_pause_camera_options(s16 x, s16 y, s8 *index, s16 xIndex) {
    handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, index, 1, 2);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_generic_string(x, y, "4:3");
    print_generic_string(x + 60, y, "16:9");

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    create_dl_translation_matrix(MENU_MTX_PUSH, ((*index - 1) * 60) + x - 12, y, 0);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    switch (*index) {
        case CAM_SELECTION_MARIO:
            if (gConfig.widescreen != 0) {
                gConfig.widescreen = 0;
                save_file_set_widescreen_mode(gConfig.widescreen);
            }
            break;
        case CAM_SELECTION_FIXED:
            if (gConfig.widescreen != 1) {
                gConfig.widescreen = 1;
                save_file_set_widescreen_mode(gConfig.widescreen);
            }
            break;
    }
}

#define X_VAL8 4
#define Y_VAL8 2

void render_pause_course_options(s16 x, s16 y, s8 *index, s16 yIndex) {
    u8 textContinue[] = { TEXT_CONTINUE };
    u8 textExitCourse[] = { TEXT_EXIT_COURSE };
    u8 textCameraAngleR[] = { TEXT_CAMERA_ANGLE_R };

    handle_menu_scrolling(MENU_SCROLL_VERTICAL, index, 1, 3);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_generic_string(x + 10, y - 2, LANGUAGE_ARRAY(textContinue));
    print_generic_string(x + 10, y - 17, LANGUAGE_ARRAY(textExitCourse));

    if (*index != MENU_OPT_CAMERA_ANGLE_R) {
        print_generic_string(x + 10, y - 33, "TOGGLE WIDESCREEN");
        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

        create_dl_translation_matrix(MENU_MTX_PUSH, x - X_VAL8, (y - ((*index - 1) * yIndex)) - Y_VAL8, 0);

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
        gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
        gDialogCameraAngleIndex = gConfig.widescreen + 1;
    }

    if (*index == MENU_OPT_CAMERA_ANGLE_R) {
        render_pause_camera_options(x + 10, y - 42, &gDialogCameraAngleIndex, 110);
    }
}

void render_pause_castle_menu_box(s16 x, s16 y) {
    create_dl_translation_matrix(MENU_MTX_PUSH, x - 78, y - 32, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.2f, 0.8f, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 105);
    gSPDisplayList(gDisplayListHead++, dl_draw_text_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, x + 6, y - 28, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, x - 9, y - 101, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 270.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void highlight_last_course_complete_stars(void) {
    u8 doneCourseIndex;

    if (gLastCompletedCourseNum == COURSE_NONE) {
        doneCourseIndex = COURSE_NUM_TO_INDEX(COURSE_MIN);
    } else {
        doneCourseIndex = COURSE_NUM_TO_INDEX(gLastCompletedCourseNum);

        if (doneCourseIndex >= COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES)) {
            doneCourseIndex = COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES);
        }
    }

    gDialogLineNum = doneCourseIndex;
}

void print_hud_pause_colorful_str(void) {
    u8 textPause[] = { TEXT_PAUSE };

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_hud_lut_string(HUD_LUT_GLOBAL, 123, 81, textPause);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

void render_pause_castle_course_stars(s16 x, s16 y, s16 fileIndex, s16 courseIndex) {
    s16 hasStar = 0;

    u8 str[COURSE_STAGES_COUNT * 2];

    u8 textStar[] = { TEXT_STAR };

    u8 starFlags = save_file_get_star_flags(fileIndex, courseIndex);
    u16 starCount = save_file_get_course_star_count(fileIndex, courseIndex);

    u16 nextStar = 0;

    if (starFlags & STAR_FLAG_ACT_100_COINS) {
        starCount--;
        print_generic_string(x + 89, y - 5, textStar);
    }

    while (hasStar != starCount) {
        if (starFlags & (1 << nextStar)) {
            str[nextStar * 2] = DIALOG_CHAR_STAR_FILLED;
            hasStar++;
        } else {
            str[nextStar * 2] = DIALOG_CHAR_STAR_OPEN;
        }

        str[nextStar * 2 + 1] = DIALOG_CHAR_SPACE;
        nextStar++;
    }

    if (starCount == nextStar && starCount != 6) {
        str[nextStar * 2] = DIALOG_CHAR_STAR_OPEN;
        str[nextStar * 2 + 1] = DIALOG_CHAR_SPACE;
        nextStar++;
    }

    str[nextStar * 2] = DIALOG_CHAR_TERMINATOR;

    print_generic_string(x + 14, y + 13, str);
}

void render_pause_castle_main_strings(s16 x, s16 y) {
    void **courseNameTbl = segmented_to_virtual(languageTable[gInGameLanguage][1]);

    u8 textCoin[] = { TEXT_COIN_X };

    void *courseName;

    u8 strVal[8];
    s16 prevCourseIndex = gDialogLineNum;


    handle_menu_scrolling(
        MENU_SCROLL_VERTICAL, &gDialogLineNum,
        COURSE_NUM_TO_INDEX(COURSE_MIN) - 1, COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES) + 1
    );

    if (gDialogLineNum == COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES) + 1) {
        gDialogLineNum = COURSE_NUM_TO_INDEX(COURSE_MIN); // Exceeded max, set to min
    }

    if (gDialogLineNum == COURSE_NUM_TO_INDEX(COURSE_MIN) - 1) {
        gDialogLineNum = COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES); // Exceeded min, set to max
    }

    if (gDialogLineNum != COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES)) {
        while (save_file_get_course_star_count(gCurrSaveFileNum - 1, gDialogLineNum) == 0) {
            if (gDialogLineNum >= prevCourseIndex) {
                gDialogLineNum++;
            } else {
                gDialogLineNum--;
            }

            if (gDialogLineNum == COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX) + 1
             || gDialogLineNum == COURSE_NUM_TO_INDEX(COURSE_MIN) - 1) {
                gDialogLineNum = COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES);
                break;
            }
        }
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    if (gDialogLineNum <= COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX)) { // Main courses
        courseName = segmented_to_virtual(courseNameTbl[gDialogLineNum]);
        render_pause_castle_course_stars(x, y, gCurrSaveFileNum - 1, gDialogLineNum);
        print_generic_string(x + 34, y - 5, textCoin);
        int_to_str(save_file_get_course_coin_score(gCurrSaveFileNum - 1, gDialogLineNum), strVal);
        print_generic_string(x + 54, y - 5, strVal);
    } else { // Castle secret stars
        u8 textStarX[] = { TEXT_STAR_X };
        courseName = segmented_to_virtual(courseNameTbl[COURSE_MAX]);
        print_generic_string(x + 40, y + 13, textStarX);
        int_to_str(save_file_get_total_star_count(gCurrSaveFileNum - 1,
                                                  COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES),
                                                  COURSE_NUM_TO_INDEX(COURSE_MAX)),
                                                  strVal);
        print_generic_string(x + 60, y + 13, strVal);
    }

    print_generic_string(x - 9, y + 30, courseName);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

s8 gCourseCompleteCoinsEqual = FALSE;
s32 gCourseDoneMenuTimer = 0;
s32 gCourseCompleteCoins = 0;
s8 gHudFlash = HUD_FLASH_NONE;

s32 render_pause_courses_and_castle(void) {
    s16 index;

#ifdef PUPPYCAM
    puppycam_check_pause_buttons();
    if (!gPCOptionOpen) {
#endif
    switch (gDialogBoxState) {
        case DIALOG_STATE_OPENING:
            gDialogLineNum = MENU_OPT_DEFAULT;
            gDialogTextAlpha = 0;
            level_set_transition(-1, NULL);
            play_sound(SOUND_MENU_PAUSE_OPEN, gGlobalSoundSource);

            if (gCurrCourseNum >= COURSE_MIN
             && gCurrCourseNum <= COURSE_MAX) {
                change_dialog_camera_angle();
                gDialogBoxState = DIALOG_STATE_VERTICAL;
            } else {
                highlight_last_course_complete_stars();
                gDialogBoxState = DIALOG_STATE_HORIZONTAL;
            }
            break;

        case DIALOG_STATE_VERTICAL:
            shade_screen();
            render_pause_my_score_coins();
            render_pause_red_coins();

            if (
                !(gMarioState->action & ACT_FLAG_INTANGIBLE) && (
                    (gMarioStates[0].action & (ACT_FLAG_MOVING | ACT_FLAG_AIR | ACT_FLAG_SWIMMING | ACT_FLAG_METAL_WATER | ACT_FLAG_PAUSE_EXIT))
                    || (gMarioStates[0].pos[1] <= gMarioStates[0].floorHeight)
                )
            ) {
                render_pause_course_options(99, 93, &gDialogLineNum, 15);
            }

            if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_PAUSE_CLOSE, gGlobalSoundSource);
                gDialogBoxState = DIALOG_STATE_OPENING;
                gMenuMode = MENU_MODE_NONE;

                if (gDialogLineNum == MENU_OPT_EXIT_COURSE) {
                    index = gDialogLineNum;
                } else { // MENU_OPT_CONTINUE or MENU_OPT_CAMERA_ANGLE_R
                    index = MENU_OPT_DEFAULT;
                }

                return index;
            }
            break;

        case DIALOG_STATE_HORIZONTAL:
            shade_screen();
            print_hud_pause_colorful_str();
            render_pause_castle_menu_box(160, 143);
            render_pause_castle_main_strings(104, 60);

            if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON | Z_TRIG)) {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_PAUSE_CLOSE, gGlobalSoundSource);
                gMenuMode = MENU_MODE_NONE;
                gDialogBoxState = DIALOG_STATE_OPENING;

                return MENU_OPT_DEFAULT;
            }
            break;
    }

    if (gDialogTextAlpha < 250) {
        gDialogTextAlpha += 25;
    }
#ifdef PUPPYCAM
    } else {
        shade_screen();
        puppycam_display_options();
    }

    puppycam_render_option_text();
#endif
    return MENU_OPT_NONE;
}

#define TXT_HISCORE_X 109
#define TXT_HISCORE_Y  36
#define TXT_CONGRATS_X 70
#define TXT_CONGRATS_Y 67

enum HUDCourseCompleteStringIDs {
    HUD_PRINT_HISCORE,
    HUD_PRINT_CONGRATULATIONS
};

void print_hud_course_complete_string(s8 str) {
    u8 textHiScore[] = { TEXT_HUD_HI_SCORE };
    u8 textCongratulations[] = { TEXT_HUD_CONGRATULATIONS };

    u8 colorFade = sins(gDialogColorFadeTimer) * 50.0f + 200.0f;

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, colorFade, colorFade, colorFade, 255);

    if (str == HUD_PRINT_HISCORE) {
        print_hud_lut_string(HUD_LUT_GLOBAL, TXT_HISCORE_X,  TXT_HISCORE_Y,  LANGUAGE_ARRAY(textHiScore));
    } else { // HUD_PRINT_CONGRATULATIONS
        print_hud_lut_string(HUD_LUT_GLOBAL, TXT_CONGRATS_X, TXT_CONGRATS_Y, LANGUAGE_ARRAY(textCongratulations));
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

void print_hud_course_complete_coins(s16 x, s16 y) {
    u8 courseCompleteCoinsStr[4];
    u8 hudTextSymCoin[] = "+ ";
    u8 hudTextSymX[] = "* ";

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    print_hud_lut_string(HUD_LUT_GLOBAL, x +  0, y, hudTextSymCoin);
    print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, hudTextSymX);

    int_to_str(gCourseCompleteCoins, courseCompleteCoinsStr);
    print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, courseCompleteCoinsStr);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    if (gCourseCompleteCoins >= gHudDisplay.coins) {
        gCourseCompleteCoinsEqual = TRUE;
        gCourseCompleteCoins = gHudDisplay.coins;

        if (gGotFileCoinHiScore) {
            print_hud_course_complete_string(HUD_PRINT_HISCORE);
        }
    } else {
        if ((gCourseDoneMenuTimer & 1) || gHudDisplay.coins > 70) {
            gCourseCompleteCoins++;
            play_sound(SOUND_MENU_YOSHI_GAIN_LIVES, gGlobalSoundSource);

#ifndef DISABLE_LIVES
            if (gCourseCompleteCoins && ((gCourseCompleteCoins % 50) == 0)) {
                play_sound(SOUND_GENERAL_COLLECT_1UP, gGlobalSoundSource);
                gMarioState->numLives++;
            }
#endif
        }

        if ((gHudDisplay.coins == gCourseCompleteCoins) && gGotFileCoinHiScore) {
            play_sound(SOUND_MENU_HIGH_SCORE, gGlobalSoundSource);
        }
    }
}

void play_star_fanfare_and_flash_hud(s32 arg, u8 starNum) {
    if (gHudDisplay.coins == gCourseCompleteCoins && (gCurrCourseStarFlags & starNum) == 0 && gHudFlash == HUD_FLASH_NONE) {
        play_star_fanfare();
        gHudFlash = arg;
    }
}

#define TXT_NAME_X1 71
#define TXT_NAME_X2 TXT_NAME_X1 - 2
#define CRS_NUM_X2 104
#define CRS_NUM_X3 CRS_NUM_X2 - 2
#define TXT_CLEAR_X1 get_string_width(name) + 81
#define TXT_CLEAR_X2 TXT_CLEAR_X1 - 2

void render_course_complete_lvl_info_and_hud_str(void) {
    u8 textCourse[] = { TEXT_COURSE };
    u8 textClear[] = { TEXT_CLEAR };
    u8 textSymStar[] = "- ";

    u8 *name;

    u8 strCourseNum[4];

    void **actNameTbl    = segmented_to_virtual(languageTable[gInGameLanguage][2]);
    void **courseNameTbl = segmented_to_virtual(languageTable[gInGameLanguage][1]);

    if (gLastCompletedCourseNum <= COURSE_STAGES_MAX) { // Main courses
        print_hud_course_complete_coins(118, 103);
        play_star_fanfare_and_flash_hud(HUD_FLASH_STARS, (1 << (gLastCompletedStarNum - 1)));

        if (gLastCompletedStarNum == 7) {
            name = segmented_to_virtual(actNameTbl[COURSE_STAGES_MAX * 6 + 1]);
        } else {
            name = segmented_to_virtual(actNameTbl[COURSE_NUM_TO_INDEX(gLastCompletedCourseNum) * 6 + gLastCompletedStarNum - 1]);
        }

        // Print course number
        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

        int_to_str(gLastCompletedCourseNum, strCourseNum);

        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gDialogTextAlpha);
        print_generic_string(65, 165, LANGUAGE_ARRAY(textCourse));
        print_generic_string(CRS_NUM_X2, 165, strCourseNum);

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
        print_generic_string(63, 167, LANGUAGE_ARRAY(textCourse));
        print_generic_string(CRS_NUM_X3, 167, strCourseNum);

        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    } else if (gLastCompletedCourseNum == COURSE_BITDW || gLastCompletedCourseNum == COURSE_BITFS) { // Bowser courses
        name = segmented_to_virtual(courseNameTbl[COURSE_NUM_TO_INDEX(gLastCompletedCourseNum)]);

        // Print course name and clear text
        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gDialogTextAlpha);
        print_generic_string(TXT_NAME_X1, 130, name);
        print_generic_string(TXT_CLEAR_X1, 130, textClear);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
        print_generic_string(TXT_NAME_X2, 132, name);
        print_generic_string(TXT_CLEAR_X2, 132, textClear);
        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

        print_hud_course_complete_string(HUD_PRINT_CONGRATULATIONS);
        print_hud_course_complete_coins(118, 111);
        play_star_fanfare_and_flash_hud(HUD_FLASH_KEYS, 0);
        return;
    } else { // Castle secret stars
        name = segmented_to_virtual(actNameTbl[COURSE_STAGES_MAX * 6]);

        print_hud_course_complete_coins(118, 103);
        play_star_fanfare_and_flash_hud(HUD_FLASH_STARS, 1 << (gLastCompletedStarNum - 1));
    }

    // Print star glyph
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    print_hud_lut_string(HUD_LUT_GLOBAL, 55, 77, textSymStar);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    // Print act name and catch text
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gDialogTextAlpha);
    print_generic_string(76, 145, name);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    print_generic_string(74, 147, name);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

#define X_VAL9 x
#define TXT_SAVEOPTIONS_X x + 12
#define TXT_SAVECONT_Y 0
#define TXT_SAVEQUIT_Y 20
#define TXT_CONTNOSAVE_Y 40

void render_save_confirmation(s16 x, s16 y, s8 *index, s16 yPos) {
    u8 textSaveAndContinue[] = { TEXT_SAVE_AND_CONTINUE };
    u8 textSaveAndQuit[] = { TEXT_SAVE_AND_QUIT };
    u8 textContinueWithoutSave[] = { TEXT_CONTINUE_WITHOUT_SAVING };

    handle_menu_scrolling(MENU_SCROLL_VERTICAL, index, 1, 3);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_generic_string(TXT_SAVEOPTIONS_X, y + TXT_SAVECONT_Y, LANGUAGE_ARRAY(textSaveAndContinue));
    print_generic_string(TXT_SAVEOPTIONS_X, y - TXT_SAVEQUIT_Y, LANGUAGE_ARRAY(textSaveAndQuit));
    print_generic_string(TXT_SAVEOPTIONS_X, y - TXT_CONTNOSAVE_Y, LANGUAGE_ARRAY(textContinueWithoutSave));

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL9, y - ((*index - 1) * yPos), 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

s32 render_course_complete_screen(void) {
    switch (gDialogBoxState) {
        case DIALOG_STATE_OPENING:
            render_course_complete_lvl_info_and_hud_str();
            if (gCourseDoneMenuTimer > 100 && gCourseCompleteCoinsEqual) {
#ifdef SAVE_NUM_LIVES
                save_file_set_num_lives(gMarioState->numLives);
#endif
                gDialogBoxState = DIALOG_STATE_VERTICAL;
                level_set_transition(-1, NULL);
                gDialogTextAlpha = 0;
                gDialogLineNum = MENU_OPT_DEFAULT;
            }
            break;

        case DIALOG_STATE_VERTICAL:
            shade_screen();
            render_course_complete_lvl_info_and_hud_str();
            render_save_confirmation(100, 86, &gDialogLineNum, 20);

            if (gCourseDoneMenuTimer > 110 && (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON))) {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                gDialogBoxState = DIALOG_STATE_OPENING;
                gMenuMode = MENU_MODE_NONE;
                gCourseDoneMenuTimer = 0;
                gCourseCompleteCoins = 0;
                gCourseCompleteCoinsEqual = FALSE;
                gHudFlash = HUD_FLASH_NONE;

                return gDialogLineNum;
            }
            break;
    }

    if (gDialogTextAlpha < 250) {
        gDialogTextAlpha += 25;
    }

    gCourseDoneMenuTimer++;

    return MENU_OPT_NONE;
}

s32 render_menus_and_dialogs(void) {
    s32 mode = MENU_OPT_NONE;

    create_dl_ortho_matrix();

    if (gMenuMode != MENU_MODE_NONE) {
        switch (gMenuMode) {
            case MENU_MODE_UNUSED_0:
                mode = render_pause_courses_and_castle();
                break;
            case MENU_MODE_RENDER_PAUSE_SCREEN:
                mode = render_pause_courses_and_castle();
                break;
            case MENU_MODE_RENDER_COURSE_COMPLETE_SCREEN:
                mode = render_course_complete_screen();
                break;
            case MENU_MODE_UNUSED_3:
                mode = render_course_complete_screen();
                break;
        }

        gDialogColorFadeTimer = (s16) gDialogColorFadeTimer + 0x1000;
    } else if (gDialogID != DIALOG_NONE) {
        // The Peach "Dear Mario" message needs to be repositioned separately
        if (gDialogID == DIALOG_020) {
            print_peach_letter_message();
            return mode;
        }

        render_dialog_entries();
        gDialogColorFadeTimer = (s16) gDialogColorFadeTimer + 0x1000;
    }

    return mode;
}

void print_string_with_shadow(s16 x, s16 y, const u8 *str, u32 color) {
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, color & 0xFF);
    print_generic_string(x, y - 1, str);
    gDPSetEnvColor(gDisplayListHead++, (color >> 24), (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
    print_generic_string(x, y, str);
}

void render_char_with_shadow(u8 c, u32 color) {
    create_dl_translation_matrix(MENU_MTX_NOPUSH, 0.0f, -1.0f, 0.0f);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, color & 0xFF);
    render_generic_char(c);
    create_dl_translation_matrix(MENU_MTX_NOPUSH, 0.0f, 1.0f, 0.0f);
    gDPSetEnvColor(gDisplayListHead++, (color >> 24), (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
    render_generic_char(c);
}

Vtx icon_icon_mesh_vtx_0[4] = {
	{{{0, 0, 0},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{20, 0, 0},0, {1008, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{20, 30, 0},0, {1008, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, 30, 0},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx icon_icon_mesh_tri_0[] = {
	gsSPVertex(icon_icon_mesh_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_icon_f3d_material_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, 1, 0, 0, 0, ENVIRONMENT, 0, 0, 0, 1),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(0, 37, 52, 255),
	gsSPEndDisplayList(),
};

Gfx icon_mesh[] = {
	gsSPDisplayList(mat_icon_f3d_material_002),
	gsSPDisplayList(icon_icon_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

u8 textEnterDogName[] = { TEXT_ENTER_DOG_NAME };
u8 textKeyboardDefines[] = { TEXT_KEYBOARD_DEFINES };
u8 dogStringTemp[DOG_STRING_LENGTH + 1];
u8 topBarMap[2][10] = {
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' },
{ CHAR_STAR, CHAR_UNFILLED_STAR, CHAR_COIN, '&', ':', '*', '!', '%', '?', '~' }, };

s32 gKeyboardShifted;
s8 keyboardCursorX = 0;
s8 keyboardCursorY = 0;
void render_dog_keyboard(s16 saveFileIndex) {
    u8 i, init, max, actualTick, topBar;
    s8 length;
    u32 white = 0xFFFFFFFF;

    if(gPlayer1Controller->buttonPressed & R_TRIG) {
        gKeyboardShifted ^= 0x1;
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
    }

    //gSPDisplayList(gDisplayListHead++, kb_bg_Plane_mesh);

    if(gDirectionsHeld != 0) {
        play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gGlobalSoundSource);
    }
    if(gDirectionsHeld & JOYSTICK_LEFT) {
        keyboardCursorX--;
        if(keyboardCursorX < 0) {
            keyboardCursorX = 9;
        }
    }
    if(gDirectionsHeld & JOYSTICK_RIGHT) {
        keyboardCursorX++;
        if(keyboardCursorX > 9) {
            keyboardCursorX = 0;
        }
    }
    if(gDirectionsHeld & JOYSTICK_UP) {
        keyboardCursorY--;
        if(keyboardCursorY < 0) {
            keyboardCursorY = 3;
        }
    }
    if(gDirectionsHeld & JOYSTICK_DOWN) {
        keyboardCursorY++;
        if(keyboardCursorY > 3) {
            keyboardCursorY = 0;
        }
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, 18.0f + (keyboardCursorX*24.0f), 128.0f - (keyboardCursorY*28.0f), 0.0f);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER);
    gSPDisplayList(gDisplayListHead++, &icon_mesh);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    print_string_with_shadow(20, 220, textEnterDogName, white);
    print_string_with_shadow(20, 20, textKeyboardDefines, white);
    length = -1;
    for(i = 0; i < DOG_STRING_LENGTH; i++) {
        dogStringTemp[i] = save_file_get_dog_string(saveFileIndex, i);
        if(dogStringTemp[i] != 0x0) {
            length = i;
        }
    }


    create_dl_scale_matrix(MENU_MTX_PUSH, 2.0f, 2.0f, 1.0f);
    create_dl_translation_matrix(MENU_MTX_NOPUSH, 10.0f, 64.0f, 0.0f);
    // for(i = 0; i < 0x40; i++) {
    //     render_generic_char(i);
    //     if(i % 10 == 9) {
    //         create_dl_translation_matrix(MENU_MTX_NOPUSH, -108.0f, -14.0f, 0.0f);
    //     } else {
    //         create_dl_translation_matrix(MENU_MTX_NOPUSH, 12.0f, 0.0f, 0.0f);
    //     }
    // }
    if(gKeyboardShifted) {
        init = 'A';
        max = 'Z';
        topBar = 0x1;
    } else {
        init = 'a';
        max = 'z';
        topBar = 0x0;
    }
    actualTick = 0;
    for(i = 0; i < 10; i++) {
        render_char_with_shadow(topBarMap[topBar][i], white);
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 12.0f, 0.0f, 0.0f);
    }
    create_dl_translation_matrix(MENU_MTX_NOPUSH, -120.0f, -14.0f, 0.0f);
    for(i = init; i <= max; i++) {
        render_char_with_shadow(i, white);
        if(actualTick % 10 == 9) {
            create_dl_translation_matrix(MENU_MTX_NOPUSH, -108.0f, -14.0f, 0.0f);
        } else {
            create_dl_translation_matrix(MENU_MTX_NOPUSH, 12.0f, 0.0f, 0.0f);
        }
        actualTick++;
    }
    render_char_with_shadow('.', white);
    create_dl_translation_matrix(MENU_MTX_NOPUSH, 12.0f, 0.0f, 0.0f);
    render_char_with_shadow('\'', white);
    // create_dl_translation_matrix(MENU_MTX_NOPUSH, 12.0f, 0.0f, 0.0f);
    // render_char_with_shadow(0x52, white);
    // create_dl_translation_matrix(MENU_MTX_NOPUSH, 12.0f, 0.0f, 0.0f);
    // render_char_with_shadow(0x50, white);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    if(length < DOG_STRING_LENGTH - 1 && (gPlayer1Controller->buttonPressed & A_BUTTON)) {
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
        if(keyboardCursorY == 3 && keyboardCursorX > 5) {
            u8 key;
            switch(keyboardCursorX - 6) {
                case 0:
                    key = '.';
                    break;
                case 1:
                    key = '\'';
                    break;
                case 2:
                case 3:
                    key = ' ';
                    break;
            }
            dogStringTemp[length + 1] = key;
        } else if(keyboardCursorY == 0) {
            dogStringTemp[length + 1] = topBarMap[topBar][keyboardCursorX];
        } else {
            dogStringTemp[length + 1] = init + keyboardCursorX + ((keyboardCursorY - 1) * 0x0A);
        }
    }
    if(length > -1 && (gPlayer1Controller->buttonPressed & B_BUTTON)) {
        play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gGlobalSoundSource);
        dogStringTemp[length] = 0x0;
    }
    save_file_set_dog_string(saveFileIndex, &dogStringTemp);

    create_dl_scale_matrix(MENU_MTX_PUSH, 3.0f, 3.0f, 1.0f);
    print_string_with_shadow(7, 58, dogStringTemp, white);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    if(length > -1 && gPlayer1Controller->buttonPressed & START_BUTTON) {
        play_sound(SOUND_MENU_DOG_ROO, gGlobalSoundSource);
        gKeyboard = 0;
    }
}

void render_bar(s16 y, char *str, u8 filled) {
    s16 width = get_string_width(str);
    create_dl_translation_matrix(MENU_MTX_PUSH, (f32)width, (f32)y, 0.0f);

    if(filled) {
        gDPSetEnvColor(gDisplayListHead++, 150, 150, 150, 175);
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 8.0f, 0.0f, 0.0f);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 50, 50, 50, 175);
    }

    gSPDisplayList(gDisplayListHead++, bar_mesh_mesh);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

s32 gWorldID = -1;
s32 gFocusID = -1;

#define NULL_ENTRY {{0, 0, 0}, {0, 0, 0}, 0, 0, 0, 0, 0}
struct HubSelection hubSelections[3][6] = {
    {
        /* {{6466.0f, 2396.0f, 2919.0f},  {3521.0f, 2615.0f, 2711.0f},  0xF800, TEXT_C0I, TEXT_C0, TEXT_C0A, 0x1},
        {{7362.0f, -1200.0f, 4084.0f}, {4580.0f, 306.0f, 2342.0f},   0x1000, TEXT_C1I, TEXT_C1, TEXT_C1A, 0x2},
        {{8518.0f, 3824.0f, 1657.0f},  {3584.0f, 3655.0f, 349.0f},   0x0000, TEXT_C2I, TEXT_C2, TEXT_C2A, 0x3},
        {{7182.0f, 1184.0f, 300.0f},   {0.0f, 0.0f, 0.0f},           0x0000, TEXT_C3I, TEXT_C3, TEXT_C3A, 0x4},
        {{7092.0f, -3399.0f, 1039.0f}, {4687.0f, -2021.0f, 274.0f},  0x1000, TEXT_C4I, TEXT_C4, TEXT_C4A, 0x5},
        {{8092.0f, -431.0f, -1894.0f}, {6292.0f, 2119.0f, -2359.0f}, 0x1C00, TEXT_B1I, TEXT_B1, TEXT_B1A, 0x6}, */

        // {0x2C00, 0x900,  7184.0f, 0x2600, 0x1B00, 5000.0f, 0xF800, TEXT_C0I, TEXT_C0, TEXT_C0A, 0x1, 0},
        {0x2C00, 0xEC00, 8400.0f, 0x2A00, 0x2C00, 7000.0f, 0x0000, TEXT_C1I, TEXT_C1, TEXT_C1A, 0x2, 11},
        {0x4000, 0x1100, 8795.0f, 0x3E00, 0x1F00, 5512.0f, 0x0000, TEXT_C2I, TEXT_C2, TEXT_C2A, 0x3, 5},
        {0x4400, 0xEE00, 7870.0f, 0xC300, 0x47A0,11520.0f, 0x0000, TEXT_C3I, TEXT_C3, TEXT_C3A, 0x4, 1},
        {0x4700, 0x0,    8976.0f, 0x5200, 0x2100, 6536.0f, 0x1C00, TEXT_B1I, TEXT_B1, TEXT_B1A, 0x5, 17},
        NULL_ENTRY,
    },
    {
        {0x8B90, 0x6E9,  7390.0f, 0x600,  0x900,  7170.0f, 0x0000, TEXT_C4I, TEXT_C4, TEXT_C4A, 0x6, 2},
        {0x9300, 0x1400, 6807.0f, 0x8B00, 0x2100, 5120.0f, 0xF800, TEXT_C5I, TEXT_C5, TEXT_C5A, 0x7, 4},
        {0xAE00, 0x400,  6551.0f, 0xAC00, 0xD00,  5120.0f, 0x0000, TEXT_C6I, TEXT_C6, TEXT_C6A, 0x8, 3},
        {0xA950, 0xAA0,  5890.0f, 0x2600, 0x4000,15620.0f, 0x0000, TEXT_C7I, TEXT_C7, TEXT_C7A, 0x9, 8},
        {0xAB90, 0x12E0, 7390.0f, 0x600,  0x900,  7170.0f, 0x0000, TEXT_B2I, TEXT_B2, TEXT_B2A, 0xA, 16},
        NULL_ENTRY,
        NULL_ENTRY,
    },
    {
        {0xB100, 0xC000, 6870.0f, 0xAE00, 0x100,  6650.0f, 0x8000, TEXT_C8I, TEXT_C8, TEXT_C8A, 0xB, 7},
        {0x7E00, 0xB800, 6350.0f, 0xE600, 0x2500, 9999.0f, 0x8000, TEXT_C9I, TEXT_C9, TEXT_C9A, 0xC, 6},
        {0x5100, 0xB400, 7890.0f, 0xD000, 0x2C00, 9200.0f, 0x8000, TEXT_C10I, TEXT_C10, TEXT_C10A, 0xD, 9},
        {0x5100, 0xB400, 7890.0f, 0xD000, 0x2C00, 9200.0f, 0x8000, TEXT_B3I, TEXT_B3, TEXT_B3A, 0xE, 18},
        NULL_ENTRY,
        NULL_ENTRY,
    },
};

struct HubAlert hubAlerts[] = {
    {60, TEXT_HA_0},
    {20, TEXT_HA_1},
    {60, TEXT_HA_2},
    {20, TEXT_HA_3},
    {60, TEXT_HA_4},
};

s32 selectedStar = 0;
s32 gCustomStarSelectActive = 0;
s32 gLevelEntryConfirmationActive = 0;
s32 gHubAlertTimer = 0;
s32 gHubAlertID = 0;

u8 *get_course_string(u8 *levelString, u8 courseIndex) {
    sprintf(levelString, "%s", hubSelections[gWorldID][courseIndex].levelNameString);
    if(hubSelections[gWorldID][courseIndex].courseID > 0) {
        if(hubSelections[gWorldID][courseIndex].courseID == 18) {
            if((save_file_get_course_star_count(gCurrSaveFileNum - 1, 18) >= 1) && (save_file_get_flags() & SAVE_FLAG_BOWSER_3_BEAT)) {
                sprintf(levelString, "%s \xFA", hubSelections[gWorldID][courseIndex].levelNameString);
            }
        } else if(hubSelections[gWorldID][courseIndex].courseID < 16) {
            if(save_file_get_course_star_count(gCurrSaveFileNum - 1, hubSelections[gWorldID][courseIndex].courseID - 1) == 7) {
                sprintf(levelString, "%s \xFA", hubSelections[gWorldID][courseIndex].levelNameString);
            }
        } else {
            if(save_file_get_course_star_count(gCurrSaveFileNum - 1, hubSelections[gWorldID][courseIndex].courseID - 1) >= 1) {
                if((hubSelections[gWorldID][courseIndex].courseID == 16 && (save_file_get_flags() & SAVE_FLAG_HAVE_KEY_1)) ||
                (hubSelections[gWorldID][courseIndex].courseID == 17 && (save_file_get_flags() & SAVE_FLAG_HAVE_KEY_2))) {
                    sprintf(levelString, "%s \xFA", hubSelections[gWorldID][courseIndex].levelNameString);
                }
            }
        }
    } else {
        sprintf(levelString, "%s \xFA", hubSelections[gWorldID][courseIndex].levelNameString);
    }
}

u8 *get_world_string(u8 *worldStringBuffer, u8 *worldString, u8 worldNum) {
    u8 allLevelsDone = 1;
    u8 i = 0;
    u8 worldID = worldNum - 1;
    for(i = 0; i < 99; i++) {
        if(hubSelections[worldID][i].courseID > 0) {
            if(hubSelections[worldID][i].courseID == 18) {
                if(!((save_file_get_course_star_count(gCurrSaveFileNum - 1, 18) >= 1) && (save_file_get_flags() & SAVE_FLAG_BOWSER_3_BEAT))) {
                    allLevelsDone = 0;
                }
            } else if(hubSelections[worldID][i].courseID == 17) {
                if(!((save_file_get_course_star_count(gCurrSaveFileNum - 1, 16) >= 1) && (save_file_get_flags() & SAVE_FLAG_HAVE_KEY_2))) {
                    allLevelsDone = 0;
                }
            } else if(hubSelections[worldID][i].courseID == 16) {
                if(!((save_file_get_course_star_count(gCurrSaveFileNum - 1, 15) >= 1) && (save_file_get_flags() & SAVE_FLAG_HAVE_KEY_1))) {
                    allLevelsDone = 0;
                }
            } else {
                if(!(save_file_get_course_star_count(gCurrSaveFileNum - 1, hubSelections[worldID][i].courseID - 1) == 7)) {
                    allLevelsDone = 0;
                }
            }
        } else {
            i = 99;
            break;
        }
    }

    if(allLevelsDone == 0) {
        sprintf(worldStringBuffer, "%s", worldString);
    } else {
        sprintf(worldStringBuffer, "%s \xFA", worldString);
    }
}

void render_hub_selection(void) {
    u32 textColor = 0xFFFFFFFF;
    u32 textDiscolor = 0xDFDFDFFF;
    u8 joystickMovement = gDirectionsHeld;
    u8 *worldStringBuffer[3][12];

    if(gFocusID == -1) {
        sDelayedWarpTimer = 0;
        switch(gWorldID) {
            case -1:
                if((joystickMovement & (JOYSTICK_DOWN | JOYSTICK_UP)) || (gPlayer1Controller->buttonPressed & A_BUTTON)) {
                    gWorldID = 0;
                }
                break;
            default:
                if(joystickMovement & JOYSTICK_UP) {
                    gWorldID--;
                    play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gGlobalSoundSource);
                    if(gWorldID < 0) {gWorldID = 2;}
                }
                if(joystickMovement & JOYSTICK_DOWN) {
                    gWorldID++;
                    play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gGlobalSoundSource);
                    if(gWorldID > 2) {gWorldID = 0;}
                }

                if(gPlayer1Controller->buttonPressed & A_BUTTON) {
                    if(gWorldID == 1 && !(save_file_get_flags() & (SAVE_FLAG_HAVE_KEY_2))) {
                        gHubAlertTimer = 30;
                        gHubAlertID = 1;
                    } else if(gWorldID == 2 && !(save_file_get_flags() & (SAVE_FLAG_HAVE_KEY_1))) {
                        gHubAlertTimer = 30;
                        gHubAlertID = 3;
                    } else {
                        gFocusID = 0;
                    }
                    play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
                } else if(gPlayer1Controller->buttonPressed & B_BUTTON) {
                    gWorldID = -1;
                    play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gGlobalSoundSource);
                }
                break;
        }

        get_world_string(worldStringBuffer[0], TEXT_WORLD_1, 1);
        get_world_string(worldStringBuffer[1], TEXT_WORLD_2, 2);
        get_world_string(worldStringBuffer[2], TEXT_WORLD_3, 3);

        render_bar(220, TEXT_SELECT_WORLD, 0);
        render_bar(200, worldStringBuffer[0], gWorldID == 0 ? 1 : 0);
        render_bar(180, worldStringBuffer[1], gWorldID == 1 ? 1 : 0);
        render_bar(160, worldStringBuffer[2], gWorldID == 2 ? 1 : 0);

        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
        print_string_with_shadow(8, 220, TEXT_SELECT_WORLD, textDiscolor);
        print_string_with_shadow(gWorldID == 0 ? 16 : 8, 200, worldStringBuffer[0], gWorldID == 0 ? textColor : textDiscolor);
        print_string_with_shadow(gWorldID == 1 ? 16 : 8, 180, worldStringBuffer[1], gWorldID == 1 ? textColor : textDiscolor);
        print_string_with_shadow(gWorldID == 2 ? 16 : 8, 160, worldStringBuffer[2], gWorldID == 2 ? textColor : textDiscolor);
        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    } else {
        f32 translateAmt = gHubStarSelectTimer*-12;
        translateAmt = CLAMP(translateAmt, -301, 0);
        if (translateAmt > -300) {
            create_dl_translation_matrix(MENU_MTX_PUSH, translateAmt, 0.0f, 0.0f);

            u8 i = 0;
            for(i = 0; i < 6; i++) {
                u8 filled = gFocusID == i ? 1 : 0;
                if(hubSelections[gWorldID][i].warpID == 0) {
                    break;
                } else {
                    u8 levelString[64];
                    get_course_string(levelString, i);
                    render_bar(200 - (i*20), levelString, filled);
                }
            }

            render_bar(220, TEXT_SELECT_LEVEL, 0);

            render_bar(48 + (SCREEN_HEIGHT - gScreenHeight), hubSelections[gWorldID][gFocusID].levelIdentifierString, 0);
            render_bar(28 + (SCREEN_HEIGHT - gScreenHeight), hubSelections[gWorldID][gFocusID].levelNameString,       0);
            render_bar(8 + (SCREEN_HEIGHT - gScreenHeight),  hubSelections[gWorldID][gFocusID].levelAuthorString,     0);

            gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

            for(i = 0; i < 6; i++) {
                u8 filled = gFocusID == i ? 8 : 0;
                if(hubSelections[gWorldID][i].warpID == 0) {
                    break;
                } else {
                    u8 levelString[64];
                    get_course_string(levelString, i);
                    print_string_with_shadow(8 + filled, 200 - (i*20), levelString, filled ? textColor : textDiscolor);
                }
            }

            print_string_with_shadow(8, 220, TEXT_SELECT_LEVEL, textDiscolor);
            print_string_with_shadow(8, 48 + (SCREEN_HEIGHT - gScreenHeight), hubSelections[gWorldID][gFocusID].levelIdentifierString, textColor);
            print_string_with_shadow(8, 28 + (SCREEN_HEIGHT - gScreenHeight), hubSelections[gWorldID][gFocusID].levelNameString, textColor);
            print_string_with_shadow(8, 8 + (SCREEN_HEIGHT - gScreenHeight), hubSelections[gWorldID][gFocusID].levelAuthorString, textColor);
            gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
        }

        if(sDelayedWarpTimer == 0) {
            if(gPlayer1Controller->buttonPressed & A_BUTTON) {
#ifndef UNLOCK_ALL
                if(hubSelections[gWorldID][gFocusID].courseID == 17 && save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) < 5) {
                    gHubAlertTimer = 30;
                    gHubAlertID = 0;
                } else if(hubSelections[gWorldID][gFocusID].courseID == 16 && save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) < 15) {
                    gHubAlertTimer = 30;
                    gHubAlertID = 2;
                } else if(hubSelections[gWorldID][gFocusID].courseID == 18 && save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) < 30) {
                    gHubAlertTimer = 30;
                    gHubAlertID = 4;
                } else
#endif
                if(gCustomStarSelectActive || gLevelEntryConfirmationActive) {
                    sDelayedWarpOp = 1;
                    sDelayedWarpArg = 0x00000002;
                    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 15, 0xFF, 0xFF, 0xFF);
                    sDelayedWarpTimer = 15;
                    sSourceWarpNodeId = hubSelections[gWorldID][gFocusID].warpID;
                    if(hubSelections[gWorldID][gFocusID].courseID == 6 && gCurrActNum > 1) { //ff special case
                        sSourceWarpNodeId = 0x1C;
                    }
                    gIntroCutsceneState = 0;
                    play_sound(SOUND_MENU_STAR_SOUND_LETS_A_GO, gGlobalSoundSource);
                } else if(hubSelections[gWorldID][gFocusID].courseID > 15 || hubSelections[gWorldID][gFocusID].courseID == 0) {
                    gLevelEntryConfirmationActive = 1;
                } else {
                    selectedStar = 0;
                    gCustomStarSelectActive = 1;
                }
            } else if(gPlayer1Controller->buttonPressed & B_BUTTON) {
                play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gGlobalSoundSource);
                if(gLevelEntryConfirmationActive) {
                    gLevelEntryConfirmationActive = 0;
                } else if(gHubStarSelectTimer > 0){
                    gCustomStarSelectActive = 0;
                } else {
                    gFocusID = -1;
                }
            } else if((joystickMovement & JOYSTICK_DOWN) && gLevelEntryConfirmationActive == 0 && gHubStarSelectTimer == 0) {
                play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gGlobalSoundSource);
                gFocusID++;
                if(gFocusID > 5 || hubSelections[gWorldID][gFocusID].warpID == 0) {
                    gFocusID = 0;
                }
            } else if((joystickMovement & JOYSTICK_UP) && gHubStarSelectTimer == 0 && gLevelEntryConfirmationActive == 0) {
                play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gGlobalSoundSource);
                gFocusID--;
                if(gFocusID < 0) {
                    s8 i;
                    for(i = 5; i >= 0; i--) {
                        if(hubSelections[gWorldID][i].warpID != 0) {
                            gFocusID = i;
                            break;
                        }
                    }
                }
            }
        }
    }

    if(gHubAlertTimer > 0) {
        char *filledString = {TEXT_FILLEDSTRING};
        create_dl_ortho_matrix();
        render_bar(80, filledString, 0);
        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
        print_string_with_shadow(hubAlerts[gHubAlertID].x, 80, hubAlerts[gHubAlertID].string, 0xFFFFFFFF);
        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
        gHubAlertTimer--;
    }
}

void geo_clear_zbuffer(Gfx *dlHead) {
    gDPPipeSync(dlHead++);
    gDPSetCycleType(dlHead++, G_CYC_FILL);
    gDPSetRenderMode(dlHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetDepthSource(dlHead++, G_ZS_PIXEL);
    gDPSetDepthImage(dlHead++, gPhysicalZBuffer);
    gDPSetColorImage(dlHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gScreenWidth, gPhysicalZBuffer);
    gDPSetFillColor(dlHead++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
    gDPFillRectangle(dlHead++, 0, gBorderHeight, gScreenWidth - 1,
                     SCREEN_HEIGHT - 1 - gBorderHeight);
    gDPPipeSync(dlHead++);
    gDPSetCycleType(dlHead++, G_CYC_1CYCLE);
    gDPSetColorImage(dlHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gScreenWidth,
                     gPhysicalFramebuffers[sRenderingFramebuffer]);
    gDPSetScissor(dlHead++, G_SC_NON_INTERLACE, 0, gBorderHeight, gScreenWidth,
                  SCREEN_HEIGHT - gBorderHeight);
}

Gfx star_hud_dl[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(star_seg3_dl_body),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPDisplayList(star_seg3_dl_eyes),
    gsSPEndDisplayList(),
};

Gfx transparent_star_hud_dl[] = {
    gsDPSetRenderMode(G_RM_CUSTOM_AA_ZB_XLU_SURF, G_RM_CUSTOM_AA_ZB_XLU_SURF2),
    gsSPDisplayList(transparent_star_seg3_dl_body),
    gsSPEndDisplayList(),
};

Gfx rainbow_star_hud_dl[] = {
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(rainbow_star_000_displaylist_mesh_layer_1),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPDisplayList(rainbow_star_001_displaylist_mesh_layer_5),
    gsSPEndDisplayList(),
};

Vtx bg_Plane_mesh_vtx_0[4] = {
	{{{-2, 104, 0}, 0, {-16, 1008}, {0x0, 0x0, 0x0, 0x0}}},
	{{{322, 104, 0}, 0, {1008, 1008}, {0x0, 0x0, 0x0, 0x0}}},
	{{{322, 204, 0}, 0, {1008, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-2, 204, 0}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
};

Gfx bg_Plane_mesh_tri_0[] = {
	gsSPVertex(bg_Plane_mesh_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx bg_Plane_mesh_vtx_1[4] = {
	{{{-2, 80, 0}, 0, {-16, 1008}, {0x0, 0x0, 0x0, 0x0}}},
	{{{64, 80, 0}, 0, {1008, 1008}, {0x0, 0x0, 0x0, 0x0}}},
	{{{64, 100, 0}, 0, {1008, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-2, 100, 0}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
};

Gfx bg_Plane_mesh_tri_1[] = {
	gsSPVertex(bg_Plane_mesh_vtx_1 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_bg_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bg_f3dlite_material[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx bg_star_select_mesh[] = {
	gsSPDisplayList(mat_bg_f3dlite_material),
	gsSPDisplayList(bg_Plane_mesh_tri_0),
	gsSPDisplayList(mat_revert_bg_f3dlite_material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

Gfx bg_star_select_100_coin_mesh[] = {
	gsSPDisplayList(mat_bg_f3dlite_material),
	gsSPDisplayList(bg_Plane_mesh_tri_1),
	gsSPDisplayList(mat_revert_bg_f3dlite_material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

u32 starColors[] = {
    0x00FFFFFF, //hynotizing high rise
    0xF6ACA9FF, //koopa atoll
    0xC90000FF, //swirling circus
    0xFF7200FF, //peach ruins
    0xFF42B0FF, //cumulus correctional center
    0x932BC4FF, //forbidden factory
    0xFFE800FF, //feudal fortress
    0x00007DFF, //awe-inspiring spires
    0xDDCEFFFF, //bowsers scuba tower
    0xFFFFFFFF, //upturned deeps
    0xA9FF4FFF, //maple markindon
    0xFFFFFFFF, //course 12
    0xFFFFFFFF, //course 13
    0xFFFFFFFF, //course 14
    0xFFFFFFFF, //course 15
    0xFFFFFFFF, //brr (irrelevant cause custom model)
    0x3F3F3FFF, //bflfo
    0xFFFFFFFF, //bfufi
};

f32 rotVal = 0.0f;
f32 rotVal100Coin = 0.0f;
u8 *textOneHundredCoin = { TEXT_100_COIN_STAR };
void render_hub_star_select(s32 cringeTimer) {
    u8 **levelNameTbl = segmented_to_virtual(seg2_course_name_table);
    u8 *currLevelName = segmented_to_virtual(levelNameTbl[COURSE_NUM_TO_INDEX(hubSelections[gWorldID][gFocusID].courseID)]);
    u8 **actNameTbl = segmented_to_virtual(seg2_act_name_table);
    u8 *selectedActName;
    s32 lvlNameX;
    s32 actNameX;
    s32 localTimer;
    s32 fadeBarTimer;
    s32 fadeTextTimer;
    f32 centerX;
    rotVal += 5.0f;
    if(rotVal > 360.0f) {rotVal -= 360.0f;}
    u8 i = 0;
    u8 starNumbers[] = {TEXT_ZERO};
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(hubSelections[gWorldID][gFocusID].courseID));
    u8 visibleStars;
    u8 allStarsVisible = 1;
    u8 lastSelectableNotCompletedStar = 0;
    u32 starColor;
    u8 starColorR;
    u8 starColorG;
    u8 starColorB;
    rotVal100Coin += 5.0f;

    starColor = starColors[hubSelections[gWorldID][gFocusID].courseID - 1];
    starColorR = starColor >> 24;
    starColorG = (starColor >> 16) & 0xFF;
    starColorB = (starColor >> 8) & 0xFF;

    // for(i = 1; i < 10; i++) {
    //     save_file_set_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(i), 0x0F);
    // }

    visibleStars = 1;
    for(i = 0; i < 6; i++) {
        if(stars & (1 << i)) {
            if(allStarsVisible)
                visibleStars = i + 2;
            else
                visibleStars = i + 1;
        } else {
            if(allStarsVisible == 1) {
                lastSelectableNotCompletedStar = i;
                allStarsVisible = 0;
            }
        }
    }

    if(visibleStars > 6) {visibleStars = 6;}

    if(cringeTimer == 1) {
        selectedStar = lastSelectableNotCompletedStar;
    }

    centerX = (gScreenWidth/2) - (((f32)(visibleStars - 1))*25.0f);

    if (!gWarpTransition.isActive) {
        if(gDirectionsHeld & JOYSTICK_LEFT) {
            u8 oS = selectedStar;
            u8 j = 0;
            selectedStar--;
            while(j == 0 && selectedStar >= 0) {
               if((stars & (1 << selectedStar)) || selectedStar == lastSelectableNotCompletedStar) {j = 1;}
               else {selectedStar--;}
            }
            if(selectedStar < 0) {selectedStar = visibleStars - 1;}
            if(oS != selectedStar) rotVal = 0;
            play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gGlobalSoundSource);
        }
        if(gDirectionsHeld & JOYSTICK_RIGHT) {
            u8 oS = selectedStar;
            u8 j = 0;
            selectedStar++;
            while(j == 0 && selectedStar <= visibleStars - 1) {
               if((stars & (1 << selectedStar)) || selectedStar == lastSelectableNotCompletedStar) {j = 1;}
               else {selectedStar++;}
            }
            if(selectedStar > visibleStars - 1) {selectedStar = 0;}
            if(oS != selectedStar) rotVal = 0;
            play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gGlobalSoundSource);
        }
    }

    gCurrActNum = gDialogCourseActNum = selectedStar + 1;

    create_dl_ortho_matrix();
    fadeBarTimer = fadeTextTimer = cringeTimer*25;
    if(fadeBarTimer > 200) {fadeBarTimer = 200;}
    if(fadeTextTimer > 255) {fadeTextTimer = 255;}
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, fadeBarTimer);
    gSPClearGeometryMode(gDisplayListHead, G_ZBUFFER);
    gDPPipeSync(gDisplayListHead++);
    gSPDisplayList(gDisplayListHead++, bg_star_select_mesh);
    gSPDisplayList(gDisplayListHead++, bg_star_select_100_coin_mesh);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, fadeTextTimer);
    lvlNameX = get_str_x_pos_from_center(160, currLevelName + 3, 10.0f);
    print_generic_string(lvlNameX, 180, currLevelName + 3);
    print_generic_string(6, 82, textOneHundredCoin);

    selectedActName = segmented_to_virtual(actNameTbl[COURSE_NUM_TO_INDEX(hubSelections[gWorldID][gFocusID].courseID) * 6 + selectedStar]);
    actNameX = get_str_x_pos_from_center(160, selectedActName, 8.0f);
    print_generic_string(actNameX, 108, selectedActName);

    create_dl_translation_matrix(MENU_MTX_PUSH, centerX - 3.0f, 164.0f, 0.0f);
    for(i = 0; i < visibleStars; i++) {
        starNumbers[0] = 0x31 + i;
        create_dl_translation_matrix(MENU_MTX_PUSH, 50.0f*i, 0.0f, 0.0f);
        print_generic_string(0, 0, starNumbers);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, centerX, 144.0f, 0.0f);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.0625f, 0.0625f, 0.0005f);

    geo_clear_zbuffer(gDisplayListHead);
    gSPSetGeometryMode(gDisplayListHead++, G_ZBUFFER);
    gDPPipeSync(gDisplayListHead++);
    for(i = 0; i < visibleStars; i++) {
        localTimer = cringeTimer - (i*2);
        if (localTimer < 0) { localTimer = 0; }
        create_dl_translation_matrix(MENU_MTX_PUSH, 800.0f*i, (200.0f / ((((f32)(localTimer)) / 10.0f) + 0.1f)), 0.0f);

        if(selectedStar == i) {
            create_dl_rotation_matrix(MENU_MTX_NOPUSH, rotVal, 0.0f, 1.0f, 0.0f);
            create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.25f, 1.25f, 1.25f);
        }

        if(stars & (0x1 << i)) {
            gDPSetPrimColor(gDisplayListHead++, 0, 0, starColorR, starColorG, starColorB, 255);
            gSPDisplayList(gDisplayListHead++, star_hud_dl);
        } else {
            gSPDisplayList(gDisplayListHead++, transparent_star_hud_dl);
        }

        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }

    // render glow now that z buffer as been written to
    {
        gDPPipeSync(gDisplayListHead++);
        gDPSetDepthSource(gDisplayListHead++, G_ZS_PRIM);
        gDPSetPrimDepth(gDisplayListHead++, 0x6000 - 1, 0);
        gDPPipeSync(gDisplayListHead++);
        localTimer = cringeTimer - (selectedStar*2);
        if (localTimer < 0) { localTimer = 0; }
        create_dl_translation_matrix(MENU_MTX_PUSH, 800.0f*selectedStar, (200.0f / ((((f32)(localTimer)) / 10.0f) + 0.1f)), 0.0f);
        gDPSetRenderMode(gDisplayListHead++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF);
        gDPSetPrimColor(gDisplayListHead++, 0, 0, starColorR, starColorG, starColorB, 255);
        gSPDisplayList(gDisplayListHead++, glow_circle_mesh);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gDPSetDepthSource(gDisplayListHead++, G_ZS_PIXEL);
    gDPPipeSync(gDisplayListHead++);



    //100 coin star
    create_dl_translation_matrix(MENU_MTX_PUSH, 54.0f, 90.0f, 0.0f);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.04f, 0.04f, 0.0005f);

    geo_clear_zbuffer(gDisplayListHead);
    gSPSetGeometryMode(gDisplayListHead++, G_ZBUFFER);
    gDPPipeSync(gDisplayListHead++);
    localTimer = cringeTimer;
    if (localTimer < 0) { localTimer = 0; }
    create_dl_translation_matrix(MENU_MTX_PUSH, -(200.0f / ((((f32)(localTimer)) / 10.0f) + 0.1f)), 0.0f, 0.0f);

    create_dl_rotation_matrix(MENU_MTX_NOPUSH, rotVal100Coin + 180.0f, 0.0f, 1.0f, 0.0f);

    if(stars & (0x40)) {
        gDPSetPrimColor(gDisplayListHead++, 0, 0, starColorR, starColorG, starColorB, 255);
        gSPDisplayList(gDisplayListHead++, star_hud_dl);
    } else {
        gSPDisplayList(gDisplayListHead++, transparent_star_hud_dl);
    }

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gDPSetDepthSource(gDisplayListHead++, G_ZS_PIXEL);
    gDPPipeSync(gDisplayListHead++);
}

u8 levelConfString[] = { TEXT_LEVEL_CONFIRMATION };
void render_hub_level_confirmation() {
    char *filledString = {TEXT_FILLEDSTRING};
    create_dl_ortho_matrix();
    render_bar(80, filledString, 0);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    print_string_with_shadow(40, 80, levelConfString, 0xFFFFFFFF);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

/* void new_star_select_loop(void) {
    Mtx *mtx   = alloc_display_list(sizeof(Mtx));
    Vec3f focusVec;
    vec3f_set(focusVec, (gCamera->pos[0] - gCamera->focus[0]), (gCamera->pos[1] - gCamera->focus[1]), (gCamera->pos[2] - gCamera->focus[2]));
    vec3f_normalize(focusVec);

    if (mtx == NULL) {
        return;
    }

    mtxf_to_mtx(mtx, gMatStack[0]);
    create_dl_translation_matrix(MENU_MTX_NOPUSH, gCamera->pos[0] - focusVec[0]*10000.0f, gCamera->pos[1] - focusVec[1]*10000.0f, gCamera->pos[2] - focusVec[2]*10000.0f);
    guScale(mtx, 0.0625f, 0.0625f, 0.0625f);
    geo_clear_zbuffer(gDisplayListHead++);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPDisplayList(gDisplayListHead++, star_seg3_dl_body);
    gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gSPDisplayList(gDisplayListHead++, star_seg3_dl_eyes);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
} */

u8 textYouGotAStar[] = { TEXT_YOU_GOT_A_STAR };
u8 textYouGotAKey[] = { TEXT_YOU_GOT_A_KEY };
u8 textSaveQuestion[] = { TEXT_SAVE_QUESTION };
u8 textYesLC[] = { TEXT_YES_LC };
u8 textNoLC[] = { TEXT_NO_LC };
u8 textContinueToNextAct[] = { TEXT_CONTINUE_TO_NEXT_ACT };
u8 textReplayLastAct[] = { TEXT_REPLAY_LAST_ACT };
u8 textExitCourseLC[] = { TEXT_EXIT_COURSE_LC };
u8 textExitGame[] = { TEXT_EXIT_GAME };
u8 textAndThe100CoinStar[] = { TEXT_AND_THE_100_COIN_STAR };
u8 textAndTheRedCoinStar[] = { TEXT_AND_THE_RED_COIN_STAR };
u8 textNextUnfinishedAct[] = { TEXT_NEXT_UNFINISHED_ACT };
u8 textAllActsCompleted[] = { TEXT_ALL_ACTS_COMPLETED };
u8 text100CoinStar[] = { TEXT_ONE_HUNDRED_COIN_STAR };
u8 textKeyTo[] = { TEXT_KEY_TO };

extern void initiate_warp(s16 destLevel, s16 destArea, s16 destWarpNode, s32 warpFlags);

extern LookAt lookAt;

s32 gEndResultMenuChoice = 0;
s32 gEndResultMenuState = 0;
void end_results_loop(void) {
    u8 **actNameTbl = segmented_to_virtual(seg2_act_name_table);
    u8 *selectedActName;
    s32 actNameX;
    u32 starColor;
    u8 starColorR;
    u8 starColorG;
    u8 starColorB;
    u8 nextUnfinishedAct = 0;

    if(gCurrCourseNum < 16) {
        selectedActName = segmented_to_virtual(actNameTbl[COURSE_NUM_TO_INDEX(gCurrCourseNum) * 6 + gLastCompletedStarNum - 1]);
        actNameX = get_str_x_pos_from_center(160, selectedActName, 2.0f);
    } else {
        selectedActName = textKeyTo;
        textKeyTo[17] = gCurrCourseNum == 17 ? 0x32 : 0x33;
        actNameX = 100;
    }
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));
    u8 i;

    for(i = 0; i < 6; i++) {
        if(stars & (1 << i)) {

        } else {
            nextUnfinishedAct = i + 1;
            i = 200;
            break;
        }
    }

    if(gLastCompletedStarNum > 6) {
        selectedActName = text100CoinStar;
    }

    starColor = starColors[gCurrCourseNum - 1];
    starColorR = starColor >> 24;
    starColorG = (starColor >> 16) & 0xFF;
    starColorB = (starColor >> 8) & 0xFF;

    rotVal += 5.0f;
    if(rotVal > 360.0f) {rotVal -= 360.0f;}

    rotVal100Coin += 7.0f;
    if(rotVal > 360.0f) {rotVal -= 360.0f;}

    if(gDirectionsHeld & JOYSTICK_UP) {
        gEndResultMenuChoice--;
        if(gEndResultMenuChoice < 0) {gEndResultMenuChoice = 1 + gEndResultMenuState;}
        play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
    }
    if(gDirectionsHeld & JOYSTICK_DOWN) {
        gEndResultMenuChoice++;
        if(gEndResultMenuChoice > 1 + gEndResultMenuState) {gEndResultMenuChoice = 0;}
        play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
    }
    gHudDisplay.flags = 0;
    if(gEndResultMenuState < 2) {
        create_dl_ortho_matrix();
        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
            create_dl_scale_matrix(MENU_MTX_PUSH, 2.0f, 2.0f, 1.0f);
            if(gCurrCourseNum > 0 && gCurrCourseNum < 16) {
                print_generic_string(get_str_x_pos_from_center(80, textYouGotAStar, 2.0f), 100, textYouGotAStar);
            } else {
                print_generic_string(get_str_x_pos_from_center(80, textYouGotAKey, 2.0f), 100, textYouGotAKey);
            }
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
        if(gCoinStarCollected) {
            print_generic_string(110, 180, textAndThe100CoinStar);
        }
        if(gRedCoinStarCollected) {
            print_generic_string(110, 180, textAndTheRedCoinStar);
        }
        print_generic_string(actNameX + 10, 150, selectedActName);

        if(gEndResultMenuState == 1) {
            if(nextUnfinishedAct == 0) {
                u8 nextPlayableAct = ((gLastCompletedStarNum % 6) + 1);
                print_generic_string(get_str_x_pos_from_center(160, textAllActsCompleted, 2.0f), 120, textAllActsCompleted);
                textReplayLastAct[11] = 0x30 + nextPlayableAct;
                print_generic_string(125, 70, textReplayLastAct);
            } else {
                u8 *nextActName = segmented_to_virtual(actNameTbl[COURSE_NUM_TO_INDEX(gCurrCourseNum) * 6 + nextUnfinishedAct - 1]);
                textNextUnfinishedAct[13] = 0x30 + nextUnfinishedAct;
                print_generic_string(get_str_x_pos_from_center(160, textNextUnfinishedAct, 2.0f), 120, textNextUnfinishedAct);
                print_generic_string(get_str_x_pos_from_center(160, nextActName, 2.0f), 100, nextActName);
                textContinueToNextAct[16] = 0x30 + nextUnfinishedAct;
                print_generic_string(125, 70, textContinueToNextAct);
            }
            print_generic_string(125, 50, textExitCourseLC);
            print_generic_string(125, 30, textExitGame);
                create_dl_translation_matrix(MENU_MTX_PUSH, 105.0f, 70.0f - (gEndResultMenuChoice*20.0f), 0.0f);
                gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
            
            if(gPlayer1Controller->buttonPressed & A_BUTTON) {
                play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
                if(gEndResultMenuChoice == 0) {
                    if(nextUnfinishedAct > 0) {
                        gCurrActNum = nextUnfinishedAct;
                        gDialogCourseActNum = nextUnfinishedAct;
                    } else {
                        gCurrActNum = ((gLastCompletedStarNum % 6) + 1);
                        gDialogCourseActNum = ((gLastCompletedStarNum % 6) + 1);
                    }
                    sDelayedWarpOp = 1;
                    sDelayedWarpArg = 0x00000002;
                    sDelayedWarpTimer = 2;
                    sSourceWarpNodeId = 0xF0;
                } else if(gEndResultMenuChoice == 1) {
                    initiate_warp(EXIT_COURSE_LEVEL, EXIT_COURSE_AREA, EXIT_COURSE_NODE, WARP_FLAGS_NONE);
                    fade_into_special_warp(WARP_SPECIAL_NONE, 0);
                    gSavedCourseNum = COURSE_NONE;
                    gHubStarSelectTimer = 0;
                    gCustomStarSelectActive = 0;
                    gLevelEntryConfirmationActive = 0;
                } else {
                    fade_into_special_warp(WARP_SPECIAL_MARIO_HEAD_REGULAR, 0);
                    gWorldID = 0;
                    gFocusID = 0;
                    gCustomStarSelectActive = 0;
                    gHubStarSelectTimer = 0;
                    gLevelEntryConfirmationActive = 0;
                }
                gEndResultMenuState = 2;
                gEndResultMenuChoice = 0;
                gHudDisplay.flags = HUD_DISPLAY_DEFAULT;
                gCoinStarCollected = 0;
                gRedCoinStarCollected = 0;
            }
        }
        if(gEndResultMenuState == 0) {
            print_generic_string(get_str_x_pos_from_center(160, textSaveQuestion, 2.0f), 130, textSaveQuestion);
            print_generic_string(150, 60, textYesLC);
            print_generic_string(150, 40, textNoLC);
                create_dl_translation_matrix(MENU_MTX_PUSH, 130.0f, 60.0f - (gEndResultMenuChoice*20.0f), 0.0f);
                gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

            if(gPlayer1Controller->buttonPressed & A_BUTTON) {
                play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
                if(gEndResultMenuChoice == 0) {
                    save_file_do_save(gCurrSaveFileNum - 1);
                }
                if(gCurrCourseNum > 0 && gCurrCourseNum < 16) {
                    gEndResultMenuState = 1;
                } else {
                    initiate_warp(EXIT_COURSE_LEVEL, EXIT_COURSE_AREA, EXIT_COURSE_NODE, WARP_FLAGS_NONE);
                    fade_into_special_warp(WARP_SPECIAL_NONE, 0);
                    gSavedCourseNum = COURSE_NONE;
                    gHubStarSelectTimer = 0;
                    gCustomStarSelectActive = 0;
                    gLevelEntryConfirmationActive = 0;
                    gEndResultMenuState = 2;
                    gHudDisplay.flags = HUD_DISPLAY_DEFAULT;
                }
                if(nextUnfinishedAct == 0) {
                    gEndResultMenuChoice = 1;
                } else {
                    gEndResultMenuChoice = 0;
                }
            }
        }
        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
        geo_clear_zbuffer(gDisplayListHead);
        gSPSetGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gSPLookAt(gDisplayListHead++, &lookAt); // needed for env map reflections

            if(gCurrCourseNum > 0 && gCurrCourseNum < 16) {
                create_dl_translation_matrix(MENU_MTX_PUSH, actNameX - 10.0f, 158.0f, 0.0f);
                create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.0625f, 0.0625f, 0.0005f);
                create_dl_rotation_matrix(MENU_MTX_NOPUSH, rotVal, 0.0f, 1.0f, 0.0f);
                gDPSetPrimColor(gDisplayListHead++, 0, 0, starColorR, starColorG, starColorB, 255);
                gSPDisplayList(gDisplayListHead++, star_hud_dl);
            } else {
                create_dl_translation_matrix(MENU_MTX_PUSH, 160.0f, 170.0f, 0.0f);
                create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.0625f, 0.0625f, 0.0005f);
                create_dl_rotation_matrix(MENU_MTX_NOPUSH, rotVal, 0.0f, 1.0f, 0.0f);
                create_dl_rotation_matrix(MENU_MTX_NOPUSH, -90.0f, 0.0f, 0.0f, 1.0f);
                gSPDisplayList(gDisplayListHead++, bowser_key_dl);
            }
            if(gCoinStarCollected || gRedCoinStarCollected) {
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                create_dl_translation_matrix(MENU_MTX_PUSH, 95.0f, 188.0f, 0.0f);
                create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.03125f, 0.03125f, 0.0005f);
                create_dl_rotation_matrix(MENU_MTX_NOPUSH, 165.0f + (rotVal100Coin), 0.0f, 1.0f, 0.0f);
                gDPSetPrimColor(gDisplayListHead++, 0, 0, starColorR, starColorG, starColorB, 255);
                if(gCurrLevelNum == LEVEL_BOWSER_1) {
                    gSPDisplayList(gDisplayListHead++, rainbow_star_hud_dl);
                } else {
                    gSPDisplayList(gDisplayListHead++, star_hud_dl);
                }
            }
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }
}
