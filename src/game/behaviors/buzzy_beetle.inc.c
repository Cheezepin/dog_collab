#define BUZZY_BEET_ACT_WALK 0
#define BUZZY_BEET_ACT_ATTACKED_MARIO 1
#define BUZZY_BEET_ACT_WIND_UP 2
#define BUZZY_BEET_ACT_IN_SHELL 3

#include <PR/ultratypes.h>

#include "src/game/area.h"
#include "actors/common1.h"
#include "audio/external.h"
#include "src/game/behavior_actions.h"
#include "behavior_data.h"
#include "src/game/camera.h"
#include "src/engine/math_util.h"
#include "src/engine/surface_collision.h"
#include "src/game/game_init.h"
#include "src/game/interaction.h"
#include "src/game/level_update.h"
#include "src/game/mario.h"
#include "src/game/mario_step.h"
#include "src/game/memory.h"
#include "src/game/obj_behaviors.h"
#include "src/game/object_helpers.h"
#include "src/game/obj_behaviors_2.h"
#include "src/game/save_file.h"
#include "sm64.h"
#include "src/game/sound_init.h"


#define INT_KICK                  (1 << 2) // 0x04
#define INT_TRIP                  (1 << 3) // 0x08

static struct ObjectHitbox sBuzzyBeetleHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 95,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

static u8 sBuzzyBeetleAttackHandlers[][6] = {
    // regular and tiny
    {
        /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
        /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
        /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
        /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_GPD_ON,
        /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
        /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
    }
};

void bhv_buzzy_beetle_init(void) {

    obj_set_hitbox(o, &sBuzzyBeetleHitbox);
    o->oGravity = -8.0f / 3.0f;
    o->oForwardVel = 0;
}

static void buzzy_beetle_begin_charge(void) {
    cur_obj_play_sound_2(SOUND_OBJ_GOOMBA_ALERT);
    o->oAnimState = 1;
    o->oAction = BUZZY_BEET_ACT_WIND_UP;
    o->oForwardVel = 0.0f;
    //o->oVelY = 50.0f / 3.0f;
}

static void buzzy_beetle_act_walk(void) {
    o->oAnimState = 0;
    cur_obj_init_animation_with_accel_and_sound(1, 0.5f + o->oForwardVel / 3.0f);
    treat_far_home_as_mario(1000.0f);

    o->oDistanceToMario = lateral_dist_between_objects(o, gMarioObject);
    o->oAngleToMario = obj_angle_to_object(o, gMarioObject);

    obj_forward_vel_approach(o->oGoombaRelativeSpeed, 0.4f);

    // If walking fast enough, play footstep sounds
    if (o->oGoombaRelativeSpeed > 3.0f) {
        cur_obj_play_sound_at_anim_range(2, 17, SOUND_OBJ_GOOMBA_WALK);
    }

    if (o->oGoombaTurningAwayFromWall) {
        o->oGoombaTurningAwayFromWall = obj_resolve_collisions_and_turn(o->oGoombaTargetYaw, 0x200);
    } else {
        // If far from home, walk toward home.
        if (o->oDistanceToMario >= 25000.0f) {
            o->oGoombaTargetYaw = o->oAngleToMario;
            o->oGoombaWalkTimer = random_linear_offset(20, 30);
        }

        if (!(o->oGoombaTurningAwayFromWall =
                  obj_bounce_off_walls_edges_objects(&o->oGoombaTargetYaw))) {
            if (o->oDistanceToMario < 500.0f) {

                if (o->oGoombaRelativeSpeed <= 2.0f) {
                    buzzy_beetle_begin_charge();
                }

                o->oGoombaTargetYaw = o->oAngleToMario;
                o->oGoombaRelativeSpeed = 20.0f;
            } else {

                o->oGoombaRelativeSpeed = 4.0f / 3.0f;
                if (o->oGoombaWalkTimer != 0) {
                    o->oGoombaWalkTimer -= 1;
                } else {
                    if (random_u16() & 3) {
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x2000);
                        o->oGoombaWalkTimer = random_linear_offset(100, 100);
                    } else {
                        //buzzy_beetle_begin_jump();
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x6000);
                    }
                }
            }
        }

        cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x200);
    }
}

static void buzzy_beetle_act_attacked_mario(void) {
        buzzy_beetle_begin_charge();
        o->oGoombaTargetYaw = o->oAngleToMario;
        o->oGoombaTurningAwayFromWall = FALSE;
}

s32 numCollidedObjs;
struct Object *other;
u8 charging;

static void buzzy_beetle_charge(u16 timeBeforeSlowdown, u8 prevAction) {
    obj_resolve_object_collisions(NULL);

    numCollidedObjs = o->numCollidedObjs;

    if (numCollidedObjs != 0) {
            other = o->collidedObjs[0];

            if (other != gMarioObject) {
                other->oInteractStatus |= ATTACK_PUNCH | INT_STATUS_WAS_ATTACKED | INT_STATUS_INTERACTED
                                      | INT_STATUS_TOUCHED_BOB_OMB;
            }
        }

    //o->oGoombaRelativeSpeed = 20.0f;

    o->oAnimState = 1;
    cur_obj_init_animation_with_accel_and_sound(0, o->oForwardVel / 5.0f);
    if(o->oTimer <= timeBeforeSlowdown) {
        o->oForwardVel = 25.0f;
    } else {
        o->oForwardVel = o->oForwardVel - 0.5f;
        if(o->oForwardVel < 1.0f) {
            o->oAction = prevAction;
            charging = 0;
        } 
    }
    cur_obj_if_hit_wall_bounce_away();
}

