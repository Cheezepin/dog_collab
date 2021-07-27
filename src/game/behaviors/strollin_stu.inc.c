static struct ObjectHitbox sStrollinStuHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};
    
void bhv_strollin_stu_init(void) {
    if(o->oBehParams2ndByte != 0) {
        if(o->parentObj != 0 && (o->oBehParams & 0x00000001)) {
            o->prevObj = spawn_object(o->parentObj, MODEL_STROLLIN_STU, bhvStrollinStu);
        } else {
            o->prevObj = spawn_object(o, MODEL_STROLLIN_STU, bhvStrollinStu);
            o->parentObj = 0;
        }
        o->prevObj->parentObj = o;
        if(o->oBehParams & 0x01000000) {
            o->prevObj->oPosY = o->oPosY + 70.0f;
            o->prevObj->oBehParams |= 0x01000001;
        } else {
            o->prevObj->oPosX = -150.0f*sins(o->oMoveAngleYaw) + o->oPosX;
            o->prevObj->oPosZ = -150.0f*coss(o->oMoveAngleYaw) + o->oPosZ;
            o->prevObj->oBehParams |= 0x00000001;
        }
        o->prevObj->oMoveAngleYaw = o->oMoveAngleYaw;
        o->prevObj->oBehParams2ndByte = o->oBehParams2ndByte - 1;
    }

    obj_set_hitbox(o, &sStrollinStuHitbox);

    o->oDrawingDistance = 6000;
    o->oDamageOrCoinValue = 1;

    o->oGravity = -8.0f / 3.0f;

    o->oGoombaScale = 1.0f;
}

void bhv_strollin_stu_update(void) {
    f32 animSpeed;
    if(o->parentObj == 0) {
        o->parentObj = 0;
        if (obj_update_standard_actions(1.0f)) {
            cur_obj_scale(1.0f);
            obj_update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);
            cur_obj_update_floor_and_walls();

            if ((animSpeed = o->oForwardVel * 0.4f) < 1.0f) {
                animSpeed = 1.0f;
            }
            cur_obj_init_animation_with_accel_and_sound(0, animSpeed);

            switch (o->oAction) {
                case GOOMBA_ACT_WALK:
                    goomba_act_walk();
                    break;
                case GOOMBA_ACT_ATTACKED_MARIO:
                    goomba_act_attacked_mario();
                    break;
                case GOOMBA_ACT_JUMP:
                    goomba_act_jump();
                    break;
            }

            //! @bug Weak attacks on huge goombas in a triplet mark them as dead even if they're not.
            // obj_handle_attacks returns the type of the attack, which is non-zero
            // even for Mario's weak attacks. Thus, if Mario weakly attacks a huge goomba
            // without harming it (e.g. by punching it), the goomba will be marked as dead
            // and will not respawn if Mario leaves and re-enters the spawner's radius
            // even though the goomba isn't actually dead.

            // if (obj_handle_attacks(&sGoombaHitbox, GOOMBA_ACT_ATTACKED_MARIO,
            //                     sGoombaAttackHandlers[0])) {
            //     mark_goomba_as_dead();
            // }

            obj_handle_attacks(&sStrollinStuHitbox, GOOMBA_ACT_ATTACKED_MARIO,
                                sGoombaAttackHandlers[0]);

            cur_obj_move_standard(-78);
        } else {
            o->oAnimState = TRUE;
        }
    } else {
        if(o->oBehParams & 0x01000000) {
            obj_update_standard_actions(1.0f);
            obj_update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);

            if ((animSpeed = o->oForwardVel * 0.4f) < 1.0f) {
                animSpeed = 1.0f;
            }

            cur_obj_init_animation_with_accel_and_sound(0, animSpeed);

            o->oForwardVel = o->parentObj->oForwardVel;
            o->oPosX = o->parentObj->oPosX;
            o->oPosY = o->parentObj->oPosY + 70.0f;
            o->oPosZ = o->parentObj->oPosZ;
            o->oMoveAngleYaw = o->parentObj->oMoveAngleYaw;
            obj_handle_attacks(&sStrollinStuHitbox, GOOMBA_ACT_ATTACKED_MARIO,
                                    sGoombaAttackHandlers[0]);

            if(o->parentObj->activeFlags == ACTIVE_FLAG_DEACTIVATED || o->parentObj->behavior != segmented_to_virtual(bhvStrollinStu)) {
                o->parentObj = 0;
            }
        } else {
            f32 distToParent = lateral_dist_between_objects(o, o->parentObj);
            obj_update_standard_actions(1.0f);
            //cur_obj_scale(1.0f);
            obj_update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);
            cur_obj_update_floor_and_walls();

            if ((animSpeed = o->oForwardVel * 0.4f) < 1.0f) {
                animSpeed = 1.0f;
            }

            cur_obj_init_animation_with_accel_and_sound(0, animSpeed);

            o->oForwardVel = o->parentObj->oForwardVel;
            if(distToParent > 154.0f) {
                o->oForwardVel += 4.0f;
            }
            if(distToParent < 146.0f) {
                o->oForwardVel -= 4.0f;
            }
            cur_obj_rotate_yaw_toward(obj_angle_to_object(o, o->parentObj), 0x400);
            obj_handle_attacks(&sStrollinStuHitbox, GOOMBA_ACT_ATTACKED_MARIO,
                                    sGoombaAttackHandlers[0]);

            cur_obj_move_standard(-78);

            if(o->parentObj->activeFlags == ACTIVE_FLAG_DEACTIVATED || o->parentObj->behavior != segmented_to_virtual(bhvStrollinStu)) {
                o->parentObj = 0;
            }
        }
    }
}