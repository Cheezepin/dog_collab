
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

void goddard_hmc_loop(void)
{
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

void hmcelevator_init(void)
{
    o->oMode = o->oBehParams2ndByte;
    o->oMoving = 0;
    o->oOff = 0;
}

void hmcelevator_loop(void)
{
    if (gMarioObject->platform == o && !o->oMoving && o->oOff == 0)
    {
        o->oMoving = 1;
        o->oOff = 1;
    }
    else
    {
        if (!o->oMoving)
            o->oOff = 0;
    }

    if (o->oMoving)
    {
        if (o->oMode)
        {
            o->oPosY -= 25;
        }
        else
            o->oPosY += 25;
        cur_obj_play_sound_2(SOUND_ENV_ELEVATOR1);
        if (gCurrAreaIndex == 2 && o->oPosY > 6000 && gMarioState->pos[1] > o->oPosY)
            initiate_warp(LEVEL_HMC, 1, 0x0C, 0);
        if (gCurrAreaIndex == 1 && o->oPosY < 1000 && gMarioState->pos[1] > o->oPosY)
            initiate_warp(LEVEL_HMC, 2, 0x0C, 0);
        o->oFloorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &o->oFloor);
        if (o->oFloorHeight - 20 < o->oPosY)
        {
            o->oMode ^= 1;
            o->oMoving = 0;
            cur_obj_play_sound_2(SOUND_GENERAL_METAL_POUND);
        }
    }
}
