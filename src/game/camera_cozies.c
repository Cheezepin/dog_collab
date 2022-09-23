#include <types.h>
#include "engine/math_util.h"
#include "levels/ddd/header.h"
#include "area.h"
#include "camera_cozies.h"
#include "camera.h"

PosFocusFov *cozies_init_views[] = {
    NULL,
    &CamAct1Pos,
    &CamAct2Pos,
    &CamAct3Pos,
    &CamAct4Pos,
    &CamAct5Pos,
    &CamAct6Pos,
};

void set_cur_act_pos_focus_fov(struct Camera *c) {
    PosFocusFov *view = segmented_to_virtual(cozies_init_views[gCurrActNum]);
    vec3f_copy(c->init_view_pos, view->pos);
    f32 *foc = segmented_to_virtual(view->focus);
    vec3f_copy(c->init_view_focus, foc);
    c->init_view_fov = view->fov;
}


PosFocusFov *cozies_switch_cutscene_views[] = {
    NULL,
    &CamSwitch1Pos,
    NULL,
    &CamSwitch3Pos,
    &CamSwitch4Pos,
};


void set_switch_cutscene_pos_focus_fov(CozyCutscenePosFocusFov *cutscene, u8 switchId) {
    PosFocusFov *view = segmented_to_virtual(cozies_switch_cutscene_views[switchId]);
    vec3f_copy(cutscene->pos, view->pos);
    f32 *foc = segmented_to_virtual(view->focus);
    vec3f_copy(cutscene->focus, foc);
    cutscene->fov = view->fov;
}


void ClosestPointOnLineSegment(Vec3f A, Vec3f B, Vec3f Point, Vec3f res)
{
    Vec3f AB;
    vec3f_diff(AB, B, A);

    Vec3f PA;
    vec3f_diff(PA, Point, A);

    f32 t = vec3f_dot(PA, AB) / vec3f_dot(AB, AB);
    t = MIN_MAX(t, 0, 1);
    vec3_prod_val(AB, AB, t);

    vec3f_add(AB, A);
    vec3f_copy(res, AB);
}

s32 test_line_segment(Vec3f center, f32 radSq, Vec3f v1, Vec3f v2, Vec3f point) {
    Vec3f diff;

    ClosestPointOnLineSegment(v1, v2, center, point);
    vec3f_diff(diff, center, point);
    f32 distsq1 = vec3f_dot(diff, diff);
    return distsq1 < radSq;
}
