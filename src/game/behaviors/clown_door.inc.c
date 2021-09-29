void bhv_clown_door_spawner_init(void){
    o->oObjClownDoorTop = spawn_object_relative(0, 0, 0, 0, o, MODEL_CLOWN_DOOR_TOP, bhvClownDoorSegmentTop);
    o->oObjClownDoorBottom = spawn_object_relative(0, 0, 0, 0, o, MODEL_CLOWN_DOOR_BOTTOM, bhvClownDoorSegmentBottom);
}

void bhv_clown_door_spawner_loop(void){
/*
switch (o->oAction) {
        case 0:
            //cur_obj_become_tangible();
            if (o->oObjClownDoorBottom->oInteractStatus & INT_STATUS_INTERACTED)
                o->oAction = 1;
        case 1:
            if (o->oTimer == 0 && (s16)(o->oMoveAngleYaw) >= 0) {
                cur_obj_play_sound_2(SOUND_GENERAL_STAR_DOOR_OPEN);
#if ENABLE_RUMBLE
                queue_rumble_data(35, 30);
#endif
            }
            //cur_obj_become_intangible();
            o->oObjClownDoorBottom->oPosY += 1.0f;
            if (o->oTimer >= 16)
                o->oAction++;
            break;
        case 2:
            if (o->oTimer >= 31)
                o->oAction++;
            break;
        case 3:
            if (o->oTimer == 0) {
                cur_obj_play_sound_2(SOUND_GENERAL_STAR_DOOR_CLOSE);
#if ENABLE_RUMBLE
                queue_rumble_data(35, 30);
#endif
            }
            o->oObjClownDoorBottom->oPosY -= 1.0f;
            if (o->oTimer >= 16)
                o->oAction++;
            break;
        case 4:
            o->oInteractStatus = 0;
            o->oAction = 0;
            break;
    }
*/

if (o->oDistanceToMario > 300.0f && o->oTimer >= 30) {
    if (o->oDoorState == 0) {
        o->oDoorState = 1;
        o->oTimer = 0;
    }
}
else if (o->oDistanceToMario <= 300.0f && o->oTimer >= 30){
    if (o->oDoorState == 1) {
        o->oDoorState = 0;
        o->oTimer = 0;
    }
}
switch (o->oDoorState) {
    case 0:
if (o->oTimer < 30) {
 o->oObjClownDoorBottom->oPosY -= 16.0f;
 o->oObjClownDoorTop->oPosY += 4.0f;
}
break;
case 1:
if (o->oTimer < 30) {
 o->oObjClownDoorBottom->oPosY += 16.0f;
 o->oObjClownDoorTop->oPosY -= 4.0f;
}
break;
}

}

void bhv_clown_door_segment_loop(void){

}