
void faz_ambient_loop(void)
{
    switch(o->oBehParams2ndByte)
    {
    case 0:
        {
            if (gMarioCurrentRoom == 1)
                cur_obj_play_sound_1(SOUND_AIR_HOWLING_WIND);
            break;
        }
    }
}

#define GODDARD_MODE_FLEE 1
#define GODDARD_MODE_STAY 2
#define GODDARD_ACT_IDLE 0
#define GODDARD_ACT_RUN 1
#define oPicked oF4
#define oMeme oF8
#define oCurrentPoint oFC

void goddard_hmc_init(void)
{
    cur_obj_scale(0.5f);
    o->oInteractionSubtype = INT_SUBTYPE_HOLDABLE_NPC;
    o->oCurrentPoint = 1;
    o->oPicked = 0;
    o->oMeme = 69;
}


//Mostly just copied from mips behaviour because why write new code when you can blatantly steal existing code.
void goddard_flee(void)
{
    s32 x, y, z;
    struct Waypoint *path = segmented_to_virtual(&hmc_area_2_spline_GoddardPath);
    path += o->oCurrentPoint;

    cur_obj_init_animation(2);
    cur_obj_become_tangible();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;

    x = path->pos[0];
    z = path->pos[2];

    o->oFaceAngleYaw += 0x1800;

    o->oPosX = approach_s32(o->oPosX, x, 30, 30);
    o->oPosZ = approach_s32(o->oPosZ, z, 30, 30);

    if (sqr(o->oPosX - x) + sqr(o->oPosZ - z) < 50)
    {
        if (o->oCurrentPoint < 17)
            o->oCurrentPoint++;
        else
            o->oCurrentPoint = 0;
    }
}

void goddard_unlock_door(struct Object *door)
{
    Vec3f targetPos = {door->oPosX, door->oPosY, door->oPosZ};

    if (door != NULL && lateral_dist_between_objects(o, door) < 450)
    {
        o->oHeldState = HELD_FREE;

        o->oPosX = approach_s32(o->oPosX, targetPos[0], 25, 25);
        o->oPosZ = approach_s32(o->oPosZ, targetPos[2], 25, 25);

        if (lateral_dist_between_objects(o, door) < 50)
        {
            struct Object *obj = create_object(bhvExplosion);
            obj->oPosX = o->oPosX;
            obj->oPosY = o->oPosY;
            obj->oPosZ = o->oPosZ;
            obj_set_model(obj, MODEL_EXPLOSION);
            obj_mark_for_deletion(door);
            obj_mark_for_deletion(o);
        }
    }
}

void goddard_hmc_loop(void)
{
    struct Object *door = cur_obj_nearest_object_with_behavior(bhvDoorDog);
    if (door != NULL && lateral_dist_between_objects(o, door) < 500)
    {
        goddard_unlock_door(door);
        return;
    }
    if (o->oHeldState == HELD_FREE && !o->oPicked)
        goddard_flee();
    else
    if (o->oHeldState == HELD_HELD)
    {
        o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        cur_obj_init_animation(0);
        cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 100.0f);
        cur_obj_become_intangible();
        o->header.gfx.angle[0] = random_u16();
        o->header.gfx.angle[1] = random_u16();
        o->header.gfx.angle[2] = random_u16();
        o->oPicked = 1;
    }
    else
    {
        struct Surface *floor;
        o->oFloorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);

        cur_obj_init_animation(0);
        cur_obj_become_tangible();
        o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;

        if (floor != NULL && o->oFloorHeight - o->oPosY < 30)
        {
            o->oPosY = o->oFloorHeight;
            o->oVelY = 0;

            //Punishment, for naughty players who think it's really funny to murder the dog.
            if (floor->type == SURFACE_DEATH_PLANE)
            {
                struct Object *obj = create_object(bhvExplosion);
                obj->oPosX = gMarioState->pos[0];
                obj->oPosY = gMarioState->pos[1];
                obj->oPosZ = gMarioState->pos[2];
                obj_set_model(obj, MODEL_EXPLOSION);
                set_mario_action(gMarioState, ACT_DISAPPEARED, 0);
                obj_mark_for_deletion(o);
            }
        }
        else
        {
            if (o->oVelY < 48)
                o->oVelY += 8;
        }
    }
}

#undef GODDARD_ACT_RUN
#undef GODDARD_ACT_IDLE
#undef GODDARD_MODE_FLEE
#undef GODDARD_MODE_STAY

#define oMode oF4
#define oMoving oF8
#define oOff oFC

u8 elevatorCD = 0;

