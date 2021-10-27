#define DOG_ANIM_IDLE 0
#define DOG_ANIM_DIG  1
#define DOG_ANIM_RUN  2
#define DOG_ANIM_WALK 3

#define OBJ_COL_FLAG_GROUNDED   (1 << 0)

void dog_FollowMario(void) {
    s16 colFlags = object_step();
    if (o->oDistanceToMario > 1000) {
        cur_obj_init_animation(DOG_ANIM_RUN);
        o->oForwardVel = 20.0f;
        obj_turn_toward_object(o, gMarioObject, 16, 0x800);
    } else if (o->oDistanceToMario > 500) {
        if (o->oTimer > 18) {
            cur_obj_init_animation(DOG_ANIM_WALK);
            o->oForwardVel = 10.0f;
            obj_turn_toward_object(o, gMarioObject, 16, 0x800);
        }
    } else {
        o->oTimer = 0;
        cur_obj_init_animation(DOG_ANIM_IDLE);
        o->oForwardVel = 0.0f;
    }
    struct MarioState *m = gMarioState;
    // zoom to mario
    if ((o->oPosY + 50.0f < m->pos[1]) && m->action & (ACT_FLAG_STATIONARY | ACT_FLAG_MOVING)) {
        #define DOG_SNAP_SPEED 25.0f
        o->oPosX = approach_f32(o->oPosX, m->pos[0], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
        o->oPosY = approach_f32(o->oPosY, m->pos[1], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
        o->oPosZ = approach_f32(o->oPosZ, m->pos[2], DOG_SNAP_SPEED, DOG_SNAP_SPEED);
    }
}


