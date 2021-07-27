#define CLEFT_ACT_ROCK 0
#define CLEFT_ACT_CHARGE 1
#define CLEFT_ACT_RAM 2
#define CLEFT_ACT_TRIP 3

static struct ObjectHitbox sCleftHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 90,
    /* height:            */ 90,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 80,
};

static u8 sCleftAttackHandlers[6] = {
        /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_NOP,
        /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
        /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_NOP,
        /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_NOP,
        /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_NOP,
        /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_NOP,
};

static u8 sCleftTrippedAttackHandlers[6] = {
        /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
        /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
        /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
        /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
        /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
        /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_cleft_init(void) {
    o->oGravity = -8.0f / 3.0f;
    obj_set_hitbox(o, &sCleftHitbox);
}

static void cleft_act_rock(void) {
    o->oAnimState = 1;
    if(o->oDistanceToMario < 1000.0f) {
        cur_obj_init_animation_with_accel_and_sound(0, 5.0f);
        if(o->oTimer > 30) {
            o->oAction = CLEFT_ACT_CHARGE;
        }
    } else {
        o->oTimer = 0;
        cur_obj_init_animation_with_accel_and_sound(2, 0.0f);
    }
}

static void cleft_act_charge(void) {
    o->oAnimState = 0;
    cur_obj_init_animation_with_accel_and_sound(0, 3.0f);
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x800);
    if(o->oTimer > 15)
        o->oAction = CLEFT_ACT_RAM;
}

static void cleft_act_ram(void) {
    o->oAnimState = 0;
    if(o->oTimer < 30) {
        o->oForwardVel = 30.0f;
    } else {
        o->oForwardVel = 30 - (o->oTimer - 30);
        if(o->oForwardVel < 0.0f)
            o->oForwardVel = 0.0f;
        if(o->oTimer > 75) {
            if(o->oDistanceToMario > 1000.0f)
                o->oAction = CLEFT_ACT_ROCK;
            else
                o->oAction = CLEFT_ACT_CHARGE;
        }
    }
    cur_obj_init_animation_with_accel_and_sound(0, o->oForwardVel / 6.0f);
}

void cleft_act_trip(void) {
    o->oAnimState = 0;
        if(o->oScuttlebugUnkFC == 0 && o->header.gfx.animInfo.animFrame > 10)
            o->oScuttlebugUnkFC = 1;
        else if (o->oScuttlebugUnkFC >= 1) {
            if (o->oTimer == 120)
                cur_obj_init_animation_with_accel_and_sound(4, 1.0f);
            else if (o->oTimer > 120 && o->header.gfx.animInfo.animFrame > 7) {
                o->oAction = CLEFT_ACT_CHARGE;
                o->oScuttlebugUnkFC = 0;
            }
            else if (o->oTimer < 120)
                cur_obj_init_animation_with_accel_and_sound(3, 1.0f);
            }
}

void bhv_cleft_update(void) {

    f32 animSpeed;

    if (obj_update_standard_actions(1.0f)) {

        cur_obj_update_floor_and_walls();

        if ((animSpeed = o->oForwardVel * 0.4f) < 1.0f) {
            animSpeed = 1.0f;
        }
        //cur_obj_init_animation_with_accel_and_sound(0, animSpeed);

        switch (o->oAction) {
            case CLEFT_ACT_ROCK:
                cleft_act_rock();
                break;
            case CLEFT_ACT_CHARGE:
                cleft_act_charge();
                break;
            case CLEFT_ACT_RAM:
                cleft_act_ram();
                break;
            case CLEFT_ACT_TRIP:
                cleft_act_trip();
                break;
        }

if (o->oAction != CLEFT_ACT_TRIP) {
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->oInteractStatus & INT_STATUS_ATTACKED_MARIO) {
                //o->oAction = REX_ACT_ATTACKED_MARIO;
        } else {
            s32 attackType = o->oInteractStatus & INT_STATUS_ATTACK_MASK;

            if(gMarioState->action == ACT_SLIDE_KICK_SLIDE || gMarioState->action == ACT_SLIDE_KICK)
                attackType = 2;
            if(gMarioState->action == ACT_JUMP_KICK || gMarioState->action == ACT_PUNCHING)
                attackType = 1;
            switch (sCleftAttackHandlers[attackType - 1]) {
                case ATTACK_HANDLER_NOP:
                    o->oInteractionSubtype = 0;
                    take_damage_and_knock_back(gMarioState, o);
                    break;

                case ATTACK_HANDLER_KNOCKBACK:
                    o->oIntangibleTimer = 15;
                    o->oAction = CLEFT_ACT_TRIP;
                    o->oForwardVel = 0;
                    cur_obj_init_animation_with_accel_and_sound(1, 1.0f);
                    o->oScuttlebugUnkFC = 0;
                    //obj_set_knockback_action(attackType);
                    break;
            }
        }
        o->oInteractStatus = 0;
    }
} else if (obj_handle_attacks(&sCleftHitbox, CLEFT_ACT_TRIP, sCleftTrippedAttackHandlers))
            //obj_mark_for_deletion(o);
            o->oForwardVel = 0;

        cur_obj_move_standard(-50);
    } else {
        o->oAnimState = TRUE;
    }
}
