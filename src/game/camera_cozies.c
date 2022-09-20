#include <types.h>
#include "engine/math_util.h"
#include "camera_cozies.h"

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
