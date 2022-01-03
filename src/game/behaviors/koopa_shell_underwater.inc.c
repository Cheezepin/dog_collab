// koopa_shell_underwater.c.inc
#include "src/game/obj_behaviors.h"
struct ObjectHitbox sKoopaShellUnderwaterHitbox = {
    /* interactType: */ INTERACT_GRABBABLE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 80,
    /* height: */ 50,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

void set_koopa_shell_underwater_hitbox(void) {
    obj_set_hitbox(o, &sKoopaShellUnderwaterHitbox);
}

void koopa_shell_underwater_get_thrown(void) {
    cur_obj_become_tangible();
    cur_obj_enable_rendering();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = 0;
    o->oAction = 1;
    o->oForwardVel = 50.0f;
    o->oVelY = 20.0f;
    obj_set_angle(o, gMarioState->faceAngle[0], gMarioState->faceAngle[1], gMarioState->faceAngle[2]);
    o->oVelX = o->oForwardVel * coss(gMarioState->faceAngle[0]) * sins(gMarioState->faceAngle[1]);
    o->oVelY = o->oForwardVel * sins(gMarioState->faceAngle[0]);
    o->oVelZ = o->oForwardVel * coss(gMarioState->faceAngle[0]) * coss(gMarioState->faceAngle[1]);

    cur_obj_move_using_vel();

    // o->oMoveAngleYaw = gMarioObject->header.gfx.angle[1];
    // o->activeFlags &= ~ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
}

s32 koopa_shell_check_walls(void) {
    struct WallCollisionData hitbox;
    f32 wall_nX, wall_nY, wall_nZ, objVelXCopy, objVelZCopy, objYawX, objYawZ;

    hitbox.x = o->oPosX;
    hitbox.y = o->oPosY;
    hitbox.z = o->oPosZ;
    hitbox.offsetY = o->hitboxHeight / 2;
    hitbox.radius = o->hitboxRadius;
    return find_wall_collisions(&hitbox) != 0;
}

void koopa_shell_underwater_thrown(void) {
    o->oFaceAngleYaw += DEGREES(30);
    if (o->oAction == 1) {
        if (o->numCollidedObjs > 0 && o->collidedObjs[0] != gMarioObject) {
            cur_obj_change_action(2);
            return;
        }

        cur_obj_move_using_vel();
        cur_obj_update_floor_height();

        s32 hit_floor = (s32) o->oFloorHeight >= (s32) (o->oPosY - (o->hitboxHeight * 0.5f));
        if (hit_floor) {
            cur_obj_change_action(2);
            return;
        }


        s32 hit_wall = koopa_shell_check_walls();
        if (hit_wall) {
            cur_obj_change_action(2);
            return;
        }

        struct Surface *ceil;
        f32 ceilHeight = find_ceil(o->oPosX, o->oPosY, o->oPosZ, &ceil);
        s32 hit_ceil = (s32) ceilHeight <= (s32)(o->oPosY + (o->hitboxHeight * 0.5f));
        if (hit_ceil) {
            cur_obj_change_action(2);
            return;
        }
    } else {
        struct Object *explosion;
        if (o->oTimer < 5)
            cur_obj_scale(1.0f + (f32) o->oTimer / 5.0f);
        else {
            explosion = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
            explosion->oGraphYOffset += 100.0f;
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
        }
    }
    
}

void bhv_koopa_shell_underwater_loop(void) {
    if (o->oAction >= 1) {
        koopa_shell_underwater_thrown();
        return;
    }
    switch (o->oHeldState) {
        case HELD_FREE:
            set_koopa_shell_underwater_hitbox();
            break;
        case HELD_HELD:
            cur_obj_unrender_set_action_and_anim(-1, 0);
            break;
        case HELD_THROWN:
            koopa_shell_underwater_get_thrown();
            return;
        case HELD_DROPPED:
            spawn_mist_particles();
            obj_mark_for_deletion(o);
            break;
    }
    if (o->oInteractStatus & INT_STATUS_STOP_RIDING) {
        spawn_mist_particles();
        obj_mark_for_deletion(o);
    }
    o->oInteractStatus = 0;
}
