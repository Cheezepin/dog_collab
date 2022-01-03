#include "types.h"
#include "object_fields.h"
#include "game/level_update.h"
#include "game/mario.h"
#include "game/object_list_processor.h"
#include "game/rendering_graph_node.h"
#include "engine/math_util.h"
#include "levels/ddd/header.h"

#ifndef THECOZIES_HELPERS_H
#define THECOZIES_HELPERS_H

void elastic_approach(f32 *cur, f32 *curVel, f32 goal, f32 speedDown, f32 speedUp);
void elastic_approach_vec3f(Vec3f cur, Vec3f curVel, Vec3f goal, f32 speedDown, f32 speedUp);
void audio_meter_approach(f32 *cur, f32 next, f32 reduction, s32 timeout, s32 *momentumTimer);
void elastic_approach_vec3s(Vec3s cur, Vec3s curVel, Vec3s goal, f32 speedDown, f32 speedUp);

#endif
