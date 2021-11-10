static struct ObjectHitbox sClownBossHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 180,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 180,
    /* hurtboxHeight:     */ 300,
};

#include "src/audio/load.h"

void bhv_clown_boss_init(void) {
    obj_set_hitbox(o, &sClownBossHitbox);
    o->oGravity = 5.5;
    o->oClownAction = 0;
    o->oClownHealth = 3;
}

void bhv_clown_boss_loop(void) {
    o->oClownBossTimer += 1;
    

    if (gMarioState->heldObj) {
        o->oObjMarioBomb = gMarioState->heldObj;
    }

    

    if (gMarioState->action == ACT_THROWING || gMarioState->action == ACT_AIR_THROW) {
        o->oClownAwooga = 1;
        o->oClownBossTimer = 0;
        if (o->oClownSound == 0) {
        play_sound(SOUND_CUSTOM_AWOOGA, gGlobalSoundSource);
        o->oClownSound = 1;
        }
    }

    if (o->oClownBossTimer >= 40 && o->oClownAwooga == 1 && o->oClownAction != 10) {
        o->oClownAwooga = 0;
    }

    if (o->oClownAwooga != 6) {
    cur_obj_update_floor_and_walls();
    //cur_obj_update_clown_floor();
    o->oClownColFlags = object_step();
    }
    //print_text_fmt_int(100, 100, "%d", o->header.gfx.animInfo.animFrame);
    //print_text_fmt_int(100, 100, "%d", o->oObjMarioBomb);

if (o->oFloorType != SURFACE_CLOWN_ARENA && (o->oPosY - o->oFloorHeight) <= 1.0f && o->oClownAction != 5) {
   o->oClownBossTimer = 0;
    o->oClownAction = 5;
    o->oClownAwooga = 0;
    
}

if (o->oClownAwooga == 1 && o->oClownAction != 10) {
    o->oClownAction = 6;
}

    switch(o->oClownAction) {
        case 0: clown_before_fight();
        break;
        case 1: clown_inbetween_actions();
        break;
        case 2: clown_charge_mario();
        break;
        case 3: clown_throw_steel_balls(0);
        break;
        case 4: clown_stomp_mario();
        break;
        case 5: clown_return_to_arena();
        break;
        case 6: clown_awooga();
        break;
        case 7: clown_end_awooga();
        break;
        case 8: clown_throw_steel_balls(1);
        break;
        case 9: clown_hurt();
        break;
        case 10: clown_death_cutscene();
        break;
    }


}

void clown_before_fight(void) {

    struct Object *curtains;

extern s8 gDialogCurPage;

cur_obj_init_animation_with_accel_and_sound(0, 0.25f + (0.25f * (gDialogCurPage + 1)));
    //if (o->oDistanceToMario < 1000.0f) {
        
    //}

    if (o->oClownActionNumber != 0) {
         play_secondary_music(SEQ_EVENT_MERRY_GO_ROUND, 0, 255, 5);
        gOverrideTempo = 48 + (10*gDialogCurPage);
    }

    if (o->oDistanceToMario < 600.0f) {
        cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
                DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_102);
        //print_text_fmt_int(100, 100, "%d", gDialogCurPage);
        //print_text_fmt_int(100, 140, "%d", o->oClownActionNumber);
        if (o->oClownActionNumber == 0) {
//create_dialog_box(DIALOG_102);
//set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
o->oClownActionNumber = 1;
}
    }

    if (gDialogCurPage == 4 && o->oClownActionNumber == 1) {
        obj_turn_toward_object(o, gMarioObject, 0x10, 0x800);
        //gOverrideTempo = 0;
    }
    if (gDialogCurPage == 5 && o->oClownActionNumber == 1) {
            o->oClownActionNumber = 2;
        }
    if (o->oClownActionNumber == 3) {
        o->oClownAction = 1;
        o->oClownBossTimer = 0;
        o->oClownActionNumber = 0;
        gOverrideTempo = 0;
        func_80321080(10);
        curtains = spawn_object_relative(0, 0, 0, 0, o, MODEL_NONE, bhvBossCurtains);
        curtains->oMoveAngleYaw = 0;
        curtains->oFaceAngleYaw = 0;
        set_mario_action(gMarioState, ACT_IDLE, 0);
        play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_LEVEL_BOSS_CACKLETTA), 0);
    }
    if (gDialogCurPage == 14 && o->oClownActionNumber == 2) {
        o->oClownActionNumber = 3;
        //gOverrideTempo = gInitOverrideTempo;
    }
}

