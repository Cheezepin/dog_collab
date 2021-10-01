void bhv_pinwheel_init(void) {
    if (o->oBehParams2ndByte == 1) {
    o->oObjBalloon = spawn_object_relative(0, 0, 0, 400, o, MODEL_CIRCUS_BALLOON, bhvCircusBalloon);
    o->oBalloonInitY = o->oObjBalloon->oPosY;
    o->oObjBalloon->oFaceAnglePitch = 0;
    o->oObjBalloon->oMoveAnglePitch = 0;
    }
}
void bhv_pinwheel_loop(void) {
    switch (o->oBehParams2ndByte) {
            case 0:
                o->oFaceAngleRoll += 0x200;
                o->oMoveAngleRoll += 0x200;
            break;
        case 1:
                o->oPinwheelTimer += 1;
                o->oFaceAngleYaw += 0x800;
                o->oMoveAngleYaw += 0x800;
                o->oObjBalloon->oPosY += 20*sins(o->oPinwheelTimer*0x400);
                cur_obj_play_sound_1(SOUND_AIR_BLOW_WIND);
                cur_obj_spawn_weak_wind_particles(12, 3.0f, 0.0f, -50.0f, 120.0f);
        break;
        }

        
}
void bhv_balloon_loop(void) {
    
}