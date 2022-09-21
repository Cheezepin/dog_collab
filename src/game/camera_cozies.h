#pragma once

void ClosestPointOnLineSegment(Vec3f A, Vec3f B, Vec3f Point, Vec3f res);
void set_cur_act_pos_focus_fov(struct Camera *c);

#define CAM_INIT_TIMER_START (5.0f * 30)
#define CAM_INIT_TIMER_LERP_START (CAM_INIT_TIMER_START - (1.5f * 30))
