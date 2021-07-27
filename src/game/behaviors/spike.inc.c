static struct ObjectHitbox sSpikeHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 10,
    /* numLootCoins:      */ 0,
    /* radius:            */ 53,
    /* height:            */ 168,
    /* hurtboxRadius:     */ 53,
    /* hurtboxHeight:     */ 168,
};

static struct ObjectHitbox sSpikeBallHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 27,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 53,
    /* height:            */ 150,
    /* hurtboxRadius:     */ 53,
    /* hurtboxHeight:     */ 150,
};

void bhv_spike_init(void) {
    cur_obj_init_animation(0);

    //cur_obj_set_room();

    o->oGravity = 4.0;
    o->oFriction = 0.5;
    o->oBuoyancy = 1.3;

    o->oMaxShotDelay = 90;
    o->oShotDelay = o->oMaxShotDelay;
    o->oShotSpeed = 20;

    obj_set_hitbox(o, &sSpikeHitbox);

    o->oIntangibleTimer = 0;
}

void bhv_spike_update(void) {
    u8 enabled = 1; //cur_obj_room_enable(MODEL_SPIKE);

    o->oInteractStatus = 0;

    if (enabled > 0)
    {
        f32 hit;
        if (enabled == 2)
        {
            o->oShotDelay = o->oMaxShotDelay;
        }

        // hit = cur_obj_check_hit(FALSE, 0xFFFF, 0);
        // if (hit > 0)
        // {
        //     if (!cur_obj_check_dead(hit, TRUE))
        //     {
        //         cur_obj_set_model(MODEL_NONE);
        //     }
        //     else
        //     {
        //         if (o->prevObj != NULL)
        //         {
        //             obj_mark_for_deletion(o->prevObj);
        //         }
        //     }
        // }

            if (o->oShotDelay == 0)
            {
                if (o->oAnimState == 0)
                {
                    cur_obj_init_animation(1);
                    o->oAnimState = 1;
                }
                if (o->oAnimState == 1)
                {
                    if (cur_obj_check_anim_frame(15))
                    {
                        o->prevObj = spawn_object_abs_with_rot(o, 0, MODEL_SPIKE_BALL, bhvSpikeBall, 0, 0, 0, 0, o->oMoveAngleYaw, 0);
                        o->prevObj->oPosX = o->oPosX;
                        o->prevObj->oPosY = o->oPosY + 100;
                        o->prevObj->oPosZ = o->oPosZ;

                        o->prevObj->oHomeX = o->oHomeX;
                        o->prevObj->oHomeZ = o->oHomeZ;

                        o->prevObj->oGravity = 0;
                    }
                    else if (cur_obj_check_anim_frame_in_range(16, 4))
                    {
                        o->prevObj->oPosY += 20;
                    }
                    else if (cur_obj_check_anim_frame(20))
                    {
                        o->prevObj->oPosY = o->oPosY + 200;
                    }
                    else if (o->header.gfx.animInfo.animFrame > 20)
                    {
                        f32 progress = ((40 - (f32)o->header.gfx.animInfo.animFrame) / 20);
                        f32 forwardPos = 106.38 + progress * -106.38;
                        o->prevObj->oPosX = o->oPosX + forwardPos * sins(o->oMoveAngleYaw);
                        o->prevObj->oPosZ = o->oPosZ + forwardPos * coss(o->oMoveAngleYaw);
                        o->prevObj->oPosY = o->oPosY + (progress * 200);
                        if (o->prevObj->oPosY < o->oPosY + 53.19)
                        {
                            o->prevObj->oPosY = o->oPosY + 53.19;
                        }
                    }
                    if (cur_obj_check_if_near_animation_end())
                    {
                        o->prevObj->oPosY = o->oPosY + 53.19;

                        o->prevObj->oForwardVel = o->oShotSpeed;

                        o->prevObj->oAnimState = 1;

                        o->prevObj->oGravity = -2.0f;

                        o->prevObj = NULL;

                        o->oShotDelay = o->oMaxShotDelay;
                        cur_obj_init_animation(0);
                        o->oAnimState = 0;
                    }
                }
            }
            else
            {
                o->oShotDelay--;
                cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x180);
            }

            //object_step();
            //cur_obj_move_using_vel();
    }

        obj_resolve_object_collisions(NULL);
}

void bhv_spike_ball_init(void) {
    obj_set_hitbox(o, &sSpikeBallHitbox);
    o->oFriction = 0.5;
    o->oGraphYOffset = 40.0f;
}

void bhv_spike_ball_loop(void)
{
    if (o->oAnimState == 1)
    {
        f32 maxDist = 532.0f;

        cur_obj_update_floor_height();
        cur_obj_move_standard(-78);

        if (o->oTimer > 120)
        {
            obj_mark_for_deletion(o);
        }
    }
}