void hmcelevator_init(void)
{
    o->oMode = o->oBehParams2ndByte;
    o->oMoving = 0;
    o->oOff = 0;
    if (gCurrAreaIndex == 2 && gMarioState->pos[1] > 5000)
    {
        stop_background_music(SEQ_LEVEL_UNDERGROUND);
        o->oPosY = gMarioState->pos[1]-100;
        o->oMode = 1;
        o->oMoving = 1;
        elevatorCD = 1;
    }
    if (gCurrAreaIndex == 1 && gMarioState->pos[1] < 1000 && gMarioState->pos[1] > 100)
    {
        stop_background_music(SEQ_LEVEL_SNOW);
        o->oPosY = gMarioState->pos[1]-100;
        o->oMode = 0;
        o->oMoving = 1;
        elevatorCD = 1;
        gMarioCurrentRoom = 2;
    }

}

Vec3s warpRelPos = {32000, 32000, 32000};

void hmcelevator_loop(void)
{
    if (gMarioObject->platform == o && !o->oMoving && o->oOff == 0 && !elevatorCD)
    {
        o->oMoving = 1;
        o->oOff = 1;
        //play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 60, 0, 0, 0);
    }
    else
    {
        if (!o->oMoving && o->oDistanceToMario > 250)
        {
            o->oOff = 0;
            if ((gCurrAreaIndex == 1 || gMarioState->pos[1] < 5000) && (gCurrAreaIndex == 2 || gMarioState->pos[1] > 1100))
                elevatorCD = 0;
        }
    }

    if (o->oMoving)
    {
        if (o->oMode)
            o->oPosY -= 25;
        else
            o->oPosY += 25;


        if (o->oPosY < 4219 && gCurrAreaIndex == 2)
        {
            o->oMode ^= 1;
            o->oMoving = 0;
            o->oOff = 1;
            cur_obj_play_sound_2(SOUND_GENERAL_METAL_POUND);
            set_background_music(SEQ_LEVEL_UNDERGROUND, SEQUENCE_ARGS(4, SEQ_LEVEL_UNDERGROUND), 30);
        }
        if (o->oPosY > 1421 && gCurrAreaIndex == 1)
        {
            o->oMode ^= 1;
            o->oMoving = 0;
            o->oOff = 1;
            cur_obj_play_sound_2(SOUND_GENERAL_METAL_POUND);
            set_background_music(SEQ_LEVEL_SNOW, SEQUENCE_ARGS(4, SEQ_LEVEL_SNOW), 30);
        }


        cur_obj_play_sound_2(SOUND_ENV_ELEVATOR1);
        if (gCurrAreaIndex == 2 && o->oPosY > 8000 && gMarioState->pos[1] > o->oPosY-100 && !elevatorCD)
        {
            warpRelPos[0] = o->oPosX - gMarioState->pos[0];
            warpRelPos[1] = o->oPosZ - gMarioState->pos[2];
            warpRelPos[2] = gMarioState->faceAngle[1];
            elevatorCD = 1;
            initiate_warp(LEVEL_HMC, 1, 0x0C, 0);
        }
        if (gCurrAreaIndex == 1 && o->oPosY < 0 && gMarioState->pos[1] > o->oPosY-100 && !elevatorCD)
        {
            warpRelPos[0] = o->oPosX - gMarioState->pos[0];
            warpRelPos[1] = o->oPosZ - gMarioState->pos[2];
            warpRelPos[2] = gMarioState->faceAngle[1];
            elevatorCD = 1;
            initiate_warp(LEVEL_HMC, 2, 0x0B, 0);
        }
    }
}

u8 starBlockSpawned;

static struct ObjectHitbox sStarblockHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void starblock_init(void)
{
    starBlockSpawned = 0;
    obj_set_hitbox(o, &sStarblockHitbox);
    o->oInteractionSubtype = INT_SUBTYPE_HOLDABLE_NPC;
}

extern struct Object *spawn_star(struct Object *starObj, f32 x, f32 y, f32 z);

void starblock_loop(void)
{
    struct Object *npc = cur_obj_nearest_object_with_behavior(bhvKoopaDialog);

    obj_set_hitbox(o, &sStarblockHitbox);
    if (npc->oBehParams2ndByte == 0xA1 && starBlockSpawned == 0)
    {
        if (lateral_dist_between_objects(o, npc) < 500 && o->oHeldState == HELD_FREE)
        {
            if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_FRONT, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_162))
            {
                struct Object *star = spawn_star(star, 2387.0f, 4500.0f, -778.0f);
                star->oBehParams = 0x04000000;
                starBlockSpawned = 1;
            }
        }
    }
    if (starBlockSpawned)
    {
        spawn_mist_particles_variable(0, 0, 100.0f);
        spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
        obj_mark_for_deletion(o);
    }

    if (o->oHeldState == HELD_HELD)
    {
        o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 100.0f);
        cur_obj_become_intangible();
    }
    else
    {
        struct Surface *floor;
        o->oFloorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);

        cur_obj_become_tangible();
        o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;

        if (floor != NULL && o->oFloorHeight - o->oPosY < 30)
        {
            o->oPosY = o->oFloorHeight;
            o->oVelY = 0;
        }
        else
        {
            if (o->oVelY < 48)
                o->oVelY += 8;
        }
    }
}

