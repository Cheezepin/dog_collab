static struct ObjectHitbox sEmuBombHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 40,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 65,
    /* height:            */ 113,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_emu_bomb_init(void) {
    o->oGravity  = 2.5f;
    o->oFriction = 0.8f;
    o->oBuoyancy = 1.3f;
    o->oInteractionSubtype = INT_SUBTYPE_KICKABLE;
}

void emu_bomb_spawn_coin(void) {
    if (((o->oBehParams >> 8) & 0x1) == 0) {
        obj_spawn_yellow_coins(o, 1);
        o->oBehParams = 0x100;
        set_object_respawn_info_bits(o, RESPAWN_INFO_TYPE_32);
    }
}

void emu_bomb_act_explode(void) {
   spawn_object(o, MODEL_BOWSER_FLAMES, bhvBowserBombExplosion);
        create_sound_spawner(SOUND_GENERAL_BOWSER_BOMB_EXPLOSION);
        set_camera_shake_from_point(SHAKE_POS_LARGE, o->oPosX, o->oPosY, o->oPosZ);
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
}

void emu_bomb_check_interactions(void) {
    obj_set_hitbox(o, &sEmuBombHitbox);
    if ((o->oInteractStatus & INT_STATUS_INTERACTED) != 0)
    {
        if ((o->oInteractStatus & INT_STATUS_MARIO_KNOCKBACK_DMG) != 0)
        {
            o->oMoveAngleYaw = gMarioObject->header.gfx.angle[1];
            o->oForwardVel   = 25.0f;
            o->oVelY         = 30.0f;
            o->oAction       = EMU_BOMB_ACT_LAUNCHED;
        }

        if ((o->oInteractStatus & INT_STATUS_TOUCHED_BOB_OMB) != 0 && o->oBehParams2ndByte != 0x30)
            o->oAction = EMU_BOMB_ACT_EXPLODE;

        o->oInteractStatus = 0;
    }

    if (obj_attack_collided_from_other_object(o) == 1 && o->oBehParams2ndByte != 0x30)
        o->oAction = EMU_BOMB_ACT_EXPLODE;
}

void emu_bomb_act_patrol(void) {
    s16 collisionFlags;

    o->oForwardVel = 5.0f;

    collisionFlags = object_step();
    if ((obj_return_home_if_safe(o, o->oHomeX, o->oHomeY, o->oHomeZ, 400) == 1)
        && (obj_check_if_facing_toward_angle(o->oMoveAngleYaw, o->oAngleToMario, 0x2000) == TRUE)) {
        o->oBobombFuseLit = 1;
        o->oAction = EMU_BOMB_ACT_CHASE_MARIO;
    }
    obj_check_floor_death(collisionFlags, sObjFloor);
}

void emu_bomb_act_chase_mario(void) {
    s16 animFrame, collisionFlags;

    animFrame = ++o->header.gfx.animInfo.animFrame;
    o->oForwardVel = 20.0f;

    collisionFlags = object_step();

    if (animFrame == 5 || animFrame == 16)
        cur_obj_play_sound_2(SOUND_OBJ_BOBOMB_WALK);

    obj_turn_toward_object(o, gMarioObject, 16, 0x800);
    obj_check_floor_death(collisionFlags, sObjFloor);
}

void emu_bomb_act_launched(void) {
    s16 collisionFlags = object_step();
    if ((collisionFlags & OBJ_COL_FLAG_GROUNDED) == OBJ_COL_FLAG_GROUNDED)
        o->oAction = EMU_BOMB_ACT_EXPLODE; /* bit 0 */
}

void emu_bomb_free_loop(void) {
    switch (o->oAction) {
        case EMU_BOMB_ACT_LAUNCHED:
            emu_bomb_act_launched();
            break;

        case EMU_BOMB_ACT_EXPLODE:
            emu_bomb_act_explode();
            break;

        case OBJ_ACT_LAVA_DEATH:
            //if (obj_lava_death() == 1)
                //create_respawner(MODEL_BLACK_emu_bomb, bhvemu_bomb, 3000);

        case OBJ_ACT_DEATH_PLANE_DEATH:
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            //create_respawner(MODEL_BLACK_emu_bomb, bhvemu_bomb, 3000);
            break;
    }

    emu_bomb_check_interactions();

}

void emu_bomb_held_loop(void) {
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    cur_obj_init_animation(1);
    cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 100.0f);
}

void emu_bomb_dropped_loop(void) {
    cur_obj_get_dropped();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    cur_obj_init_animation(0);

    o->oHeldState = 0;
    o->oAction = EMU_BOMB_ACT_PATROL;
}

void emu_bomb_thrown_loop(void) {
    cur_obj_enable_rendering_2();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState  = 0;
    o->oFlags     &= ~OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW; /* bit 3 */
    o->oForwardVel = 25.0f;
    o->oVelY       = 20.0f;
    o->oAction     = EMU_BOMB_ACT_LAUNCHED;
}

void bhv_emu_bomb_loop(void) {
    
if (o->oInteractStatus & INT_STATUS_HIT_MINE)
    {
        spawn_object(o, MODEL_BOWSER_FLAMES, bhvBowserBombExplosion);
        create_sound_spawner(SOUND_GENERAL_BOWSER_BOMB_EXPLOSION);
        set_camera_shake_from_point(SHAKE_POS_LARGE, o->oPosX, o->oPosY, o->oPosZ);
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    set_object_visibility(o, 7000);
    
    if (is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 4000) != 0) {
        switch (o->oHeldState) {
            case HELD_FREE:
                emu_bomb_free_loop();
                break;

            case HELD_HELD:
                emu_bomb_held_loop();
                break;

            case HELD_THROWN:
                emu_bomb_thrown_loop();
                break;

            case HELD_DROPPED:
                emu_bomb_thrown_loop();
                break;
        }

        
    }
}