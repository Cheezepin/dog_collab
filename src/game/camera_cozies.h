#pragma once

void ClosestPointOnLineSegment(Vec3f A, Vec3f B, Vec3f Point, Vec3f res);
void set_cur_act_pos_focus_fov(struct Camera *c);
void set_switch_cutscene_pos_focus_fov(CozyCutscenePosFocusFov *cutscene, u8 switchId);

#define CAM_INIT_TIMER_START (5.0f * 30)
#define CAM_INIT_TIMER_LERP_START (CAM_INIT_TIMER_START - (1.5f * 30))

#define COZY_SWITCH_CUTSCENE_PART2 (lroundf(1.5f * 30))
#define COZY_SWITCH_CUTSCENE_LENGTH (4 * 30)