void clown_inbetween_actions(void) {
    

o->oGravity = 5.5;
cur_obj_init_animation_with_accel_and_sound(1, 2.0f);

//slowly approach mario
    obj_turn_toward_object(o, gMarioObject, 0x10, 0x400);
    if (o->oDistanceToMario > 1000.0f) {
        o->oForwardVel = 10.0f;

    }
    else {
        o->oForwardVel = 1.0f;
    }

obj_scale_xyz(o, 1, (1 - 0.2*coss(o->oClownBossTimer * 0xB80)), 1);

//sway to the side and back
    o->oPosX += 8 * sins(0x200 * o->oClownBossTimer) * coss(o->parentObj->oFaceAngleYaw);
    o->oPosZ += 8 * sins(0x200 * o->oClownBossTimer) * -sins(o->parentObj->oFaceAngleYaw);

    if ((o->header.gfx.animInfo.animFrame) % 15 == 0) {
        if (o->header.gfx.node.flags & GRAPH_RENDER_ACTIVE) {
        o->oVelY = 40.0f;
        }
    }

 //wait a little longer than 3 seconds (6 if your on console xd)
    if (o->oClownBossTimer >= 100) {
        int rand = random_u16();
        //decide next action

        

        switch (rand % 3) {
            case 0: o->oClownAction = 2;
            break;
            case 1: o->oClownAction = 3;
            break;
            case 2: o->oClownAction = 4;
            o->oVelY = 42.0f;
            break;
        }
        o->oClownNumActionsSinceBomb += 1;
        if (o->oClownNumActionsSinceBomb >= 4) {
            o->oClownAction = 8;
            o->oVelY = 0.0f;
            o->oClownNumActionsSinceBomb = 0;
        }
        o->oClownBossTimer = 0;
        o->oClownActionNumber = 0;
    }
}

void clown_charge_mario(void) {
//o->oClownAction = 1;

if (gMarioState->floor->type != SURFACE_CLOWN_ARENA && gMarioState->floorHeight <= 1) {
        set_mario_action(gMarioState, ACT_QUICKSAND_DEATH, 0);
    }

if ((o->oClownBossTimer - 2) % 30 == 0) {
play_sound(SOUND_CUSTOM_CARTOON_RUN, gGlobalSoundSource);
}

if (o->oClownBossTimer <= 30) {
cur_obj_init_animation_with_accel_and_sound(7, 2.0f);
obj_turn_toward_object(o, gMarioObject, 0x10, 0x400);
}
else {
    obj_scale_xyz(o, 1, (1 + 0.25*sins(o->oClownBossTimer * 0x1000)), 1);
    cur_obj_init_animation_with_accel_and_sound(8, 3.0f);
    
    if (o->oDistanceToMario < 1000.0f) {
    o->oForwardVel = 50.0f;
    obj_turn_toward_object(o, gMarioObject, 0x10, 0x100);
    }
    else {
       o->oForwardVel = 50.0f; 
       obj_turn_toward_object(o, gMarioObject, 0x10, 0x400);
    }
}

if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
        o->oClownAction = 5;
    }

if (o->oClownBossTimer >= 270) {

o->oClownBossTimer = 0;
        o->oClownAction = 1;
}
}

void clown_start_stomp(void) {
    o->oVelY = -30;
    cur_obj_init_animation_with_accel_and_sound(4, 1.0f);
    obj_scale_xyz(o, 1, (.75 + 0.25*coss(o->oClownBossTimer*5 * 0x280)), 1);
    if (o->oClownBossTimer >= 10) {
        o->oClownActionNumber = 1;
    }
}

