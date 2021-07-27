#define BLARGG_IDLE 0
#define BLARGG_LUNGE 1

//bparams:
//1: does he go through walls during lunge? (0: yes, 1: no)

static struct ObjectHitbox sBlarggHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 175,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 175,
    /* hurtboxHeight:     */ 200,
};

static u8 sBlarggAttackHandlers[][6] = {
    // regular and tiny
    {
        /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
        /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
        /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
        /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_GPD_ON,
        /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
        /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
    },
};

void bhv_blargg_init(void) {
    obj_set_hitbox(o, &sBlarggHitbox);
    o->oWallHitboxRadius = 250.0f;
    o->oDamageOrCoinValue = o->oBehParams >> 16;
    if(o->oBehParams >> 24 == 0)
        o->activeFlags = o->activeFlags | ACTIVE_FLAG_MOVE_THROUGH_GRATE;
}

void blargg_act_idle(void) {
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 
            0x400);
    cur_obj_init_animation(0);
    cur_obj_resolve_wall_collisions();
    //make him not go through floors LULW
    if (o->oDistanceToMario < 3000.f) {
        o->oForwardVel = 5.0f;
        if(o->oDistanceToMario < 1000.f && o->oTimer > 30) {
            o->oHomeX = o->oPosX;
            o->oHomeY = o->oPosY;
            o->oHomeZ = o->oPosZ;
            o->oAction = BLARGG_LUNGE;
        }
    } else
        o->oForwardVel = 0.0f;
}

void blargg_act_lunge(void) {
    cur_obj_init_animation(1);
        if (o->oTimer >= 88)
            o->oAction = BLARGG_IDLE;
        else if (o->oTimer >= 53) {
            o->oForwardVel = 0.0f;
            cur_obj_set_pos_to_home();
        } else {
            //if (o->oTimer <= 18)
                cur_obj_resolve_wall_collisions();
            o->oForwardVel = 20.0f;
        }
}

void bhv_blargg_update(void) {

    switch(o->oAction) {
        case BLARGG_IDLE:
            blargg_act_idle();
            break;
        case BLARGG_LUNGE:
            blargg_act_lunge();
            break;
    }
    //cur_obj_move_xz_using_fvel_and_yaw();
    cur_obj_move_standard(-50);
    o->oInteractStatus = 0;
}