#define ZH_LASER_RING_SPAWNER_ACT_IDLE     0
#define ZH_LASER_RING_SPAWNER_ACT_CHARGING 1
#define ZH_LASER_RING_SPAWNER_ACT_COOLDOWN 2

#define ZH_LASER_RING_GROWTH_RATE 0.1
#define ZH_LASER_RING_GROWTH_TIME 40
#define ZH_LASER_RING_BASE_RADIUS 250

#define ZH_LASER_RING_SPAWNER_CHARGE_TIME    20
#define ZH_LASER_RING_SPAWNER_COOLDOWN_TIME  20
#define ZH_LASER_RING_SPAWNER_DETECT_RADIUS  (ZH_LASER_RING_BASE_RADIUS * ZH_LASER_RING_GROWTH_RATE * ZH_LASER_RING_GROWTH_TIME)

static struct ObjectHitbox sLaserRingHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 100,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 50,
};

static struct ObjectHitbox sSpikedLaserRingHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 100,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 50,
};

void bhv_laser_ring_spawner_init(void)
{
    o->oAction = ZH_LASER_RING_SPAWNER_ACT_CHARGING;
    o->oAnimState = ((o->oBehParams2ndByte & 0x1) ^ 0x1);
    if(o->oAnimState == 1) {
        obj_set_hitbox(o, &sSpikedLaserRingHitbox);
    } else {
        obj_set_hitbox(o, &sLaserRingHitbox);
        o->oInteractionSubtype |= INT_SUBTYPE_TWIRL_BOUNCE;
    }
}

static void laser_ring_spawner_act_idle(f32 xzDist)
{
    if (xzDist <= ZH_LASER_RING_SPAWNER_DETECT_RADIUS)
    {
        cur_obj_change_action(ZH_LASER_RING_SPAWNER_ACT_CHARGING);
    }
    o->oSpawnerTopOffset = 0.0f;
}

static void laser_ring_spawner_act_charging(f32 xzDist)
{
//    if (xzDist > ZH_LASER_RING_SPAWNER_DETECT_RADIUS)
//    {
//        cur_obj_change_action(ZH_LASER_RING_SPAWNER_ACT_IDLE);
//    }
    if (xzDist <= ZH_LASER_RING_SPAWNER_DETECT_RADIUS && o->oTimer >= ZH_LASER_RING_SPAWNER_CHARGE_TIME)
    {
        spawn_object_relative(
            /* behParam */ 0x00, /* pos */ 0, 50, 0,
            /* parent */ o, /* model */ MODEL_LASER_RING, bhvLaserRing);
        cur_obj_play_sound_2(SOUND_GENERAL_ACTIVATE_CAP_SWITCH);
        cur_obj_change_action(ZH_LASER_RING_SPAWNER_ACT_COOLDOWN);
    }
    o->oSpawnerTopOffset= approach_f32_asymptotic(o->oSpawnerTopOffset, 10.0f, 0.3f);
}

static void laser_ring_spawner_act_cooldown(void)
{
    if (o->oTimer >= ZH_LASER_RING_SPAWNER_COOLDOWN_TIME)
    {
        cur_obj_change_action(ZH_LASER_RING_SPAWNER_ACT_CHARGING);
    }
    o->oSpawnerTopOffset= approach_f32_asymptotic(o->oSpawnerTopOffset, 0.0f, 0.7f);
}

void bhv_laser_ring_spawner_loop(void)
{
    f32 xDel = gMarioState->pos[0] - o->oPosX;
    f32 zDel = gMarioState->pos[2] - o->oPosZ;
    f32 marioXZDist = sqrtf(xDel * xDel + zDel * zDel);
    switch (o->oAction)
    {
        case ZH_LASER_RING_SPAWNER_ACT_IDLE:
            laser_ring_spawner_act_idle(marioXZDist);
            break;
        case ZH_LASER_RING_SPAWNER_ACT_CHARGING:
            laser_ring_spawner_act_charging(marioXZDist);
            break;
        case ZH_LASER_RING_SPAWNER_ACT_COOLDOWN:
            laser_ring_spawner_act_cooldown();
            break;
    }
    o->oInteractStatus = 0;
}

void bhv_laser_ring_init(void)
{
    cur_obj_scale(0.0f);
}

u32 interact_shock(struct MarioState *m, UNUSED u32 interactType, struct Object *o);

void bhv_laser_ring_loop(void)
{
    f32 xDel = gMarioState->pos[0] - o->oPosX;
    f32 zDel = gMarioState->pos[2] - o->oPosZ;
    f32 marioXZDist = sqrtf(xDel * xDel + zDel * zDel);
    f32 marioYMin = gMarioState->pos[1];
    f32 marioYMax = gMarioState->pos[1] + 160.0f;
    f32 outerRadius = o->oTimer * ZH_LASER_RING_GROWTH_RATE * ZH_LASER_RING_BASE_RADIUS;
    f32 innerRadius = outerRadius - 50;

    // Check if mario is in contact with the laser ring
    if (marioXZDist >= innerRadius && marioXZDist <= outerRadius && o->oPosY >= marioYMin && o->oPosY <= marioYMax)
    {
        interact_shock(gMarioState, INTERACT_SHOCK, o);
    }

    if (o->oTimer > ZH_LASER_RING_GROWTH_TIME)
    {
        obj_mark_for_deletion(o);
        return;
    }
    cur_obj_scale(o->oTimer * ZH_LASER_RING_GROWTH_RATE);
}
