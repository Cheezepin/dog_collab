
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
}
void bhv_2639Elevator_loop(void) {
	switch (o->oAction) {
		case 0:
			if (gMarioObject->platform == o) {
				o->oTimer = 0;
				o->oAction++;
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
	}
}
