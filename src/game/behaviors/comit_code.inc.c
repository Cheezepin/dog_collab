
struct ObjectHitbox sRainbowCloudHitbox = {
    /* interactType: */ INTERACT_DAMAGE,
    /* downOffset: */ 125,
    /* damageOrCoinValue: */ 1,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 25,
    /* height: */ 125,
    /* hurtboxRadius: */ 25,
    /* hurtboxHeight: */ 125,
};


void bhv_cloud_rainbow_loop(void) {
    switch (o->oAction) {
        case 0:
            o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 100.0f, 1.5f, 1.5f);
            if (o->header.gfx.scale[2] > 99.0f) {
                o->header.gfx.scale[2] = 100.0f;
                o->oAction = 1;
                o->oForwardVel = 15.0f;
            }
            break;
        case 1:
            cur_obj_move_using_fvel_and_gravity();
            if (o->oTimer > 99) {
                o->oAction = 2;
                o->oForwardVel = 30.0f;
            }
            break;
        case 2:
            cur_obj_move_using_fvel_and_gravity();
            o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 0.0f, 1.5f, 1.5f);
            if (o->header.gfx.scale[2] == 0) {
                o->activeFlags = 0;
            }
            break;
    }
}

void bhv_rainbow_cloud_init(void) {
    obj_set_hitbox(o, &sRainbowCloudHitbox);
}


void bhv_rainbow_cloud_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 25 && o->oDistanceToMario < 2500.0f) {
                o->oAction = 1;
                cur_obj_init_animation_with_sound(0);
            }
            break;
        case 1:
            if (o->header.gfx.animInfo.animFrame == 16) {
                o->oObjF4 = spawn_object(o, MODEL_CLOUD_RAINBOW, bhvCloudRainbow);
                o->oObjF4->oPosY -= 70.0f;
            } else if (cur_obj_check_if_at_animation_end()) {
                o->oAction = 0;
                cur_obj_init_animation_with_sound(1);
            }
            break;
    }
    o->oInteractStatus = 0;
}




void bhv_stretch_cloud_init(void) {  
    o->oFloatF4 = 1.0f;
}


void bhv_stretch_cloud_loop(void) {
    switch (o->oAction) {
        case 0:
            o->header.gfx.scale[0] = approach_f32_asymptotic(o->header.gfx.scale[0], 3.0f, 0.15f);
            if (o->header.gfx.scale[0] - 3.0f < -0.1f) {
                o->oTimer = 0;
            }
            if (o->oTimer > 45) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->header.gfx.scale[0] = approach_f32_asymptotic(o->header.gfx.scale[0], 1.0f, 0.15f);
            if (o->header.gfx.scale[0] - 1.0f > 0.1f) {
                o->oTimer = 0;
            }
            if (o->oTimer > 45) {
                o->oAction = 0;
            }
            break;
    }
}




void bhv_bounce_cloud_init(void) {  
    o->oFloatF4 = 1.0f;
}


void bhv_bounce_cloud_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                play_sound(SOUND_ACTION_BOUNCE_OFF_OBJECT, m->marioObj->header.gfx.cameraToObject);
                m->pos[1] = m->floorHeight + 20.0f;
                m->vel[1] = 80.0f;
                m->flags & MARIO_UNKNOWN_08;
                reset_mario_pitch(m);
                play_sound(SOUND_MARIO_TWIRL_BOUNCE, m->marioObj->header.gfx.cameraToObject);
                drop_and_set_mario_action(m, ACT_TWIRLING, 0);
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFloatF4 -= 0.15f;
            o->header.gfx.scale[1] = o->oFloatF4;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.1f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 <= 0.6f) {
                o->oFloatF4 = 0.6f;
                o->oAction = 2;
            }
            break;
        case 2:
            o->oFloatF4 += 0.18f;
            o->header.gfx.scale[1] = o->oFloatF4;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 0.8f, 0.07f, 0.07f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 >= 1.4f) {
                o->oFloatF4 = 1.4f;
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFloatF4 -= 0.08f;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.0f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 <= 1.0f) {
                o->header.gfx.scale[0] = (o->header.gfx.scale[2] = 1.0f);
                o->oFloatF4 = 1.0f;
                o->oAction = 0;
            }
            o->header.gfx.scale[1] = o->oFloatF4;
            break;
    }
}