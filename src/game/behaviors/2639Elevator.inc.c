
extern s16 sDelayedWarpTimer;
extern s16 sSourceWarpNodeId;
#define WARP_OP_WARP_OBJECT 4
extern s16 sDelayedWarpOp;

void elvWarpMario(int node) {
    sDelayedWarpTimer = 0x13;
    sSourceWarpNodeId = node;
    sDelayedWarpOp = WARP_OP_WARP_OBJECT;
    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x16, 0,0,0);
}


void bhv_2639Elevator_init(void) {
    o->oAction = 0;
    // o->oHomeY = o->oPosY;
}
void bhv_2639Elevator_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gCurrAreaIndex != 2) { // make sure this only happens in the new area
                if ((o->oBehParams >> 24) == 1) {
                    o->oAction = 5;
                    o->oTimer = 0;
                }
            }

            else {
                if (gMarioObject->platform == o) {
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
            o->oPosY += 8.0f;
            if (o->oTimer > 200) {
                o->oAction++;
                elvWarpMario(o->oBehParams2ndByte);
            }
        break;
        case 3:
            o->oPosY += 8.0f;
        break;


        case 5:
            o->oPosY -= 200.0f;
            extern void teleportMario(f32, f32, f32);
            teleportMario(o->oPosX, o->oPosY, o->oPosZ);
            // if (o->oTimer > 60) {
                o->oAction ++;
                o->oTimer = 0;
            // }

        break;

        case 6:
            o->oPosY += 8;
            if (o->oPosY >= o->oHomeY) {
                o->oPosY = o->oHomeY;
                if (gMarioObject->platform != o) {
                    o->oTimer = 0;
                    o->oAction++;
                }
            }
        break;
        case 7:
            if (gMarioObject->platform == o) {
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
            o->oPosY -= 8.0f;
            if (o->oTimer > 200) {
                o->oAction++;
                elvWarpMario(o->oBehParams2ndByte);
            }
        break;
        case 10:
            o->oPosY -= 8.0f;
        break;
    }



    // print_text_fmt_int(20, 100, "S %d", o->oAction);
}