void clown_stomp_mario(void) {
cur_obj_init_animation_with_accel_and_sound(5, 1.0f);
    if (o->oClownActionNumber == 0) {
        return clown_start_stomp();
    }

    if (o->oClownActionNumber > 4) {
        o->oClownActionNumber = 0;
        return o->oClownAction = 1;
    }

    if (o->oClownColFlags != 0x01) {
        if (o->oVelY >= 0) {
        obj_scale_xyz(o, (0.75 - 0.25*coss(o->oVelY * 0x280)), (1 + 0.5*coss(o->oVelY * 0x280)), (0.75 - 0.25*coss(o->oVelY * 0x280)));
        }
        if (o->oVelY < -20) {
         obj_scale_xyz(o, (0.75 - 0.25*coss((o->oVelY+20) * 0x500)), (1 + 0.5*coss((o->oVelY+20) * 0x500)), (0.75 - 0.25*coss((o->oVelY+20) * 0x500)));   
        }
    }

    o->oGravity = 1.5;
    if (o->oClownColFlags == 0x01) {
        o->oVelY = 42.0f;
        o->header.gfx.animInfo.animFrame = 0;
        o->header.gfx.animInfo.animFrameAccelAssist = 2;
        o->oClownBossTimer = 0;
        o->oClownActionNumber += 1;
        play_sound(SOUND_GENERAL_BOING2, gGlobalSoundSource);
    }

    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
        o->oClownAction = 5;
    }

    if (o->oClownBossTimer < 5) {
        o->oMoveAngleYaw = obj_angle_to_object(o, gMarioObject);
    }
    if (o->oClownBossTimer == 6) {
        o->oForwardVel = o->oDistanceToMario / 90;
    }
    //failsafe
    if (o->oClownBossTimer >= 300) {
        o->oClownAction = 5;
    }

}

void clown_throw_steel_balls(int bomb) {
    struct Object *spawnBomb;
     cur_obj_init_animation_with_accel_and_sound(6, 1.0f);
     obj_scale_xyz(o, 1, (1 + 0.25*sins(o->oClownBossTimer*5 * 0x200)), 1);
    if ((o->oClownBossTimer - 5) % 30 == 0) {
        if (o->oClownActionNumber == 2 && bomb == 1) {
            int numBombs = (random_u16() % 3) +1;
            for (int i = 0; i < numBombs; i++) {
            spawnBomb = spawn_object_relative(0x30, 0, 10.0f, 0, o, MODEL_BLACK_BOBOMB, bhvBobomb);
            spawnBomb->oVelY = 30.0f;
            spawnBomb->oForwardVel = 30.0f;
            spawnBomb->oMoveAngleYaw += (-0x1000 + i*0x1000);
            spawnBomb->oFaceAngleYaw += (-0x1000 + i*0x1000);
            }
        }
        else {
        spawn_object_relative(0, 0, 30.0f, 0, o, MODEL_BOWLING_BALL, bhvClownBowlingBall);
        }
        o->header.gfx.animInfo.animFrame = 0;
        o->header.gfx.animInfo.animFrameAccelAssist = 1;
        o->oClownActionNumber += 1;
    }
    if (o->oClownBossTimer >= 90) {
        o->oClownAction = 1;
        o->oClownBossTimer = 0;
    }
}

void clown_awooga(void) {
    obj_scale_xyz(o, 1, 1, 1);
    cur_obj_init_animation_with_accel_and_sound(2, 2.0f);

    struct Object *bomb;
    f32 dist;

    bomb = cur_obj_find_nearest_object_with_behavior(bhvBobomb, &dist);

    

    if (bomb) {
        obj_turn_toward_object(o, bomb, 0x10, 0x800);
    }

    if (o->header.gfx.animInfo.animFrame >= 18) {
        o->oPosY += 16*sins(0x2000 * o->oClownBossTimer);
        o->oPosX += 16*sins(0x2000 * o->oClownBossTimer) * sins(o->parentObj->oFaceAngleYaw);
    o->oPosZ += 16*sins(0x2000 * o->oClownBossTimer) * -coss(o->parentObj->oFaceAngleYaw);
    }
    
    if (o->oClownAwooga == 0) {
         o->oClownSound = 0;
    o->oClownAction = 7;
    }
    if (dist < 400.0f && gMarioState->action != ACT_THROWING && gMarioState->action != ACT_AIR_THROW) {
        bomb->oAction = BOBOMB_ACT_EXPLODE;
        bomb->oTimer = 5;
        spawn_object_relative(0, 0, 50.0f, 0, o, MODEL_EXPLOSION, bhvExplosion);
        spawn_object_relative(20.0f, 0, 30.0f, 0, o, MODEL_EXPLOSION, bhvExplosion);
        spawn_object_relative(-20.0f, 0, 30.0f, 0, o, MODEL_EXPLOSION, bhvExplosion);
        spawn_object_relative(0, 20.0f, 30.0f, 0, o, MODEL_EXPLOSION, bhvExplosion);
        spawn_object_relative(0, -20.0f, 30.0f, 0, o, MODEL_EXPLOSION, bhvExplosion);
        o->oClownAction = 9;
        o->oClownHealth -= 1;
        o->oClownAwooga = 0;
        o->oClownBossTimer = 0;
    }
}

