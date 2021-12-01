void bhv_clown_clock_init(void) {

}
void bhv_clown_clock_loop(void) {
    //o->oTimer += 1;

if (o->oTimer >= 35) {
    o->oTimer = 0;
}

    if (o->oTimer >= 30) {
        switch (o->oBehParams2ndByte) {
            case 0:
                o->oFaceAnglePitch += (0x8000 * 2) / 60;
                o->oMoveAnglePitch += (0x8000 * 2) / 60;
            break;
        case 1:
                o->oFaceAngleYaw += (0x8000 * 2) / 60;
                o->oMoveAngleYaw += (0x8000 * 2) / 60;
        break;
        }
    }
}