void koopa_boss_spawn(void)
{
    if (o->oBehParams2ndByte == 0x9B)
    {
        struct Object *matt = cur_obj_nearest_object_with_behavior(bhvBossMatt);
        if (matt)
        {
            o->oBehParams2ndByte = 0xA3;
            struct Object *obj = create_object(bhvExplosion);
            obj->oPosX = matt->oPosX;
            obj->oPosY = matt->oPosY;
            obj->oPosZ = matt->oPosZ;
            obj_set_model(obj, MODEL_EXPLOSION);
            obj_mark_for_deletion(matt);
        }
    }
}

#include "game/print.h"

#define oMode oF4
#define oFirstHit oF8
#define oPhase oFC
#define oFireTime o100
#define oAmmo o104
#define oWaitTime o108

#define MODE_PREFIGHT 0
#define MODE_FIGHTING 1
#define MODE_MORTIS 2

void koopa_boss_init(void)
{
    cur_obj_scale(2.0f);
    o->oHealth = 3;
    o->oMode = 0;
    o->oFirstHit = 0;
    o->oPhase = 0;
    o->oFireTime = 0;
    o->oAmmo = random_u16() % 12;
    o->oWaitTime = 0;
}

static struct ObjectHitbox sBossKoopaHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 3,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void koopa_boss_prefight(void)
{

    obj_set_hitbox(o, &sBossKoopaHitbox);
    if (o->oDistanceToMario < 1000)
    {
        stop_background_music(SEQ_LEVEL_UNDERGROUND);
        if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_FRONT, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_167))
        {
            o->oMode = MODE_FIGHTING;
            set_background_music(SEQ_EVENT_BOSS, SEQUENCE_ARGS(4, SEQ_EVENT_BOSS), 30);
        }
    }
}

void koopa_find_anchor(void)
{
    struct Object *obj;
    struct ObjectNode *listHead;
    s32 countUp = 0;
    s32 count;
    tryAgain:
    count = random_u16() % 24;

    listHead = &gObjectLists[get_object_list_from_behavior(segmented_to_virtual(bhvKoopaBossAnchor))];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead)
    {
        if (obj->behavior == segmented_to_virtual(bhvKoopaBossAnchor))
        {
            if (countUp == count)
            {
                if (obj == o->oBitsPlatformBowser)
                    goto tryAgain;
                o->oBitsPlatformBowser = obj;
                o->oHomeX = obj->oPosX;
                o->oHomeY = obj->oPosY;
                o->oHomeZ = obj->oPosZ;
                return;
            }
            countUp++;
        }
        obj = (struct Object *) obj->header.next;
    }
}

void koopa_boss_hurt(void)
{
    cur_obj_init_animation(4);
    cur_obj_extend_animation_if_at_end();
    struct Surface *floor;
    f32 floorHeight = find_floor(o->oPosX, o->oPosY+1000, o->oPosZ, &floor);
    o->oForwardVel = 0;
    if (o->oVelY > -40)
        o->oVelY -= 8;
    o->oPosY += o->oVelY;
    if (ABS(floorHeight - o->oPosY) < 100 && o->oVelY < 0)
    {
        o->oPosY = floorHeight;
        o->oPhase = 1;
        o->oHealth--;
        o->oVelY = 0;
        cur_obj_play_sound_2(SOUND_GENERAL_METAL_POUND);
        spawn_mist_particles_variable(0, 0, 100.0f);
        cur_obj_become_tangible();
    }
}

void koopa_boss_jump(void)
{
    struct Surface *floor;
    f32 floorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);

    cur_obj_init_animation(2);
    cur_obj_extend_animation_if_at_end();

    if (o->oPhase == 1)
    {
        o->oPhase = 2;
        koopa_find_anchor();
        cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
        o->oVelY = 100;
        cur_obj_become_intangible();
        if (o->oBitsPlatformBowser == NULL)
            o->oPhase = 1;
    }
    else
    if (o->oPhase == 2)
    {
        arc_to_goal_pos(&o->oHomeX, &o->oPosVec, o->oVelY, -4.0f);
        cur_obj_move_using_fvel_and_gravity();
        if (lateral_dist_between_objects(o, o->oBitsPlatformBowser) < 100 && ABS(o->oPosY - o->oHomeY) < 50)
        {
            o->oPosY = floorHeight;
            o->oAmmo = random_u16() % 24 + (8 - o->oHealth);
            o->oPhase = 0;
            if (o->oFirstHit == 0)
                o->oFirstHit = 1;
        }
    }
}