void clown_end_awooga(void) {
    cur_obj_init_animation_with_accel_and_sound(3, 2.0f);
    if (o->header.gfx.animInfo.animFrame >= 18) {
        o->oClownAction = 1;
        o->oClownBossTimer = 0;
    }
}

void clown_return_to_arena(void) {

cur_obj_init_animation_with_accel_and_sound(5, 0.0f);

    if (o->oClownBossTimer < 30) {
       obj_scale_xyz(o, 1, coss(o->oClownBossTimer * 0x222), 1);
    }

    if (o->oClownBossTimer == 30) {
        o->oPosX = 71;
        o->oPosY = 170;
        o->oPosZ = -78;
    }

    if (o->oClownBossTimer > 30) {
       obj_scale_xyz(o, 1, sins((o->oClownBossTimer - 30) * 0x222), 1);
    }

    if (o->oClownBossTimer == 60) {
        obj_scale_xyz(o, 1, 1, 1);
        o->oClownAction = 1;
        o->oClownBossTimer = 0;
    }

}

void clown_hurt(void) {
    cur_obj_init_animation_with_accel_and_sound(9, 1.0f);
    if (o->oClownBossTimer >= 60) {
        if (o->oClownHealth > 0) {
        o->oClownAction = 1;
        }
        else {
            o->oClownAction = 10;
            o->oClownActionNumber = 0;
            o->oClownBossTimer = 0;
        }
    }

    obj_scale_xyz(o, 1, (1 + (0.5 - 0.5/(double)o->oClownBossTimer)*sins(o->oClownBossTimer * 0x1000)), 1);
}

