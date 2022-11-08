static struct ObjectHitbox sEmuAmpHitbox = {
    /* interactType:      */ INTERACT_SHOCK,
    /* downOffset:        */ 40,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 0,
    /* height:            */ 0,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_attackable_amp_init(void) {
    struct Object *bowserObj;
    struct Object *doggoObj;
    vec3_copy(&o->oHomeVec, &o->oPosVec);
    o->oGravity = 0;
    o->oFriction = 1.0f;
    o->oBuoyancy = 1.0f;
    o->oHomeY = 119;
    o->oPosY = o->oHomeY;
    o->oHomingAmpAvgY = o->oHomeY;
    f32 dist;
    bowserObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &dist);
    doggoObj = cur_obj_nearest_object_with_behavior(bhvDogEmu);
    o->parentObj = bowserObj;
    o->childObj = doggoObj;
    if (o->parentObj->oHealth == 3) o->oPiranhaPlantScale = 20.0f;
    else if (o->parentObj->oHealth == 2) o->oPiranhaPlantScale = 25.0f;
    else if (o->parentObj->oHealth == 1) o->oPiranhaPlantScale = 35.0f;
    else {o->oPiranhaPlantScale = 30.0f;}
    o->oForwardVel = o->oPiranhaPlantScale;
}

void check_emu_amp_attack(void) {
    u8 marioAttack = 5;
        //obj_set_hitbox(o, &sEmuAmpHitbox);
     if (o->oDistanceToMario < 100 && o->oDistanceToMario > 0) {
         if (abs_angle_diff(o->oMoveAngleYaw, gMarioObject->oMoveAngleYaw) > 0x6000) {
            if (gMarioStates[0].action == ACT_SLIDE_KICK) {marioAttack= 1;}
           else if (gMarioStates[0].action == ACT_PUNCHING) {marioAttack= 1;}
           else if (gMarioStates[0].action == ACT_MOVE_PUNCHING) {marioAttack= 1;}
           else if (gMarioStates[0].action == ACT_SLIDE_KICK_SLIDE) {marioAttack= 1;}
           else if (gMarioStates[0].action == ACT_JUMP_KICK) {marioAttack= 1;}
           else {marioAttack = 0;}
         } else {marioAttack = 0;}
     }

     if (o->childObj->oAction == INJURED){
            o->oAction = EMU_AMP_HIT_DOG;
     }
     switch (marioAttack){
         case 0:
         o->oAction = EMU_AMP_SUCCESS;
         o->oInteractStatus = 0;
         break;
         case 1:
         o->oAction = EMU_AMP_COUNTER;
         o->oInteractStatus = 0;
         o->oPiranhaPlantScale += 5.0f;
         break;
         default: 
         if (o->oDistanceToMario <= 60){
         o->oAction = EMU_AMP_SUCCESS;
         o->oInteractStatus = 0;
         }
         else{
         o->oAction = EMU_AMP_CHASE;}
         break;
     }
}

void attackable_amp_counter(void) {
    o->oMoveAngleYaw = obj_angle_to_object(o->parentObj, o);
    obj_turn_toward_object(o, o->parentObj, 16, DEGREES(180));
    if (lateral_dist_between_objects(o, o->parentObj) < 220) {
     o->oForwardVel = 20.0f;
    if (lateral_dist_between_objects(o, o->parentObj) < 150) {o->oAction = EMU_AMP_CHASE;}
    }
 o->oInteractStatus = 0;
}


void attackable_amp_appear_loop(void) {
    // gLakituState.goalPos is the position lakitu is moving towards.
    // In Lakitu and Mario cam, it is usually very close to the current camera position.
    // In Fixed cam, it is the point behind Mario the camera will go to when transitioning
    // to Lakitu cam. Homing amps will point themselves towards this point when appearing.
    f32 relativeTargetX = o->childObj->oPosX - o->oPosX;
    f32 relativeTargetZ = o->childObj->oPosZ - o->oPosZ;
    s16 targetYaw = atan2s(relativeTargetZ, relativeTargetX);

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, targetYaw, 0x1000);
    o->oAction = EMU_AMP_CHASE;
    //o->oAmpYPhase = 0;
}


void attackable_amp_chase_loop(void) {
    if (o->oPiranhaPlantScale > 10){o->oForwardVel = o->oPiranhaPlantScale;}
    if (o->oForwardVel > 50.0f) o->oForwardVel = 50.0f;
    if (o->childObj->oAction == EMU_DOG_RANDOM_LOCATION || o->childObj->oAction == EMU_DOG_RUN_AROUND){
        o->oAction = RETURN_TO_BOWSER;
    } else {
    o->oMoveAngleYaw = atan2s(o->childObj->oPosZ - o->oPosZ, o->childObj->oPosX - o->oPosX);
    //turn towards the dog

        obj_turn_toward_object(o, o->childObj, 16, 0x400);

    // The amp's position will sinusoidally oscillate 40 units around its average Y.
    o->oPosY = o->oHomingAmpAvgY + sins(o->oAmpYPhase * 0x400) * 20.0f;

    // Handle attacks
    check_emu_amp_attack();
    }
}

void attackable_amp_success(void) {
    interact_shock(gMarioState, INTERACT_SHOCK, gCurrentObject);
    gMarioState->hurtCounter += 4;
    o->oInteractStatus = 0;
    o->oAction = EMU_AMP_CHASE;
}

void attackable_amp_hit_dog(void) {
    obj_mark_for_deletion(o);
}

void return_to_bowser(void){
 o->oMoveAngleYaw = obj_angle_to_object(o->parentObj, o);
    obj_turn_toward_object(o, o->parentObj, 16, DEGREES(180));
 o->oInteractStatus = 0;
 o->parentObj->oAction = BOWSER_ACT_PRE_ATTACK;
 if (lateral_dist_between_objects(o, o->parentObj) < 220) {
     o->oForwardVel = 20.0f;
    if (lateral_dist_between_objects(o, o->parentObj) < 150) {obj_mark_for_deletion(o);}
    }
}
void bhv_attackable_amp_loop(void) {
    switch (o->oAction) {
        case EMU_AMP_CHASE:
        attackable_amp_chase_loop();
        break;

        case EMU_AMP_SUCCESS:
        attackable_amp_success();
        break;

        case EMU_AMP_COUNTER:
        attackable_amp_counter();
        break;

        case EMU_AMP_HIT_DOG:
        attackable_amp_hit_dog();
        break;
        case RETURN_TO_BOWSER:
        return_to_bowser();
        break;
    }
    object_step();
}