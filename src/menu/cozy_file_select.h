#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "types.h"

#pragma once

struct _FileSelectMenuState;

typedef struct _EnumOption {
    u8 value;
    char *label;
} EnumOption;

typedef s32 (*FileSelectOptionCallback)(struct _FileSelectMenuState *mState);

typedef struct _FileSelectOption {
    char *label;
    FileSelectOptionCallback onSelect;
    s8 disabled;
    EnumOption *enumOptions;
    u8 numEnumOptions;
    s16 *curEnumValue;
    u8 overrideMenuType;
} FileSelectOption;

typedef struct _FileSelectMenu {
    FileSelectOption *options;
    u8 numOptions;
    s8 curOpt;
    char *label;
    struct _FileSelectMenu *parentOptions;
    u8 menuType;
} FileSelectMenu;

#define MENU_OPTIONS(opts, label, parent, menuType) { opts, (s32)(sizeof(opts) / sizeof(FileSelectOption)), 0, label, parent, menuType }

typedef struct _FileSelectMenuState {
    u8 waitingForStickReturn;
    u8 waitingForEnumStickReturn;
    s8 optDirection; // -1/0/1
    s8 enumDirection; // -1/0/1
    FileSelectMenu *menu;
    FileSelectMenu *parentMenu;
    s32 alpha;
    u8 closing;
    u16 closeTimer;
} FileSelectMenuState;

enum FileSelectPresses {
    FILE_SELECT_PRESS_NONE,
    FILE_SELECT_PRESS_CONFIRM,
    FILE_SELECT_PRESS_CANCEL,
};

enum FileSelectCallbackResponse {
    OPT_CALLBACK_NONE,
    OPT_CALLBACK_EXIT,
    OPT_CALLBACK_BACK,
    OPT_CALLBACK_CLOSE,
};

enum FileSelectMenuTypes {
    MENU_TYPE_BASIC,
    MENU_TYPE_NUMBERED,
};

void init_file_select(void);
s32 run_file_select(void);
