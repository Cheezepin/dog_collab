#include "levels/bitdw/model.inc.c"
void bhv_emu_electric_spinner(void) {
    long a;
    a = o->oBehParams;
    if (a >= 0x10000000) {
        o->oFaceAngleRoll -= (a-0x10000000); 
    }
    else {
        o->oFaceAngleRoll += a;
     }
}
static struct ObjectHitbox sShockHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 140,
    /* hurtboxRadius:     */ 180,
    /* hurtboxHeight:     */ 100,
};
u8 timer;
static void should_despawn(void) {
if (gMarioState == INTERACT_SHOCK){
     mark_obj_for_deletion(o);
     print_fps(1,1);
     o->oAction = 2;
    }
       else if (gMarioState->action == ACT_BACKWARD_AIR_KB) {
        print_fps(89,89);
        obj_set_pos(o, gMarioObject->oPosX, gMarioObject->oPosY, gMarioObject->oPosZ);
        o->oAction = 2;
    }
    else { o->oAction = 1; }
    
}
static void despawn(void) {
//if (timer >= 2){
    mark_obj_for_deletion(o);
    //print_fps(89,89);
    if (gMarioState == ACT_BACKWARD_AIR_KB) {
        print_fps(89,89);
        obj_set_pos(o, gMarioObject->oPosX, gMarioObject->oPosY, gMarioObject->oPosZ);
        o->oAction = 1;
    }
    //o->oAction = 1;
    else {
        o->oAction = 1;
    }
}

static void (*sShockActions[])(void) = {
    should_despawn,
    despawn,
};

void bhv_shock_texture_loop(void) {
    obj_set_hitbox(o, &sShockHitbox);
    cur_obj_call_action_function(sShockActions);
     if (o->oInteractStatus) {
        m->actionArg = (gMarioState->action & ACT_FLAG_AIR) == 0;
        set_mario_action(gMarioState, ACT_SHOCKED, actionArg);
    }
    
}

void bhv_emu_simple_spinner(void){
    long a;
    a = o->oBehParams;
    if (a >= 0x10000000) {
        o->oFaceAngleYaw -= (a-0x10000000); 
    }
    else {
        o->oFaceAngleYaw += a;
    }
}

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
    COLOR_INDEX(7), //orange 7
    COLOR_INDEX(8), // some gray 8
    COLOR_INDEX(11), //yellow 11
    COLOR_INDEX(13),//blue 13
    COLOR_INDEX(12), //green 12
    COLOR_INDEX(9), //light orange 9
    COLOR_INDEX(4), //red 4
*/
u8 indices[] = {
    COLOR_INDEX(4),
    COLOR_INDEX(7),
    COLOR_INDEX(9),
    COLOR_INDEX(11),
    COLOR_INDEX(12),
    COLOR_INDEX(13),
};

void palette_swap(void){

    if (o->oTimer == 0) {
        vein_rock = segmented_to_virtual(bitdw_dl_scrolling_texture_ci4_pal_rgba16);
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