/********************************************************
 * ******************************************************
 * ****************GODDARD CAGE**************************
 * ***************SIMILAR TO BOWSER BOMB*****************
 ********************************************************
 * ******************************************************/


// bhv_bowser_bomb_loop but it only cares about bowser and doesn't explode if mario hits it

void bhv_goddard_cage_loop(void) {
    
    if (o->oInteractStatus & INT_STATUS_HIT_MINE)
    {
       spawn_mist_particles_variable(0, 0, 46.0f);
        spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, 4);
        create_sound_spawner(SOUND_GENERAL_BOWSER_BOMB_EXPLOSION);
        set_camera_shake_from_point(SHAKE_POS_LARGE, o->oPosX, o->oPosY, o->oPosZ);

        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    set_object_visibility(o, 7000);
}

void bhv_goddard_cageCOL_loop(void) {
    f32 dist;
    if (cur_obj_find_nearest_object_with_behavior(bhvGoddardCage, &dist) == NULL){

        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}


struct Object *mario_find_nearest_object_with_behavior(const BehaviorScript *behavior) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj != gMarioObject) {
                f32 objDist = dist_between_objects(gMarioObject, obj);
                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }

    //*dist = minDist;
    return closestObj;
}

#define DOG_ANIM_IDLE 0
#define DOG_ANIM_DIG  1
#define DOG_ANIM_RUN  2
#define DOG_ANIM_WALK 3
#define DOG_ANIM_POUNCE 4
#define DOG_ANIM_KNOCKBACK 5
s32 nextX, nextZ, nextXangle, nextZangle;
u8 dogHealth = 3;

void rand_polar_coord(void){
    f32 theta;
    u16 r;
    theta = random_float() * 2 * M_PI;
    r = (random_u16() % 3500) + (random_u16() % 3500);
    if (r >=3500) {r = 7000-r;}
    if (r < 2000) {r = 3500 - r;}
    theta = radians_to_angle(theta);
    nextX = ((r * cosf(theta))); 
    nextZ = ((r * sinf(theta)));
    nextXangle = nextX - o->oPosX;
    nextZangle = nextZ - o->oPosZ;
}


extern u8 floor_check = 0;
void freedom (void) {
    if(floor_check == 0) {
    cur_obj_init_animation(DOG_ANIM_POUNCE);
    o->oForwardVel = 10.0f;
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(78);
    o->oVelY = -10.0f;
    if(o->oVelY < -64.0f) {o->oVelY = -64.0f;}
    if(o->oPosY - o->oFloorHeight >= -20.0f && o->oPosY - o->oFloorHeight < 5.0f) {
        cur_obj_init_animation(DOG_ANIM_WALK);
        o->oVelY = 0.0f;
        floor_check=1;
    }
    }
    else if (floor_check >= 60){ 
        cur_obj_init_animation(DOG_ANIM_IDLE);
        o->oForwardVel = 0.0f;
        o->oAction = EMU_DOG_RANDOM_LOCATION;
        floor_check = 0;
    }
    else {
        floor_check++;
    }
}

void find_random_location(void) {
    f32 dist;
    f32 randCords;
    s16 turnSpeed = 0x100;
    rand_polar_coord();
    o->oMoveAngleYaw = atan2s(nextZangle, nextXangle);
    o->oForwardVel = 20.0f;
    o->oAction = EMU_DOG_RUN_AROUND;
    
}

void set_ashpile_target(void) {
    struct Object *ashpileNearMario;
    ashpileNearMario = mario_find_nearest_object_with_behavior(bhvAshpileEmu); //should find the nearest ashpile to mario
    o->childObj = ashpileNearMario;
    nextX = o->childObj->oPosX - o->oPosX;
    nextZ = o->childObj->oPosZ - o->oPosZ;
    o->oMoveAngleYaw = atan2s(nextZ, nextX);
    o->oForwardVel = 200.0f;
    o->oAction = GOTO_ASHPILE;
}

