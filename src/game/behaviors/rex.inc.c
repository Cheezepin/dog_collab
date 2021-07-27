    /* oAction */
    #define REX_ACT_WALK 0
    #define REX_ACT_ATTACKED_MARIO 1
    #define REX_ACT_JUMP 2
    #define ATTACK_HANDLER_GPD_ON 9

static struct ObjectHitbox sRexHitbox = {
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

static u8 sRexAttackHandlers[][6] = {
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

void bhv_rex_init(void) {

    //o->oGoombaScale = 1.0f;
    //o->oGoombaSize = o->oBehParams2ndByte & GOOMBA_BP_SIZE_MASK;

    o->oGraphYOffset = -61.0f;

    o->oGravity = -8.0f / 3.0f; //* o->oGoombaScale
    obj_set_hitbox(o, &sRexHitbox);
    //cur_obj_scale(o->oGoombaScale);
}

/**
 * Enter the jump action and set initial y velocity.
 */
static void rex_begin_jump(void) {
    cur_obj_play_sound_2(SOUND_OBJ_GOOMBA_ALERT);
    o->oAction = REX_ACT_JUMP;
    o->oForwardVel = 0.0f;
    o->oVelY = 50.0f / 3.0f; //* o->oGoombaScale;
}

/**
 * Walk around randomly occasionally jumping. If mario comes within range,
 * chase him.
 */
static void rex_act_walk(void) {
    treat_far_home_as_mario(1000.0f);

    obj_forward_vel_approach(o->oGoombaRelativeSpeed, 0.4f);

    // If walking fast enough, play footstep sounds
    if (o->oGoombaRelativeSpeed > 4.0f / 3.0f) {
        cur_obj_play_sound_at_anim_range(2, 17, SOUND_OBJ_GOOMBA_WALK);
    }

    if (o->oGoombaTurningAwayFromWall) {
        o->oGoombaTurningAwayFromWall = obj_resolve_collisions_and_turn(o->oGoombaTargetYaw, 0x200);
    } else {
        // If far from home, walk toward home.
        if (o->oDistanceToMario >= 25000.0f) {
            o->oGoombaTargetYaw = o->oAngleToMario;
            o->oGoombaWalkTimer = random_linear_offset(20, 30);
        }

        if (!(o->oGoombaTurningAwayFromWall =
                  obj_bounce_off_walls_edges_objects(&o->oGoombaTargetYaw))) {
            if (o->oDistanceToMario < 500.0f) {
                // If close to mario, begin chasing him. If not already chasing
                // him, jump first

                if (o->oGoombaRelativeSpeed <= 2.0f) {
                    rex_begin_jump();
                }

                o->oGoombaTargetYaw = o->oAngleToMario;
                o->oGoombaRelativeSpeed = 20.0f;
            } else {
                // If mario is far away, walk at a normal pace, turning randomly
                // and occasionally jumping

                o->oGoombaRelativeSpeed = 4.0f / 3.0f;
                if (o->oGoombaWalkTimer != 0) {
                    o->oGoombaWalkTimer -= 1;
                } else {
                    if (random_u16() & 3) {
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x2000);
                        o->oGoombaWalkTimer = random_linear_offset(100, 100);
                    } else {
                        rex_begin_jump();
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x6000);
                    }
                }
            }
        }

        cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x200);
    }
}

static void rex_act_attacked_mario(void) {
        rex_begin_jump();
        o->oGoombaTargetYaw = o->oAngleToMario;
        o->oGoombaTurningAwayFromWall = FALSE;
}

/**
 * Move until landing, and rotate toward target yaw.
 */
static void rex_act_jump(void) {
    obj_resolve_object_collisions(NULL);

    if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
        o->oAction = REX_ACT_WALK;
    } else {
        cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x800);
    }
}

void bhv_rex_update(void) {
    // PARTIAL_UPDATE

    f32 animSpeed;

    if (obj_update_standard_actions(1.0f)) {

        //obj_update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);
        cur_obj_update_floor_and_walls();

        if ((animSpeed = o->oForwardVel * 0.4f) < 1.0f) {
            animSpeed = 1.0f;
        }
        cur_obj_init_animation_with_accel_and_sound(0, animSpeed);

        switch (o->oAction) {
            case REX_ACT_WALK:
                rex_act_walk();
                break;
            case REX_ACT_ATTACKED_MARIO:
                rex_act_attacked_mario();
                break;
            case REX_ACT_JUMP:
                rex_act_jump();
                break;
        }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->oInteractStatus & INT_STATUS_ATTACKED_MARIO) {
            if (o->oAction != REX_ACT_ATTACKED_MARIO) {
                o->oAction = REX_ACT_ATTACKED_MARIO;
                o->oTimer = 0;
            }
        } else {
            s32 attackType = o->oInteractStatus & INT_STATUS_ATTACK_MASK;

            switch (sRexAttackHandlers[0][attackType - 1]) {
                case ATTACK_HANDLER_NOP:
                    break;

                case ATTACK_HANDLER_KNOCKBACK:
                    obj_set_knockback_action(attackType);
                    break;

                case ATTACK_HANDLER_SQUISHED:
                    if (o->header.gfx.scale[1] < 1.0f) {
                        obj_set_squished_action();
                    } else {
                    o->header.gfx.scale[1] = 0.5f;
                    }
                    break;
                case ATTACK_HANDLER_GPD_ON:
                    obj_set_squished_action();
                    break;
        }
        }
        o->oInteractStatus = 0;
    }

        cur_obj_move_standard(-78);
    } else {
        o->oAnimState = TRUE;
    }
}
