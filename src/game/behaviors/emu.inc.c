#include "levels/bitdw/model.inc.c"
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
        spawn_object(o, MODEL_BOWSER_FLAMES, bhvBowserBombExplosion);
        create_sound_spawner(SOUND_GENERAL_BOWSER_BOMB_EXPLOSION);
        set_camera_shake_from_point(SHAKE_POS_LARGE, o->oPosX, o->oPosY, o->oPosZ);
        obj_mark_for_deletion(bhvGoddardCageCOL);

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
