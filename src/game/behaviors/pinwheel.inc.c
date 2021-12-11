void bhv_pinwheel_init(void) {
    if (o->oBehParams2ndByte == 1) {
    o->oObjBalloon = spawn_object_relative(0, 0, 0, 400, o, MODEL_CIRCUS_BALLOON, bhvCircusBalloon);
    o->oBalloonInitY = o->oObjBalloon->oPosY;
    o->oObjBalloon->oFaceAnglePitch = 0;
    o->oObjBalloon->oMoveAnglePitch = 0;
    }
    if (o->oBehParams2ndByte == 4 || o->oBehParams2ndByte == 5) {
        obj_scale_xyz(o, 0.5, 0.5, 0.5);
    }
}
void bhv_pinwheel_loop(void) {
    if (o->header.gfx.node.flags & GRAPH_RENDER_ACTIVE) {

    switch (o->oBehParams2ndByte) {
            case 0:
            case 4:
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
        case 2:
                o->oFaceAngleRoll += 0x800;
                o->oMoveAngleRoll += 0x800;
                cur_obj_play_sound_1(SOUND_AIR_BLOW_WIND);
                cur_obj_spawn_weak_wind_particles(12, 3.0f, 0.0f, -50.0f, 120.0f);
        break;
        case 3:
        o->oFaceAngleYaw += 0x800;
         o->oMoveAngleYaw += 0x800;
        cur_obj_play_sound_1(SOUND_AIR_BLOW_WIND);
        cur_obj_spawn_pinwheel_wind_particles(12, 3.0f, 0.0f, -50.0f, 120.0f);

        break;
        }
    }
    
        
}

void bhv_balloon_init(void) {
    //switch (o->oBehParams2ndByte) {
            //case 0:
            o->oObjBalloonCol = spawn_object_relative(0, 0, 0, 0, o, MODEL_NONE, bhvCircusBalloonCol);
            o->oBalloonInitSide = o->oPosZ;
    //break;

}

void bhv_balloon_loop(void) {    
    switch (o->oBehParams2ndByte) {
            case 0:
            o->oFaceAngleYaw += 0x100;
                o->oMoveAngleYaw += 0x100;

            o->oObjBalloonCol->oPosX = o->oPosX;
            o->oObjBalloonCol->oPosY = o->oPosY;
            o->oObjBalloonCol->oPosZ = o->oPosZ;

    break;
    case 1:
        //load_object_collision_model();
        o->oFaceAngleYaw += 0x100;
                o->oMoveAngleYaw += 0x100;
        
            o->oBalloonTimer += 1;
            o->oPosY += 10*sins(o->oPinwheelTimer*0x300);
            o->oPosX += 50*sins(o->oPinwheelTimer*0x170);

            o->oObjBalloonCol->oPosX = o->oPosX;
            o->oObjBalloonCol->oPosY = o->oPosY;
            o->oObjBalloonCol->oPosZ = o->oPosZ;
    break;

    case 2:
        //load_object_collision_model();
        o->oFaceAngleYaw += 0x100;
                o->oMoveAngleYaw += 0x100;
        
            o->oBalloonTimer += 1;
            o->oPosY += 10*sins(o->oPinwheelTimer*0x300);
            o->oPosZ -= 50*sins(o->oPinwheelTimer*0x170);

            o->oObjBalloonCol->oPosX = o->oPosX;
            o->oObjBalloonCol->oPosY = o->oPosY;
            o->oObjBalloonCol->oPosZ = o->oPosZ;
    break;
}
}