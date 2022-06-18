void bhv_cheezeplat_loop(void) {
    if(cur_obj_is_mario_on_platform()) {
        o->oAction = 1;
    } else if(dist_between_objects(gMarioObject, o) > 1500.0f) {
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
        o->oAction = 0;
    }
    if(o->oAction == 1) {
        if(o->oPlatformSpeed < 80.0f && o->oPosY < 500.0f) {
            o->oPlatformSpeed += 1.0f;
        }
        else if(o->oPlatformSpeed > 0.0f && o->oPosY > 500.0f) {
             o->oPlatformSpeed -= 2.0f;
             if(o->oPlatformSpeed <= 0.0f) {
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                cur_obj_play_sound_2(SOUND_GENERAL_METAL_POUND);
             }
        }
        
        o->oVelZ = -o->oPlatformSpeed;
        o->oVelY = o->oPlatformSpeed;
        o->oPosY += o->oVelY;
        o->oPosZ += o->oVelZ;
        if(o->oPlatformSpeed > 0.0f) {
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
        }
    }
}

void explode(s16 dontDeactivate) {
    struct Object *explosion;
    explosion = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
    explosion->oGraphYOffset += 100.0f;
    if(dontDeactivate == 0)
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
}

struct CollisionData *bombwallCols[2] = {
    &cheezebombwall_collision,
    &cheeze_bombwall2_collision
};

void bhv_cheezebombwall_loop(void) {
    f32 dist;
    if(o->collisionData == 0) {
        o->collisionData = segmented_to_virtual(bombwallCols[o->oBehParams2ndByte]);
    }
    if(lateral_dist_between_objects(o, cur_obj_find_nearest_object_with_behavior(bhvCheezeDog, &dist)) < 75.0f) {
        explode(0);
    }
    load_object_collision_model();
    o->oInteractStatus = 0;
}

static struct ObjectHitbox sKoopatrolHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ -1,
    /* radius:            */ 60,
    /* height:            */ 150,
    /* hurtboxRadius:     */ 40,
    /* hurtboxHeight:     */ 130,
};


static u8 sKoopatrolUnshelledAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_koopatrol_init(void) {
    obj_set_hitbox(o, &sKoopatrolHitbox);
    o->oKoopatrolCooldown = 0;
}

struct Surface *surf;
Vec3f dir;
Vec3f hitpos;
Vec3f pos;
f32 koopatrolViewRange = 2000.0f;

s32 check_if_mario_is_seen(void) {
    s32 searchAngle = o->oAngleToMario - o->oMoveAngleYaw;
    f32 distFromHit;
    f32 rayDist;
    
    while(searchAngle >= 0x10000) {searchAngle -= 0x10000;}
    while(searchAngle < 0x0) {searchAngle += 0x10000;}

    if(o->oKoopatrolCooldown > 0) {
        o->oKoopatrolCooldown--;
        return FALSE;
    }
    //print_text_fmt_int(220, 20, "0x%x", searchAngle);

    vec3f_set(pos, o->oPosX, o->oPosY + 150.0f, o->oPosZ);
    if(o->oDistanceToMario < koopatrolViewRange) {
        rayDist = o->oDistanceToMario;
    } else {
        rayDist = koopatrolViewRange;
    }
    vec3f_set(dir, sins(o->oAngleToMario)*rayDist, 0, coss(o->oAngleToMario)*rayDist);
    vec3f_set(hitpos, 0, 0, 0);
    find_surface_on_ray(pos, dir, &surf, hitpos, RAYCAST_FIND_FLOOR | RAYCAST_FIND_CEIL | RAYCAST_FIND_WALL);
    //print_text_fmt_int(180, 40, "%d", (s32)hitpos[0]);
    //print_text_fmt_int(250, 40, "%d", (s32)hitpos[2]);
    distFromHit = sqrtf(POW2(o->oPosX - hitpos[0]) + POW2(o->oPosZ - hitpos[2]));
    //print_text_fmt_int(180, 80, "%d", (s32)rayDist);
    //print_text_fmt_int(180, 60, "%d", (s32)distFromHit);
    if((searchAngle < 0x3800 || searchAngle > 0x0000C800) && o->oDistanceToMario < koopatrolViewRange && absf(gMarioState->pos[1] + 150.0f - o->oPosY) <= o->oDistanceToMario && distFromHit >= rayDist - 1.0f) {
        return TRUE;
    }
    return FALSE;
}

