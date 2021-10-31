void bhv_clown_door_spawner_init(void){
    o->oObjClownDoorTop = spawn_object_relative(0, 0, 0, 0, o, MODEL_CLOWN_DOOR_TOP, bhvClownDoorSegmentTop);
    o->oObjClownDoorBottom = spawn_object_relative(0, 0, 0, 0, o, MODEL_CLOWN_DOOR_BOTTOM, bhvClownDoorSegmentBottom);
    
}

void bhv_clown_door_spawner_loop(void){

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

void bhv_steel_gate_init(void) {
    if (o->oBehParams2ndByte == 1) {
        obj_scale_xyz(o, 1.5, 1.5, 1.5);
    }
}