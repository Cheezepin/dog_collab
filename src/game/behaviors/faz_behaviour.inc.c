
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