void buzzy_beetle_act_wind_up(void) {
    if(o->oTimer <= 30) {
        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x800);
        cur_obj_init_animation_with_accel_and_sound(0, 5.0f);
        o->oForwardVel = 0.0f;
    } else
        buzzy_beetle_charge(31, BUZZY_BEET_ACT_WALK);
}

void buzzy_beetle_act_in_shell(void) {

    s16 dYawToObject = obj_angle_to_object(gMarioObject, o) - gMarioState->faceAngle[1];
    if (gMarioState->flags & MARIO_KICKING && o->oInteractStatus != 0 && o->collidedObjs[0] == gMarioObject) {
                // 120 degrees total, or 60 each way
                if (-0x2AAA <= dYawToObject && dYawToObject <= 0x2AAA) {
                    charging = 1;
                    o->oTimer = 0;
                    o->oMoveAngleYaw = obj_angle_to_object(gMarioObject, o);
                }
    }

    if(charging == 1) {
        if (o->oTimer > 6)
            o->oInteractType = INTERACT_BOUNCE_TOP;
        buzzy_beetle_charge(30, BUZZY_BEET_ACT_IN_SHELL);
    } else {
        o->oForwardVel = 0;
        //o->oGoombaBlinkTimer = 1.0f;
        cur_obj_init_animation_with_accel_and_sound(1, 0.0f);
            o->oAnimState = 1;
            o->oInteractType = INTERACT_GRABBABLE;
            o->oInteractionSubtype = INT_SUBTYPE_KICKABLE;
            charging = 0;
            if(o->oDistanceToMario < 100.0f && gMarioState->action & ACT_FLAG_AIR && gMarioState->pos[1] > o->oPosY) {
                charging = 1;
                o->oTimer = 0;
                o->oMoveAngleYaw = obj_angle_to_object(gMarioObject, o);
                gMarioState->pos[1] = o->oPosY + o->hitboxHeight;
                gMarioState->vel[1] = 30.0f;
                gMarioState->flags &= ~MARIO_UNKNOWN_08;
                play_sound(SOUND_ACTION_BOUNCE_OFF_OBJECT, gMarioState->marioObj->header.gfx.cameraToObject);
            }
    }
}

void bhv_buzzy_beetle_update(void) {
    
    if (gMarioState->heldObj != o && o->oGaloombaGrabbed == 1) {
        o->oGaloombaGrabbed = 0;
        cur_obj_become_tangible();
       o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
       if (o->oHeldState != HELD_FREE) {
        cur_obj_get_dropped();
        o->oAction = BUZZY_BEET_ACT_IN_SHELL;
        if (gMarioState->action & 0x80000000)
            charging = 1;
        else
            charging = 0;
        o->oIntangibleTimer = 5;
        o->oTimer = 0;
        o->oMoveAngleYaw = gMarioState->faceAngle[1];
        //cur_obj_init_animation_with_accel_and_sound(1, o->oGoombaBlinkTimer);
       }
    }
    if (gMarioState->heldObj == o) {
       o->oGaloombaGrabbed = 1;
       o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
       cur_obj_become_intangible();
    }

    if (obj_update_standard_actions(1.0f)) {

        //obj_update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);
        cur_obj_update_floor_and_walls();

        //if ((animSpeed = o->oForwardVel / 0.4f) < 1.0f) {
        //    animSpeed = 1.0f;
        //}

        switch (o->oAction) {
            case BUZZY_BEET_ACT_WALK:
                buzzy_beetle_act_walk();
                break;
            case BUZZY_BEET_ACT_ATTACKED_MARIO:
                buzzy_beetle_act_attacked_mario();
                break;
            case BUZZY_BEET_ACT_WIND_UP:
                buzzy_beetle_act_wind_up();
                break;
            case BUZZY_BEET_ACT_IN_SHELL:
                buzzy_beetle_act_in_shell();
                break;
        }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->oInteractStatus & INT_STATUS_ATTACKED_MARIO && o->oAction != BUZZY_BEET_ACT_IN_SHELL) {
            if (o->oAction != BUZZY_BEET_ACT_ATTACKED_MARIO) {
                o->oAction = BUZZY_BEET_ACT_ATTACKED_MARIO;
                o->oTimer = 0;
            }
        } else {
            s32 attackType = o->oInteractStatus & INT_STATUS_ATTACK_MASK;

            switch (sBuzzyBeetleAttackHandlers[0][attackType - 1]) {
                case ATTACK_HANDLER_NOP:
                    break;

                case ATTACK_HANDLER_SQUISHED:
                    o->oAction = BUZZY_BEET_ACT_IN_SHELL;
                    o->oForwardVel = 0;
                    o->oInteractType = INTERACT_GRABBABLE;
                    o->oInteractionSubtype = INT_SUBTYPE_KICKABLE;
                    o->oFlags = o->oFlags | OBJ_FLAG_HOLDABLE;
                    o->oDamageOrCoinValue = 0;
                    break;
                case ATTACK_HANDLER_GPD_ON:
                    obj_set_squished_action();
                    break;
        }
        }
        o->oInteractStatus = 0;
    }

        cur_obj_move_standard(-50);

    } else {
        //o->oAnimState = TRUE;
    }
}