void koopa_boss_shooting(void)
{
    if (o->oFireTime > 0)
        return;
    if (o->oAmmo == 0)
    {
        if (o->oWaitTime-- <= 0)
            o->oPhase = 1;
        return;
    }
    cur_obj_become_tangible();
    o->oAmmo--;
    s16 targetAngle = ((o->oFaceAngleYaw - 0xC00) + (random_u16() % 0x1800));
    struct Object *bullet = create_object(bhvBossShell);
    obj_set_model(bullet, MODEL_KOOPA_SHELL);
    bullet->oPosX = o->oPosX;
    bullet->oPosY = o->oPosY+200;
    bullet->oPosZ = o->oPosZ;
    obj_scale(bullet, 2.5f-((f32)o->oHealth/2));
    bullet->oForwardVel = 32 + ((4-o->oHealth) * 4);
    bullet->oMoveAngleYaw = targetAngle;
    o->oFireTime = 24 - (8-(o->oHealth*2));
    if (o->oAmmo == 0)
        o->oWaitTime = 45;
}

void koopa_boss_fighting(void)
{
    if (o->oHealth == 0)
    {
        o->oMode = MODE_MORTIS;
        return;
    }

    cur_obj_init_animation(1);

    o->oFaceAngleYaw = atan2s(o->oPosZ - gMarioState->pos[2], o->oPosX - gMarioState->pos[0])+0x8000;

    if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED)
    {
        o->oPhase = 3;
        o->oVelY = 100;
        cur_obj_play_sound_2(SOUND_OBJ_KOOPA_FLYGUY_DEATH);
        o->oInteractStatus = 0;
    }

    if (o->oPhase == 3)
    {
        koopa_boss_hurt();
    }
    else
    {
        o->oInteractStatus = 0;
    }

    if (o->oDistanceToMario < 1050 && o->oPhase == 0 && o->oAmmo == 0)
        o->oPhase = 1;

    if (o->oPhase == 1 || o->oPhase == 2)
        koopa_boss_jump();

    o->oFireTime--;

    if (o->oPhase == 0)
    {
        koopa_boss_shooting();
    }

}

void koopa_boss_mortis(void)
{
    cur_obj_init_animation(4);
    cur_obj_extend_animation_if_at_end();
    if (o->oDistanceToMario < 1000)
    {
        if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_FRONT, DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_169))
        {
            set_background_music(SEQ_LEVEL_UNDERGROUND, SEQUENCE_ARGS(4, SEQ_LEVEL_UNDERGROUND), 30);
            struct Object *star = spawn_star(star, -354.0f, 250.0f, -9775.0f);
            star->oBehParams = 0x05000000;
            spawn_mist_particles_variable(0, 0, 100.0f);
            spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
            cur_obj_play_sound_2(SOUND_OBJ_KOOPA_FLYGUY_DEATH);
            obj_mark_for_deletion(o);
        }
    }
}

void koopa_boss_loop(void)
{
    switch (o->oMode)
    {
    case MODE_PREFIGHT:
        koopa_boss_prefight();
        break;
    case MODE_FIGHTING:
        koopa_boss_fighting();
        break;
    case MODE_MORTIS:
        koopa_boss_mortis();
        break;
    }
}

#undef oMode
#undef oFirstHit
#undef oPhase

#define oMarked oF4

static struct ObjectHitbox sShellBulletHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 75,
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 50,
};

void koopa_boss_shell_init()
{
    o->oMarked = 0;
    obj_set_model(o, MODEL_KOOPA_SHELL);
    cur_obj_become_tangible();
    cur_obj_enable_rendering();
}

extern s32 obj_handle_attacks(struct ObjectHitbox *hitbox, s32 attackedMarioAction, u8 *attackHandlers);

void koopa_boss_shell_loop(void)
{
    struct Surface *floor;
    f32 floorHeight = find_floor(o->oPosX, o->oPosY+500, o->oPosZ, &floor);
    o->oPosY = floorHeight;
    o->oFaceAngleYaw+= 0x1000;
    obj_set_hitbox(o, &sShellBulletHitbox);
    cur_obj_move_using_fvel_and_gravity();
    if (o->oInteractStatus & INT_STATUS_ATTACKED_MARIO)
        o->oTimer = 300;
    if (o->oTimer >= 300)
    {
        struct Object *obj = create_object(bhvExplosion);
        obj->oPosX = o->oPosX;
        obj->oPosY = o->oPosY;
        obj->oPosZ = o->oPosZ;
        obj_set_model(obj, MODEL_EXPLOSION);
        obj_mark_for_deletion(o);
    }
}
