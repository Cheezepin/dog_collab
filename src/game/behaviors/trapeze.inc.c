struct ObjectHitbox sTrapezeHitbox = {
    /* interactType: */ INTERACT_TRAPEZE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 200,
    /* height: */ 50,
    /* hurtboxRadius: */ 200,
    /* hurtboxHeight: */ 200,
};

void bhv_trapeze_init() {
    o->oObjTrapezeHitbox = spawn_object_relative(o->oBehParams2ndByte, 0, 0, 0, o, MODEL_NONE, bhvTrapezeHitbox);
}

void bhv_trapeze_loop() {
    if (o->oBehParams2ndByte != 1) {
    o->oTrapezeTimer += 1;
    o->oFaceAngleRoll = 0x2000*sins(o->oTrapezeTimer*0x300);
                o->oMoveAngleRoll = 0x2000*sins(o->oTrapezeTimer*0x300);
    }

}

void bhv_trapeze_hitbox_init() {
    obj_set_hitbox(o, &sTrapezeHitbox);
}
void bhv_trapeze_hitbox_loop() {

    f32 offsetXZ;
    s16 offsetAngle;

    offsetAngle = o->parentObj->oFaceAngleRoll;
    offsetXZ = 300.0f * sins(offsetAngle);

     o->oPosX = o->parentObj->oPosX + offsetXZ * coss(o->parentObj->oFaceAngleYaw);

    o->oPosY = o->parentObj->oPosY - 300.0f * coss(offsetAngle);

    o->oPosZ = o->parentObj->oPosZ + offsetXZ * -sins(o->parentObj->oFaceAngleYaw);

    if (o->oTrapezeGrabbing == 0 && gMarioState->action == ACT_TRAPEZE) {
        o->oIsLastTrapeze = 0;
    }

    if (gMarioState->action != ACT_BACKFLIP && gMarioState->action != ACT_TRAPEZE) {
        o->oIsLastTrapeze = 0;
    }

    if (o->oTrapezeGrabbing == 1 && gMarioState->action == ACT_TRAPEZE) {
        
        //print_text_fmt_int(100, 50, "%d", o->oTrapezeMomentum);
        

        if (o->oTrapezeMomentum <= 0) {
            o->oTrapezeMomentum = 0; 
        }
        if (o->oTrapezeMomentum >= 20) {
            o->oTrapezeMomentum = 20; 
        }
    //check whether to flip
        if (o->oTrapezeMomentum <= 15 && o->oTrapezeFlipTimer == 0) {
            o->oTrapezeFlip = 1;
            gMarioState->faceAngle[1] = o->parentObj->oFaceAngleYaw - 0x4000;
        }
    //flip
        if (o->oTrapezeFlip == 0) {
            if (o->oTrapezeFlipTimer == 3) {
            play_sound(SOUND_ACTION_SPIN, gMarioState->marioObj->header.gfx.cameraToObject);
            }

            o->oTrapezeFlipTimer += 1;
            gMarioState->faceAngle[0] = -0xC80 * o->oTrapezeFlipTimer+ 0x8000;
           gMarioState->faceAngle[1] = o->parentObj->oFaceAngleYaw - 0x4000;
            

            
            gMarioState->pos[0] = o->oPosX - 60*sins(o->oTrapezeFlipTimer * 0xC80) * coss(o->parentObj->oFaceAngleYaw);
        gMarioState->pos[1] = o->oPosY +20 + (-60*coss(o->oTrapezeFlipTimer * 0xC80) + 60);
        gMarioState->pos[2] = o->oPosZ - 60*sins(o->oTrapezeFlipTimer * 0xC80) * -sins(o->parentObj->oFaceAngleYaw);

        if (o->oTrapezeFlipTimer >= 20) {
            o->oTrapezeFlip = 1;
            o->oTrapezeFlipTimer = 0;
        }

        }
    //after flip
        if (o->oTrapezeFlip == 1) {

        o->oTrapezeMomentum -= 1;
        //if there is momentum, do a little swing to make the grab not look as bad
     if (o->oTrapezeMomentum > 0) {
        o->oTrapezeFlipTimer += 1;
        gMarioState->pos[0] = o->oPosX + (30*sins(o->parentObj->oTrapezeTimer*0x300) - 7*o->oTrapezeMomentum*sins(0x800*o->oTrapezeFlipTimer)) * coss(o->parentObj->oFaceAngleYaw);
        gMarioState->pos[1] = o->oPosY + 20 + o->oTrapezeMomentum*sins(0x800*o->oTrapezeFlipTimer);
        gMarioState->pos[2] = o->oPosZ + (30*sins(o->parentObj->oTrapezeTimer*0x300) - 7*o->oTrapezeMomentum*sins(0x800*o->oTrapezeFlipTimer)) * -sins(o->parentObj->oFaceAngleYaw);
    
     gMarioState->faceAngle[0] = 0x8000 + 0x2000*sins(o->parentObj->oTrapezeTimer*0x300 - 3*0x300 ) - 0x400*o->oTrapezeMomentum*sins(0x800*o->oTrapezeFlipTimer);
    }

        //hanging after momentum
    else {
         gMarioState->pos[0] = o->oPosX + 30*sins(o->parentObj->oTrapezeTimer*0x300) * coss(o->parentObj->oFaceAngleYaw);
        gMarioState->pos[1] = o->oPosY + 20;
        gMarioState->pos[2] = o->oPosZ + 30*sins(o->parentObj->oTrapezeTimer*0x300) * -sins(o->parentObj->oFaceAngleYaw);

         gMarioState->faceAngle[0] = 0x8000 + 0x2000*sins(o->parentObj->oTrapezeTimer*0x300 - 3*0x300 );
    }
        //wahoo
        if (gMarioState->input & INPUT_A_PRESSED) {
            gMarioState->action = ACT_BACKFLIP;
            gMarioState->forwardVel = -50*sins(o->parentObj->oTrapezeTimer*0x300 - 3*0x300);
            gMarioState->vel[1] = 30.0f - 60*coss(o->parentObj->oTrapezeTimer*0x300 - 3*0x300);
            o->oTrapezeFlip = 0;
            o->oTrapezeGrabbing = 0;
            o->oIsLastTrapeze = 1;
            gMarioState->faceAngle[0] = 0;
        }


        }
    }

}

void bhv_balloon_platform_loop(void) {
    if (o->oBehParams2ndByte == 0) {
    o->oBalloonPlatformOscilationTimer += 1;
    o->oPosY += 5* sins(o->oBalloonPlatformOscilationTimer * 0x200);
    }
}