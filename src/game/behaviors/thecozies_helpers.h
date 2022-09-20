#include <PR/gbi.h>
#include "types.h"
#include "object_fields.h"
#include "game/level_update.h"
#include "game/mario.h"
#include "game/game_init.h"
#include "game/object_list_processor.h"
#include "game/rendering_graph_node.h"
#include "game/print.h"
#include "game/save_file.h"
#include "game/tile_scroll.h"
#include "engine/math_util.h"
#include "levels/ddd/header.h"
#include "behavior_data.h"

#ifndef THECOZIES_HELPERS_H
#define THECOZIES_HELPERS_H

void elastic_approach(f32 *cur, f32 *curVel, f32 goal, f32 speedDown, f32 speedUp);
void elastic_approach_vec3f(Vec3f cur, Vec3f curVel, Vec3f goal, f32 speedDown, f32 speedUp);
void audio_meter_approach(f32 *cur, f32 next, f32 reduction, s32 timeout, s32 *momentumTimer);
void elastic_approach_vec3s(Vec3s cur, Vec3s curVel, Vec3s goal, f32 speedDown, f32 speedUp);
struct Object *find_any_object_with_behavior_and_bparam2(const BehaviorScript *behavior, u32 bparam);
s32 check_mario_on_object(struct MarioState *m);

ALWAYS_INLINE s32 check_water(void) {
    return gCurrActNum > 1;
    // return save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_DDD)) & STAR_FLAG_ACT_1;
}

ALWAYS_INLINE struct Object *get_water_switch(s32 sID) {
    return find_any_object_with_behavior_and_bparam2(bhvWaterSwitch, sID);
}

ALWAYS_INLINE s32 check_my_water_level_is_active(void) {
    struct Object *obj = find_any_object_with_behavior_and_bparam2(bhvWaterSwitch, BPARAM2);
    if (!obj) return FALSE;
    return obj->oWaterSwitchActivated;
    // return save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_DDD)) & STAR_FLAG_ACT_1;
}

#endif