void clown_death_cutscene(void) {
    extern s8 gDialogCurPage;
    struct Object *goddard;
    obj_scale_xyz(o, 1, 1, 1);
    

    if (o->oClownActionNumber == 0) {
        cur_obj_init_animation_with_accel_and_sound(0, 3.0f);
        create_dialog_box(DIALOG_103);
set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
o->oClownActionNumber = 1;

    }
if (o->oClownActionNumber == 1) {
    switch (gDialogCurPage) {
        case 1:
        case 2:
        gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
        o->oPosX = 71;
        o->oPosZ = -78;
        o->oFaceAngleYaw = 0;
        o->oMoveAngleYaw = 0;
        //goddard->oPosX = o->oPosX;
        //goddard->oPosZ = o->oPosZ + 500;
        gCamera->cutscene = 1;
            gLakituState.goalFocus[0] = o->oPosX;
         gLakituState.goalFocus[1] = o->oPosY + 300;
         gLakituState.goalFocus[2] = o->oPosZ;
         gLakituState.goalPos[0] = o->oPosX + 700;
         gLakituState.goalPos[1] = o->oPosY + 100;
         gLakituState.goalPos[2] = o->oPosZ + 700;
        break;
        case 4:
    o->oClownActionNumber = 2;
    o->oClownBossTimer = 0;
    
        break;
    }
}

if (o->oClownActionNumber == 2) {
    //goddard->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_DOG];
    goddard = spawn_object_relative(0, 0, 0, 1500.0f, o, MODEL_DOG, bhvDogForSC);
    goddard->oFaceAngleYaw = 0x8000;
    goddard->oMoveAngleYaw = 0x8000;
    
    gMarioState->pos[0] = goddard->oPosX;
    gMarioState->pos[0] = goddard->oPosZ;
         gLakituState.goalFocus[0] = goddard->oPosX;
         gLakituState.goalFocus[1] = goddard->oPosY;
         gLakituState.goalFocus[2] = goddard->oPosZ;
         gLakituState.goalPos[0] = goddard->oPosX - 500;
         gLakituState.goalPos[1] = goddard->oPosY + 300;
         gLakituState.goalPos[2] = goddard->oPosZ - 1300;
         o->oClownAwooga = 1;
         o->oClownActionNumber = 3;
}

if (o->oClownActionNumber == 3) {
    f32 dist;
    goddard = cur_obj_find_nearest_object_with_behavior(bhvDogForSC, &dist);
goddard->oPosZ -= 20;
if (o->oClownBossTimer >= 60) {
    o->oClownActionNumber = 4;
}
}

if (o->oClownActionNumber == 4) {
    f32 dist;
goddard = cur_obj_find_nearest_object_with_behavior(bhvDogForSC, &dist);
goddard->oPosZ = o->oPosZ + 1800;
goddard->oPosY = o->oPosY + 300;
cur_obj_init_animation_with_accel_and_sound(2, 2.0f);
play_sound(SOUND_CUSTOM_AWOOGA, gGlobalSoundSource);
gLakituState.goalFocus[0] = o->oPosX;
         gLakituState.goalFocus[1] = o->oPosY + 400;
         gLakituState.goalFocus[2] = o->oPosZ;
         gLakituState.goalPos[0] = o->oPosX + 400;
         gLakituState.goalPos[1] = o->oPosY + 100;
         gLakituState.goalPos[2] = o->oPosZ + 400;
         o->oClownActionNumber = 5;
}
if (o->oClownActionNumber == 5) {
    f32 dist;
    
        o->oPosY += 16*sins(0x2000 * o->oClownBossTimer);
        o->oPosX += 16*sins(0x2000 * o->oClownBossTimer) * sins(o->parentObj->oFaceAngleYaw);
    o->oPosZ += 16*sins(0x2000 * o->oClownBossTimer) * -coss(o->parentObj->oFaceAngleYaw);
    
    goddard = cur_obj_find_nearest_object_with_behavior(bhvDogForSC, &dist);
    
goddard->oPosZ -= 30;

    if (goddard->oPosZ - o->oPosZ <= 0) {
        gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_MARIO];
        gCamera->cutscene = 0;
        set_mario_action(gMarioState, ACT_IDLE, 0);
        obj_mark_for_deletion(goddard);
        spawn_object_relative(4, 0, 100, 0, o, MODEL_NONE, bhvGoddardClownFight);
        obj_mark_for_deletion(o);
    }
}


}


Gfx *geo_clown_head_scaler(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    struct GraphNodeScaleBetter *scaleNode = (struct GraphNodeScaleBetter *) node->next;
    struct Object *obj;

    obj = (struct Object *) gCurGraphNodeObject;

    if (callContext == GEO_CONTEXT_RENDER) {
        if (obj->oClownAction == 9) {
            if (o->oClownBossTimer < 30) {
        scaleNode->scaleX = 0.5f;
        scaleNode->scaleY = 0.5f;
        scaleNode->scaleZ = 0.5f;
            }
            else {
                scaleNode->scaleX = 0.0f + (o->oClownBossTimer/30);
        scaleNode->scaleY = 1.0f + 0.1*sins(obj->oClownBossTimer * 0x222);
        scaleNode->scaleZ = 0.0f + (o->oClownBossTimer/30);
            }
        }
        else {
        scaleNode->scaleX = 1.0f;
        scaleNode->scaleY = 1.0f;
        scaleNode->scaleZ = 1.0f; 
        }
        
    }
    
    return NULL;
}

Gfx *geo_clown_bone_scaler(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    struct GraphNodeScaleBetter *scaleNode = (struct GraphNodeScaleBetter *) node->next;
    struct Object *obj;

    obj = (struct Object *) gCurGraphNodeObject;

    if (callContext == GEO_CONTEXT_RENDER) {
        if (obj->oClownAction == 9) {
        scaleNode->scaleX = 1.0f;
        scaleNode->scaleY = 1.0f;
        scaleNode->scaleZ = 1.0f;
        }
        else {
        scaleNode->scaleX = 0.0f;
        scaleNode->scaleY = 0.0f;
        scaleNode->scaleZ = 0.0f; 
        }
        
    }
    
    return NULL;
}