void bhv_koopatrol_loop(void) {
    f32 koopatrolRange = 100.0f;
    f32 rayDist;
    f32 distFromHit;
    s32 angle;
    f32 x = 99999.9f;
    f32 z = 99999.9f;
    struct Surface *floor = 0;
    s32 searchAngle = o->oAngleToMario - o->oMoveAngleYaw;
    while(searchAngle >= 0x10000) {searchAngle -= 0x10000;}
    while(searchAngle < 0x0) {searchAngle += 0x10000;}

    if ((o->oRoom != -1 && gMarioCurrentRoom != o->oRoom) || (o->activeFlags & ACTIVE_FLAG_FAR_AWAY)) {
        o->oAction = 4;
    }

    switch(o->oAction) {
        case 0:
            x = 99999.9f;
            z = 99999.9f;
            floor = 0;
            while(sqrtf(POW2(x) + POW2(z)) > koopatrolRange || floor == 0) {
                x = (random_float() - 0.5f)*koopatrolRange*2;
                z = (random_float() - 0.5f)*koopatrolRange*2;
                find_floor(o->oHomeX + x, o->oHomeY, o->oHomeZ + z, &floor);
            }

            o->oKoopatrolTargetX = o->oHomeX + x;
            o->oKoopatrolTargetZ = o->oHomeZ + z;
            o->oAction = 1;
            o->oForwardVel = 0.0f;
            break;
        case 1:
            angle = atan2s((o->oKoopatrolTargetZ - o->oPosZ), (o->oKoopatrolTargetX - o->oPosX));
            o->oForwardVel = 20.0f;
            cur_obj_init_animation_with_accel_and_sound(1, 2.1f);
            koopa_play_footstep_sound(1, 21);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, angle, 0x400);
            if(o->oMoveAngleYaw == angle) {
                o->oForwardVel = 20.0f;
            } else {
                o->oForwardVel = 0.0f;
            }
            if(sqrtf(POW2(o->oKoopatrolTargetZ - o->oPosZ) + POW2(o->oKoopatrolTargetX - o->oPosX)) < 25.0f || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oTimer > 150) {
                o->oAction = 2;
            }
            if(check_if_mario_is_seen()) {
                o->oAction = 3;
                cur_obj_play_sound_2(SOUND_OBJ_KOOPA_TALK);
            }
            break;
        case 2:
            cur_obj_init_animation_with_accel_and_sound(1, 1.0f);
            if(o->oTimer > 150) {
                if((random_u16() % 10 == 0)) {
                    o->oAction = 0;
                }
            }
            //o->oMoveAngleYaw += 0x100;
            o->oForwardVel = 5.0f;
            if(check_if_mario_is_seen()) {
                o->oAction = 3;
                cur_obj_play_sound_2(SOUND_OBJ_KOOPA_TALK);
            }
            break;
        case 3:
            cur_obj_init_animation_with_accel_and_sound(2, 3.0f);
            koopa_play_footstep_sound(1, 21);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x200);
            o->oForwardVel = 52.0f;
            vec3f_set(pos, o->oPosX, o->oPosY + 150.0f, o->oPosZ);
            vec3f_set(pos, o->oPosX, o->oPosY + 150.0f, o->oPosZ);
            if(o->oDistanceToMario < koopatrolViewRange) {
                rayDist = o->oDistanceToMario;
            } else {
                rayDist = koopatrolViewRange;
            }
            vec3f_set(dir, sins(o->oAngleToMario)*rayDist, 0, coss(o->oAngleToMario)*rayDist);
            vec3f_set(hitpos, 0, 0, 0);
            find_surface_on_ray(pos, dir, &surf, hitpos, RAYCAST_FIND_FLOOR | RAYCAST_FIND_CEIL | RAYCAST_FIND_WALL);
            distFromHit = sqrtf(POW2(o->oPosX - hitpos[0]) + POW2(o->oPosZ - hitpos[2]));
            if(o->oTimer > 60 && (o->oDistanceToMario > koopatrolViewRange || distFromHit < rayDist - 1.0f)) {
                o->oAction = 2;
                o->oKoopatrolCooldown = 75;
            }
            break;
        case 4:
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
            if(gMarioCurrentRoom == o->oRoom || !(o->activeFlags & ACTIVE_FLAG_FAR_AWAY)) {
                o->oAction = 0;
            }
            break;
    }
    cur_obj_move_standard(78);
    cur_obj_update_floor_and_walls();
    if (gCurrentObject->oMoveFlags & OBJ_MOVE_HIT_WALL) {
        gCurrentObject->oMoveAngleYaw = 0x8000 + gCurrentObject->oWallAngle * 2 - gCurrentObject->oMoveAngleYaw;
    }
    mtxf_align_terrain_triangle(gCurrentObject->transform, &gCurrentObject->oPosX, gCurrentObject->oMoveAngleYaw, 60.f);
}
