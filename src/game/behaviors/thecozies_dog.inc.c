#include "game/behaviors/thecozies_helpers.h"

void bhv_cozies_dog_init() {
    o->oNumLootCoins = 5;
}

#define COZIES_DOG_LOOK_AT_MARIO_DIST 1000
#define COZIES_DOG_SPAWN_COINS_DIST 500

enum COZIES_DOG_ACTS {
    COZIES_DOG_ACT_WAIT,
    COZIES_DOG_ACT_SPAWN_COINS,
    COZIES_DOG_ACT_SPAWNED_COINS,
};

void bhv_cozies_dog_loop() {
    if (o->oDistanceToMario < COZIES_DOG_LOOK_AT_MARIO_DIST) {
        o->oFaceAngleYaw = approach_angle(o->oFaceAngleYaw, o->oAngleToMario, DEGREES(3));

        if (o->oAction == COZIES_DOG_ACT_WAIT && o->oDistanceToMario < COZIES_DOG_SPAWN_COINS_DIST) {
            cur_obj_change_action(COZIES_DOG_ACT_SPAWN_COINS);
            cur_obj_init_animation(4);
        }
    }

    switch(o->oAction) {
        case COZIES_DOG_ACT_WAIT:
            break;
        case COZIES_DOG_ACT_SPAWN_COINS:
            if (o->oTimer % 20 == 0) {
                cur_obj_spawn_loot_20_coins(1, 10);
                cur_obj_init_animation(4);
            }

            if (o->oNumLootCoins == 0) cur_obj_change_action(COZIES_DOG_ACT_SPAWNED_COINS);
            break;
        case COZIES_DOG_ACT_SPAWNED_COINS:
            cur_obj_init_animation(0);
            break; 
    }
}