Gfx *geo_clown_eyes_scaler(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    struct GraphNodeScaleBetter *scaleNode = (struct GraphNodeScaleBetter *) node->next;
    struct Object *obj;

    obj = (struct Object *) gCurGraphNodeObject;

if (callContext == GEO_CONTEXT_RENDER) {
    if (obj->oClownAwooga == 0) {
        scaleNode->scaleX = 1.0f + 0.1*sins(obj->oClownBossTimer * 0x800);
        scaleNode->scaleY = 1.0f;
        scaleNode->scaleZ = 1.0f;
    }
    else {
        scaleNode->scaleX = 1.0f;
        scaleNode->scaleY = 1.0f;
        scaleNode->scaleZ = 1.0f;
    }
        
    }
    return NULL;
}

Gfx *geo_clown_awooga_eyes_scaler(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    struct GraphNodeScaleBetter *scaleNode = (struct GraphNodeScaleBetter *) node->next;
    struct Object *obj;

    obj = (struct Object *) gCurGraphNodeObject;

if (callContext == GEO_CONTEXT_RENDER) {
    if (obj->header.gfx.animInfo.animFrame >= 5 && obj->oClownAction == 6) {
        if (scaleNode->scaleZ < 20) {
        scaleNode->scaleZ += 1.0f;
        }
        else {
        scaleNode->scaleZ = 20.0f;
        }
        scaleNode->scaleX = 1.0f;
        scaleNode->scaleY = 1.0f;
    }
    else if (obj->oClownAction == 10 && obj->oClownAwooga == 1) {
        if (scaleNode->scaleZ < 20) {
        scaleNode->scaleZ += 1.0f;
        }
        else {
        scaleNode->scaleZ = 20.0f;
        }
        scaleNode->scaleX = 1.0f;
        scaleNode->scaleY = 1.0f;
    }
    else {
        scaleNode->scaleX = 1.0f;
        scaleNode->scaleY = 1.0f;
        scaleNode->scaleZ = 1.0f;
    }
        
    }
    return NULL;
}

Gfx *geo_clown_awooga_mouth_scaler(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    struct GraphNodeScaleBetter *scaleNode = (struct GraphNodeScaleBetter *) node->next;
    struct Object *obj;

    obj = (struct Object *) gCurGraphNodeObject;

if (callContext == GEO_CONTEXT_RENDER) {
    if (obj->header.gfx.animInfo.animFrame >= 5 && obj->oClownAction == 6) {
        if (scaleNode->scaleY < 10) {
        scaleNode->scaleY += 1.0f;
        }
        else {
        scaleNode->scaleY = 10.0f;
        }
        scaleNode->scaleX = 1.0f;
        scaleNode->scaleZ = 1.0f;
    }
    else if (obj->oClownAction == 10 && obj->oClownAwooga == 1) {
        if (scaleNode->scaleY < 10) {
        scaleNode->scaleY += 1.0f;
        }
        else {
        scaleNode->scaleY = 10.0f;
        }
        scaleNode->scaleX = 1.0f;
        scaleNode->scaleZ = 1.0f;
    }
    else {
        scaleNode->scaleX = 0.0f;
        scaleNode->scaleY = 0.0f;
        scaleNode->scaleZ = 0.0f;
    }
        
    }
    return NULL;
}

void bhv_boss_curtains_loop(void) {
    if (o->oCurtainTimer == 1) {
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_BOSS_CURTAINS];
    }
    if (o->oCurtainTimer < 30) {
        o->oCurtainTimer += 1;
        obj_scale_xyz(o, 1, sins(o->oClownBossTimer * 0x222), 1);
    }
    else {
        obj_scale_xyz(o, 1, 1, 1);
    }
}

void bhv_goddard_clown_fight_init(void) {
    if (o->parentObj->oClownActionNumber == 4) {
        cur_obj_init_animation_with_accel_and_sound(4, 1.0f);
    }
}

