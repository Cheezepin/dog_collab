#ifndef LEVEL_SCRIPT_H
#define LEVEL_SCRIPT_H

#include <PR/ultratypes.h>

struct LevelCommand;

extern LevelScript level_script_entry[];

struct LevelCommand *level_script_execute(struct LevelCommand *cmd);

extern s32 determine_starting_level(void);

#endif // LEVEL_SCRIPT_H
