// nipper.c.inc

struct ObjectHitbox sNipperHitbox = {
    /* interactType: */ INTERACT_BOUNCE_TOP,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 1,
    /* health: */ 0,
    /* numLootCoins: */ 3,
    /* radius: */ 230,
    /* height: */ 80,
    /* hurtboxRadius: */ 90,
    /* hurtboxHeight: */ 60,
};

u8 sNipperAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_NOP,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_NOP,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_nipper_init(void) {
    obj_set_hitbox(o, &sNipperHitbox);
}

void bhv_nipper_update(void) {
    f32 sp18;
    cur_obj_update_floor_and_walls();
    if(obj_update_standard_actions(1.0f)) {
    //if (obj_handle_attacks(&sNipperHitbox, 3, sNipperAttackHandlers))
    //    mark_obj_for_deletion(o);
        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->oInteractStatus & INT_STATUS_ATTACKED_MARIO) {
            o->oSubAction = 3;
            }
        else {
            s32 attackType = o->oInteractStatus & INT_STATUS_ATTACK_MASK;

            switch (sNipperAttackHandlers[attackType - 1]) {
                case ATTACK_HANDLER_NOP:
                    o->oInteractionSubtype = 0;
                    take_damage_and_knock_back(gMarioState, o);
                    break;

                case ATTACK_HANDLER_KNOCKBACK:
                    obj_set_knockback_action(attackType);
                    cur_obj_init_animation(1);
                    break;
        }
        }
    }
        o->oInteractStatus = 0;
    if(o->oInteractStatus & INT_STATUS_ATTACKED_MARIO) 
        o->oSubAction = 3;

    if (o->oSubAction != 1)
        o->oScuttlebugUnkF8 = 0;
    switch (o->oSubAction) {
        case 0:
            if (o->oMoveFlags & OBJ_MOVE_LANDED)
                cur_obj_play_sound_2(SOUND_OBJ_GOOMBA_ALERT);
            if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
                o->oHomeX = o->oPosX;
                o->oHomeY = o->oPosY;
                o->oHomeZ = o->oPosZ;
                o->oSubAction++;
            }
            break;
        case 1:
            o->oForwardVel = 5.0f;
            if (lateral_dist_between_objects(o, gMarioObject) > 1000.0f) {
                o->oAngleToMario = cur_obj_angle_to_home();
                cur_obj_init_animation(0);
                o->oSkeeterUnk1AC = 0;
            }
            else {
                o->oAngleToMario = obj_angle_to_object(o, gMarioObject);
                if (o->oScuttlebugUnkF8 == 0) {
                    cur_obj_init_animation(0);
                    o->oScuttlebugUnkFC = 0;
                    if (abs_angle_diff(o->oAngleToMario, o->oMoveAngleYaw) < 0x800) {
                        o->oScuttlebugUnkF8 = 1;
                        o->oVelY = 20.0f;
                        cur_obj_play_sound_2(SOUND_OBJ2_SCUTTLEBUG_ALERT);
                    }
                } else if (o->oScuttlebugUnkF8 == 1) {
                    if(o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND && (gMarioState->action == ACT_JUMP || gMarioState->action == ACT_DOUBLE_JUMP || gMarioState->action == ACT_TRIPLE_JUMP || gMarioState->action == ACT_LONG_JUMP || gMarioState->action == ACT_SIDE_FLIP || gMarioState->action == ACT_BACKFLIP) && gMarioObject->header.gfx.animInfo.animFrame < 2) {
                        o->oVelY = gMarioState->vel[1];
                        o->oSkeeterUnk1AC = 2;
                        o->oForwardVel = 0;
                        cur_obj_init_animation(1);
                        cur_obj_play_sound_2(SOUND_OBJ2_SCUTTLEBUG_ALERT);
                    }
                    else {
                        if(o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
                            o->oForwardVel = 15.0f;
                            if (o->oSkeeterUnk1AC > 0)
                                o->oSkeeterUnk1AC--;
                            else {
                                o->oSkeeterUnk1AC = 0;
                                cur_obj_init_animation(0);
                                o->oScuttlebugUnkFC++;
                            }
                        }
                    }
                    if (o->oScuttlebugUnkFC > 90) {
                        o->oScuttlebugUnkF8 = 0;
                        o->oSkeeterUnk1AC = 0;
                        cur_obj_init_animation(0);
                        o->oSubAction = 0;
                    }
                }
            }
            if (update_angle_from_move_flags(&o->oAngleToMario))
                o->oSubAction = 2;
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x200);
            break;
        case 2:
            o->oForwardVel = 5.0f;
            if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario)
                o->oSubAction = 1;
            if (o->oPosY - o->oHomeY < -200.0f)
                obj_mark_for_deletion(o);
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
            break;
        case 3:
            cur_obj_init_animation(0);
            o->oFlags &= ~8;
            o->oForwardVel = -10.0f;
            o->oVelY = 30.0f;
            cur_obj_play_sound_2(SOUND_OBJ2_SCUTTLEBUG_ALERT);
            o->oSubAction++;
            break;
        case 4:
            o->oForwardVel = -10.0f;
            if (o->oMoveFlags & OBJ_MOVE_LANDED) {
                o->oSubAction++;
                o->oVelY = 0.0f;
                o->oScuttlebugUnkFC = 0;
                o->oFlags |= 8;
                o->oInteractStatus = 0;
            }
            break;
        case 5:
            o->oForwardVel = 2.0f;
            o->oScuttlebugUnkFC++;
            if (o->oScuttlebugUnkFC > 30)
                o->oSubAction = 0;
            break;
    }
    if (o->oForwardVel < 10.0f)
        sp18 = 1.0f;
    else
        sp18 = 3.0f;
    //cur_obj_init_animation_with_accel_and_sound(0, sp18);
    if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND)
        //set_obj_anim_with_accel_and_sound(0, 23, SOUND_OBJ2_SCUTTLEBUG_WALK);
    if (o->parentObj != o) {
        if (obj_is_hidden(o))
            obj_mark_for_deletion(o);
        if (o->activeFlags == ACTIVE_FLAG_DEACTIVATED)
            o->parentObj->oScuttlebugSpawnerUnk88 = 1;
    }
    cur_obj_move_standard(-50);
    }
}