struct SpawnParticlesInfo sFightStars = {
    0, 10, MODEL_CARTOON_STAR, 0, 40, 0, 20, 40, 252, 30, 5.0f, 0.0f
};

struct SpawnParticlesInfo sFightPuffs = {
    2, 10, MODEL_MIST, 0, 40, 0, 20, 40, 252, 30, 120.0f, 10.0f
};

struct SpawnParticlesInfo sFightPuffSingle = {
    2, 1, MODEL_MIST, 0, 40, 0, 20, 40, 252, 30, 140.0f, 10.0f
};

void bhv_goddard_clown_fight_loop(void) {
    extern s8 gDialogCurPage;
    if (o->oDistanceToMario < 600.0f && o->oGCFAction == 0) {
        cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
                DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_104);
                if (gDialogCurPage >= 5) {
                    o->oGCFAction = 1;
                    spawn_clown_star(350.0f, o->oPosY + 100, -350.0f);
                    set_mario_action(gMarioState, ACT_IDLE, 0);
                }
    }

    if (gGlobalTimer % 12 == 0) {
    cur_obj_spawn_particles(&sFightStars);
    
    }
    if (gGlobalTimer % 8 == 0) {
    cur_obj_spawn_particles(&sFightPuffs);
    }
    if (gGlobalTimer % 2 == 0) {
    cur_obj_spawn_particles(&sFightPuffSingle);
    }

    if (gGlobalTimer % 40 == 0) {
        play_sound(SOUND_GENERAL_BREAK_BOX, gGlobalSoundSource);
    }
    if ((gGlobalTimer + 10) % 40 == 0) {
        play_sound(SOUND_GENERAL_POUND_WOOD_POST, gGlobalSoundSource);
    }
    if ((gGlobalTimer + 20) % 40 == 0) {
        play_sound(SOUND_GENERAL_BOING2, gGlobalSoundSource);
    }
    if ((gGlobalTimer + 30) % 40 == 0) {
        play_sound(SOUND_GENERAL_METAL_POUND, gGlobalSoundSource);
    }
}

void bhv_circus_cannon_init(void) {
   
}

void bhv_circus_cannon_loop(void) {
    struct Object *clown;
    f32 dist;
    clown = cur_obj_find_nearest_object_with_behavior(bhvClownBoss, &dist);
    if (clown && clown->oClownAction != 0 && clown->oClownAction != 10) {

        if ((o->oCircusCannonTimer + 150*o->oBehParams2ndByte) % 450 == 0) {
            int rand = random_u16();
        
        play_sound(SOUND_OBJ_CANNON4, gGlobalSoundSource);
        switch (rand % 3) {
            case 0:
            o->oObjShootObject = spawn_object_relative(0x30, 100, 100, 0, o, MODEL_BLACK_BOBOMB, bhvBobomb);
            o->oObjShootObject->oVelY = 30.0f;
            o->oObjShootObject->oForwardVel = 320.0f;
            o->oObjShootObject->oAction = BOBOMB_ACT_CHASE_MARIO;
            o->oObjShootObject->oBobombFuseLit = 1;
            break;
            case 1:
            o->oObjShootObject = spawn_object_relative(1, 100, 100, 0, o, MODEL_BOWLING_BALL, bhvClownBowlingBall);
            o->oObjShootObject->oVelY = 40.0f;
            o->oObjShootObject->oForwardVel = 100.0f;
            o->oObjShootObject->oMoveAngleYaw = o->oMoveAngleYaw + 0x4000;
            o->oObjShootObject->oFaceAngleYaw = o->oFaceAngleYaw + 0x4000;
            break;
            case 2:
            o->oObjShootObject = spawn_object_relative(0x30, 100, 100, 0, o, MODEL_BLUE_FLAME, bhvBlueBowserFlame);
            o->oObjShootObject->oMoveAngleYaw = o->oMoveAngleYaw + 0x4000;
            o->oObjShootObject->oFaceAngleYaw = o->oFaceAngleYaw + 0x4000;
            o->oObjShootObject->oVelY = 30.0f;
            o->oObjShootObject->oForwardVel = 120.0f;
            break;
        }

        }

        o->oCircusCannonTimer += 1;
    }
}