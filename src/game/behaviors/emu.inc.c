#include "levels/bitdw/header.h"
#include "levels/bowser_1/header.h"
void bhv_emu_sphere(void){
   long a;
    a = o->oBehParams;
    if (a >= 0x10000000) {
        o->oFaceAnglePitch -= (a-0x10000000); 
    }
    else {
        o->oFaceAnglePitch += a;
    }
}

// This accounts for both the first and second u8 entries
#define COLOR_INDEX(_x) _x*2, _x*2+1

// Color count is actually color count*2, since u16 is stored as two u8
#define COLOR_COUNT 12

u8* vein_rock;

u8 swapSlots[COLOR_COUNT];

/*******Labeled indecies***********
    COLOR_INDEX(5), //some gray 5
    *COLOR_INDEX(6), //orange 6
    COLOR_INDEX(8), // some gray 8
    COLOR_INDEX(9), //yellow 9
    COLOR_INDEX(11),//blue 11
    *COLOR_INDEX(10), //green 10
    *COLOR_INDEX(9), //light orange 9
    COLOR_INDEX(4), //red 4
*/
u8 indices[] = {
    COLOR_INDEX(4),
    COLOR_INDEX(6),
    COLOR_INDEX(8),
    COLOR_INDEX(9),
    COLOR_INDEX(10),
    COLOR_INDEX(11),
};

void palette_swap(void){
    if (gCurrLevelNum == LEVEL_BITDW){
        if (o->oTimer == 0) {
            vein_rock = segmented_to_virtual(bitdw_dl_scrolling_texture_ci4_pal_rgba16);
        }
    }
     else if (gCurrLevelNum == LEVEL_BOWSER_1){
        if (o->oTimer == 0) {
            vein_rock = segmented_to_virtual(bowser_1_dl_scrolling_texture_ci4_pal_rgba16);
        }
    }
    if (o->oTimer % 6 == 0) {
        s32 i;
        s32 index;
        
        for (i = 0; i < COLOR_COUNT; i++) {
            index = (i+2)%COLOR_COUNT;
            swapSlots[index] = vein_rock[indices[i]];
        }

        for(i = 0; i < COLOR_COUNT; i++) {
            vein_rock[indices[i]] = swapSlots[i];
        }
    }
}

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


#define DOG_ANIM_IDLE 0
#define DOG_ANIM_DIG  1
#define DOG_ANIM_RUN  2
#define DOG_ANIM_WALK 3
#define DOG_ANIM_POUNCE 4
#define DOG_ANIM_KNOCKBACK 5
s32 nextX, nextZ, nextXangle, nextZangle;

void rand_polar_coord(void){
    f32 theta;
    u16 r;
    theta = random_float() * 2 * M_PI;
    r = (random_u16() % 2800) + (random_u16() % 2800);
    if (r >=2800) {r = 5400-r;}
    theta = radians_to_angle(theta);
    nextX = ((r * cosf(theta))); 
    nextZ = ((r * sinf(theta)));
    nextXangle = nextX - o->oPosX;
    nextZangle = nextZ - o->oPosZ;
    //return atan2s(nextZ, nextX);
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
    }
    else {
        floor_check++;
    }
}

void find_random_location(void) {
    struct Object *bowser;
    f32 dist;
    f32 randCords;
    s16 turnSpeed = 0x100;
    rand_polar_coord();
    bowser = cur_obj_find_nearest_object_with_behavior(bhvBowser, &dist);
    o->oMoveAngleYaw = atan2s(nextZangle, nextXangle);
    o->oForwardVel = 20.0f;
    o->oAction = EMU_DOG_RUN_AROUND;
    
}

void goto_ashpile(void) {
    struct Object *ashpile;
    ashpile = cur_obj_nearest_object_with_behavior(bhvAshpileEmu);
    o->childObj = ashpile;
    nextX = o->childObj->oPosX - o->oPosX;
    nextZ = o->childObj->oPosZ - o->oPosZ;
    o->oMoveAngleYaw = atan2s(nextZ, nextX);
    o->oForwardVel = 50.0f;
}
void run_around(void) {
    cur_obj_init_animation(DOG_ANIM_RUN);
    // print_text_fmt_int(5, 20, "X %d", nextX);
    // print_text_fmt_int(5, 40, "Z %d", nextZ);
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
   cur_obj_init_animation(DOG_ANIM_IDLE);
   o->oPosY -= 147;
   o->oFaceAngleYaw += DEGREES(180);
}

void injured (void) {
    cur_obj_init_animation(DOG_ANIM_POUNCE);
    mark_obj_for_deletion(o->parentObj); //deletes the amp
    o->childObj->oAction = 0; //resets the ashpile
   
     o->oPosY = 95;
     o->oAction = EMU_DOG_RANDOM_LOCATION;
 
}
void bhv_idle_dog_loop (void) {
    f32 dist;
    if (cur_obj_find_nearest_object_with_behavior(bhvGoddardCage, &dist) == NULL){
        struct Object *amp;
        if (o->oAction == DIG && cur_obj_nearest_object_with_behavior(bhvAttackableAmp) != NULL){
            amp = cur_obj_nearest_object_with_behavior(bhvAttackableAmp);
            o->parentObj = amp;
            if (o->parentObj->oPosX < o->oPosX + 20 && o->parentObj->oPosX > o->oPosX - 20 && o->parentObj->oPosZ < o->oPosZ + 20 && o->parentObj->oPosZ > o->oPosZ - 20){
                o->oAction = INJURED;
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
    o->oForwardVel = 15.0f;
}

void check_emu_amp_attack(void) {
    u8 marioAttack = 5;
        //obj_set_hitbox(o, &sEmuAmpHitbox);
     if (o->oDistanceToMario < 100 && o->oDistanceToMario > 60) {
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
 //o->oForwardVel = 15.0f;
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
    o->oMoveAngleYaw = atan2s(o->childObj->oPosZ - o->oPosZ, o->childObj->oPosX - o->oPosX);
    //struct Object *doggo;
    //doggo = cur_obj_nearest_object_with_behavior(bhvDogEmu);
    //o->childObj = doggo;
    // If the amp is locked on to Mario, start "chasing" him by moving
    // in a straight line at 15 units/second for 32 frames.

        // Move the amp's average Y (the Y value it oscillates around) to align with
        // Mario's head. Mario's graphics' Y + 150 is around the top of his head.
        // Note that the average Y will slowly go down to approach his head if the amp
        // is above his head, but if the amp is below it will instantly snap up.

        obj_turn_toward_object(o, o->childObj, 16, 0x400);

        // The amp's average Y will approach Mario's graphical Y position + 250
        // at a rate of 10 units per frame. Interestingly, this is different from
        // the + 150 used while chasing him. Could this be a typo?

    // The amp's position will sinusoidally oscillate 40 units around its average Y.
    o->oPosY = o->oHomingAmpAvgY + sins(o->oAmpYPhase * 0x400) * 20.0f;

    // Handle attacks
    check_emu_amp_attack();
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
    }
    object_step();
}
