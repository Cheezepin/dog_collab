
extern s16 sDelayedWarpTimer;
extern s16 sSourceWarpNodeId;
#define WARP_OP_WARP_OBJECT 4
extern s16 sDelayedWarpOp;


void elvWarpMario(int node) {
    sDelayedWarpTimer = 0x13;
    sSourceWarpNodeId = node;
    sDelayedWarpOp = WARP_OP_WARP_OBJECT;
    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x13, 0,0,0);
}

#define oElevatorMovementMultiplier OBJECT_FIELD_F32(0x1B)
#define elevDistanceLatch OBJECT_FIELD_S32(0x1C)
void bhv_2639Elevator_init(void) {
    o->oAction = 0;

    o->elevDistanceLatch = 1; // 2 means DONT go down, 0 means CLEAR

    s8 multiplier = ((o->oBehParams >> 8) & 0xFF);

    if (multiplier == 0) {
        o->oElevatorMovementMultiplier = 1.0f;
    } else {
        o->oElevatorMovementMultiplier = -1.0f;
    }

    // if (o->oPosY < -100) {
    //     o->oPosY = 0;
    //     o->oHomeY = o->oPosY;
    // }
}
void bhv_2639Elevator_loop(void) {

    if (o->oDistanceToMario >= 1500) {
        o->elevDistanceLatch = 2;
    }
    if (o->oDistanceToMario < 1500 && o->elevDistanceLatch == 2) {
        o->elevDistanceLatch = 0;
    }

    switch (o->oAction) {
        case 0:
            if (gCurrAreaIndex != 2) { // make sure this only happens in the new area
                if ((o->oBehParams >> 24) == 1) {
                    o->oAction = 5;
                    o->oTimer = 0;
                }
            }

            else {
                if (gMarioObject->platform == o && o->elevDistanceLatch == 0) {
                    o->oTimer = 0;
                    o->oAction++;
                }
            }
        break;

        case 1:
            if (o->oTimer > 18) {
                o->oAction++;
                o->oTimer = 0;
            }
        break;
        case 2:
            o->oPosY += (8.0f * o->oElevatorMovementMultiplier);
            if (o->oTimer > 200) {
                o->oAction++;
                elvWarpMario(o->oBehParams2ndByte);
                o->elevDistanceLatch = 1;
            }
        break;
        case 3:
            o->oPosY += (8.0f * o->oElevatorMovementMultiplier);
            o->oTimer = 0;
        break;


        case 5:
            o->oPosY -= (200.0f * o->oElevatorMovementMultiplier);
            extern void teleportMario(f32, f32, f32);
            teleportMario(o->oPosX, o->oPosY + 20.0f, o->oPosZ);
            o->elevDistanceLatch = 1;
            // if (o->oTimer > 60) {
                o->oAction ++;
                o->oTimer = 0;
            // }

        break;

        case 6:
            o->oPosY += (8 * o->oElevatorMovementMultiplier);
            teleportMario(o->oPosX, o->oPosY + 20.0f, o->oPosZ);
            o->elevDistanceLatch = 1;
            if (o->oElevatorMovementMultiplier == -1.0f) {
                if (o->oPosY <= o->oHomeY) {
                    o->oPosY = o->oHomeY;
                        o->oAction++;
                        o->oTimer = 0;
                }
            } else {
                if (o->oPosY >= o->oHomeY) {
                    o->oPosY = o->oHomeY;
                        o->oTimer = 0;
                        o->oAction++;
                    // if (gMarioObject->platform != o) {
                    // }
                }
            }
        break;
        case 7:
            if (gMarioObject->platform == o && o->elevDistanceLatch == 0) {
                o->oTimer = 0;
                o->oAction++;
            }
        break;

        case 8:
            if (o->oTimer > 18) {
                o->oAction++;
                o->oTimer = 0;
            }
        break;
        case 9:
            o->oPosY -= (8.0f * o->oElevatorMovementMultiplier);
            if (o->oTimer > 200) {
                o->oAction++;
                elvWarpMario(o->oBehParams2ndByte);
                o->elevDistanceLatch = 1;
            }
        break;
        case 10:
            o->oPosY -= (8.0f * o->oElevatorMovementMultiplier);
        break;
    }


    // char dbg[50];
    // sprintf(dbg, "F %0.2f L %d S %d", o->oDistanceToMario, o->elevDistanceLatch, o->oAction);
    // print_text(20, 100, dbg);
}