void goto_ashpile(void) {}
void run_around(void) {
    cur_obj_init_animation(DOG_ANIM_RUN);
    //print_text_fmt_int(5, 20, "X %d", nextX);
    //print_text_fmt_int(5, 40, "Z %d", nextZ);
    if (nextX > o->oPosX - 10.0f && nextX < o->oPosX + 10.0f && nextZ > o->oPosZ - 10.0f && nextZ < o->oPosZ + 10.0f){
        o->oAction = EMU_DOG_RANDOM_LOCATION;
    }
}

void dig(void){
   cur_obj_init_animation(DOG_ANIM_DIG);
   o->oForwardVel = 0.0f;
}

void null_action(void){}

UNUSED static void (*sEmuDogActions[])(void) = {
    freedom,
    find_random_location,
    run_around,
};

void bhv_idle_dog_init (void) {
    struct Object *bowser;
    bowser = cur_obj_nearest_object_with_behavior(bhvBowser);
    o->prevObj = bowser;
   cur_obj_init_animation(DOG_ANIM_IDLE);
   o->oPosY -= 147;
   o->oFaceAngleYaw += DEGREES(180);
   if (dogHealth > 2) {dogHealth = 2;}
}
s32 initPosX, targetPosX, initPosZ, targetDist;
void injured (void) {
    o->oTimer++;
    cur_obj_init_animation_and_extend_if_at_end(DOG_ANIM_KNOCKBACK);
    targetDist+=2;
    o->oPosY = (-targetDist)*(targetDist-95) + 95;
    o->oPosY /= 5;
    mark_obj_for_deletion(o->parentObj); //deletes the amp
    o->parentObj->oCameraLakituBlinkTimer--;
    o->childObj->oAction = 1; //resets the ashpile
    if (dogHealth <= 0){
        gMarioState->health = 0x00FF;
        gMarioState->hurtCounter = 0;
        spawn_object(gMarioObject, MODEL_NONE, bhvExplosion);
        level_trigger_warp(gMarioState, WARP_OP_DEATH);
        // woosh, he's gone!
        set_mario_action(gMarioState, ACT_DISAPPEARED, 0);
    }
    if (targetDist >= 95){
        dogHealth--;
        o->oPosY = 95;
        o->oAction = EMU_DOG_RANDOM_LOCATION;
    }
}
void bhv_idle_dog_loop (void) {
    if (cur_obj_nearest_object_with_behavior(bhvGoddardCage) == NULL){
        print_text_fmt_int(0, 0, "Dog Health = %d", dogHealth);
        //print_text_fmt_int(0, 50, "action = %d", o->oAction);
        //print_text_fmt_int(0, 100, "X %d", o->oPosX);
        //print_text_fmt_int(0, 200, "Y %d", o->oPosY);
        struct Object *amp;
        if (o->oAction == DIG && cur_obj_nearest_object_with_behavior(bhvAttackableAmp) != NULL){
            amp = cur_obj_nearest_object_with_behavior(bhvAttackableAmp);
            o->parentObj = amp;
            if (dist_between_objects(o, o->parentObj) < 51 && o->oAction != INJURED){
                o->oHomeX = 0;
                o->oHomeY = 95;
                o->oHomeZ = 0;
                initPosX = o->oPosX;
                initPosZ = o->oPosZ;
                targetDist = 0;
                o->oMoveAngleYaw = atan2s(o->oHomeZ, o->oHomeX);
                o->oAction = INJURED;
                o->oForwardVel = 20;
                o->oTimer = 0;
            }
        }
        switch(o->oAction){
            case EMU_DOG_FREEDOM:
            freedom();
            break;
            case EMU_DOG_RANDOM_LOCATION:
            find_random_location();
            break;
            case EMU_DOG_RUN_AROUND:
            run_around();
            break;
            case SET_ASHPILE_TARGET:
            set_ashpile_target();
            break;
            case GOTO_ASHPILE:
            goto_ashpile();
            break;
            case DIG:
            dig();
            break;
            case INJURED:
            injured();
            break;
            default:
            freedom();
            break;
        }


    }
    else {
        o->oAction = 50;
        switch (o->oAction) {
            case 50:
            null_action();
        }
    }
}