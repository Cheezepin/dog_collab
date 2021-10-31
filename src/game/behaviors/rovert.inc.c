//hey sussy baka >:3

void bhv_Magma_Thwomp() {
    if (o->oTimer > 120) {
        o->oTimer = 0;
        }

    if (o->oTimer == o->oBehParams2ndByte*20) {
        o->oVelY = 60;
        o->oSubAction = 1;
        cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
        }

    o->oVelY -= 2;
    o->oPosY += o->oVelY;

    if (o->oPosY < o->oHomeY) {
        if (o->oSubAction) {
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
            o->oSubAction = 0;
            }
        o->oPosY = o->oHomeY;
        o->oVelY = 0;
        }
    }

void bhv_swing_Board (void) {
        if (o->oAction == 0) {
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                o->oTimer = 0;
                play_sound(SOUND_GENERAL_OPEN_CHEST, o->header.gfx.cameraToObject);
                }
            }
        if (o->oAction == 1) {
            o->oFaceAngleRoll += o->oMoveAngleRoll;
            if (o->oFaceAngleRoll > 0x4000) {
                o->oMoveAngleRoll -= 0x50;
                }
                else
                {
                o->oMoveAngleRoll += 0x50;
                }

            if (o->oTimer < 120) {
                o->oMoveAngleRoll *= .98;
                }

            }
        if (o->oDistanceToMario > 5000.0f) {
            o->oAction = 0;
            o->oMoveAngleRoll = 0;;
            o->oFaceAngleRoll = 0;
            }
    }

void bhv_Propane_Shooter(void) {
    struct Object *obj;

    if (o->oBehParams2ndByte == 1) {
        o->oFaceAngleYaw += 0x400;
        }
        else
        {
        o->oFaceAngleYaw -= 0x400;
        }
    if (o->oDistanceToMario < 1500.0f) {
        cur_obj_play_sound_1(SOUND_AIR_BLOW_FIRE);
        if (o->oTimer%3) {
            obj = spawn_object(o,MODEL_BLUE_FLAME,bhvPropane);
            obj->oMoveAngleYaw = o->oFaceAngleYaw;
            obj->oPosY += 90.0f;
            obj = spawn_object(o,MODEL_BLUE_FLAME,bhvPropane);
            obj->oMoveAngleYaw = o->oFaceAngleYaw+0x7FFF;
            obj->oPosY += 90.0f;
            }
        }
    }

void bhv_Propane_Flame(void) {
    obj_scale(o,3.0f-(o->oTimer * .15));
    o->oPosX += sins(o->oMoveAngleYaw) * 50.0f;
    o->oPosZ += coss(o->oMoveAngleYaw) * 50.0f;
    if (o->oTimer > 15) {
        obj_mark_for_deletion(o);
        }
    }

void bhv_lava_grate_loop(void) {
    if (o->oBehParams2ndByte == 0) {
        o->oPosY += o->oVelY;

        if (gMarioObject->platform == o) {
            if (o->oVelY > -50.0f) {
                o->oVelY -= .25;
                }
            }
            else
            {
            if (o->oVelY < 50.0f) {
                o->oVelY += .5;
                }
            }

        if (o->oVelY > (o->oHomeY - o->oPosY)*.1) {
            o->oVelY = (o->oHomeY - o->oPosY)*.1;
            }
        if (o->oPosY > o->oHomeY) {
            o->oPosY = o->oHomeY;
            o->oVelY = 0;
            }
        }
    }